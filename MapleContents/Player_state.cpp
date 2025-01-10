#include "PreCompile.h"


#include <EngineBase/FSMStateManager.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/TimeEventComponent.h>

#include "Player.h"
#include "EventCharacter.h"


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

	FSM.CreateState(ECharacterState::UseSkill, std::bind(&APlayer::UseSkill, this, std::placeholders::_1),
		[this]()
		{
		
		}
	);
}




void APlayer::Idle(float _DeltaTime)
{
	// 제자리에서 이동전환
	PlayerGroundCheck(GravityForce * _DeltaTime);
	Gravity(_DeltaTime);


	if (UEngineInput::IsPress(VK_LEFT)){ FSM.ChangeState(ECharacterState::Walk);}
	if (UEngineInput::IsPress(VK_RIGHT)) { FSM.ChangeState(ECharacterState::Walk); }
	if (UEngineInput::IsPress(VK_DOWN)){ FSM.ChangeState(ECharacterState::Prone); }
	if (UEngineInput::IsPress(VK_UP))
	{
		FSM.ChangeState(ECharacterState::Walk);
	}


	// 제자리에서 점프 사용

	if (UEngineInput::IsPress('C')) { FSM.ChangeState(ECharacterState::IdleJump);  }


	// 제자리 스킬 사용

	if (UEngineInput::IsPress('A')) { FSM.ChangeState(ECharacterState::UseSkill); }

	if (UEngineInput::IsPress('S')) { FSM.ChangeState(ECharacterState::UseSkill); }

	if (UEngineInput::IsPress('D')) { FSM.ChangeState(ECharacterState::UseSkill); }

	if (UEngineInput::IsPress('E')) { FSM.ChangeState(ECharacterState::UseSkill); }

	if (UEngineInput::IsPress('Q')) { FSM.ChangeState(ECharacterState::UseSkill); }
}


void APlayer::Prone(float _DeltaTime)
{
	PlayerGroundCheck(GravityForce * _DeltaTime);
	Gravity(_DeltaTime);

	if (UEngineInput::IsUp(VK_DOWN))
	{
		FSM.ChangeState(ECharacterState::Idle);
	}

	if (UEngineInput::IsPress('Q')) { FSM.ChangeState(ECharacterState::UseSkill); }
}




void APlayer::Walk(float _DeltaTime)
{
	PlayerGroundCheck(GravityForce * _DeltaTime);
	Gravity(_DeltaTime);

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

	// 캐릭터 이동
	if (UEngineInput::IsPress(VK_LEFT))
	{
		AddActorLocation(-CurrentVelocity * _DeltaTime);
	}
	if (UEngineInput::IsPress(VK_RIGHT))
	{
		AddActorLocation(CurrentVelocity * _DeltaTime);
	}
	
	
	
	// 점프
		
	if (UEngineInput::IsDown('C') && UEngineInput::IsPress(VK_LEFT))
	{ 
		bIsJumpRight = false; 
		FSM.ChangeState(ECharacterState::WalkJump); 
	}

	if (UEngineInput::IsDown('C') && UEngineInput::IsPress(VK_RIGHT)) 
	{
		bIsJumpRight = true; 
		FSM.ChangeState(ECharacterState::WalkJump);
	}
		
	// 이동이 멈출 때 Idle 상태로 전환
	if (UEngineInput::IsUp(VK_LEFT) || UEngineInput::IsUp(VK_RIGHT))
	{
		FSM.ChangeState(ECharacterState::Idle);
	}

	// 이동 중 스킬 사용
	{
		if (UEngineInput::IsPress('A')) { FSM.ChangeState(ECharacterState::UseSkill); }

		if (UEngineInput::IsPress('S')) { FSM.ChangeState(ECharacterState::UseSkill); }

		if (UEngineInput::IsPress('D')) { FSM.ChangeState(ECharacterState::UseSkill); }

		if (UEngineInput::IsPress('E')) { FSM.ChangeState(ECharacterState::UseSkill); }

		if (UEngineInput::IsPress('Q')) { FSM.ChangeState(ECharacterState::UseSkill); }
	}


}

