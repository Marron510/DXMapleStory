#include "PreCompile.h"
#include "Joy.h"

#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

AJoy::AJoy()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	Joyrenderer = CreateDefaultSubObject<USpriteRenderer>();
	Joyrenderer->SetupAttachment(RootComponent);

	Joyrenderer->CreateAnimation("Joy", "Joy", 0, 7, 0.2f);

	{
		USpriteRenderer::FrameAnimation* Animation = Joyrenderer->FindAnimation("Joy");
	}

	Joyrenderer->ChangeAnimation("Joy");
}

AJoy::~AJoy()
{

}

void AJoy::BeginPlay()
{
	AActor::BeginPlay();
}

void AJoy::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}
