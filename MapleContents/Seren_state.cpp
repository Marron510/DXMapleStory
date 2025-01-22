#include "PreCompile.h"
#include "Seren.h"


#include <EngineBase/FSMStateManager.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/TimeEventComponent.h>
#include <EngineCore/Collision.h>

#include "MapleInstance.h"
#include "SerenCollision.h"
#include "CerniumPlazaMode.h"
#include "EventCharacter.h"
#include "MapleEnum.h"
#include "Player.h"

void ASeren::StateInit()
{

	//4���� ���� ��� �Ȱ��� �ൿ�ϴ� �� ( Idle, Walk, Rush, Die, Hit)
	SerenFSM.CreateState(ESerenState::Idle, std::bind(&ASeren::Idle, this, std::placeholders::_1),
		[this]()
		{
			SerenRender->ChangeAnimation("Phase1_Stand");
		}
	);

	SerenFSM.CreateState(ESerenState::Walk, std::bind(&ASeren::Walk, this, std::placeholders::_1),
		[this]()
		{
			SerenRender->ChangeAnimation("Phase1_Stand");
		}
	);

	SerenFSM.CreateState(ESerenState::Rush, std::bind(&ASeren::Rush, this, std::placeholders::_1),
		[this]()
		{
			SerenRender->ChangeAnimation("Phase1_Rush");
		}
	);
	SerenFSM.CreateState(ESerenState::Sting, std::bind(&ASeren::ASting, this, std::placeholders::_1),
		[this]()
		{
			SerenRender->ChangeAnimation("Phase1_Sting");
		}
	);

	SerenFSM.CreateState(ESerenState::Die, std::bind(&ASeren::Die, this, std::placeholders::_1),
		[this]()
		{
			SerenRender->ChangeAnimation("NoonSerenDie");
		}
	);
	
}


void ASeren::Idle(float _DeltaTime)
{
	// 0. ���� �÷��̾� ���ؼ� �̵�

	OutRangeCollision->SetCollisionStay([this](UCollision* _This, UCollision* _Other)
		{
			if (true == bIsIdle)
			{
			SerenFSM.ChangeState(ESerenState::Walk);
			bIsIdle = false;
			return;
			}
		});

	// 1. ���� �ݸ��� �浹 �� 

	

	// ���������� ü����

	// 2. ���� �ݸ������� ��� ��



	// 99. ���� üũ
}

void ASeren::Walk(float _DeltaTime)
{
	SkillCoolTime -= _DeltaTime;

	// ��ų ��� ���� ���� Ȯ��(�ٰŸ�, ���Ÿ�)

	CheckCollision->SetCollisionStay([this, _DeltaTime](UCollision* _This, UCollision* _Other)
		{

			

			bIsInRange = true;

			if( 0 >= SkillCoolTime)
			{
				this->StingCollision->SetActive(true);
				SerenFSM.ChangeState(ESerenState::Sting);
				return;
			}

		});

	// �ٰŸ� -> ���Ÿ�
	CheckCollision->SetCollisionEnd([this, _DeltaTime](UCollision* _This, UCollision* _Other)
		{
			bIsInRange = false;
		});


	// ���� ��ų
	OutRangeCollision->SetCollisionStay([this, _DeltaTime](UCollision* _This, UCollision* _Other)
		{
				// ���Ÿ� �� ���� ��� ����
				if (0 >= SkillCoolTime && false == bIsInRange)
				{
					this->RushCollision->SetActive(true);
					SerenFSM.ChangeState(ESerenState::Rush);
					return;
				}
		});


	CurPlayerLocation = Player->GetActorLocation();
	// �̵� ����
	FVector SerenLocation = GetActorLocation();
	DifferentLocation = CurPlayerLocation - SerenLocation;
	DifferentLocation.Normalize();

	if (0 < DifferentLocation.X)
	{
		SetActorRelativeScale3D(FVector{ -1.0f, 1.0f, 1.0f });
	}
	else if (0 >= DifferentLocation.X)
	{
		SetActorRelativeScale3D(FVector{ 1.0f, 1.0f, 1.0f });
	}

	AddActorLocation(FVector(DifferentLocation.X * _DeltaTime * 50.0f, 0.0f, 0.0f));




}

void ASeren::Rush(float _DeltaTime)
{
	if (true == SerenRender->IsCurAnimationEnd() && true == bIsRush)
	{
		SkillCoolTime = StimgCoolTime;
		RushCollision->SetActive(false);
		bIsRush = false;
		bIsIdle = true;
		if (0.0f > DifferentLocation.X)
		{
			AddActorLocation(FVector{ -690.0f, 0.0f });
			SerenFSM.ChangeState(ESerenState::Idle);
			return;
		}
		if (0.0f < DifferentLocation.X)
		{
			AddActorLocation(FVector{ 690.0f, 0.0f });
			SerenFSM.ChangeState(ESerenState::Idle);
			return;
		}
	}

	RushCollision->SetCollisionStay([this, _DeltaTime](UCollision* _This, UCollision* _Other)
		{
			if (true == _Other->IsColliding() && true == SerenRender->IsCurAnimationEnd())
			{
				GetGameInstance<MapleInstance>()->Status.Hp -= 5.0f;
				float Curhp = GetGameInstance<MapleInstance>()->Status.Hp;
				bIsRush = true;
			}
		});

	if (true == SerenRender->IsCurAnimationEnd())
	{
		bIsRush = true;
	}
}


void ASeren::ASting(float _DeltaTime)
{
	


	if (true == SerenRender->IsCurAnimationEnd() && true == bIsSting)
	{
		SkillCoolTime = StimgCoolTime;
		StingCollision->SetActive(false);
		bIsSting = false;
		bIsIdle = true;
		SerenFSM.ChangeState(ESerenState::Idle);
		return;
	}
	
	
	
	StingCollision->SetCollisionStay([this, _DeltaTime](UCollision* _This, UCollision* _Other)
		{
			if (true == _Other->IsColliding() && true == SerenRender->IsCurAnimationEnd())
			{
				GetGameInstance<MapleInstance>()->Status.Hp -= 5.0f;
				float Curhp = GetGameInstance<MapleInstance>()->Status.Hp;
				bIsSting = true;
			}
		});

	if (true == SerenRender->IsCurAnimationEnd())
	{
		bIsSting = true;
	}

}

void ASeren::Die(float _DeltaTime)
{
	Collision->SetActive(false);
	CheckCollision->SetActive(false);
	OutRangeCollision->SetActive(false);
}