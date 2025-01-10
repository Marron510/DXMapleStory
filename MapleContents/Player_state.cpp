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
	// ���ڸ����� �̵���ȯ
	PlayerGroundCheck(GravityForce * _DeltaTime);
	Gravity(_DeltaTime);


	if (UEngineInput::IsPress(VK_LEFT)){ FSM.ChangeState(ECharacterState::Walk);}
	if (UEngineInput::IsPress(VK_RIGHT)) { FSM.ChangeState(ECharacterState::Walk); }
	if (UEngineInput::IsPress(VK_DOWN)){ FSM.ChangeState(ECharacterState::Prone); }
	if (UEngineInput::IsPress(VK_UP))
	{
		FSM.ChangeState(ECharacterState::Walk);
	}


	// ���ڸ����� ���� ���

	if (UEngineInput::IsPress('C')) { FSM.ChangeState(ECharacterState::IdleJump);  }


	// ���ڸ� ��ų ���

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

	// ĳ���� �̵�
	if (UEngineInput::IsPress(VK_LEFT))
	{
		AddActorLocation(-CurrentVelocity * _DeltaTime);
	}
	if (UEngineInput::IsPress(VK_RIGHT))
	{
		AddActorLocation(CurrentVelocity * _DeltaTime);
	}
	
	
	
	// ����
		
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
		
	// �̵��� ���� �� Idle ���·� ��ȯ
	if (UEngineInput::IsUp(VK_LEFT) || UEngineInput::IsUp(VK_RIGHT))
	{
		FSM.ChangeState(ECharacterState::Idle);
	}

	// �̵� �� ��ų ���
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

	// ���� ����
	AddActorLocation(JumpVelocity * _DeltaTime);


	if (true == UEngineInput::IsPress(VK_LEFT))
	{
		SetActorRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
	}

	if (true == UEngineInput::IsPress(VK_RIGHT))
	{

		SetActorRelativeScale3D(FVector(-1.0f, 1.0f, 1.0f));

	}

	// ���� �� Idle ���·� ��ȯ
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

	// ���� ����
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

	// ���� �� Idle ���·� ��ȯ
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

	

	// ��ų �ִϸ��̼��� ������ Idle ��ȯ
	if (true == PlayerRenderer->IsCurAnimationEnd()) { FSM.ChangeState(ECharacterState::Idle); }

	// ���� ���� ����
	if (UEngineInput::IsPress('A')) { PlayerRenderer->ChangeAnimation("Wrath"); }

	// ��Ʈ����ũ ��� ��
	if (UEngineInput::IsPress('S')) { PlayerRenderer->ChangeAnimation("StrikeDualShot"); }
	
	// ����� �ٷ� ĳ���� Idle ��ȯ
	if (UEngineInput::IsUp('S')) { FSM.ChangeState(ECharacterState::Idle); }

	// ���� ����̵� 
	if (UEngineInput::IsPress('D')) { PlayerRenderer->ChangeAnimation("Tornado"); }

	// �Ѹ� ���Ʈ
	if (UEngineInput::IsPress('E')) { PlayerRenderer->ChangeAnimation("Rolling"); }

	// ���� ����̺�
	if (UEngineInput::IsPress('Q')) { PlayerRenderer->ChangeAnimation("Charge"); }
	
	// ����ű ��������
	{
		if (UEngineInput::IsPress('W')) { PlayerRenderer->ChangeAnimation("HighKick"); }
		if (UEngineInput::IsDown('W')) { AddActorLocation(FVector(0.0f, 200.0f)); }
	}
}
