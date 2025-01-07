#include "PreCompile.h"
#include "LeafTornadoFront.h"

#include <EnginePlatform/EngineInput.h>

#include <Enginecore/TimeEventComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>


ALeafTornadoFront::ALeafTornadoFront()
{
	TimeEventComponent = CreateDefaultSubObject<UTimeEventComponent>();
	
	SkillRenderFront = CreateDefaultSubObject<USpriteRenderer>();
	RootComponent = SkillRenderFront;

	SkillRenderFront->CreateAnimation("LeafTornadoDown", "LeafTornadoDown", 0, 11, 0.072f, false);
	SkillRenderFront->CreateAnimation("None", "WrathOfEnril", 14, 14, 0.01f, false);

	SkillRenderFront->ChangeAnimation("None");
}

ALeafTornadoFront::~ALeafTornadoFront()
{

}

void ALeafTornadoFront::BeginPlay()
{
	ASkillManager::BeginPlay();
}

void ALeafTornadoFront::Tick(float _DeltaTime)
{
	ASkillManager::Tick(_DeltaTime);

	if (UEngineInput::IsPress('D'))
	{
		SkillRenderFront->ChangeAnimation("LeafTornadoDown");

		SkillRenderFront->SetRelativeLocation(FVector{ 25.0f, -390.0f, FrontSkillZPos });
	
		TimeEventComponent->AddEndEvent(0.87f, [this]()
			{
				SkillRenderFront->ChangeAnimation("None");
			}, false
		);

	}
}
