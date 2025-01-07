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
	// 제자리에서 이동전환

	if (UEngineInput::IsPress(VK_LEFT)){ FSM.ChangeState(ECharacterState::Walk);}
	if (UEngineInput::IsPress(VK_RIGHT)) { FSM.ChangeState(ECharacterState::Walk); }

	/*if (UEngineInput::IsPress(VK_UP))
	{
		AddRelativeLocation(FVector{ 0.0f, 300.0f * _DeltaTime, 0.0f });
	}*/

	if (UEngineInput::IsPress(VK_DOWN)){ FSM.ChangeState(ECharacterState::Prone); }


	// 제자리에서 점프 사용

	if (UEngineInput::IsPress('C')) { FSM.ChangeState(ECharacterState::Jump); }


	// 제자리 스킬 사용
	
	if (UEngineInput::IsDown('Q'))
	{
		FSM.ChangeState(ECharacterState::UseSkill);

		TimeEventComponent->AddEndEvent(1.0f, [this]()
			{
				bIsCharge = true;
			}, false
		);

		TimeEventComponent->AddEndEvent(2.0f, [this]()
			{
				bIsCharge = false;
			}, false
		);
	}

	if (UEngineInput::IsDown('W'))
	{

		if (true == bIsCharge && true == bIsGround)
		{
			FSM.ChangeState(ECharacterState::UseSkill);
			PlayerRenderer->AddRelativeLocation(FVector{ 0.0f, 50.0f, 0.0f });
		}

	}


	if (UEngineInput::IsPress('R'))
	{
		//FSM.ChangeState(ECharacterState::UseSkill);
	}

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
		// FSM.ChangeState(ECharacterState::UseSkill);
	}

	if (UEngineInput::IsPress('G'))
	{
		FSM.ChangeState(ECharacterState::UseSkill);
	}

	if (UEngineInput::IsPress('H'))
	{
		//FSM.ChangeState(ECharacterState::UseSkill);
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

	// 이동
	// 
	// 왼쪽 이동
	{
		if (UEngineInput::IsPress(VK_LEFT))
		{
			AddRelativeLocation(FVector{ -300.0f * _DeltaTime, 0.0f, 0.0f });
			SetActorRelativeScale3D(FVector{ 1.0f, 1.0f, 1.0f });
		}

		// 왼쪽 이동 끝

		if (UEngineInput::IsUp(VK_LEFT))
		{
			FSM.ChangeState(ECharacterState::Idle);
			SetActorRelativeScale3D(FVector{ 1.0f, 1.0f, 1.0f });
		}

		// 오른쪽 이동

		if (UEngineInput::IsPress(VK_RIGHT))
		{
			AddRelativeLocation(FVector{ 300.0f * _DeltaTime, 0.0f, 0.0f });
			SetActorRelativeScale3D(FVector{ -1.0f, 1.0f, 1.0f });
		}

		// 오른쪽 이동 끝
		if (UEngineInput::IsUp(VK_RIGHT))
		{
			FSM.ChangeState(ECharacterState::Idle);
			SetActorRelativeScale3D(FVector{ -1.0f, 1.0f, 1.0f });
		}
	}


	/*if (UEngineInput::IsPress(VK_UP))
	{
		AddRelativeLocation(FVector{ 0.0f, 300.0f * _DeltaTime, 0.0f });
	}*/

	// 엎드리기

	if (UEngineInput::IsPress(VK_DOWN))
	{
		FSM.ChangeState(ECharacterState::Prone);
	}

	// 이동 중 스킬 사용
	{
		if (UEngineInput::IsDown('Q'))
		{
			FSM.ChangeState(ECharacterState::UseSkill);

			TimeEventComponent->AddEndEvent(1.0f, [this]()
				{
					bIsCharge = true;
				}, false
			);

			TimeEventComponent->AddEndEvent(2.0f, [this]()
				{
					bIsCharge = false;
				}, false
			);
		}

		if (UEngineInput::IsDown('W'))
		{

			if (true == bIsCharge && true == bIsGround)
			{
				FSM.ChangeState(ECharacterState::UseSkill);
				PlayerRenderer->AddRelativeLocation(FVector{ 0.0f, 50.0f, 0.0f });
			}

		}

		if (UEngineInput::IsPress('E'))
		{
			if (false == bIsGround)
			{
				FSM.ChangeState(ECharacterState::UseSkill);
			}
		}

		if (UEngineInput::IsPress('R'))
		{
			//FSM.ChangeState(ECharacterState::UseSkill);
		}

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

		if (UEngineInput::IsPress('F'))
		{
			if (false == bIsGround)
			{
				//FSM.ChangeState(ECharacterState::UseSkill);
			}
		}

		if (UEngineInput::IsPress('G'))
		{
			FSM.ChangeState(ECharacterState::UseSkill);
		}

		if (UEngineInput::IsPress('H'))
		{
			//FSM.ChangeState(ECharacterState::UseSkill);
		}
	}


}

