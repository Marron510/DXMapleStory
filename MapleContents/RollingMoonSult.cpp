#include "PreCompile.h"
#include "RollingMoonSult.h"

#include <EnginePlatform/EngineInput.h>

#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>

#include "MapleEnum.h"

ARollingMoonSult::ARollingMoonSult()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	RollingMoonSult = CreateDefaultSubObject<USpriteRenderer>();
	RollingMoonSult->SetupAttachment(RootComponent);

	RollingMoonSult->CreateAnimation("RollingMoonSult", "RollingMoonSult", 0, 8, 0.07f, false);
	RollingMoonSult->CreateAnimation("None", "WrathOfEnril", 14, 14, 0.01f, false);
	RollingMoonSult->ChangeAnimation("None");

	RollingMoonSult->SetRelativeLocation(FVector{ 0.0f, -100.0f, static_cast<float>(EMapleZEnum::Player_Skill_Front)});


	Collision = CreateDefaultSubObject<UCollision>();
	Collision->SetupAttachment(RootComponent);
	Collision->SetCollisionProfileName("PlayerSKill");

	Collision->SetScale3D({ 230.0f, 260.0f });
	Collision->SetRelativeLocation(FVector{ 0.0f, 36.0f , static_cast<float>(EMapleZEnum::Player) });
	Collision->SetCollisionEnter([](UCollision* _This, UCollision* _Other)
		{
		});

}

ARollingMoonSult::~ARollingMoonSult()
{

}

void ARollingMoonSult::BeginPlay()
{
	ASkillManager::BeginPlay();
}

void ARollingMoonSult::Tick(float _DeltaTime)
{
	ASkillManager::Tick(_DeltaTime);

	if (true == RollingMoonSult->IsCurAnimationEnd())
	{
		RollingMoonSult->ChangeAnimation("None");
		Collision->SetActive(false);
		RollingMoonSult->SetActive(false);
	}

	if (UEngineInput::IsPress('E'))
	{
		RollingMoonSult->ChangeAnimation("RollingMoonSult");
		Collision->SetActive(true);
		RollingMoonSult->SetActive(true);
	}
}
