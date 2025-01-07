#include "PreCompile.h"
#include "WrathOfEnril.h"

#include <EnginePlatform/EngineInput.h>

#include <Enginecore/TimeEventComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>


AWrathOfEnril::AWrathOfEnril()
{
	WrathOfEnril = CreateDefaultSubObject<USpriteRenderer>();
	RootComponent = WrathOfEnril;

	TimeEventComponent = CreateDefaultSubObject<UTimeEventComponent>();
	WrathOfEnril->CreateAnimation("WrathOfEnril", "WrathOfEnril", 0, 13, 0.1f, false);
	WrathOfEnril->CreateAnimation("None", "WrathOfEnril", 14, 14, 0.01f, false);
	WrathOfEnril->ChangeAnimation("None");
	WrathOfEnril->SetRelativeLocation({ 0.0f, 0.0f, 0.0f });
}

AWrathOfEnril::~AWrathOfEnril()
{

}

void AWrathOfEnril::BeginPlay()
{
	ASkillManager::BeginPlay();
}

void AWrathOfEnril::Tick(float _DeltaTime)
{
	ASkillManager::Tick(_DeltaTime);

	if (UEngineInput::IsPress('A'))
	{
		WrathOfEnril->ChangeAnimation("WrathOfEnril");
		WrathOfEnril->SetRelativeLocation(FVector{ -250.0f, -194.0f, FrontSkillZPos });
		
		TimeEventComponent->AddEndEvent(0.86f, [this]()
			{
				WrathOfEnril->ChangeAnimation("None");
			}, false
		);
	}
}
