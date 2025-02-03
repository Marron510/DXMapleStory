#include "PreCompile.h"
#include "Ishtar.h"

#include <EnginePlatform/EngineInput.h>

#include <EngineCore/TimeEventComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>

#include "MapleEnum.h"
#include "SerenCollision.h"

AIshtar::AIshtar()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	Ishtar = CreateDefaultSubObject<USpriteRenderer>();
	Ishtar->SetupAttachment(RootComponent);

	Ishtar->CreateAnimation("Ishtar_Pre", "IshPre", 0, 5, 0.0614f, false);
	Ishtar->CreateAnimation("Ishtar_Down", "IshDown", 0, 7, 0.0614f);
	Ishtar->CreateAnimation("Ishtar_End", "IshEnd", 0, 8, 0.0614f, false);


	Ishtar->CreateAnimation("None", "WrathOfEnril", 14, 14, 0.01f, false);
	
	Ishtar->ChangeAnimation("None");

	Ishtar->SetRelativeLocation(FVector{ -20.0f, -170.0f, static_cast<float>(EMapleZEnum::Player_Skill_Front) });
}

AIshtar::~AIshtar()
{

}

void AIshtar::BeginPlay()
{
	ASkillManager::BeginPlay();
	
}

void AIshtar::Tick(float _DeltaTime)
{
	ASkillManager::Tick(_DeltaTime);

	if (true == UEngineInput::IsUp(VK_SPACE))
	{
		Ishtar->ChangeAnimation("Ishtar_End");
		bIsStart = false;
	}


	if (true == UEngineInput::IsDown(VK_SPACE))
	{
		Ishtar->ChangeAnimation("Ishtar_Pre");
		bIsStart = true;
		return;
	}

	if (true == Ishtar->IsCurAnimationEnd() && false == bIsStart)
	{
		Ishtar->ChangeAnimation("None");
		return;
	}


	if (true == Ishtar->IsCurAnimationEnd() && true == bIsStart)
	{
		Ishtar->ChangeAnimation("Ishtar_Down");
	}

}
