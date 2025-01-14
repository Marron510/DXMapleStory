#include "PreCompile.h"


#include <EngineBase/FSMStateManager.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/TimeEventComponent.h>
#include <EngineCore/Collision.h>

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
	FSM.CreateState(ECharacterState::UpJump, std::bind(&APlayer::UpJump, this, std::placeholders::_1),
		[this]()
		{
			PlayerRenderer->ChangeAnimation("Jump");
		}
	);
	FSM.CreateState(ECharacterState::WalkUpJump, std::bind(&APlayer::WalkUpJump, this, std::placeholders::_1),
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
	Gravity(_DeltaTime);
	IdleUseSkill(_DeltaTime);
	

	if (UEngineInput::IsPress(VK_LEFT) && true == MoveCollision->IsColliding()){ FSM.ChangeState(ECharacterState::Walk); return; }
	if (UEngineInput::IsPress(VK_RIGHT) && true == MoveCollision->IsColliding()) { FSM.ChangeState(ECharacterState::Walk); return; }
	if (UEngineInput::IsPress(VK_DOWN) && true == MoveCollision->IsColliding()){ FSM.ChangeState(ECharacterState::Prone); return; }
	//if (UEngineInput::IsPress(VK_UP))
	//{
	//	FSM.ChangeState(ECharacterState::Walk);
	//	return;
	//}

	if (UEngineInput::IsPress('C')) { bIsJumping = true; FSM.ChangeState(ECharacterState::IdleJump); return; }


	// 체공
	if (false == bIsJumping  && false == bIsGround)
	{
		FSM.ChangeState(ECharacterState::Air);
		return;
	}

	if (true == PlayerRenderer->IsCurAnimationEnd())
	{
		FSM.ChangeState(ECharacterState::Idle);
	}
	
}


void APlayer::Prone(float _DeltaTime)
{
	Gravity(_DeltaTime);
	IdleUseSkill(_DeltaTime);
	
	
	if (UEngineInput::IsUp(VK_DOWN) && true == MoveCollision->IsColliding())
	{
		FSM.ChangeState(ECharacterState::Idle);
		return;
	}


	
	// 엎드려서 점프(아래점프)
	//if (UEngineInput::IsDown('C')) { FSM.ChangeState(ECharacterState::IdleJump); }
}




