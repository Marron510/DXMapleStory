#include "PreCompile.h"


#include <EngineBase/FSMStateManager.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/TimeEventComponent.h>

#include "Player.h"
#include "EventCharacter.h"
#include "MapleEnum.h"

#include "WrathOfEnril.h"




void APlayer::StateInit()
{
	FSM.CreateState(ECharacterState::Idle, std::bind(&APlayer::Idle, this, std::placeholders::_1),
		[this]()
		{
			PlayerRenderer->ChangeAnimation("Idle");
		}
	);

	FSM.CreateState(ECharacterState::Prone, std::bind(&APlayer::Prone, this, std::placeholders::_1),
		[this]()
		{
			PlayerRenderer->ChangeAnimation("Prone");
		}
	);

	FSM.CreateState(ECharacterState::Walk, std::bind(&APlayer::Walk, this, std::placeholders::_1),
		[this]()
		{
			PlayerRenderer->ChangeAnimation("Walk");
		}
	);
	FSM.CreateState(ECharacterState::IdleJump, std::bind(&APlayer::IdleJump, this, std::placeholders::_1),
		[this]()
		{
			PlayerRenderer->ChangeAnimation("Jump");
		}
	);

	FSM.CreateState(ECharacterState::WalkJump, std::bind(&APlayer::WalkJump, this, std::placeholders::_1),
		[this]()
		{
			PlayerRenderer->ChangeAnimation("Jump");
		}
	);
	FSM.CreateState(ECharacterState::Air, std::bind(&APlayer::Air, this, std::placeholders::_1),
		[this]()
		{
			PlayerRenderer->ChangeAnimation("Jump");
		}
	);

	
}




void APlayer::Idle(float _DeltaTime)
{
	// 제자리에서 이동전환
	PlayerGroundCheck(GravityForce * _DeltaTime);
	Gravity(_DeltaTime);
	UseSkill(_DeltaTime);
	

	if (UEngineInput::IsPress(VK_LEFT)){ FSM.ChangeState(ECharacterState::Walk); return; }
	if (UEngineInput::IsPress(VK_RIGHT)) { FSM.ChangeState(ECharacterState::Walk); return; }
	if (UEngineInput::IsPress(VK_DOWN)){ FSM.ChangeState(ECharacterState::Prone); return; }
	if (UEngineInput::IsPress(VK_UP))
	{
		FSM.ChangeState(ECharacterState::Walk);

	}
	
	if (false == bIsGround)
	{
		FSM.ChangeState(ECharacterState::Air);
	}


	// 제자리에서 점프 사용

	if (UEngineInput::IsPress('C')) { bIsJumping = true; FSM.ChangeState(ECharacterState::IdleJump); return; }


}


void APlayer::Prone(float _DeltaTime)
{
	PlayerGroundCheck(GravityForce * _DeltaTime);
	Gravity(_DeltaTime);
	UseSkill(_DeltaTime);
	if (UEngineInput::IsUp(VK_DOWN))
	{
		FSM.ChangeState(ECharacterState::Idle);
		return;
	}


	
	// 엎드려서 점프
	if (UEngineInput::IsDown('C')) { FSM.ChangeState(ECharacterState::IdleJump); }
}




void APlayer::Walk(float _DeltaTime)
{
	PlayerGroundCheck(GravityForce * _DeltaTime);
	Gravity(_DeltaTime);
	UseSkill(_DeltaTime);

	if (UEngineInput::IsPress(VK_LEFT))
	{
		TargetVelocity = FVector(PlayerSpeed, 0.0f, 0.0f);
		SetActorRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
	}

	if (UEngineInput::IsPress(VK_RIGHT))
	{
		TargetVelocity = FVector(PlayerSpeed, 0.0f, 0.0f);
		SetActorRelativeScale3D(FVector(-1.0f, 1.0f, 1.0f));
	}

	CurrentVelocity.X = UEngineMath::Lerp(CurrentVelocity.X, TargetVelocity.X, _DeltaTime * 2.0f);


	// 체공

	if (false == bIsGround && true == UEngineInput::IsPress(VK_RIGHT) )
	{
		int a = 0;
	}
	
	// 점프
		
	if (UEngineInput::IsDown('C') && UEngineInput::IsPress(VK_LEFT))
	{ 
		bIsJumpRight = false; 
		FSM.ChangeState(ECharacterState::WalkJump); 
		return;
	}

	if (UEngineInput::IsDown('C') && UEngineInput::IsPress(VK_RIGHT)) 
	{
		bIsJumpRight = true; 
		FSM.ChangeState(ECharacterState::WalkJump);
		return;
	}
		
	// 이동이 멈출 때 Idle 상태로 전환
	if (UEngineInput::IsUp(VK_LEFT) || UEngineInput::IsUp(VK_RIGHT))
	{
		FSM.ChangeState(ECharacterState::Idle);
		return;
	}

	

	// 캐릭터 이동
	if (UEngineInput::IsPress(VK_LEFT))
	{
		AddActorLocation(-CurrentVelocity * _DeltaTime);
	}
	if (UEngineInput::IsPress(VK_RIGHT))
	{
		AddActorLocation(CurrentVelocity * _DeltaTime);
	}


}

