#include "PreCompile.h"
#include "Manyu.h"


#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>


AManyu::AManyu()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	Manyurenderer = CreateDefaultSubObject<USpriteRenderer>();
	Manyurenderer->SetupAttachment(RootComponent);

	Manyurenderer->CreateAnimation("Manyu", "Manyu", 0, 0, 0.2f);

	{
		USpriteRenderer::FrameAnimation* Animation = Manyurenderer->FindAnimation("Manyu");
		Animation->IsAutoScale = true;
		Animation->AutoScaleRatio = 1.0f;
	}

	Manyurenderer->ChangeAnimation("Manyu");
}

AManyu::~AManyu()
{

}

void AManyu::BeginPlay()
{
	AActor::BeginPlay();
}

void AManyu::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}