void APlayer::IdleJump(float _DeltaTime)
{
	bIsGround = false;
	PlayerGroundCheck(GravityForce * _DeltaTime);
	Gravity(_DeltaTime);

	static FVector JumpVelocity = JumpPower;
	FVector TargetJumpVelocity = FVector::ZERO;

	if (false == bIsGround)
	{
		TargetJumpVelocity = JumpPower;
	}

	JumpVelocity.Y = UEngineMath::Lerp(JumpVelocity.Y, TargetJumpVelocity.Y, _DeltaTime * 5.0f);

	// 점프 실행
	AddActorLocation(JumpVelocity * _DeltaTime);


	if (true == UEngineInput::IsPress(VK_LEFT))
	{
		SetActorRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
	}

	if (true == UEngineInput::IsPress(VK_RIGHT))
	{

		SetActorRelativeScale3D(FVector(-1.0f, 1.0f, 1.0f));

	}

	// 착지 시 Idle 상태로 전환
	if (0.00001f > TargetJumpVelocity.Y)
	{
		FSM.ChangeState(ECharacterState::Idle);
	}

}

void APlayer::WalkJump(float _DeltaTime)
{
	bIsGround = false;
	//bIsJumpMoveEnd = false;
	PlayerGroundCheck(GravityForce * _DeltaTime);
	Gravity(_DeltaTime);

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
		SetActorRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
	}

	else if (true == bIsJumpRight)
	{

		AddActorLocation(FVector(PlayerSpeed * _DeltaTime, 0.0f, 0.0f));
		SetActorRelativeScale3D(FVector(-1.0f, 1.0f, 1.0f));

	}

	// 착지 시 Idle 상태로 전환
	if (true == UEngineInput::IsUp(VK_RIGHT) || true == UEngineInput::IsUp(VK_LEFT))
	{
		bIsJumpMoveEnd = true;
	}
	if (true == bIsJumpMoveEnd && 0.00001f > TargetJumpVelocity.Y)
	{
		bIsJumpMoveEnd = false;
		FSM.ChangeState(ECharacterState::Idle);
	}

}

void APlayer::UseSkill(float _DeltaTime)
{
	PlayerGroundCheck(GravityForce * _DeltaTime);
	Gravity(_DeltaTime);

	

	// 스킬 애니메이션이 끝나면 Idle 전환
	if (true == PlayerRenderer->IsCurAnimationEnd()) { FSM.ChangeState(ECharacterState::Idle); }

	// 레쓰 오브 엔릴
	if (UEngineInput::IsPress('A')) { PlayerRenderer->ChangeAnimation("Wrath"); }

	// 스트라이크 듀얼 샷
	if (UEngineInput::IsPress('S')) { PlayerRenderer->ChangeAnimation("StrikeDualShot"); }
	
	// 스듀는 바로 캐릭터 Idle 전환
	if (UEngineInput::IsUp('S')) { FSM.ChangeState(ECharacterState::Idle); }

	// 리프 토네이도 
	if (UEngineInput::IsPress('D')) { PlayerRenderer->ChangeAnimation("Tornado"); }

	// 롤링 어썰트
	if (UEngineInput::IsPress('E')) { PlayerRenderer->ChangeAnimation("Rolling"); }

	// 차지 드라이브
	if (UEngineInput::IsPress('Q')) { PlayerRenderer->ChangeAnimation("Charge"); }
	
	// 하이킥 데몰리션
	{
		if (UEngineInput::IsPress('W')) { PlayerRenderer->ChangeAnimation("HighKick"); }
		if (UEngineInput::IsDown('W')) { AddActorLocation(FVector(0.0f, 200.0f)); }
	}
}
