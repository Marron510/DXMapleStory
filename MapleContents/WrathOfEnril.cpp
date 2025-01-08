#include "PreCompile.h"
#include "WrathOfEnril.h"

#include <EnginePlatform/EngineInput.h>

#include <Enginecore/TimeEventComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>


AWrathOfEnril::AWrathOfEnril()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	WrathOfEnril = CreateDefaultSubObject<USpriteRenderer>();
	WrathOfEnril->SetupAttachment(RootComponent);

	TimeEventComponent = CreateDefaultSubObject<UTimeEventComponent>();
	WrathOfEnril->CreateAnimation("WrathOfEnril", "WrathOfEnril", 0, 13, 0.0614f, false);
	WrathOfEnril->CreateAnimation("None", "WrathOfEnril", 14, 14, 0.01f, false);
	WrathOfEnril->ChangeAnimation("None");

	WrathOfEnril->SetRelativeLocation(FVector{ -230.0f, -420.0f, FrontSkillZPos });
}

AWrathOfEnril::~AWrathOfEnril()
{

}

void AWrathOfEnril::BeginPlay()
{
	ASkillManager::BeginPlay();
}

void AWrathOfEnril::Tick(float _DeltaTime)
{
	ASkillManager::Tick(_DeltaTime);

	if (true == WrathOfEnril->IsCurAnimationEnd())
	{
		WrathOfEnril->ChangeAnimation("None");
		WrathOfEnril->SetActive(false);
	}

	if (UEngineInput::IsPress('A'))
	{
		WrathOfEnril->ChangeAnimation("WrathOfEnril");
		WrathOfEnril->SetActive(true);
	}
}
