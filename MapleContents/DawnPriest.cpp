#include "PreCompile.h"
#include "DawnPriest.h"


#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>


ADawnPriest::ADawnPriest()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	ADawnPriestenderer = CreateDefaultSubObject<USpriteRenderer>();
	ADawnPriestenderer->SetupAttachment(RootComponent);

	ADawnPriestenderer->CreateAnimation("DawnPriest", "DawnPriest", 0, 7, 0.2f);

	{
		USpriteRenderer::FrameAnimation* Animation = ADawnPriestenderer->FindAnimation("DawnPriest");
		Animation->IsAutoScale = true;
		Animation->AutoScaleRatio = 1.0f;
	}

	ADawnPriestenderer->ChangeAnimation("DawnPriest");

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
