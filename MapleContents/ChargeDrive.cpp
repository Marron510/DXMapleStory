#include "PreCompile.h"
#include "ChargeDrive.h"

#include <EnginePlatform/EngineInput.h>

#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

#include "MapleEnum.h"

AChargeDrive::AChargeDrive()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	ChargeDrive_Front = CreateDefaultSubObject<USpriteRenderer>();
	ChargeDrive_Back = CreateDefaultSubObject<USpriteRenderer>();
	
	ChargeDrive_Front->SetupAttachment(RootComponent);
	ChargeDrive_Back->SetupAttachment(RootComponent);

	ChargeDrive_Front->CreateAnimation("ChargeDrive_Front", "ChargeDrive", 0, 10, 0.07f, false);
	ChargeDrive_Back->CreateAnimation("ChargeDrive_Back", "ChargeDrive", 11, 18, 0.04f, false);

	ChargeDrive_Front->CreateAnimation("None", "WrathOfEnril", 14, 14, 0.01f, false);
	ChargeDrive_Back->CreateAnimation("None", "WrathOfEnril", 14, 14, 0.01f, false);

	ChargeDrive_Front->ChangeAnimation("None");
	ChargeDrive_Back->ChangeAnimation("None");

	ChargeDrive_Front->SetRelativeLocation(FVector{ 0.0f, -30.0f, static_cast<float>(EMapleZEnum::Player_Skill_Back) });
	ChargeDrive_Back->SetRelativeLocation(FVector{ -20.0f, -50.0f, static_cast<float>(EMapleZEnum::Player_Skill_Front) });
}

AChargeDrive::~AChargeDrive()
{

	

}

void AChargeDrive::BeginPlay()
{
	ASkillManager::BeginPlay();
}

void AChargeDrive::Tick(float _DeltaTime)
{
	ASkillManager::Tick(_DeltaTime);

	if (true == ChargeDrive_Front->IsCurAnimationEnd())
	{
		ChargeDrive_Front->ChangeAnimation("None");
		ChargeDrive_Back->ChangeAnimation("None");
		ChargeDrive_Front->SetActive(false);
		ChargeDrive_Back->SetActive(false);
	}

	if (UEngineInput::IsPress('Q'))
	{
		ChargeDrive_Front->ChangeAnimation("ChargeDrive_Front");
		ChargeDrive_Back->ChangeAnimation("ChargeDrive_Back");
		ChargeDrive_Front->SetActive(true);
		ChargeDrive_Back->SetActive(true);
	}

}
