#include "PreCompile.h"
#include "SunSet.h"


#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>



ASunSet::ASunSet()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();

	RootComponent = Default;

	{
		std::shared_ptr<class USpriteRenderer> SunSet_Sky = CreateDefaultSubObject<USpriteRenderer>();
		SunSet_Sky->SetSprite("02_SunSetImage", 0);
		SunSet_Sky->SetupAttachment(RootComponent);
		SunSet_Sky->SetScale3D({ 1832.0f , 952.0f });
		SunSet_Sky->SetRelativeLocation({ 0.0f, -500.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> SunSet_Moon_LeftUp = CreateDefaultSubObject<USpriteRenderer>();
		SunSet_Moon_LeftUp->SetSprite("02_SunSetImage", 1);
		SunSet_Moon_LeftUp->SetupAttachment(RootComponent);
		SunSet_Moon_LeftUp->SetScale3D({ 840.0f , 832.0f });
		SunSet_Moon_LeftUp->SetRelativeLocation({ -340.0f, -140.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> SunSet_Moon_CenterUp = CreateDefaultSubObject<USpriteRenderer>();
		SunSet_Moon_CenterUp->SetSprite("02_SunSetImage", 2);
		SunSet_Moon_CenterUp->SetupAttachment(RootComponent);
		SunSet_Moon_CenterUp->SetScale3D({ 632.0f , 474.0f });
		SunSet_Moon_CenterUp->SetRelativeLocation({ 20.0f, 200.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> SunSet_Cloud_CenterBack = CreateDefaultSubObject<USpriteRenderer>();
		SunSet_Cloud_CenterBack->SetSprite("02_SunSetImage", 15);
		SunSet_Cloud_CenterBack->SetupAttachment(RootComponent);
		SunSet_Cloud_CenterBack->SetScale3D({ 534.0f , 200.0f });
		SunSet_Cloud_CenterBack->SetRelativeLocation({ 200.0f, 150.0f });
	}


	{
		std::shared_ptr<class USpriteRenderer> SunSet_Moon_RightMid = CreateDefaultSubObject<USpriteRenderer>();
		SunSet_Moon_RightMid->SetSprite("02_SunSetImage", 2);
		SunSet_Moon_RightMid->SetupAttachment(RootComponent);
		SunSet_Moon_RightMid->SetScale3D({ 632.0f , 474.0f });
		SunSet_Moon_RightMid->SetRelativeLocation({ 300.0f, -100.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> SunSet_Castle = CreateDefaultSubObject<USpriteRenderer>();
		SunSet_Castle->SetSprite("02_SunSetImage", 4);
		SunSet_Castle->SetupAttachment(RootComponent);
		SunSet_Castle->SetScale3D({ 590.0f , 76.0f });
		SunSet_Castle->SetRelativeLocation({ -50.0f, -54.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> SunSet_Cloud_LeftBottomBack = CreateDefaultSubObject<USpriteRenderer>();
		SunSet_Cloud_LeftBottomBack->SetSprite("02_SunSetImage", 5);
		SunSet_Cloud_LeftBottomBack->SetupAttachment(RootComponent);
		SunSet_Cloud_LeftBottomBack->SetScale3D({ 1600.0f , 220.0f });
		SunSet_Cloud_LeftBottomBack->SetRelativeLocation({ -760.0f, -210.0f });
	}



	{
		std::shared_ptr<class USpriteRenderer> SunSet_Cloud_LeftCenter = CreateDefaultSubObject<USpriteRenderer>();
		SunSet_Cloud_LeftCenter->SetSprite("02_SunSetImage", 6);
		SunSet_Cloud_LeftCenter->SetupAttachment(RootComponent);
		SunSet_Cloud_LeftCenter->SetScale3D({ 496.0f , 210.0f });
		SunSet_Cloud_LeftCenter->SetRelativeLocation({ -310.0f, 40.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> SunSet_Cloud_RightUP = CreateDefaultSubObject<USpriteRenderer>();
		SunSet_Cloud_RightUP->SetSprite("02_SunSetImage", 6);
		SunSet_Cloud_RightUP->SetupAttachment(RootComponent);
		SunSet_Cloud_RightUP->SetScale3D({ 496.0f , 210.0f });
		SunSet_Cloud_RightUP->SetRelativeLocation({ 580.0f, 190.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> SunSet_Cloud_RightBack = CreateDefaultSubObject<USpriteRenderer>();
		SunSet_Cloud_RightBack->SetSprite("02_SunSetImage", 8);
		SunSet_Cloud_RightBack->SetupAttachment(RootComponent);
		SunSet_Cloud_RightBack->SetScale3D({ 1440.0f , 440.0f });
		SunSet_Cloud_RightBack->SetRelativeLocation({ 1000.0f, 100.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> SunSet_Cloud_LeftBot = CreateDefaultSubObject<USpriteRenderer>();
		SunSet_Cloud_LeftBot->SetSprite("02_SunSetImage", 7);
		SunSet_Cloud_LeftBot->SetupAttachment(RootComponent);
		SunSet_Cloud_LeftBot->SetScale3D({ 1068.0f , 466.0f });
		SunSet_Cloud_LeftBot->SetRelativeLocation({ -600.0f, -250.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> SunSet_Cloud_RightBot = CreateDefaultSubObject<USpriteRenderer>();
		SunSet_Cloud_RightBot->SetSprite("02_SunSetImage", 7);
		SunSet_Cloud_RightBot->SetupAttachment(RootComponent);
		SunSet_Cloud_RightBot->SetScale3D({ 1068.0f , 466.0f });
		SunSet_Cloud_RightBot->SetRelativeLocation({ 650.0f, -200.0f });
	}
	{
		std::shared_ptr<class USpriteRenderer> SunSet_Cliff1 = CreateDefaultSubObject<USpriteRenderer>();
		SunSet_Cliff1->SetSprite("02_SunSetImage", 9);
		SunSet_Cliff1->SetupAttachment(RootComponent);
		SunSet_Cliff1->SetScale3D({ 224.0f , 546.0f });
		SunSet_Cliff1->SetRelativeLocation({ -806.0f, -200.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> SunSet_Cliff2 = CreateDefaultSubObject<USpriteRenderer>();
		SunSet_Cliff2->SetSprite("02_SunSetImage", 10);
		SunSet_Cliff2->SetupAttachment(RootComponent);
		SunSet_Cliff2->SetScale3D({ 248.0f , 654.0f });
		SunSet_Cliff2->SetRelativeLocation({ 792.0f, -210.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> SunSet_Floor = CreateDefaultSubObject<USpriteRenderer>();
		SunSet_Floor->SetSprite("02_SunSetImage", 11);
		SunSet_Floor->SetupAttachment(RootComponent);
		SunSet_Floor->SetScale3D({ 1832.0f , 952.0f });
		SunSet_Floor->SetRelativeLocation({ 0.0f, -440.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> SunSet_Stone1 = CreateDefaultSubObject<USpriteRenderer>();
		SunSet_Stone1->SetSprite("02_SunSetImage", 12);
		SunSet_Stone1->SetupAttachment(RootComponent);
		SunSet_Stone1->SetScale3D({ 180.0f , 130.0f });
		SunSet_Stone1->SetRelativeLocation({ -340.0f, -246.0f });
		SunSet_Stone1->SetOrder(1);
	}


	{
		std::shared_ptr<class USpriteRenderer> SunSet_Stone2 = CreateDefaultSubObject<USpriteRenderer>();
		SunSet_Stone2->SetSprite("02_SunSetImage", 13);
		SunSet_Stone2->SetupAttachment(RootComponent);
		SunSet_Stone2->SetScale3D({ 312.0f , 114.0f });
		SunSet_Stone2->SetRelativeLocation({ 300.0f, -246.0f });
		SunSet_Stone2->SetOrder(1);
	}
	
	{
		std::shared_ptr<class USpriteRenderer> SunSet_Fog_BottomLeft = CreateDefaultSubObject<USpriteRenderer>();
		SunSet_Fog_BottomLeft->SetSprite("02_SunSetImage", 14);
		SunSet_Fog_BottomLeft->SetupAttachment(RootComponent);
		SunSet_Fog_BottomLeft->SetScale3D({ 1040.0f , 366.0f });
		SunSet_Fog_BottomLeft->SetRelativeLocation({ -500.0f, -446.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> SunSet_Fog_BottomRight = CreateDefaultSubObject<USpriteRenderer>();
		SunSet_Fog_BottomRight->SetSprite("02_SunSetImage", 14);
		SunSet_Fog_BottomRight->SetupAttachment(RootComponent);
		SunSet_Fog_BottomRight->SetScale3D({ 1040.0f , 366.0f });
		SunSet_Fog_BottomRight->SetRelativeLocation({ 500.0f, -446.0f });
	}

}

ASunSet::~ASunSet()
{

}

void ASunSet::BeginPlay()
{
	AActor::BeginPlay();
}

void ASunSet::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}
