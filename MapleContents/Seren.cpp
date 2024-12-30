#include "PreCompile.h"
#include "Seren.h"

#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>


ASeren::ASeren()
{

	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	SerenRender = CreateDefaultSubObject<USpriteRenderer>();

	SerenRender->SetupAttachment(RootComponent);

	SerenRender->CreateAnimation("NoonSerenStand", "NoonSerenStand.png", 0, 14, 0.09f);



	{
		USpriteRenderer::FrameAnimation* Animation = SerenRender->FindAnimation("NoonSerenStand");
		Animation->IsAutoScale = true;
		Animation->AutoScaleRatio = 1.0f;
	}



	SerenRender->ChangeAnimation("NoonSerenStand");

}

ASeren::~ASeren()
{

}

void ASeren::BeginPlay()
{
	AActor::BeginPlay();
}

void ASeren::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}
