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

	PlayerRenderer->SetupAttachment(RootComponent);

	PlayerRenderer->CreateAnimation("Idle", "Idle.png", 0, 3, 0.7f);
	PlayerRenderer->CreateAnimation("Walk", "Walk.png", 0, 3, 0.08f);
	PlayerRenderer->CreateAnimation("Tornado", "Leaf_Tornado.png", 0, 8, 0.1f, false);
	PlayerRenderer->CreateAnimation("Rolling", "Rolling.png", 0, 8, 0.1f);
	PlayerRenderer->CreateAnimation("Jump", "Jump.png", 0, 0, 0.1f);
	PlayerRenderer->CreateAnimation("StrikeDualShot", "StrikeDualShot.png", 0, 6, 0.076f);


	{
		USpriteRenderer::FrameAnimation* Animation = PlayerRenderer->FindAnimation("Idle");
	}
	{
		USpriteRenderer::FrameAnimation* Animation = PlayerRenderer->FindAnimation("Walk");
	}	
	{
		USpriteRenderer::FrameAnimation* Animation = PlayerRenderer->FindAnimation("Tornado");
	} 
	{
		USpriteRenderer::FrameAnimation* Animation = PlayerRenderer->FindAnimation("Rolling");
	}
	{
		USpriteRenderer::FrameAnimation* Animation = PlayerRenderer->FindAnimation("Jump");
	}

	PlayerRenderer->ChangeAnimation("Idle");

	

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
		SetActorRelativeScale3D(FVector{ 1.0f, 1.0f, 1.0f });
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
		AddRelativeLocation(FVector{ 0.0f, 300.0f * _DeltaTime, 0.0f });
	}

	if (UEngineInput::IsPress('S'))
	{
		AddRelativeLocation(FVector{ 0.0f, -300.0f * _DeltaTime, 0.0f });
	}

	if (UEngineInput::IsPress('Q'))
	{
		AddActorRotation(FVector{ 0.0f, 0.0f , 360.0f * _DeltaTime });
	}

	if (UEngineInput::IsPress('C'))
	{
		PlayerRenderer->ChangeAnimation("Jump");

	}
	
	if (UEngineInput::IsPress('E'))
	{
		PlayerRenderer->ChangeAnimation("Tornado");

	}

	if (UEngineInput::IsPress('R'))
	{
		PlayerRenderer->ChangeAnimation("Rolling");
	}

	if (UEngineInput::IsPress('T'))
	{
		PlayerRenderer->ChangeAnimation("StrikeDualShot");
	}

}
