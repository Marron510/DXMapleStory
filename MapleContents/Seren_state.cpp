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
#include "Aura.h"
#include "Small8Laser.h"


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
	SerenFSM.CreateState(ESerenState::Sting, std::bind(&ASeren::Sting, this, std::placeholders::_1),
		[this]()
		{
			SerenRender->ChangeAnimation("Phase1_Sting");
		}
	);

	SerenFSM.CreateState(ESerenState::SwordAura, std::bind(&ASeren::SwordAura, this, std::placeholders::_1),
		[this]()
		{
			SerenRender->ChangeAnimation("Phase1_SwordAura");
		}
	);

	SerenFSM.CreateState(ESerenState::SmallLaser, std::bind(&ASeren::SmallLaser, this, std::placeholders::_1),
		[this]()
		{
			SerenRender->ChangeAnimation("Phase1_Laser");
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
			if (true == SerenRender->IsCurAnimationEnd())
			{
				if (0 >= SkillCoolTime && 3 > StingCount)
				{
					this->StingCollision->SetActive(true);

					SerenFSM.ChangeState(ESerenState::Sting);
					return;
				}

				if (0 >= SkillCoolTime && 3 >= StingCount && true == bIsSwordAura)
				{
					SerenFSM.ChangeState(ESerenState::SmallLaser);
					return;
				}

				if (0 >= SkillCoolTime && 3 >= StingCount)
				{
					SerenFSM.ChangeState(ESerenState::SwordAura);
					return;
				}
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
				if (0 >= SkillCoolTime && false == bIsInRange && true == SerenRender->IsCurAnimationEnd())
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
			AddActorLocation(FVector{ -RushDistance, 0.0f });
			SerenFSM.ChangeState(ESerenState::Idle);
			return;
		}
		if (0.0f < DifferentLocation.X)
		{
			AddActorLocation(FVector{ RushDistance, 0.0f });
			SerenFSM.ChangeState(ESerenState::Idle);
			return;
		}
	}

	RushCollision->SetCollisionStay([this, _DeltaTime](UCollision* _This, UCollision* _Other)
		{
			if (true == _Other->IsColliding() && true == SerenRender->IsCurAnimationEnd())
			{
				// ���� ������
				GetGameInstance<MapleInstance>()->Status.Hp -= RushDamage;
				float Curhp = GetGameInstance<MapleInstance>()->Status.Hp;
				Player->bIsdamageOn();
				bIsRush = true;
			}
		});

	if (true == SerenRender->IsCurAnimationEnd())
	{
		bIsRush = true;
	}
}


void ASeren::Sting(float _DeltaTime)
{

	if (true == SerenRender->IsCurAnimationEnd() && true == bIsSting)
	{
		SkillCoolTime = StimgCoolTime;
		StingCollision->SetActive(false);
		bIsSting = false;
		bIsIdle = true;
		StingCount += 1;
		SerenFSM.ChangeState(ESerenState::Idle);
		return;
	}
	
	
	
	StingCollision->SetCollisionStay([this, _DeltaTime](UCollision* _This, UCollision* _Other)
		{
			if (true == _Other->IsColliding() && true == SerenRender->IsCurAnimationEnd())
			{
				// ��� ������
				GetGameInstance<MapleInstance>()->Status.Hp -= StingDamage;
				float Curhp = GetGameInstance<MapleInstance>()->Status.Hp;
				Player->bIsdamageOn();
				bIsSting = true;
			}
		});

	if (true == SerenRender->IsCurAnimationEnd())
	{
		bIsSting = true;
	}

}


void ASeren::SwordAura(float _DeltaTime)
{
	AuraCoolTime -= _DeltaTime;

	FVector SerenLocation = GetActorLocation();
	DifferentLocation = CurPlayerLocation - SerenLocation;
	DifferentLocation.Normalize();

	if (0 < DifferentLocation.X)
	{
		SetActorRelativeScale3D(FVector{ -1.0f, 1.0f, 1.0f });
		bIsAuraLeft = true;
	}
	else if (0 >= DifferentLocation.X)
	{
		SetActorRelativeScale3D(FVector{ 1.0f, 1.0f, 1.0f });
		bIsAuraLeft = false;
	}

	if (0.0f >= AuraCoolTime && false == bIsAuraDir)
	{
		std::shared_ptr<class AAura> Aura = GetWorld()->SpawnActor<AAura>();
		FVector AuraLocation = GetActorLocation() + FVector(120.0f, -170.0f);
		Aura->SetActorLocation(AuraLocation);


		bIsAuraDir = true;
	}

	if (true == SerenRender->IsCurAnimationEnd())
	{
		SkillCoolTime = StimgCoolTime;
		AuraCoolTime = 1.0f;
		bIsSwordAura = true;
		bIsIdle = true;
		bIsAuraDir = false;
		SerenFSM.ChangeState(ESerenState::Idle);
	}


	//if (true == SerenRender->IsCurAnimationEnd())
	//{
	//	std::shared_ptr<class AAura> Aura = GetWorld()->SpawnActor<AAura>();
	//	FVector AuraLocation = GetActorLocation() + FVector(0.0f, -170.0f);
	//	Aura->SetActorLocation(AuraLocation);
	//	SkillCoolTime = StimgCoolTime;
	//	bIsSwordAura = true;
	//	bIsIdle = true;
	//	SerenFSM.ChangeState(ESerenState::Idle);
	//}
}


void ASeren::SmallLaser(float _DeltaTime)
{
	if (true == SerenRender->IsCurAnimationEnd())
	{
		SkillCoolTime = StimgCoolTime;
		StingCount = 0;
		bIsIdle = true;
		bIsSwordAura = false;
		bIsSmalllaser = false;
		SerenFSM.ChangeState(ESerenState::Idle);
		return;
	}

	if (false == bIsSmalllaser)
	{
		Small8Laser = GetWorld()->SpawnActor<ASmall8Laser>();
		Small8Laser->AttachToActor(this);
		Small8Laser->SetActive(true);
		bIsSmalllaser = true;
	}

	if (true == Small8Laser->GetLaser1()->IsCurAnimationEnd())
	{
		Small8Laser->SetActive(false);
	}

}



void ASeren::Die(float _DeltaTime)
{
	Collision->SetActive(false);
	CheckCollision->SetActive(false);
	OutRangeCollision->SetActive(false);
}