#include "PreCompile.h"
#include "LeafTornadoBack.h"

#include <EnginePlatform/EngineInput.h>

#include <Enginecore/TimeEventComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>


ALeafTornadoBack::ALeafTornadoBack()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	TimeEventComponent = CreateDefaultSubObject<UTimeEventComponent>();

	LeafTornadoBack = CreateDefaultSubObject<USpriteRenderer>();
	LeafTornadoBack->SetupAttachment(RootComponent);

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

		LeafTornadoBack->SetRelativeLocation(FVector{ 0.0f, -390.0f, FrontSkillZPos + 0.1f });
	
		TimeEventComponent->AddEndEvent(0.87f, [this]()
			{
				LeafTornadoBack->ChangeAnimation("None");
			}, false
		);

	}
}
