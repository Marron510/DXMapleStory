#include "PreCompile.h"
#include "UnicornSpike.h"
#include <EnginePlatform/EngineInput.h>

#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>

#include "MapleEnum.h"

AUnicornSpike::AUnicornSpike()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	UnicornSpike = CreateDefaultSubObject<USpriteRenderer>();
	UnicornSpike->SetupAttachment(RootComponent);

	UnicornSpike->CreateAnimation("UnicornSpike", "UnicornSpike", 0, 15, 0.08f, false);
	UnicornSpike->CreateAnimation("None", "WrathOfEnril", 14, 14, 0.01f, false);
	UnicornSpike->ChangeAnimation("None");

	UnicornSpike->SetRelativeLocation(FVector{ -200.0f, -136.0f, static_cast<float>(EMapleZEnum::Player_Skill_Front) });

	Collision = CreateDefaultSubObject<UCollision>();
	Collision->SetupAttachment(RootComponent);
	Collision->SetCollisionProfileName("PlayerSKill");

	Collision->SetScale3D({ 700.0f, 220.0f });
	Collision->SetRelativeLocation(FVector{ -280.0f, 80.0f , static_cast<float>(EMapleZEnum::Player) });
	Collision->SetCollisionEnter([](UCollision* _This, UCollision* _Other)
		{
		});

}

AUnicornSpike::~AUnicornSpike()
{

}


void AUnicornSpike::BeginPlay()
{
	ASkillManager::BeginPlay();
}

void AUnicornSpike::Tick(float _DeltaTime)
{
	ASkillManager::Tick(_DeltaTime);

	if (true == UnicornSpike->IsCurAnimationEnd())
	{
		UnicornSpike->ChangeAnimation("None");
		Collision->SetActive(false);
		UnicornSpike->SetActive(false);
	}

	if (UEngineInput::IsPress('R'))
	{
		UnicornSpike->ChangeAnimation("UnicornSpike");
		UnicornSpike->SetActive(true);
		Collision->SetActive(true);
	}
}
