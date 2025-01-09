#include "PreCompile.h"
#include "CerniumPlaza.h"
#include <EnginePlatform/EngineInput.h>

#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

#include "MapleEnum.h"

ACerniumPlaza::ACerniumPlaza()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;
	

	{
		Plaza_Front = CreateDefaultSubObject<USpriteRenderer>();
		Plaza_Front->SetSprite("Cernium", 0);
		Plaza_Front->SetupAttachment(RootComponent);
		Plaza_Front->SetRelativeLocation({ 2415.0f, -160.0f, static_cast<float>(EMapleZEnum::BackGround_Front)});
	}

	{
		Plaza_Mid = CreateDefaultSubObject<USpriteRenderer>();
		Plaza_Mid->SetSprite("Cernium", 14);
		Plaza_Mid->SetupAttachment(RootComponent);
		Plaza_Mid->SetRelativeLocation({ 2415.0f, -160.0f, static_cast<float>(EMapleZEnum::BackGround_Mid) });
	}

	{
		Plaza_Back = CreateDefaultSubObject<USpriteRenderer>();
		Plaza_Back->SetSprite("Cernium", 13);
		Plaza_Back->SetupAttachment(RootComponent);
		Plaza_Back->SetRelativeLocation({ 2415.0f, -160.0f, static_cast<float>(EMapleZEnum::BackGround_Back) });
	}
	
	// 깃발
	{
		Flag0 = CreateDefaultSubObject<USpriteRenderer>();

		Flag0->SetupAttachment(RootComponent);
		Flag0->CreateAnimation("Flag", "Flag.png", 0, 6, 0.1f);
		USpriteRenderer::FrameAnimation* Animation = Flag0->FindAnimation("Flag");
		Flag0->ChangeAnimation("Flag");
		Flag0->SetRelativeLocation({ -334.0f + 2415.0f, 374.0f + 230.0f , static_cast<float>(EMapleZEnum::Object_Front) });
	}
	{
		Flag1 = CreateDefaultSubObject<USpriteRenderer>();

		Flag1->SetupAttachment(RootComponent);
		Flag1->CreateAnimation("Flag", "Flag.png", 0, 6, 0.1f);
		USpriteRenderer::FrameAnimation* Animation = Flag1->FindAnimation("Flag");
		Flag1->ChangeAnimation("Flag");
		Flag1->SetRelativeLocation({ -800.0f + 2415.0f, 484.0f + 230.0f , static_cast<float>(EMapleZEnum::Object_Front) });
	}

	{
		Flag2 = CreateDefaultSubObject<USpriteRenderer>();

		Flag2->SetupAttachment(RootComponent);
		Flag2->CreateAnimation("Flag", "Flag.png", 0, 6, 0.1f);
		USpriteRenderer::FrameAnimation* Animation = Flag2->FindAnimation("Flag");
		Flag2->ChangeAnimation("Flag");
		Flag2->SetRelativeLocation({ -1302.0f + 2415.0f, 638.0f + 230.0f , static_cast<float>(EMapleZEnum::Object_Front) });
	}


	{
		Flag3 = CreateDefaultSubObject<USpriteRenderer>();

		Flag3->SetupAttachment(RootComponent);
		Flag3->CreateAnimation("Flag", "Flag.png", 0, 6, 0.1f);
		USpriteRenderer::FrameAnimation* Animation = Flag3->FindAnimation("Flag");
		Flag3->ChangeAnimation("Flag");
		Flag3->SetRelativeLocation({ 364.0f + 2415.0f, 374.0f + 230.0f , static_cast<float>(EMapleZEnum::Object_Front) });
	}
	{
		Flag4 = CreateDefaultSubObject<USpriteRenderer>();

		Flag4->SetupAttachment(RootComponent);
		Flag4->CreateAnimation("Flag", "Flag.png", 0, 6, 0.1f);
		USpriteRenderer::FrameAnimation* Animation = Flag4->FindAnimation("Flag");
		Flag4->ChangeAnimation("Flag");
		Flag4->SetRelativeLocation({ 840.0f + 2415.0f, 484.0f + 230.0f , static_cast<float>(EMapleZEnum::Object_Front) });
	}

	{
		Flag5 = CreateDefaultSubObject<USpriteRenderer>();

		Flag5->SetupAttachment(RootComponent);
		Flag5->CreateAnimation("Flag", "Flag.png", 0, 6, 0.1f);
		USpriteRenderer::FrameAnimation* Animation = Flag5->FindAnimation("Flag");
		Flag5->ChangeAnimation("Flag");
		Flag5->SetRelativeLocation({ 1328.0f + 2415.0f, 638.0f + 230.0f, static_cast<float>(EMapleZEnum::Object_Front) });
	}

	// 왼쪽 건물

	{
		Smithy = CreateDefaultSubObject<USpriteRenderer>();

		Smithy->SetupAttachment(RootComponent);
		Smithy->CreateAnimation("Smithy", "Smithy", 0, 8, 0.15f);
		USpriteRenderer::FrameAnimation* Animation = Smithy->FindAnimation("Smithy");
		Smithy->ChangeAnimation("Smithy");
		Smithy->SetRelativeLocation({ -1100.0f + 2415.0f, -130.0f + 230.0f , static_cast<float>(EMapleZEnum::Building_Back) });
	}

	{
		BuildingLeft_0 = CreateDefaultSubObject<USpriteRenderer>();
		BuildingLeft_0->SetSprite("Cernium", 1);
		BuildingLeft_0->SetupAttachment(RootComponent);
		BuildingLeft_0->SetRelativeLocation({ -1370 + 2415.0f, -150.0f + 230.0f , static_cast<float>(EMapleZEnum::Building_Mid3) });
	}
	
	{
		BuildingLeft_1 = CreateDefaultSubObject<USpriteRenderer>();
		BuildingLeft_1->SetSprite("Cernium", 2);
		BuildingLeft_1->SetupAttachment(RootComponent);
		BuildingLeft_1->SetRelativeLocation({ -1850 + 2415.0f, -333.0f + 230.0f , static_cast<float>(EMapleZEnum::Building_Mid2)});
	}

	// 오른쪽 건물

	{
		Potion = CreateDefaultSubObject<USpriteRenderer>();

		Potion->SetupAttachment(RootComponent);
		Potion->CreateAnimation("Potion", "Potion", 0, 15, 0.15f);
		USpriteRenderer::FrameAnimation* Animation = Potion->FindAnimation("Potion");
		Potion->ChangeAnimation("Potion");
		Potion->SetRelativeLocation({ 1160.0f + 2415.0f, -130.0f + 230.0f , static_cast<float>(EMapleZEnum::Building_Back) });
	}

	{
		BuildingRight_0 = CreateDefaultSubObject<USpriteRenderer>();
		BuildingRight_0->SetSprite("Cernium", 3);
		BuildingRight_0->SetupAttachment(RootComponent);
		BuildingRight_0->SetRelativeLocation({ 1400.0f + 2415.0f, -150.0f + 230.0f , static_cast<float>(EMapleZEnum::Building_Mid3) });
	}

	{
		BuildingRight_1 = CreateDefaultSubObject<USpriteRenderer>();
		BuildingRight_1->SetSprite("Cernium", 4);
		BuildingRight_1->SetupAttachment(RootComponent);
		BuildingRight_1->SetRelativeLocation({ 1830 + 2415.0f, -310.0f + 230.0f , static_cast<float>(EMapleZEnum::Building_Mid2) });
	}

	// Object


	{
		Tree_0 = CreateDefaultSubObject<USpriteRenderer>();
		Tree_0->SetSprite("Cernium", 7);
		Tree_0->SetupAttachment(RootComponent);
		Tree_0->SetRelativeLocation({ -1860.0f + 2415.0f, -182.0f + 230.0f , static_cast<float>(EMapleZEnum::Building_Mid1) });
	}

	{
		Tree_1 = CreateDefaultSubObject<USpriteRenderer>();
		Tree_1->SetSprite("Cernium", 7);
		Tree_1->SetupAttachment(RootComponent);
		Tree_1->SetRelativeLocation({ 1890.0f + 2415.0f, -182.0f + 230.0f , static_cast<float>(EMapleZEnum::Building_Mid1) });
	}

	{
		DawnPriestFlag = CreateDefaultSubObject<USpriteRenderer>();
		DawnPriestFlag->SetSprite("Cernium", 5);
		DawnPriestFlag->SetupAttachment(RootComponent);
		DawnPriestFlag->SetRelativeLocation({ -1700.0f + 2415.0f, -182.0f + 230.0f , static_cast<float>(EMapleZEnum::Building_Mid1) });
	}

	{
		FirePriestFlag = CreateDefaultSubObject<USpriteRenderer>();
		FirePriestFlag->SetSprite("Cernium", 6);
		FirePriestFlag->SetupAttachment(RootComponent);
		FirePriestFlag->SetRelativeLocation({ 1700.0f + 2415.0f, -182.0f + 230.0f, static_cast<float>(EMapleZEnum::Building_Mid1) });
	}

	{
		FootHold_Left_0 = CreateDefaultSubObject<USpriteRenderer>();
		FootHold_Left_0->SetSprite("Cernium", 8);
		FootHold_Left_0->SetupAttachment(RootComponent);
		FootHold_Left_0->SetRelativeLocation({ 422.0f + 2415.0f, 255.0f + 230.0f , static_cast<float>(EMapleZEnum::Front_Object1) });
	}

	{
		FootHold_Left_1 = CreateDefaultSubObject<USpriteRenderer>();
		FootHold_Left_1->SetSprite("Cernium", 8);
		FootHold_Left_1->SetupAttachment(RootComponent);
		FootHold_Left_1->SetRelativeLocation({ 818.0f + 2415.0f, 405.0f + 230.0f , static_cast<float>(EMapleZEnum::Front_Object1) });
	}

	{
		FootHold_Mid = CreateDefaultSubObject<USpriteRenderer>();
		FootHold_Mid->SetSprite("Cernium", 9);
		FootHold_Mid->SetupAttachment(RootComponent);
		FootHold_Mid->SetRelativeLocation({ 954.0f + 2415.0f, 404.0f + 230.0f , static_cast<float>(EMapleZEnum::Front_Object1) });
	}

	{
		FootHold_Right = CreateDefaultSubObject<USpriteRenderer>();
		FootHold_Right->SetSprite("Cernium", 10);
		FootHold_Right->SetupAttachment(RootComponent);
		FootHold_Right->SetRelativeLocation({ -782.0f + 2415.0f, 405.0f + 230.0f, static_cast<float>(EMapleZEnum::Front_Object1) });
	}

	{
		BigTree_Left = CreateDefaultSubObject<USpriteRenderer>();
		BigTree_Left->SetSprite("Cernium", 11);
		BigTree_Left->SetupAttachment(RootComponent);
		BigTree_Left->SetRelativeLocation({ -2180.0f + 2415.0f, -420.0f + 230.0f , static_cast<float>(EMapleZEnum::Front_Object3) });
	}

	{
		BigTree_Right = CreateDefaultSubObject<USpriteRenderer>();
		BigTree_Right->SetSprite("Cernium", 12);
		BigTree_Right->SetupAttachment(RootComponent);
		BigTree_Right->SetRelativeLocation({ 2200.0f + 2415.0f, -420.0f + 230.0f, static_cast<float>(EMapleZEnum::Front_Object3) });
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
