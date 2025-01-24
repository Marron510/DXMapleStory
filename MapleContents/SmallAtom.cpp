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

	SmallAtom->CreateAnimation("Phase1_SwordAura_Ball", "Phase1_SwordAura_Ball", 0, 5, 0.07f);
	SmallAtom->ChangeAnimation("Phase1_SwordAura_Ball");

	SmallAtom->SetRelativeLocation(FVector{ 0.0f, -100.0f, static_cast<float>(EMapleZEnum::Monster_Skill) });


	Collision = CreateDefaultSubObject<UCollision>();
	Collision->SetupAttachment(RootComponent);
	Collision->SetCollisionProfileName("MonsterSKill");

	Collision->SetScale3D({ 400.0f, 120.0f });
	Collision->SetRelativeLocation(FVector{ -56.0f, 260.0f , static_cast<float>(EMapleZEnum::Monster_Skill) });
}

ASmallAtom::~ASmallAtom()
{

}

void ASmallAtom::BeginPlay()
{
}

void ASmallAtom::Tick(float _DeltaTime)
{
}

void ASmallAtom::Move(float _DeltaTime)
{
}
