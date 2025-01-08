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

	if (UEngineInput::IsPress(VK_LEFT)){ FSM.ChangeState(ECharacterState::Walk);}
	if (UEngineInput::IsPress(VK_RIGHT)) { FSM.ChangeState(ECharacterState::Walk); }

	/*if (UEngineInput::IsPress(VK_UP))
	{
		AddRelativeLocation(FVector{ 0.0f, 300.0f * _DeltaTime, 0.0f });
	}*/

	if (UEngineInput::IsPress(VK_DOWN)){ FSM.ChangeState(ECharacterState::Prone); }


	// ���ڸ����� ���� ���

	if (UEngineInput::IsPress('C')) { FSM.ChangeState(ECharacterState::Jump); }


	// ���ڸ� ��ų ���
	

	if (UEngineInput::IsDown('A'))
	{
		FSM.ChangeState(ECharacterState::UseSkill);
	}


	if (UEngineInput::IsDown('S'))
	{
		FSM.ChangeState(ECharacterState::UseSkill);
	}

	if (UEngineInput::IsDown('D'))
	{
		FSM.ChangeState(ECharacterState::UseSkill);
	}
}


void APlayer::Prone(float _DeltaTime)
{
	if (UEngineInput::IsUp(VK_DOWN))
	{
		FSM.ChangeState(ECharacterState::Idle);
	}
}


void APlayer::Walk(float _DeltaTime)
{

	// �̵�
	// 
	// ���� �̵�
	{
		if (UEngineInput::IsPress(VK_LEFT))
		{
			AddRelativeLocation(FVector{ -300.0f * _DeltaTime, 0.0f, 0.0f });
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
			AddRelativeLocation(FVector{ 300.0f * _DeltaTime, 0.0f, 0.0f });
			SetActorRelativeScale3D(FVector{ -1.0f, 1.0f, 1.0f });
		}

		// ������ �̵� ��
		if (UEngineInput::IsUp(VK_RIGHT))
		{
			FSM.ChangeState(ECharacterState::Idle);
			SetActorRelativeScale3D(FVector{ -1.0f, 1.0f, 1.0f });
		}
	}


	// �̵� �� ��ų ���
	{
		if (UEngineInput::IsDown('A'))
		{
			FSM.ChangeState(ECharacterState::UseSkill);
		}


		if (UEngineInput::IsDown('S'))
		{
			FSM.ChangeState(ECharacterState::UseSkill);
		}

		if (UEngineInput::IsDown('D'))
		{
			FSM.ChangeState(ECharacterState::UseSkill);
		}

	}


}

void APlayer::Jump(float _DeltaTime)
{
	// ���� ����

	// ���ڸ� ����
	if (UEngineInput::IsPress('C'))
	{
		//
	}

	// ���� ��ų ���


}

void APlayer::UseSkill(float _DeltaTime)
{
	// ��ų �ִϸ��̼��� ������ Idle ��ȯ
	if (true == PlayerRenderer->IsCurAnimationEnd())
	{
		PlayerRenderer->ChangeAnimation("Idle");
	}



	// ���� ���� ����
	if (UEngineInput::IsPress('A'))
	{
		PlayerRenderer->ChangeAnimation("Wrath");
	}

	// ��Ʈ����ũ ��� ��
	if (UEngineInput::IsPress('S'))
	{
		PlayerRenderer->ChangeAnimation("StrikeDualShot");
	}
	// ����� �ٷ� ĳ���� Idle ��ȯ
	if (UEngineInput::IsUp('S'))
	{
		FSM.ChangeState(ECharacterState::Idle);
	}

	// ���� ����̵� 
	if (UEngineInput::IsPress('D'))
	{
		PlayerRenderer->ChangeAnimation("Tornado");
	}

}