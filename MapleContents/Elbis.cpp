#include "PreCompile.h"
#include "Elbis.h"


#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

AElbis::AElbis()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	Elbisrenderer = CreateDefaultSubObject<USpriteRenderer>();
	Elbisrenderer->SetupAttachment(RootComponent);

	Elbisrenderer->CreateAnimation("Elbis", "Elbis", 0, 14, 0.15f);

	{
		USpriteRenderer::FrameAnimation* Animation = Elbisrenderer->FindAnimation("Elbis");
	}

	Elbisrenderer->ChangeAnimation("Elbis");
}

AElbis::~AElbis()
{

}

void AElbis::BeginPlay()
{
	AActor::BeginPlay();

}

void AElbis::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}
