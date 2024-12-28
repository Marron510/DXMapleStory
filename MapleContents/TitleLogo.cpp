#include "PreCompile.h"
#include "TitleLogo.h"
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/DefaultSceneComponent.h>


ATitleLogo::ATitleLogo()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	LogoRenderer = CreateDefaultSubObject<USpriteRenderer>();

	LogoRenderer->CreateAnimation("Idle", "Idle.png", 0, 3, 0.7f);
	LogoRenderer->CreateAnimation("Walk", "Walk.png", 0, 3, 0.08f);
	LogoRenderer->CreateAnimation("Tornado", "Leaf_Tornado.png", 0, 8, 0.1f, false);
	LogoRenderer->CreateAnimation("Rolling", "Rolling.png", 0, 8, 0.1f);


	{
		USpriteRenderer::FrameAnimation* Animation = LogoRenderer->FindAnimation("Idle");
		Animation->IsAutoScale = true;
		Animation->AutoScaleRatio = 1.0f;
	}

	{
		USpriteRenderer::FrameAnimation* Animation = LogoRenderer->FindAnimation("Walk");
		Animation->IsAutoScale = true;
		Animation->AutoScaleRatio = 1.0f;
	}

	{
		USpriteRenderer::FrameAnimation* Animation = LogoRenderer->FindAnimation("Tornado");
		Animation->IsAutoScale = true;
		Animation->AutoScaleRatio = 1.0f;
	}


	{
		USpriteRenderer::FrameAnimation* Animation = LogoRenderer->FindAnimation("Rolling");
		Animation->IsAutoScale = true;
		Animation->AutoScaleRatio = 1.0f;
	}

	LogoRenderer->ChangeAnimation("Idle");

	LogoRenderer->SetRelativeScale3D({ 50, 50, 1.0f });
	LogoRenderer->SetupAttachment(RootComponent);

	//Child = CreateDefaultSubObject<USpriteRenderer>();
	//Child->SetSprite("Player.png", 2);
	//// 부모의 스케일이 나에게 영향을 주면서 나는 100이 아닐수가 있다
	//Child->SetRelativeLocation({100.0f, 0.0f, 0.0f});
	//Child->SetScale3D({ 50.0f, 50.0f, 1.0f });
	//// Child->SetScale3D({ 50.0f, 50.0f, 1.0f });
	//Child->SetupAttachment(RootComponent);
}


ATitleLogo::~ATitleLogo()
{
}

void ATitleLogo::BeginPlay()
{
	AActor::BeginPlay();
}

void ATitleLogo::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	if (UEngineInput::IsPress('A'))
	{
		LogoRenderer->ChangeAnimation("Walk");
		AddRelativeLocation(FVector{ -300.0f * _DeltaTime, 0.0f, 0.0f });
	}
	if (UEngineInput::IsUp('A'))
	{
		LogoRenderer->ChangeAnimation("Idle");
	}
	if (UEngineInput::IsPress('D'))
	{
		AddRelativeLocation(FVector{ 300.0f * _DeltaTime, 0.0f, 0.0f });
		//AddActorRotation(FVector{ 0.0f, 360.0f * _DeltaTime, 0.0f  });
	}

	if (UEngineInput::IsPress('W'))
	{
		AddRelativeLocation(FVector{ 0.0f, 100.0f * _DeltaTime, 0.0f });
	}

	if (UEngineInput::IsPress('S'))
	{
		AddRelativeLocation(FVector{ 0.0f, -100.0f * _DeltaTime, 0.0f });
	}

	if (UEngineInput::IsPress('Q'))
	{
		AddActorRotation(FVector{ 0.0f, 0.0f , 360.0f * _DeltaTime });
	}

	if (UEngineInput::IsPress('E'))
	{
		LogoRenderer->ChangeAnimation("Tornado");
		
	}

	if (UEngineInput::IsPress('R'))
	{
		LogoRenderer->ChangeAnimation("Rolling");
	}
}