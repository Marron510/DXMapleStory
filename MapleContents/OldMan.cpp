#include "PreCompile.h"
#include "OldMan.h"


#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

AOldMan::AOldMan()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	OldManrenderer = CreateDefaultSubObject<USpriteRenderer>();
	OldManrenderer->SetupAttachment(RootComponent);

	OldManrenderer->CreateAnimation("OldMan", "OldMan", 0, 7, 0.2f);

	{
		USpriteRenderer::FrameAnimation* Animation = OldManrenderer->FindAnimation("OldMan");
		Animation->IsAutoScale = true;
		Animation->AutoScaleRatio = 1.0f;
	}

	OldManrenderer->ChangeAnimation("OldMan");

}

AOldMan::~AOldMan()
{

}

void AOldMan::BeginPlay()
{
	AActor::BeginPlay();
}

void AOldMan::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}
