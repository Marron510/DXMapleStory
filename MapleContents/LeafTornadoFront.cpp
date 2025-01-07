#include "PreCompile.h"
#include "LeafTornadoFront.h"

#include <EnginePlatform/EngineInput.h>

#include <Enginecore/TimeEventComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>


ALeafTornadoFront::ALeafTornadoFront()
{
	TimeEventComponent = CreateDefaultSubObject<UTimeEventComponent>();
	
	LeafTornadoFront = CreateDefaultSubObject<USpriteRenderer>();
	RootComponent = LeafTornadoFront;

	LeafTornadoFront->CreateAnimation("LeafTornadoDown", "LeafTornadoDown", 0, 11, 0.072f, false);
	LeafTornadoFront->CreateAnimation("None", "WrathOfEnril", 14, 14, 0.01f, false);

	LeafTornadoFront->ChangeAnimation("None");
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
		LeafTornadoFront->ChangeAnimation("LeafTornadoDown");

		LeafTornadoFront->SetRelativeLocation(FVector{ 25.0f, -390.0f, FrontSkillZPos });
	
		TimeEventComponent->AddEndEvent(0.87f, [this]()
			{
				LeafTornadoFront->ChangeAnimation("None");
			}, false
		);

	}
}
