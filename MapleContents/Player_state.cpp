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

	FSM.CreateState(ECharacterState::Jump, std::bind(&APlayer::Jump, this, std::placeholders::_1),
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

	if (UEngineInput::IsPress('C')) { FSM.ChangeState(ECharacterState::Jump);  }


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

	// �̵�
	
	
	{
		// ���� �̵�

		if (UEngineInput::IsPress(VK_LEFT))
		{
			
			AddActorLocation(FVector{ -PlayerSpeed * _DeltaTime, 0.0f, 0.0f });
			SetActorRelativeScale3D(FVector{ 1.0f, 1.0f, 1.0f });
		}

		// ���� �̵� ��

		if (UEngineInput::IsUp(VK_LEFT))
		{
			FSM.ChangeState(ECharacterState::Idle);
			SetActorRelativeScale3D(FVector{ 1.0f, 1.0f, 1.0f });
		}

		// ������ �̵�

		if (UEngineInput::IsPress(VK_RIGHT))
		{
			AddActorLocation(FVector{ PlayerSpeed * _DeltaTime, 0.0f, 0.0f });
			SetActorRelativeScale3D(FVector{ -1.0f, 1.0f, 1.0f });
		}

		// ������ �̵� ��
		if (UEngineInput::IsUp(VK_RIGHT))
		{
			FSM.ChangeState(ECharacterState::Idle);
			SetActorRelativeScale3D(FVector{ -1.0f, 1.0f, 1.0f });
		}

		if (UEngineInput::IsPress(VK_UP))
		{
			AddActorLocation(FVector{ 0.0f, PlayerSpeed *2* _DeltaTime, 0.0f });
		}
	}

	// ����
		
		if (UEngineInput::IsDown('C')) { FSM.ChangeState(ECharacterState::Jump); }
		

	// �̵� �� ��ų ���
	{
		if (UEngineInput::IsPress('A')) { FSM.ChangeState(ECharacterState::UseSkill); }

		if (UEngineInput::IsPress('S')) { FSM.ChangeState(ECharacterState::UseSkill); }

		if (UEngineInput::IsPress('D')) { FSM.ChangeState(ECharacterState::UseSkill); }

		if (UEngineInput::IsPress('E')) { FSM.ChangeState(ECharacterState::UseSkill); }

		if (UEngineInput::IsPress('Q')) { FSM.ChangeState(ECharacterState::UseSkill); }
	}


}

void APlayer::Jump(float _DeltaTime)
{
	
	bIsGround = false;
	PlayerGroundCheck(GravityForce * _DeltaTime);
	Gravity(_DeltaTime);

	// 1. Idle���� ���� ����

	if (true == UEngineInput::IsDown('C'))
	{

	}

	AddActorLocation(JumpPower * _DeltaTime);

	//// 2. ���������� �����̸鼭 Idle���� ���� ����
	//if (true == UEngineInput::IsPress(VK_RIGHT) && true == UEngineInput::IsDown('C'))
	//{
	//	AddActorLocation(FVector(PlayerSpeed * _DeltaTime, JumpPower.Y * _DeltaTime));
	//}
	//// 2. �������� �����̸鼭 Idle���� ���� ����
	//if (true == UEngineInput::IsPress(VK_LEFT) && true == UEngineInput::IsDown('C'))
	//{
	//	AddActorLocation(FVector(-PlayerSpeed * _DeltaTime, JumpPower.Y * _DeltaTime));
	//}
	// ���ڸ� ����
	if (true == bIsGround)
	{
		FSM.ChangeState(ECharacterState::Idle);
	}

	// ���� ��ų ���


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
