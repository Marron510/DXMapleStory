#include "PreCompile.h"
#include "LeafTornadoBack.h"

#include <EnginePlatform/EngineInput.h>

#include <Enginecore/TimeEventComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>


ALeafTornadoBack::ALeafTornadoBack()
{
	TimeEventComponent = CreateDefaultSubObject<UTimeEventComponent>();

	LeafTornadoBack = CreateDefaultSubObject<USpriteRenderer>();
	RootComponent = LeafTornadoBack;

	LeafTornadoBack->CreateAnimation("LeafTornadoUp", "LeafTornadoUp", 0, 11, 0.072f, false);
	LeafTornadoBack->CreateAnimation("None", "WrathOfEnril", 14, 14, 0.01f, false);
	LeafTornadoBack->ChangeAnimation("None");
}

ALeafTornadoBack::~ALeafTornadoBack()
{

}

void ALeafTornadoBack::BeginPlay()
{
	ASkillManager::BeginPlay();
}

void ALeafTornadoBack::Tick(float _DeltaTime)
{
	ASkillManager::Tick(_DeltaTime);

	if (UEngineInput::IsPress('D'))
	{
		LeafTornadoBack->ChangeAnimation("LeafTornadoUp");

		LeafTornadoBack->SetRelativeLocation(FVector{ 0.0f, -390.0f, BackSkillZPos });
	
		TimeEventComponent->AddEndEvent(0.87f, [this]()
			{
				LeafTornadoBack->ChangeAnimation("None");
			}, false
		);

	}
}
