#include "PreCompile.h"
#include "RollingMoonSult.h"

#include <EnginePlatform/EngineInput.h>

#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

#include "MapleEnum.h"

ARollingMoonSult::ARollingMoonSult()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	RollingMoonSult = CreateDefaultSubObject<USpriteRenderer>();
	RollingMoonSult->SetupAttachment(RootComponent);

	RollingMoonSult->CreateAnimation("RollingMoonSult", "RollingMoonSult", 0, 8, 0.1f, false);
	RollingMoonSult->CreateAnimation("None", "WrathOfEnril", 14, 14, 0.01f, false);
	RollingMoonSult->ChangeAnimation("None");

	RollingMoonSult->SetRelativeLocation(FVector{ 0.0f, -100.0f, static_cast<float>(EMapleZEnum::Player_Skill_Front)});

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
		RollingMoonSult->SetActive(false);
	}

	if (UEngineInput::IsPress('E'))
	{
		RollingMoonSult->ChangeAnimation("RollingMoonSult");
		RollingMoonSult->SetActive(true);
	}
}
