#include "PreCompile.h"
#include "WrathOfEnril.h"

#include <EnginePlatform/EngineInput.h>

#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>

#include "MapleEnum.h"

AWrathOfEnril::AWrathOfEnril()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	WrathOfEnril = CreateDefaultSubObject<USpriteRenderer>();
	WrathOfEnril->SetupAttachment(RootComponent);

	WrathOfEnril->CreateAnimation("WrathOfEnril", "WrathOfEnril", 0, 13, 0.0614f, false);
	WrathOfEnril->CreateAnimation("None", "WrathOfEnril", 14, 14, 0.01f, false);
	WrathOfEnril->ChangeAnimation("None");

	Collision = CreateDefaultSubObject<UCollision>();
	Collision->SetupAttachment(RootComponent);
	Collision->SetCollisionProfileName("Player");

	Collision->SetScale3D({ 640.0f, 340.0f });
	Collision->SetRelativeLocation(FVector{ -330.0f, 120.0f , static_cast<float>(EMapleZEnum::Player) });
	Collision->SetCollisionEnter([](UCollision* _This, UCollision* _Other)
		{
			_Other->GetActor()->Destroy();
			UEngineDebug::OutPutString("Destroy");
		});

	WrathOfEnril->SetRelativeLocation(FVector{ -230.0f, -220.0f, static_cast<float>(EMapleZEnum::Player_Skill_Front)});

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
		Collision->SetActive(false);
		WrathOfEnril->SetActive(false);
	}

	if (UEngineInput::IsPress('A'))
	{
		WrathOfEnril->ChangeAnimation("WrathOfEnril");
		WrathOfEnril->SetActive(true);
		Collision->SetActive(true);
	}
}
