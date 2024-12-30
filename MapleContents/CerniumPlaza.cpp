#include "PreCompile.h"
#include "CerniumPlaza.h"


#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>



ACerniumPlaza::ACerniumPlaza()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;
	
	{
		Plaza = CreateDefaultSubObject<USpriteRenderer>();
		Plaza->SetSprite("Cernium", 0);
		Plaza->SetupAttachment(RootComponent);
		Plaza->SetScale3D({ 4830.0f , 1590.0f });
		Plaza->SetRelativeLocation({ 0, -390 });
	}

	{
		std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
		RootComponent = Default;

		Smithy = CreateDefaultSubObject<USpriteRenderer>();

		Smithy->SetupAttachment(RootComponent);
		Smithy->CreateAnimation("Smithy", "Smithy", 0, 8, 0.15f);
		USpriteRenderer::FrameAnimation* Animation = Smithy->FindAnimation("Smithy");
		Smithy->ChangeAnimation("Smithy");
		Smithy->SetRelativeLocation({ -1100.0f, -130.0f });
		Animation->IsAutoScale = true;
		Animation->AutoScaleRatio = 1.0f;
	}

	{
		BuildingLeft_0 = CreateDefaultSubObject<USpriteRenderer>();
		BuildingLeft_0->SetSprite("Cernium", 1);
		BuildingLeft_0->SetupAttachment(RootComponent);
		BuildingLeft_0->SetScale3D({ 478.0f , 678.0f });
		BuildingLeft_0->SetRelativeLocation({ -1370, -150 });
	}
	
	{
		BuildingLeft_1 = CreateDefaultSubObject<USpriteRenderer>();
		BuildingLeft_1->SetSprite("Cernium", 2);
		BuildingLeft_1->SetupAttachment(RootComponent);
		BuildingLeft_1->SetScale3D({ 1200.0f , 1200.0f });
		BuildingLeft_1->SetRelativeLocation({ -1850, -333 });
	}

	{
		std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
		RootComponent = Default;

		Potion = CreateDefaultSubObject<USpriteRenderer>();

		Potion->SetupAttachment(RootComponent);
		Potion->CreateAnimation("Potion", "Potion", 0, 15, 0.15f);
		USpriteRenderer::FrameAnimation* Animation = Potion->FindAnimation("Potion");
		Potion->ChangeAnimation("Potion");
		Potion->SetRelativeLocation({ 1160.0f, -130.0f });
		Animation->IsAutoScale = true;
		Animation->AutoScaleRatio = 1.0f;
	}

	{
		BuildingRight_0 = CreateDefaultSubObject<USpriteRenderer>();
		BuildingRight_0->SetSprite("Cernium", 3);
		BuildingRight_0->SetupAttachment(RootComponent);
		BuildingRight_0->SetScale3D({ 478.0f , 678.0f });
		BuildingRight_0->SetRelativeLocation({ 1400, -150 });
	}

	{
		BuildingRight_1 = CreateDefaultSubObject<USpriteRenderer>();
		BuildingRight_1->SetSprite("Cernium", 4);
		BuildingRight_1->SetupAttachment(RootComponent);
		BuildingRight_1->SetScale3D({ 1200.0f , 1200.0f });
		BuildingRight_1->SetRelativeLocation({ 1830, -310 });
	}

}


ACerniumPlaza::~ACerniumPlaza()
{
}

void ACerniumPlaza::BeginPlay()
{
	AActor::BeginPlay();
}

void ACerniumPlaza::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	
	
}