void APlayer::Jump(float _DeltaTime)
{
	// 점프 로직

	// 제자리 점프
	if (UEngineInput::IsPress('C'))
	{
		//
	}

	// 점프 스킬 사용


}

void APlayer::UseSkill(float _DeltaTime)
{
	
	if (UEngineInput::IsDown('Q'))
	{
		PlayerRenderer->ChangeAnimation("Charge");

		TimeEventComponent->AddEndEvent(1.0f, [this]()
			{
				bIsCharge = true;
			}, false
		);

		TimeEventComponent->AddEndEvent(2.0f, [this]()
			{
				bIsCharge = false;
			}, false
		);
	}

	if (UEngineInput::IsDown('W'))
	{

		if (true == bIsCharge && true == bIsGround)
		{
			PlayerRenderer->AddRelativeLocation(FVector{ 0.0f, 50.0f, 0.0f });
		}

	}

	if (UEngineInput::IsPress('E'))
	{
		if (false == bIsGround)
		{
			SubSkillRenderer->ChangeAnimation("RollingMoonSult");
			PlayerRenderer->ChangeAnimation("Rolling");

			SubSkillRenderer->SetRelativeLocation(FVector{ 0.0f, -100.0f, -0.11f });
			PlayerRenderer->SetRelativeLocation(FVector{ 0.0f, 0.0f, -0.1f });
		}
	}

	if (UEngineInput::IsPress('R'))
	{
		PlayerRenderer->ChangeAnimation("Unicorn");
	}

	if (UEngineInput::IsPress('A'))
	{
		PlayerRenderer->ChangeAnimation("Wrath");
		PlayerRenderer->SetRelativeLocation(FVector{ 0.0f, 0.0f, -0.1f });

		TimeEventComponent->AddEndEvent(0.86f, [this]()
			{
				FSM.ChangeState(ECharacterState::Idle);
			}, false
		);
	}


	if (UEngineInput::IsDown('S'))
	{
		PlayerRenderer->ChangeAnimation("StrikeDualShot");
		SubSkillRenderer->ChangeAnimation("StrikeDualShot");
		SkillRenderer->ChangeAnimation("StrikeDualShot_Back");

		SkillRenderer->SetRelativeLocation(FVector{ 20.0f, -60.0f, -0.01f });
		SubSkillRenderer->SetRelativeLocation(FVector{ 40.0f, -80.0f, -0.11f });
		PlayerRenderer->SetRelativeLocation(FVector{ 0.0f, 0.0f, -0.1f });
	}

	if (UEngineInput::IsDown('D'))
	{
		SkillRenderer->ChangeAnimation("LeafTornadoUp");
		SubSkillRenderer->ChangeAnimation("LeafTornadoDown");
		PlayerRenderer->ChangeAnimation("Tornado");

		SkillRenderer->SetRelativeLocation(FVector{ 0.0f, -390.0f, -0.01f });
		SubSkillRenderer->SetRelativeLocation(FVector{ 25.0f, -390.0f, -0.11f });
		PlayerRenderer->SetRelativeLocation(FVector{ 0.0f, 0.0f, -0.1f });
	}

	if (UEngineInput::IsPress('F'))
	{
		if (false == bIsGround)
		{

		}
	}

	if (UEngineInput::IsPress('G'))
	{
		PlayerRenderer->ChangeAnimation("LegendarySpear");
	}

	if (UEngineInput::IsPress('H'))
	{
		PlayerRenderer->ChangeAnimation("Jump");
	}
}