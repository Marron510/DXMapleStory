#include "PreCompile.h"
#include "Shorn.h"


#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>


AShorn::AShorn()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	Shornrenderer = CreateDefaultSubObject<USpriteRenderer>();
	Shornrenderer->SetupAttachment(RootComponent);

	Shornrenderer->CreateAnimation("Shorn", "Shorn", 0, 8, 0.2f);

	{
		USpriteRenderer::FrameAnimation* Animation = Shornrenderer->FindAnimation("Shorn");
	}

	Shornrenderer->ChangeAnimation("Shorn");

}

AShorn::~AShorn()
{

}

void AShorn::BeginPlay()
{
	AActor::BeginPlay();
}

void AShorn::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}
