#include "PreCompile.h"
#include "DawnPriest.h"


#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>


ADawnPriest::ADawnPriest()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	DawnPriestrenderer = CreateDefaultSubObject<USpriteRenderer>();
	DawnPriestrenderer->SetupAttachment(RootComponent);

	DawnPriestrenderer->CreateAnimation("DawnPriest", "DawnPriest", 0, 7, 0.2f);

	{
		USpriteRenderer::FrameAnimation* Animation = DawnPriestrenderer->FindAnimation("DawnPriest");
	}

	DawnPriestrenderer->ChangeAnimation("DawnPriest");

}

ADawnPriest::~ADawnPriest()
{

}

void ADawnPriest::BeginPlay()
{
	AActor::BeginPlay();
}

void ADawnPriest::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}
