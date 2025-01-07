#include "PreCompile.h"
#include "LeafTornadoBack.h"

#include <EnginePlatform/EngineInput.h>

#include <Enginecore/TimeEventComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>


ALeafTornadoBack::ALeafTornadoBack()
{
	TimeEventComponent = CreateDefaultSubObject<UTimeEventComponent>();

	SkillRenderBack = CreateDefaultSubObject<USpriteRenderer>();
	RootComponent = SkillRenderBack;

	SkillRenderBack->CreateAnimation("LeafTornadoUp", "LeafTornadoUp", 0, 11, 0.072f, false);
	SkillRenderBack->CreateAnimation("None", "WrathOfEnril", 14, 14, 0.01f, false);
	SkillRenderBack->ChangeAnimation("None");
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
		SkillRenderBack->ChangeAnimation("LeafTornadoUp");

		SkillRenderBack->SetRelativeLocation(FVector{ 0.0f, -390.0f, BackSkillZPos });
	
		TimeEventComponent->AddEndEvent(0.87f, [this]()
			{
				SkillRenderBack->ChangeAnimation("None");
			}, false
		);

	}
}
