#include "PreCompile.h"
#include "FirePriest.h"


#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>


AFirePriest::AFirePriest()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	FirePriestrenderer = CreateDefaultSubObject<USpriteRenderer>();
	FirePriestrenderer->SetupAttachment(RootComponent);

	FirePriestrenderer->CreateAnimation("FirePriest", "FirePriest", 0, 7, 0.2f);

	{
		USpriteRenderer::FrameAnimation* Animation = FirePriestrenderer->FindAnimation("FirePriest");
		Animation->IsAutoScale = true;
		Animation->AutoScaleRatio = 1.0f;
	}

	FirePriestrenderer->ChangeAnimation("FirePriest");

}

AFirePriest::~AFirePriest()
{

}

void AFirePriest::BeginPlay()
{
	AActor::BeginPlay();
}

void AFirePriest::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}
