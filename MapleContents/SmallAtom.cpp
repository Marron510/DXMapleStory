#include "PreCompile.h"
#include "SmallAtom.h"


#include <EnginePlatform/EngineInput.h>

#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>
#include <EngineCore/TimeEventComponent.h>

#include "MapleInstance.h"
#include "MapleEnum.h"
#include "Player.h"


ASmallAtom::ASmallAtom()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	SmallAtom = CreateDefaultSubObject<USpriteRenderer>();
	SmallAtom->SetupAttachment(RootComponent);

	SmallAtom->CreateAnimation("Small_Atom_Start", "Small_Atom_Start", 0, 8, 0.1f);
	SmallAtom->CreateAnimation("Small_Atom_Ing", "Small_Atom_Ing", 0, 15, 0.08f);
	SmallAtom->CreateAnimation("Small_Atom_End", "Small_Atom_End", 0, 6, 0.1f);
	SmallAtom->ChangeAnimation("Small_Atom_Start");

	SmallAtom->SetRelativeLocation(FVector{ 0.0f, 0.0f, static_cast<float>(EMapleZEnum::Monster_Skill) + 70.0f });


	Collision = CreateDefaultSubObject<UCollision>();
	Collision->SetupAttachment(RootComponent);
	Collision->SetCollisionProfileName("MonsterSKill");

	Collision->SetScale3D({ 50.0f, 50.0f });
	Collision->SetRelativeLocation(FVector{ 0.0f, 120.0f, static_cast<float>(EMapleZEnum::Monster_Skill) + 70.0f });
}

ASmallAtom::~ASmallAtom()
{

}

void ASmallAtom::BeginPlay()
{
	AActor::BeginPlay();
	
	Player = dynamic_cast<APlayer*>(GetWorld()->GetMainPawn());

	Collision->SetCollisionStay([this](UCollision* _This, UCollision* _Other)
		{
			GetGameInstance<MapleInstance>()->Status.TakeDamage(AtomDamage);
			//float Curhp = GetGameInstance<MapleInstance>()->Status.CurHp;
			Player->bIsdamageOn();
			SmallAtom->ChangeAnimation("Small_Atom_End");
			Collision->SetActive(false);
		});

	Create();
}

void ASmallAtom::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	

	Move(_DeltaTime);
}


void ASmallAtom::Restart()
{
	bIsStart = false;
	bIsEnd = false;
	this->SetActive(true);
	Collision->SetActive(true);
	SmallAtom->SetActive(true);
	SmallAtom->ChangeAnimation("Small_Atom_Ing");
}

void ASmallAtom::Create()
{

	if (true == bIsStart)
	{
		return;
	}

	if (true == SmallAtom->IsCurAnimationEnd() && false == bIsEnd)
	{
		SmallAtom->ChangeAnimation("Small_Atom_Ing");
		bIsStart = true;
	}
}

void ASmallAtom::Move(float _DeltaTime)
{
	// �÷��̾�� �ε����� ��
	if (true == Collision->IsColliding() && false== bIsEnd)
	{
		if (true == SmallAtom->IsCurAnimationEnd())
		{
			this->SetActive(false);
			SmallAtom->ChangeAnimation("Small_Atom_Ing");
			
			bIsEnd = true;
		}
		return;
	}
	
	
	if (-1240.0f < this->GetActorLocation().Y || true == bIsStart)
	{
		this->AddActorLocation(FVector::DOWN * AtomSpeed * _DeltaTime);
	}
	
	// �ٴڿ� ����� ��
	else if (-1240.0f >= this->GetActorLocation().Y)
	{
		SmallAtom->ChangeAnimation("Small_Atom_End");
		Collision->SetActive(false);

		if (true == SmallAtom->IsCurAnimationEnd())
		{
			this->SetActive(false);
			bIsEnd = true;
		}
	}

}
