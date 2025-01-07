#include "PreCompile.h"
#include "WrathOfEnril.h"

#include <EnginePlatform/EngineInput.h>

#include <Enginecore/TimeEventComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>


AWrathOfEnril::AWrathOfEnril()
{
	TimeEventComponent = CreateDefaultSubObject<UTimeEventComponent>();
	SkillRender->CreateAnimation("WrathOfEnril", "WrathOfEnril", 0, 13, 0.1f, false);
	SkillRender->CreateAnimation("None", "WrathOfEnril", 14, 14, 0.01f, false);
	SkillRender->ChangeAnimation("None");
	SkillRender->SetRelativeLocation({ 0.0f, 0.0f, 0.0f });



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
		SkillRender->ChangeAnimation("WrathOfEnril");
		SkillRender->SetRelativeLocation(FVector{ -250.0f, -194.0f, -0.11f });
		
		TimeEventComponent->AddEndEvent(0.86f, [this]()
			{
				SkillRender->ChangeAnimation("None");
			}, false
		);
	}
}
