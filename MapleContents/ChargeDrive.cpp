#include "PreCompile.h"
#include "ChargeDrive.h"

#include <EnginePlatform/EngineInput.h>

#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>

#include "MapleEnum.h"

AChargeDrive::AChargeDrive()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	ChargeDrive_Front = CreateDefaultSubObject<USpriteRenderer>();
	ChargeDrive_Back = CreateDefaultSubObject<USpriteRenderer>();
	
	ChargeDrive_Back->SetupAttachment(RootComponent);
	ChargeDrive_Front->SetupAttachment(RootComponent);

	ChargeDrive_Front->CreateAnimation("ChargeDrive_Front", "ChargeDrive", 0, 10, 0.06f, false);
	ChargeDrive_Back->CreateAnimation("ChargeDrive_Back", "ChargeDrive", 11, 19, 0.04f, false);

	ChargeDrive_Front->CreateAnimation("None", "WrathOfEnril", 14, 14, 0.01f, false);
	ChargeDrive_Back->CreateAnimation("None", "WrathOfEnril", 14, 14, 0.01f, false);

	ChargeDrive_Front->ChangeAnimation("None");
	ChargeDrive_Back->ChangeAnimation("None");

	ChargeDrive_Front->SetRelativeLocation(FVector{ 0.0f, -30.0f, static_cast<float>(EMapleZEnum::Player_Skill_Front) });
	ChargeDrive_Back->SetRelativeLocation(FVector{ 0.0f, -50.0f, static_cast<float>(EMapleZEnum::Player_Skill_Front) - 50.0f});

	Collision = CreateDefaultSubObject<UCollision>();
	Collision->SetupAttachment(RootComponent);
	Collision->SetCollisionProfileName("PlayerSKill");

	Collision->SetScale3D({ 160.0f, 120.0f });
	Collision->SetRelativeLocation(FVector{ -20.0f, 60.0f , static_cast<float>(EMapleZEnum::Player) });
	Collision->SetCollisionEnter([](UCollision* _This, UCollision* _Other)
		{
		});
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
		Collision->SetActive(false);
		ChargeDrive_Front->SetActive(false);
		ChargeDrive_Back->SetActive(false);
		
	}



	if (true == UEngineInput::IsPress('Q'))
	{
		ChargeDrive_Front->ChangeAnimation("ChargeDrive_Front");
		ChargeDrive_Back->ChangeAnimation("ChargeDrive_Back");
		Collision->SetActive(true);
		ChargeDrive_Front->SetActive(true);
		ChargeDrive_Back->SetActive(true);
	}

}
