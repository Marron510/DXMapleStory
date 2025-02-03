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

	Ishtar->CreateAnimation("Ishtar", "Ishtar", 0, 13, 0.0614f, false);
	Ishtar->CreateAnimation("None", "Ishtar", 14, 14, 0.01f, false);
	Ishtar->ChangeAnimation("None");

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

}
