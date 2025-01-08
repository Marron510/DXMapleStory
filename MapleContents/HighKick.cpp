#include "PreCompile.h"
#include "HighKick.h"

#include <EnginePlatform/EngineInput.h>

#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

#include "MapleEnum.h"
#include "ChargeDrive.h"

AHighKick::AHighKick()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	HighKick = CreateDefaultSubObject<USpriteRenderer>();
	HighKick->SetupAttachment(RootComponent);

	HighKick->CreateAnimation("HighKickDemolition", "HighKick", 0, 12, 0.0614f, false);
	HighKick->CreateAnimation("None", "WrathOfEnril", 14, 14, 0.01f, false);
	HighKick->ChangeAnimation("None");

	HighKick->SetRelativeLocation(FVector{ 0.0f, -200.0f, static_cast<float>(EMapleZEnum::Player_Skill_Front) });
}

AHighKick::~AHighKick()
{

}


void AHighKick::BeginPlay()
{
	ASkillManager::BeginPlay();
}

void AHighKick::Tick(float _DeltaTime)
{
	ASkillManager::Tick(_DeltaTime);

	


	if (true == HighKick->IsCurAnimationEnd())
	{
		HighKick->ChangeAnimation("None");
		HighKick->SetActive(false);
	}

	if (true == UEngineInput::IsPress('W'))
	{
		HighKick->ChangeAnimation("HighKickDemolition");
		HighKick->SetActive(true);
	}
}
