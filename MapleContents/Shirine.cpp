#include "PreCompile.h"
#include "Shirine.h"


#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>


AShirine::AShirine()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	Shirinerenderer = CreateDefaultSubObject<USpriteRenderer>();
	Shirinerenderer->SetupAttachment(RootComponent);

	Shirinerenderer->CreateAnimation("Shirine", "Shirine", 0, 7, 0.2f);

	{
		USpriteRenderer::FrameAnimation* Animation = Shirinerenderer->FindAnimation("Shirine");
		Animation->IsAutoScale = true;
		Animation->AutoScaleRatio = 1.0f;
	}

	Shirinerenderer->ChangeAnimation("Shirine");
}

AShirine::~AShirine()
{

}

void AShirine::BeginPlay()
{
	AActor::BeginPlay();
}

void AShirine::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}
