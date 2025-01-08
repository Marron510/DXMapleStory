#include "PreCompile.h"
#include "StrikeDualShot.h"

#include <EnginePlatform/EngineInput.h>

#include <Enginecore/TimeEventComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>


AStrikeDualShot::AStrikeDualShot()
{
	TimeEventComponent = CreateDefaultSubObject<UTimeEventComponent>();

	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;
	
	StrikeDaulShotFront = CreateDefaultSubObject<USpriteRenderer>();
	StrikeDaulShotBack = CreateDefaultSubObject<USpriteRenderer>();


	StrikeDaulShotFront->SetupAttachment(RootComponent);
	StrikeDaulShotBack->SetupAttachment(RootComponent);

	StrikeDaulShotFront->CreateAnimation("StrikeDualShotFront", "StrikeDualShot", 0, 10, 0.032f);
	StrikeDaulShotFront->CreateAnimation("None", "WrathOfEnril", 14, 14, 0.01f, false);
	
	StrikeDaulShotBack->CreateAnimation("StrikeDualShotBack", "StrikeDualShot_Back", 0, 6, 0.0457f);
	StrikeDaulShotBack->CreateAnimation("None", "WrathOfEnril", 14, 14, 0.01f, false);
	
	StrikeDaulShotFront->ChangeAnimation("None");
	StrikeDaulShotBack->ChangeAnimation("None");
	
	StrikeDaulShotFront->SetRelativeLocation(FVector{ 40.0f, -320.0f, FrontSkillZPos });
	StrikeDaulShotBack->SetRelativeLocation(FVector{ 40.0f, -280.0f, BackSkillZPos });
}

AStrikeDualShot::~AStrikeDualShot()
{

}

void AStrikeDualShot::BeginPlay()
{
	ASkillManager::BeginPlay();
}

void AStrikeDualShot::Tick(float _DeltaTime)
{
	ASkillManager::Tick(_DeltaTime);

	if (false == UEngineInput::IsPressTime('S') && true == StrikeDaulShotFront->IsCurAnimationEnd())
	{
		StrikeDaulShotFront->ChangeAnimation("None");
		StrikeDaulShotBack->ChangeAnimation("None");

		StrikeDaulShotFront->SetActive(false);
		StrikeDaulShotBack->SetActive(false);
	}

	if (UEngineInput::IsPress('S'))
	{
		StrikeDaulShotFront->ChangeAnimation("StrikeDualShotFront");
		StrikeDaulShotBack->ChangeAnimation("StrikeDualShotBack");
		StrikeDaulShotFront->SetActive(true);
		StrikeDaulShotBack->SetActive(true);
	}

}
