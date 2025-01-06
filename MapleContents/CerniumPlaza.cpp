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
		Plaza->SetRelativeLocation({ 0, -390, -1.0f});
	}



	// 깃발
	{
		RootComponent = Default;

		Flag0 = CreateDefaultSubObject<USpriteRenderer>();

		Flag0->SetupAttachment(RootComponent);
		Flag0->CreateAnimation("Flag", "Flag.png", 0, 6, 0.1f);
		USpriteRenderer::FrameAnimation* Animation = Flag0->FindAnimation("Flag");
		Flag0->ChangeAnimation("Flag");
		Flag0->SetRelativeLocation({ -334.0f, 374.0f , -2.0f});
	}
	{
		RootComponent = Default;

		Flag1 = CreateDefaultSubObject<USpriteRenderer>();

		Flag1->SetupAttachment(RootComponent);
		Flag1->CreateAnimation("Flag", "Flag.png", 0, 6, 0.1f);
		USpriteRenderer::FrameAnimation* Animation = Flag1->FindAnimation("Flag");
		Flag1->ChangeAnimation("Flag");
		Flag1->SetRelativeLocation({ -800.0f, 484.0f , -2.0f });
	}

	{
		RootComponent = Default;

		Flag2 = CreateDefaultSubObject<USpriteRenderer>();

		Flag2->SetupAttachment(RootComponent);
		Flag2->CreateAnimation("Flag", "Flag.png", 0, 6, 0.1f);
		USpriteRenderer::FrameAnimation* Animation = Flag2->FindAnimation("Flag");
		Flag2->ChangeAnimation("Flag");
		Flag2->SetRelativeLocation({ -1302.0f, 638.0f , -2.0f });
	}


	{
		RootComponent = Default;

		Flag3 = CreateDefaultSubObject<USpriteRenderer>();

		Flag3->SetupAttachment(RootComponent);
		Flag3->CreateAnimation("Flag", "Flag.png", 0, 6, 0.1f);
		USpriteRenderer::FrameAnimation* Animation = Flag3->FindAnimation("Flag");
		Flag3->ChangeAnimation("Flag");
		Flag3->SetRelativeLocation({ 364.0f, 374.0f , -2.0f });
	}
	{
		RootComponent = Default;

		Flag4 = CreateDefaultSubObject<USpriteRenderer>();

		Flag4->SetupAttachment(RootComponent);
		Flag4->CreateAnimation("Flag", "Flag.png", 0, 6, 0.1f);
		USpriteRenderer::FrameAnimation* Animation = Flag4->FindAnimation("Flag");
		Flag4->ChangeAnimation("Flag");
		Flag4->SetRelativeLocation({ 840.0f, 484.0f , -2.0f });
	}

	{
		RootComponent = Default;

		Flag5 = CreateDefaultSubObject<USpriteRenderer>();

		Flag5->SetupAttachment(RootComponent);
		Flag5->CreateAnimation("Flag", "Flag.png", 0, 6, 0.1f);
		USpriteRenderer::FrameAnimation* Animation = Flag5->FindAnimation("Flag");
		Flag5->ChangeAnimation("Flag");
		Flag5->SetRelativeLocation({ 1328.0f, 638.0f , -2.0f });
	}

	// 왼쪽 건물

	{
		RootComponent = Default;

		Smithy = CreateDefaultSubObject<USpriteRenderer>();

		Smithy->SetupAttachment(RootComponent);
		Smithy->CreateAnimation("Smithy", "Smithy", 0, 8, 0.15f);
		USpriteRenderer::FrameAnimation* Animation = Smithy->FindAnimation("Smithy");
		Smithy->ChangeAnimation("Smithy");
		Smithy->SetRelativeLocation({ -1100.0f, -130.0f , -3.0f });
	}

	{
		BuildingLeft_0 = CreateDefaultSubObject<USpriteRenderer>();
		BuildingLeft_0->SetSprite("Cernium", 1);
		BuildingLeft_0->SetupAttachment(RootComponent);
		BuildingLeft_0->SetRelativeLocation({ -1370, -150 , -3.1f });
	}
	
	{
		BuildingLeft_1 = CreateDefaultSubObject<USpriteRenderer>();
		BuildingLeft_1->SetSprite("Cernium", 2);
		BuildingLeft_1->SetupAttachment(RootComponent);
		BuildingLeft_1->SetRelativeLocation({ -1850, -333 , -3.2f });
	}

	// 오른쪽 건물

	{
		RootComponent = Default;

		Potion = CreateDefaultSubObject<USpriteRenderer>();

		Potion->SetupAttachment(RootComponent);
		Potion->CreateAnimation("Potion", "Potion", 0, 15, 0.15f);
		USpriteRenderer::FrameAnimation* Animation = Potion->FindAnimation("Potion");
		Potion->ChangeAnimation("Potion");
		Potion->SetRelativeLocation({ 1160.0f, -130.0f , -3.0f });
	}

	{
		BuildingRight_0 = CreateDefaultSubObject<USpriteRenderer>();
		BuildingRight_0->SetSprite("Cernium", 3);
		BuildingRight_0->SetupAttachment(RootComponent);
		BuildingRight_0->SetRelativeLocation({ 1400, -150 , -3.1f });
	}

	{
		BuildingRight_1 = CreateDefaultSubObject<USpriteRenderer>();
		BuildingRight_1->SetSprite("Cernium", 4);
		BuildingRight_1->SetupAttachment(RootComponent);
		BuildingRight_1->SetRelativeLocation({ 1830, -310 , -3.2f });
	}

	// Object

	{
		DawnPriestFlag = CreateDefaultSubObject<USpriteRenderer>();
		DawnPriestFlag->SetSprite("Cernium", 5);
		DawnPriestFlag->SetupAttachment(RootComponent);
		DawnPriestFlag->SetRelativeLocation({ -1700, -182 , -3.0f });
	}

	{
		FirePriestFlag = CreateDefaultSubObject<USpriteRenderer>();
		FirePriestFlag->SetSprite("Cernium", 6);
		FirePriestFlag->SetupAttachment(RootComponent);
		FirePriestFlag->SetRelativeLocation({ 1700, -182, -3.0f });
	}

	{
		Tree_0 = CreateDefaultSubObject<USpriteRenderer>();
		Tree_0->SetSprite("Cernium", 7);
		Tree_0->SetupAttachment(RootComponent);
		Tree_0->SetRelativeLocation({ -1860, -182 , -3.0f });
	}

	{
		Tree_1 = CreateDefaultSubObject<USpriteRenderer>();
		Tree_1->SetSprite("Cernium", 7);
		Tree_1->SetupAttachment(RootComponent);
		Tree_1->SetRelativeLocation({ 1890, -182 , -3.0f });
	}


	{
		FootHold_Left_0 = CreateDefaultSubObject<USpriteRenderer>();
		FootHold_Left_0->SetSprite("Cernium", 8);
		FootHold_Left_0->SetupAttachment(RootComponent);
		FootHold_Left_0->SetRelativeLocation({ 422, 255 , -3.3f });
	}

	{
		FootHold_Left_1 = CreateDefaultSubObject<USpriteRenderer>();
		FootHold_Left_1->SetSprite("Cernium", 8);
		FootHold_Left_1->SetupAttachment(RootComponent);
		FootHold_Left_1->SetRelativeLocation({ 818, 405 , -3.3f });
	}

	{
		FootHold_Mid = CreateDefaultSubObject<USpriteRenderer>();
		FootHold_Mid->SetSprite("Cernium", 9);
		FootHold_Mid->SetupAttachment(RootComponent);
		FootHold_Mid->SetRelativeLocation({ 954, 404 , -3.3f });
	}

	{
		FootHold_Right = CreateDefaultSubObject<USpriteRenderer>();
		FootHold_Right->SetSprite("Cernium", 10);
		FootHold_Right->SetupAttachment(RootComponent);
		FootHold_Right->SetRelativeLocation({ -782, 405, -3.3f });
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