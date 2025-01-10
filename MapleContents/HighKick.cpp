#include "PreCompile.h"
#include "HighKick.h"

#include <EnginePlatform/EngineInput.h>

#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>

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

	Collision = CreateDefaultSubObject<UCollision>();
	Collision->SetupAttachment(RootComponent);
	Collision->SetCollisionProfileName("Player");

	Collision->SetScale3D({ 200.0f, 180.0f });
	Collision->SetRelativeLocation(FVector{ 0.0f, 30.0f, static_cast<float>(EMapleZEnum::Player) });
	Collision->SetCollisionEnter([](UCollision* _This, UCollision* _Other)
		{
		});
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
		Collision->SetActive(false);
		HighKick->SetActive(false);
	}

	if (true == UEngineInput::IsPress('W'))
	{
		HighKick->ChangeAnimation("HighKickDemolition");
		Collision->SetActive(true);
		HighKick->SetActive(true);
	}
}
