#include "PreCompile.h"
#include "Hate.h"


#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>


AHate::AHate()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	Haterenderer = CreateDefaultSubObject<USpriteRenderer>();
	Haterenderer->SetupAttachment(RootComponent);

	Haterenderer->CreateAnimation("Hate", "Hate", 0, 9, 0.2f);

	{
		USpriteRenderer::FrameAnimation* Animation = Haterenderer->FindAnimation("Hate");
	}

	Haterenderer->ChangeAnimation("Hate");
}

AHate::~AHate()
{

}

void AHate::BeginPlay()
{
	AActor::BeginPlay();
}

void AHate::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}