void APlayer::Walk(float _DeltaTime)
{
	Gravity(_DeltaTime);
	IdleUseSkill(_DeltaTime);

	if (UEngineInput::IsPress(VK_LEFT) && true == MoveCollision->IsColliding())
	{
		TargetVelocity = FVector(PlayerSpeed, 0.0f, 0.0f);
		SetActorRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
	}

	if (UEngineInput::IsPress(VK_RIGHT) && true == MoveCollision->IsColliding())
	{
		TargetVelocity = FVector(PlayerSpeed, 0.0f, 0.0f);
		SetActorRelativeScale3D(FVector(-1.0f, 1.0f, 1.0f));
	}

	CurrentVelocity.X = UEngineMath::Lerp(CurrentVelocity.X, TargetVelocity.X, _DeltaTime * 2.0f);


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
	if (UEngineInput::IsUp(VK_LEFT) && true == MoveCollision->IsColliding() || UEngineInput::IsUp(VK_RIGHT) && true == MoveCollision->IsColliding())
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
	

	Gravity(_DeltaTime);
	AirUseSkill(_DeltaTime);

	JumpVelocity = JumpPower;
	TargetJumpVelocity = FVector::ZERO;

	
	if (false == bIsGround)
	{
		TargetJumpVelocity = JumpPower;
	}

	JumpVelocity.Y = UEngineMath::Lerp(JumpVelocity.Y, TargetJumpVelocity.Y, _DeltaTime * 5.0f);

	// 점프 실행
	if (true == bIsJumping && false == bIsZeroGravity)
	{
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

	if (true == UEngineInput::IsDown('C') && true == UEngineInput::IsPress(VK_UP))
	{
		FSM.ChangeState(ECharacterState::UpJump);
	}



	if (true == UEngineInput::IsPress(VK_LEFT))
	{
		SetActorRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
		AddActorLocation(FVector(-PlayerSpeed * 0.2f * _DeltaTime, 0.0f, 0.0f));
	}
	if (true == UEngineInput::IsPress(VK_RIGHT))
	{
		SetActorRelativeScale3D(FVector(-1.0f, 1.0f, 1.0f));
		AddActorLocation(FVector(PlayerSpeed * 0.2f * _DeltaTime, 0.0f, 0.0f));
	}

	// 착지 시 Idle 상태로 전환
	if (true == UEngineInput::IsUp('C') && true == bIsGround)
	{
		bIsJumpMoveEnd = true;

	}
	if (true == UEngineInput::IsFree('C') && true == bIsGround)
	{
		bIsJumpMoveEnd = true;

	}

	if (true == bIsJumpMoveEnd && bIsGround == true)
	{
		bIsJumpMoveEnd = false;
		FSM.ChangeState(ECharacterState::Idle);
		return;
	}

}

void APlayer::WalkJump(float _DeltaTime)
{
	Gravity(_DeltaTime);
	AirUseSkill(_DeltaTime);

	JumpVelocity = JumpPower; 
	TargetJumpVelocity = FVector::ZERO; 

	if (false == bIsGround)
	{
		TargetJumpVelocity = JumpPower;
	}

	JumpVelocity.Y = UEngineMath::Lerp(JumpVelocity.Y, TargetJumpVelocity.Y, _DeltaTime * 5.0f);

	// 점프 실행
	if (false == bIsZeroGravity)
	{
		AddActorLocation(JumpVelocity * _DeltaTime);
	}


	if (true == UEngineInput::IsDown('C') && true == UEngineInput::IsPress(VK_UP))
	{
		FSM.ChangeState(ECharacterState::WalkUpJump);
	}



	if (false == bIsJumpRight )
	{
		AddActorLocation(FVector(-PlayerSpeed * 0.85f * _DeltaTime, 0.0f, 0.0f));
	}

	else if (true == bIsJumpRight)
	{
		AddActorLocation(FVector(PlayerSpeed * 0.85f * _DeltaTime, 0.0f, 0.0f));
	}
	
	if (true == UEngineInput::IsPress(VK_LEFT) && true == bIsJumpRight)
	{
		SetActorRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
		AddActorLocation(FVector(-PlayerSpeed * 0.2f * _DeltaTime, 0.0f, 0.0f));
	}
	if (true == UEngineInput::IsPress(VK_RIGHT) && false == bIsJumpRight)
	{
		SetActorRelativeScale3D(FVector(-1.0f, 1.0f, 1.0f));
		AddActorLocation(FVector(PlayerSpeed * 0.2f * _DeltaTime, 0.0f, 0.0f));
	}
	if (true == UEngineInput::IsPress(VK_LEFT) )
	{
		SetActorRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
	}
	if (true == UEngineInput::IsPress(VK_RIGHT))
	{
		SetActorRelativeScale3D(FVector(-1.0f, 1.0f, 1.0f));
	}



	// 착지 시 Idle 상태로 전환
	if (true == UEngineInput::IsUp('C') && true == bIsGround)
	{
		bIsJumpMoveEnd = true;

	}
	if (true == UEngineInput::IsFree('C') && true == bIsGround)
	{
		bIsJumpMoveEnd = true;

	}

	if (true == bIsJumpMoveEnd && bIsGround == true)
	{
		bIsJumpMoveEnd = false;
		FSM.ChangeState(ECharacterState::Idle);
		return;
	}

}

void APlayer::UpJump(float _DeltaTime)
{
	Gravity(_DeltaTime);
	AirUseSkill(_DeltaTime);



	JumpVelocity = JumpPower;
	TargetJumpVelocity = FVector::ZERO;


	if (false == bIsGround)
	{
		TargetJumpVelocity = JumpPower;
	}

	JumpVelocity.Y = UEngineMath::Lerp(JumpVelocity.Y, TargetJumpVelocity.Y, _DeltaTime * 5.0f);

	AddActorLocation(JumpPower * 0.03f);

	if (true == bIsGround)
	{
		FSM.ChangeState(ECharacterState::Idle);
		return;
	}


}

void APlayer::WalkUpJump(float _DeltaTime)
{
	Gravity(_DeltaTime);
	AirUseSkill(_DeltaTime);



	JumpVelocity = JumpPower;
	TargetJumpVelocity = FVector::ZERO;


	if (false == bIsGround)
	{
		TargetJumpVelocity = JumpPower;
	}

	JumpVelocity.Y = UEngineMath::Lerp(JumpVelocity.Y, TargetJumpVelocity.Y, _DeltaTime * 5.0f);


	if (false == bIsJumpRight)
	{
		AddActorLocation(FVector(-PlayerSpeed * 0.85f * _DeltaTime, 500.0f * 0.03f, 0.0f));
	}

	else if (true == bIsJumpRight)
	{
		AddActorLocation(FVector(PlayerSpeed * 0.85f * _DeltaTime, 500.0f * 0.03f, 0.0f));
	}

	if (true == bIsGround)
	{
		FSM.ChangeState(ECharacterState::Idle);
		return;
	}


}


void APlayer::Air(float _DeltaTime)
{
	Gravity(_DeltaTime);
	AirUseSkill(_DeltaTime);

	if (true == bIsGround)
	{
		FSM.ChangeState(ECharacterState::Idle);
		return;
	}

	
}




void APlayer::IdleUseSkill(float _DeltaTime)
{
	// 레쓰 오브 엔릴
	if (UEngineInput::IsPress('A')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("Wrath"); }

	// 스트라이크 듀얼 샷
	if (UEngineInput::IsPress('S')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("StrikeDualShot"); }

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

	// 리프 토네이도 
	if (UEngineInput::IsPress('D')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("Tornado");
	bIsLeafUsing = true;
	}

	// 롤링 어썰트
	if (UEngineInput::IsPress('E')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("Rolling"); bIsZeroGravity = true; }

	// 하이킥 데몰리션
	{
		if (UEngineInput::IsPress('W')) { PlayerRenderer->ChangeAnimation("HighKick"); }
		if (UEngineInput::IsDown('W')) { AddActorLocation(FVector(0.0f, 200.0f)); }
	}
}
