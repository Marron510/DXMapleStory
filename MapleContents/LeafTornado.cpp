#include "PreCompile.h"
#include "LeafTornado.h"

#include <EnginePlatform/EngineInput.h>

#include <Enginecore/TimeEventComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>


ALeafTornado::ALeafTornado()
{
	TimeEventComponent = CreateDefaultSubObject<UTimeEventComponent>();

	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	LeafTornadoFront = CreateDefaultSubObject<USpriteRenderer>();
	LeafTornadoBack = CreateDefaultSubObject<USpriteRenderer>();
	
	LeafTornadoFront->SetupAttachment(RootComponent);
	LeafTornadoBack->SetupAttachment(RootComponent);
	
	LeafTornadoFront->CreateAnimation("LeafTornadoDown", "LeafTornadoDown", 0, 11, 0.072f, false);
	LeafTornadoFront->CreateAnimation("None", "WrathOfEnril", 14, 14, 0.01f, false);

	LeafTornadoBack->CreateAnimation("LeafTornadoUp", "LeafTornadoUp", 0, 11, 0.072f, false);
	LeafTornadoBack->CreateAnimation("None", "WrathOfEnril", 14, 14, 0.01f, false);

	LeafTornadoFront->ChangeAnimation("None");
	LeafTornadoBack->ChangeAnimation("None");

	LeafTornadoFront->SetRelativeLocation(FVector{ 25.0f, -600.0f, FrontSkillZPos });
	LeafTornadoBack->SetRelativeLocation(FVector{ 0.0f, -640.0f, BackSkillZPos});
}

ALeafTornado::~ALeafTornado()
{

}

void ALeafTornado::BeginPlay()
{
	ASkillManager::BeginPlay();
}

void ALeafTornado::Tick(float _DeltaTime)
{
	ASkillManager::Tick(_DeltaTime);

	if (true == LeafTornadoFront->IsCurAnimationEnd())
	{
		LeafTornadoFront->ChangeAnimation("None");
		LeafTornadoBack->ChangeAnimation("None");
		LeafTornadoFront->SetActive(false);
		LeafTornadoBack->SetActive(false);
	}

	if (UEngineInput::IsPress('D'))
	{
		LeafTornadoFront->ChangeAnimation("LeafTornadoDown");
		LeafTornadoBack->ChangeAnimation("LeafTornadoUp");
		LeafTornadoFront->SetActive(true);
		LeafTornadoBack->SetActive(true);
	}
}
