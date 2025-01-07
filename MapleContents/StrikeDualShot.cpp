#include "PreCompile.h"
#include "StrikeDualShot.h"

#include <EnginePlatform/EngineInput.h>

#include <Enginecore/TimeEventComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

AStrikeDualShot::AStrikeDualShot()
{
	//TimeEventComponent = CreateDefaultSubObject<UTimeEventComponent>();

	StrikeDaulShotFront = CreateDefaultSubObject<USpriteRenderer>();
	RootComponent = StrikeDaulShotFront;


	// ½ºµà
	StrikeDaulShotFront->CreateAnimation("StrikeDualShot", "StrikeDualShot", 0, 10, 0.05f, false);
	//SkillRenderer->CreateAnimation("StrikeDualShot_Back", "StrikeDualShot_Back", 0, 6, 0.077f, false);


	StrikeDaulShotFront->CreateAnimation("None", "WrathOfEnril", 14, 14, 0.01f, false);
	StrikeDaulShotFront->ChangeAnimation("None");
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


}

