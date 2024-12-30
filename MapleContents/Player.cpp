#include "PreCompile.h"
#include "Player.h"

#include <EnginePlatform/EngineInput.h>

#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>


APlayer::APlayer()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	PlayerRenderer = CreateDefaultSubObject<USpriteRenderer>();

	PlayerRenderer->CreateAnimation("Idle", "Idle.png", 0, 3, 0.7f);
	PlayerRenderer->CreateAnimation("Walk", "Walk.png", 0, 3, 0.08f);
	PlayerRenderer->CreateAnimation("Tornado", "Leaf_Tornado.png", 0, 8, 0.1f, false);
	PlayerRenderer->CreateAnimation("Rolling", "Rolling.png", 0, 8, 0.1f);


	{
		USpriteRenderer::FrameAnimation* Animation = PlayerRenderer->FindAnimation("Idle");
		Animation->AutoScaleRatio = 1.0f;
	}

	{
		USpriteRenderer::FrameAnimation* Animation = PlayerRenderer->FindAnimation("Walk");
		Animation->AutoScaleRatio = 1.0f;
	}

	{
		USpriteRenderer::FrameAnimation* Animation = PlayerRenderer->FindAnimation("Tornado");
		Animation->IsAutoScale = true;
		Animation->AutoScaleRatio = 1.0f;
	}


	{
		USpriteRenderer::FrameAnimation* Animation = PlayerRenderer->FindAnimation("Rolling");
		Animation->IsAutoScale = true;
		Animation->AutoScaleRatio = 1.0f;
	}

	PlayerRenderer->ChangeAnimation("Idle");

	PlayerRenderer->SetupAttachment(RootComponent);

}

APlayer::~APlayer()
{
}

void APlayer::BeginPlay()
{
	APawn::BeginPlay();

}
void APlayer::Tick(float _DeltaTime)
{
	APawn::Tick(_DeltaTime);

	if (UEngineInput::IsPress('A'))
	{
		PlayerRenderer->ChangeAnimation("Walk");
		AddRelativeLocation(FVector{ -300.0f * _DeltaTime, 0.0f, 0.0f });
		SetActorRelativeScale3D(FVector{ 1.0f, 1.0f, 1.0f });
	}

	if (UEngineInput::IsUp('A'))
	{
		PlayerRenderer->ChangeAnimation("Idle");
	}

	if (UEngineInput::IsPress('D'))
	{
		PlayerRenderer->ChangeAnimation("Walk");
		AddRelativeLocation(FVector{ 300.0f * _DeltaTime, 0.0f, 0.0f });
		SetActorRelativeScale3D(FVector{ -1.0f, 1.0f, 1.0f });
		
	}

	if (UEngineInput::IsUp('D'))
	{
		PlayerRenderer->ChangeAnimation("Idle");
		SetActorRelativeScale3D(FVector{ -1.0f, 1.0f, 1.0f });
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
		PlayerRenderer->ChangeAnimation("Tornado");

	}

	if (UEngineInput::IsPress('R'))
	{
		PlayerRenderer->ChangeAnimation("Rolling");
	}

}
