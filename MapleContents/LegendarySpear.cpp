#include "PreCompile.h"
#include "LegendarySpear.h"

#include <EnginePlatform/EngineInput.h>

#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>


#include "MapleEnum.h"

ALegendarySpear::ALegendarySpear()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	LegendarySpearFront = CreateDefaultSubObject<USpriteRenderer>();
	LegendarySpearMid = CreateDefaultSubObject<USpriteRenderer>();

	LegendarySpearFront->SetupAttachment(RootComponent);
	LegendarySpearMid->SetupAttachment(RootComponent);

	LegendarySpearFront->CreateAnimation("LegendarySpearFront", "LegendarySpearFront", 0, 23, 0.052f, false);
	LegendarySpearFront->CreateAnimation("None", "WrathOfEnril", 14, 14, 0.01f, false);

	LegendarySpearMid->CreateAnimation("LegendarySpearMid", "LegendarySpearMid", 0, 19, 0.042f, false);
	LegendarySpearMid->CreateAnimation("None", "WrathOfEnril", 14, 14, 0.01f, false);

	LegendarySpearFront->ChangeAnimation("None");
	LegendarySpearMid->ChangeAnimation("None");

	LegendarySpearFront->SetRelativeLocation(FVector{ -500.0f, -260.0f, static_cast<float>(EMapleZEnum::Player_Skill_Front) });
	LegendarySpearMid->SetRelativeLocation(FVector{ 0.0f, -250.0f, static_cast<float>(EMapleZEnum::Player_Skill_Front) - 20.0f });


	Collision = CreateDefaultSubObject<UCollision>();
	Collision->SetupAttachment(RootComponent);
	Collision->SetCollisionProfileName("PlayerSKill");

	Collision->SetScale3D({ 640.0f, 340.0f });
	Collision->SetRelativeLocation(FVector{ -330.0f, 120.0f, static_cast<float>(EMapleZEnum::Player) });
	Collision->SetCollisionEnter([](UCollision* _This, UCollision* _Other)
		{
		});
}

ALegendarySpear::~ALegendarySpear()
{
	
}

void ALegendarySpear::BeginPlay()
{
	ASkillManager::BeginPlay();
}

void ALegendarySpear::Tick(float _DeltaTime)
{
	ASkillManager::Tick(_DeltaTime);

	if (true == LegendarySpearFront->IsCurAnimationEnd())
	{
		LegendarySpearFront->ChangeAnimation("None");
		LegendarySpearMid->ChangeAnimation("None");
		Collision->SetActive(false);
		LegendarySpearFront->SetActive(false);
		LegendarySpearMid->SetActive(false);
	}

	if (UEngineInput::IsPress('G'))
	{
		LegendarySpearFront->ChangeAnimation("LegendarySpearFront");
		LegendarySpearMid->ChangeAnimation("LegendarySpearMid");
		Collision->SetActive(true);
		LegendarySpearFront->SetActive(true);
		LegendarySpearMid->SetActive(true);
	}
}