void APlayer::IdleJump(float _DeltaTime)
{
	bIsGround = false;
	PlayerGroundCheck(GravityForce * _DeltaTime);
	JumpGravity(_DeltaTime);
	UseSkill(_DeltaTime);

	JumpVelocity = JumpPower;
	TargetJumpVelocity = FVector::ZERO;

	
	if (false == bIsGround)
	{
		TargetJumpVelocity = JumpPower;
	}

	JumpVelocity.Y = UEngineMath::Lerp(JumpVelocity.Y, TargetJumpVelocity.Y, _DeltaTime * 5.0f);

	if (true == bIsJumping)
	{
		// 점프 실행
		AddActorLocation(JumpVelocity * _DeltaTime);
	}
	


	if (true == UEngineInput::IsDown(VK_LEFT))
	{
		SetActorRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
	}

	if (true == UEngineInput::IsDown(VK_RIGHT))
	{

		SetActorRelativeScale3D(FVector(-1.0f, 1.0f, 1.0f));

	}
	
	if (true == bIsLeafUsing)
	{
		AddActorLocation(JumpVelocity * 0.8f * _DeltaTime);
	}

	// 착지 시 Idle 상태로 전환



	// 스킬 사용시
	if (true == bIsSkillUsing && 0.00001f > TargetJumpVelocity.Y)
	{
		bIsJumping = false;
		

		if (true == PlayerRenderer->IsCurAnimationEnd())
		{
			AddActorLocation(FVector::UP * 4.0f);
			bIsSkillUsing = false;
			bIsLeafUsing = false;
			FSM.ChangeState(ECharacterState::Idle);
		}
	}

	else if (true == bIsSkillUsing && 0.00001f < TargetJumpVelocity.Y)
		{
			bIsJumping = true;

			if (true == PlayerRenderer->IsCurAnimationEnd())
			{
				AddActorLocation(FVector::UP *4.0f);
				bIsSkillUsing = false;
				FSM.ChangeState(ECharacterState::Air);
				return;
			}
		}
	// 스킬 사용 안할시
	else if (false == bIsSkillUsing && 0.00001f > TargetJumpVelocity.Y)
	{
		AddActorLocation(FVector::UP * 4.0f);
		FSM.ChangeState(ECharacterState::Idle);
		return;
	}
	
	//if (0.00001f > TargetJumpVelocity.Y)
	//{
	//	AddActorLocation(FVector::UP * 10.0f);
	//	FSM.ChangeState(ECharacterState::Idle);
	//}

}

