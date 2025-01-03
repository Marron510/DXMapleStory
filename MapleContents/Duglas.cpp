#include "PreCompile.h"
#include "Duglas.h"


#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

ADuglas::ADuglas()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	Duglasrenderer = CreateDefaultSubObject<USpriteRenderer>();
	Duglasrenderer->SetupAttachment(RootComponent);

	Duglasrenderer->CreateAnimation("Duglas", "Duglas", 0, 11, 0.2f);

	{
		USpriteRenderer::FrameAnimation* Animation = Duglasrenderer->FindAnimation("Duglas");
	}

	Duglasrenderer->ChangeAnimation("Duglas");
}

ADuglas::~ADuglas()
{

}

void ADuglas::BeginPlay()
{
	AActor::BeginPlay();

}

void ADuglas::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}
