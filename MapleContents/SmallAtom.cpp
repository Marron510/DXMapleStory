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
			GetGameInstance<MapleInstance>()->Status.Hp -= AtomDamage;
			float Curhp = GetGameInstance<MapleInstance>()->Status.Hp;
			Player->bIsdamageOn();
			Collision->SetActive(false);
		});

	Create();
}

void ASmallAtom::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	

	Move(_DeltaTime);
}


void ASmallAtom::Create()
{
	if (true == bIsStart)
	{
		return;
	}

	if (true == SmallAtom->IsCurAnimationEnd())
	{
		SmallAtom->ChangeAnimation("Small_Atom_Ing");
		bIsStart = true;
	}
}

void ASmallAtom::Move(float _DeltaTime)
{
	if (true == Collision->IsColliding())
	{
		SmallAtom->ChangeAnimation("Small_Atom_End");

		if (true == SmallAtom->IsCurAnimationEnd())
		{
			SmallAtom->SetActive(false);
		}
		return;
	}
	
	
	if (-1240.0f < this->GetActorLocation().Y || true == bIsStart)
	{
		this->AddActorLocation(FVector::DOWN * AtomSpeed * _DeltaTime);
	}
	

	else if (-1240.0f >= this->GetActorLocation().Y)
	{
		SmallAtom->ChangeAnimation("Small_Atom_End");
		
		if (true == SmallAtom->IsCurAnimationEnd())
		{
			SmallAtom->SetActive(false);
			Collision->SetActive(false);
		}
	}

}