void APlayer::WalkJump(float _DeltaTime)
{
	bIsGround = false;
	//bIsJumpMoveEnd = false;
	PlayerGroundCheck(GravityForce * _DeltaTime);
	JumpGravity(_DeltaTime);
	UseSkill(_DeltaTime);

	JumpVelocity = JumpPower; 
	TargetJumpVelocity = FVector::ZERO; 

	if (false == bIsGround)
	{
		TargetJumpVelocity = JumpPower;
	}

	JumpVelocity.Y = UEngineMath::Lerp(JumpVelocity.Y, TargetJumpVelocity.Y, _DeltaTime * 5.0f);

	// 점프 실행
	AddActorLocation(JumpVelocity * _DeltaTime);





	if (false == bIsJumpRight )
	{
		AddActorLocation(FVector(-PlayerSpeed * _DeltaTime, 0.0f, 0.0f));
	}

	else if (true == bIsJumpRight)
	{
		AddActorLocation(FVector(PlayerSpeed * _DeltaTime, 0.0f, 0.0f));
	}
	
	if (true == UEngineInput::IsDown(VK_LEFT))
	{
		SetActorRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
	}
	if (true == UEngineInput::IsDown(VK_RIGHT))
	{
		SetActorRelativeScale3D(FVector(-1.0f, 1.0f, 1.0f));
	}

	// 착지 시 Idle 상태로 전환
	if (true == UEngineInput::IsUp(VK_RIGHT) || true == UEngineInput::IsUp(VK_LEFT))
	{
		bIsJumpMoveEnd = true;
	}
	if (true == bIsJumpMoveEnd && 0.00000000001f > TargetJumpVelocity.Y)
	{
		bIsJumpMoveEnd = false;
		AddActorLocation(FVector::UP * 6.0f);
		FSM.ChangeState(ECharacterState::Idle);
		return;
	}

}


void APlayer::Air(float _DeltaTime)
{
	PlayerGroundCheck(GravityForce * _DeltaTime);
	Gravity(_DeltaTime);
	UseSkill(_DeltaTime);

	if (true == bIsGround )
	{
		FSM.ChangeState(ECharacterState::Idle);
		return;
	}

}

void APlayer::UseSkill(float _DeltaTime)
{
	// 레쓰 오브 엔릴
	if (UEngineInput::IsPress('A')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("Wrath"); }

	// 스트라이크 듀얼 샷
	if (UEngineInput::IsPress('S')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("StrikeDualShot"); }

	// 스듀는 바로 캐릭터 Idle 전환
	if (UEngineInput::IsUp('S')) { bIsSkillUsing = true; FSM.ChangeState(ECharacterState::Idle); }

	// 리프 토네이도 
	if (UEngineInput::IsPress('D')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("Tornado");
	
	}

	// 롤링 어썰트
	if (UEngineInput::IsPress('E')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("Rolling"); }

	// 차지 드라이브
	if (UEngineInput::IsPress('Q')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("Charge"); }

	// 하이킥 데몰리션
	{
		if (UEngineInput::IsPress('W')) { PlayerRenderer->ChangeAnimation("HighKick"); }
		if (UEngineInput::IsDown('W')) { AddActorLocation(FVector(0.0f, 200.0f)); }
	}
}



void APlayer::IdleUseSkill(float _DeltaTime)
{
	// 레쓰 오브 엔릴
	if (UEngineInput::IsPress('A')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("Wrath"); }

	// 스트라이크 듀얼 샷
	if (UEngineInput::IsPress('S')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("StrikeDualShot"); }

	// 스듀는 바로 캐릭터 Idle 전환
	if (UEngineInput::IsUp('S')) { bIsSkillUsing = true; FSM.ChangeState(ECharacterState::Idle); }

	// 차지 드라이브
	if (UEngineInput::IsPress('Q')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("Charge"); }

	// 하이킥 데몰리션
	{
		if (UEngineInput::IsPress('W')) { PlayerRenderer->ChangeAnimation("HighKick"); }
		if (UEngineInput::IsDown('W')) { AddActorLocation(FVector(0.0f, 200.0f)); }
	}
}

void APlayer::AirUseSkill(float _DeltaTime)
{
	// 레쓰 오브 엔릴
	if (UEngineInput::IsPress('A')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("Wrath"); }

	// 스트라이크 듀얼 샷
	if (UEngineInput::IsPress('S')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("StrikeDualShot"); }

	// 스듀는 바로 캐릭터 Idle 전환
	if (UEngineInput::IsUp('S')) { bIsSkillUsing = true; FSM.ChangeState(ECharacterState::Air); }

	// 리프 토네이도 
	if (UEngineInput::IsPress('D')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("Tornado");
	bIsLeafUsing = true;
	
	}

	// 롤링 어썰트
	if (UEngineInput::IsPress('E')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("Rolling"); }

	// 하이킥 데몰리션
	{
		if (UEngineInput::IsPress('W')) { PlayerRenderer->ChangeAnimation("HighKick"); }
		if (UEngineInput::IsDown('W')) { AddActorLocation(FVector(0.0f, 200.0f)); }
	}
}
