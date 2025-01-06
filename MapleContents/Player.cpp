#include "PreCompile.h"
#include "Player.h"

#include <EnginePlatform/EngineInput.h>

#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/TimeEventComponent.h>

APlayer::APlayer()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	TimeEventComponent = CreateDefaultSubObject<UTimeEventComponent>();

	SkillRenderer = CreateDefaultSubObject<USpriteRenderer>();
	PlayerRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SubSkillRenderer = CreateDefaultSubObject<USpriteRenderer>();

	SkillRenderer->SetupAttachment(RootComponent);
	PlayerRenderer->SetupAttachment(RootComponent);
	SubSkillRenderer->SetupAttachment(RootComponent);

	// 엔릴
	SkillRenderer->CreateAnimation("WrathOfEnril", "WrathOfEnril", 0, 13, 0.05f,false);
	// 리프
	SubSkillRenderer->CreateAnimation("LeafTornadoDown", "LeafTornadoDown", 0, 11, 0.05f, false);
	SkillRenderer->CreateAnimation("LeafTornadoUp", "LeafTornadoUp", 0, 11, 0.072f, false);
	// None
	SkillRenderer->CreateAnimation("None", "WrathOfEnril", 14, 14, 0.2f, false);
	SubSkillRenderer->CreateAnimation("None", "WrathOfEnril", 14, 14, 0.2f, false);
	
	PlayerRenderer->CreateAnimation("Idle", "Idle.png", 0, 3, 0.7f);
	PlayerRenderer->CreateAnimation("Walk", "Walk.png", 0, 3, 0.08f);
	PlayerRenderer->CreateAnimation("Tornado", "LeafTornado.png", 0, 8, 0.09f, false);
	PlayerRenderer->CreateAnimation("Rolling", "Rolling.png", 0, 8, 0.1f);
	PlayerRenderer->CreateAnimation("Jump", "Jump.png", 0, 0, 0.1f);
	PlayerRenderer->CreateAnimation("StrikeDualShot", "StrikeDualShot.png", 0, 6, 0.076f);
	PlayerRenderer->CreateAnimation("Charge", "Charge.png", 0, 8, 0.1f);
	PlayerRenderer->CreateAnimation("Wrath", "Wrath.png", 0, 4, 0.1f, false);
	PlayerRenderer->CreateAnimation("Unicorn", "Unicorn.png", 0, 4, 0.14f, false);
	PlayerRenderer->CreateAnimation("LegendarySpear", "LegendarySpear.png", 0, 11, 0.046f, false);
	PlayerRenderer->CreateAnimation("Prone", "Prone.png", 0, 0, 0.046f, false);
	PlayerRenderer->CreateAnimation("ProneAttack", "Prone.png", 0, 1, 0.1f, false);


	PlayerRenderer->ChangeAnimation("Idle");
	

	SkillRenderer->ChangeAnimation("None");
	SubSkillRenderer->ChangeAnimation("None");

	PlayerRenderer->SetRelativeLocation(FVector{ 0.0f, 0.0f, -3.5f });
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
	

	if (true == PlayerRenderer->IsCurAnimationEnd())
	{
		SkillRenderer->ChangeAnimation("None");
		PlayerRenderer->ChangeAnimation("Idle");
		SubSkillRenderer->ChangeAnimation("None");
	}

	if (UEngineInput::IsPress(VK_LEFT))
	{
		PlayerRenderer->ChangeAnimation("Walk");
		AddRelativeLocation(FVector{ -300.0f * _DeltaTime, 0.0f, 0.0f });
		SetActorRelativeScale3D(FVector{ 1.0f, 1.0f, 1.0f });
	}
	if (UEngineInput::IsUp(VK_LEFT))
	{
		PlayerRenderer->ChangeAnimation("Idle");
		SetActorRelativeScale3D(FVector{ 1.0f, 1.0f, 1.0f });
	}
	
	if (UEngineInput::IsPress(VK_RIGHT))
	{
		PlayerRenderer->ChangeAnimation("Walk");
		
		AddRelativeLocation(FVector{ 300.0f * _DeltaTime, 0.0f, 0.0f });
		SetActorRelativeScale3D(FVector{ -1.0f, 1.0f, 1.0f });
	}
	
	if (UEngineInput::IsUp(VK_RIGHT))
	{
		PlayerRenderer->ChangeAnimation("Idle");
		SetActorRelativeScale3D(FVector{ -1.0f, 1.0f, 1.0f });
	}

	if (UEngineInput::IsPress(VK_UP))
	{
		AddRelativeLocation(FVector{ 0.0f, 300.0f * _DeltaTime, 0.0f });
	}

	if (UEngineInput::IsPress(VK_DOWN))
	{
		//AddRelativeLocation(FVector{ 0.0f, -300.0f * _DeltaTime, 0.0f });
		PlayerRenderer->ChangeAnimation("Prone");

	}

	if (UEngineInput::IsUp(VK_DOWN))
	{
		//AddRelativeLocation(FVector{ 0.0f, -300.0f * _DeltaTime, 0.0f });
		PlayerRenderer->ChangeAnimation("Idle");

	}

	if (UEngineInput::IsDown('C'))
	{
		PlayerRenderer->ChangeAnimation("Jump");
	}

	if (UEngineInput::IsDown('Q'))
	{
		PlayerRenderer->ChangeAnimation("Charge");

		TimeEventComponent->AddEndEvent(1.0f, [this]()
			{
				bIsCharge = true;
			}, false
		);

		TimeEventComponent->AddEndEvent(2.0f, [this]()
			{
				bIsCharge = false;
			}, false
		);
	}

	if (UEngineInput::IsDown('W'))
	{

		if (true== bIsCharge && true == bIsGround)
		{
			PlayerRenderer->AddRelativeLocation(FVector{ 0.0f, 50.0f, 0.0f});
		}

	}
	
	if (UEngineInput::IsPress('E'))
	{
		if (false == bIsGround)
		{
			PlayerRenderer->ChangeAnimation("Rolling");
		}
	}

	if (UEngineInput::IsPress('R'))
	{
		PlayerRenderer->ChangeAnimation("Unicorn");
	}

	if (UEngineInput::IsDown('A'))
	{
		SkillRenderer->ChangeAnimation("WrathOfEnril");
		PlayerRenderer->ChangeAnimation("Wrath");
		
		SkillRenderer->SetRelativeLocation(FVector{ -200.0f, -200.0f, -3.1f });
		PlayerRenderer->SetRelativeLocation(FVector{ 0.0f, 0.0f, -3.5f });
	}

		
	if (UEngineInput::IsDown('S'))
	{
		PlayerRenderer->ChangeAnimation("StrikeDualShot");

	}

	if (UEngineInput::IsDown('D'))
	{
		SkillRenderer->ChangeAnimation("LeafTornadoUp");
		SubSkillRenderer->ChangeAnimation("LeafTornadoDown");
		PlayerRenderer->ChangeAnimation("Tornado");

		SkillRenderer->SetRelativeLocation(FVector{ 25.0f, -390.0f, -3.1f });
		SubSkillRenderer->SetRelativeLocation(FVector{ 25.0f, -390.0f, -3.6f });
		PlayerRenderer->SetRelativeLocation(FVector{ 0.0f, 0.0f, -3.5f });
	}

	if (UEngineInput::IsPress('F'))
	{
		if (false == bIsGround)
		{
			
		}
	}

	if (UEngineInput::IsPress('G'))
	{
		PlayerRenderer->ChangeAnimation("LegendarySpear");
	}

	if (UEngineInput::IsPress('H'))
	{
		PlayerRenderer->ChangeAnimation("Jump");
	}
}
