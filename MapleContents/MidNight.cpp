#include "PreCompile.h"
#include "MidNight.h"


#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>


AMidNight::AMidNight()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();

	RootComponent = Default;

	{
		std::shared_ptr<class USpriteRenderer> MidNight_Sky = CreateDefaultSubObject<USpriteRenderer>();
		MidNight_Sky->SetSprite("03_MidnightImage", 0);
		MidNight_Sky->SetupAttachment(RootComponent);
		MidNight_Sky->SetScale3D({ 1832.0f , 952.0f });
		MidNight_Sky->SetRelativeLocation({ 0.0f, -500.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> MidNight_Moon_LeftUp = CreateDefaultSubObject<USpriteRenderer>();
		MidNight_Moon_LeftUp->SetSprite("03_MidnightImage", 1);
		MidNight_Moon_LeftUp->SetupAttachment(RootComponent);
		MidNight_Moon_LeftUp->SetScale3D({ 748.0f , 514.0f });
		MidNight_Moon_LeftUp->SetRelativeLocation({ -340.0f, 40.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> MidNight_Moon_CenterUp = CreateDefaultSubObject<USpriteRenderer>();
		MidNight_Moon_CenterUp->SetSprite("03_MidnightImage", 2);
		MidNight_Moon_CenterUp->SetupAttachment(RootComponent);
		MidNight_Moon_CenterUp->SetScale3D({ 536.0f , 546.0f });
		MidNight_Moon_CenterUp->SetRelativeLocation({ 20.0f, 120.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> MidNight_Cloud_CenterBack = CreateDefaultSubObject<USpriteRenderer>();
		MidNight_Cloud_CenterBack->SetSprite("03_MidnightImage", 15);
		MidNight_Cloud_CenterBack->SetupAttachment(RootComponent);
		MidNight_Cloud_CenterBack->SetScale3D({ 534.0f , 200.0f });
		MidNight_Cloud_CenterBack->SetRelativeLocation({ 200.0f, 150.0f });
	}


	{
		std::shared_ptr<class USpriteRenderer> MidNight_Moon_RightMid = CreateDefaultSubObject<USpriteRenderer>();
		MidNight_Moon_RightMid->SetSprite("03_MidnightImage", 2);
		MidNight_Moon_RightMid->SetupAttachment(RootComponent);
		MidNight_Moon_RightMid->SetScale3D({ 536.0f , 546.0f });
		MidNight_Moon_RightMid->SetRelativeLocation({ 300.0f, -100.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> MidNight_Castle = CreateDefaultSubObject<USpriteRenderer>();
		MidNight_Castle->SetSprite("03_MidnightImage", 4);
		MidNight_Castle->SetupAttachment(RootComponent);
		MidNight_Castle->SetScale3D({ 590.0f , 76.0f });
		MidNight_Castle->SetRelativeLocation({ -50.0f, -44.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> MidNight_Cloud_LeftBottomBack = CreateDefaultSubObject<USpriteRenderer>();
		MidNight_Cloud_LeftBottomBack->SetSprite("03_MidnightImage", 5);
		MidNight_Cloud_LeftBottomBack->SetupAttachment(RootComponent);
		MidNight_Cloud_LeftBottomBack->SetScale3D({ 1600.0f , 220.0f });
		MidNight_Cloud_LeftBottomBack->SetRelativeLocation({ -760.0f, -210.0f });
	}



	{
		std::shared_ptr<class USpriteRenderer> MidNight_Cloud_LeftCenter = CreateDefaultSubObject<USpriteRenderer>();
		MidNight_Cloud_LeftCenter->SetSprite("03_MidnightImage", 6);
		MidNight_Cloud_LeftCenter->SetupAttachment(RootComponent);
		MidNight_Cloud_LeftCenter->SetScale3D({ 496.0f , 210.0f });
		MidNight_Cloud_LeftCenter->SetRelativeLocation({ -310.0f, -20.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> MidNight_Cloud_RightUP = CreateDefaultSubObject<USpriteRenderer>();
		MidNight_Cloud_RightUP->SetSprite("03_MidnightImage", 6);
		MidNight_Cloud_RightUP->SetupAttachment(RootComponent);
		MidNight_Cloud_RightUP->SetScale3D({ 496.0f , 210.0f });
		MidNight_Cloud_RightUP->SetRelativeLocation({ 580.0f, 150.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> MidNight_Cloud_RightBack = CreateDefaultSubObject<USpriteRenderer>();
		MidNight_Cloud_RightBack->SetSprite("03_MidnightImage", 8);
		MidNight_Cloud_RightBack->SetupAttachment(RootComponent);
		MidNight_Cloud_RightBack->SetScale3D({ 1440.0f , 440.0f });
		MidNight_Cloud_RightBack->SetRelativeLocation({ 1000.0f, 100.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> MidNight_Cloud_LeftBot = CreateDefaultSubObject<USpriteRenderer>();
		MidNight_Cloud_LeftBot->SetSprite("03_MidnightImage", 7);
		MidNight_Cloud_LeftBot->SetupAttachment(RootComponent);
		MidNight_Cloud_LeftBot->SetScale3D({ 1116.0f , 466.0f });
		MidNight_Cloud_LeftBot->SetRelativeLocation({ -600.0f, -250.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> MidNight_Cloud_RightBot = CreateDefaultSubObject<USpriteRenderer>();
		MidNight_Cloud_RightBot->SetSprite("03_MidnightImage", 7);
		MidNight_Cloud_RightBot->SetupAttachment(RootComponent);
		MidNight_Cloud_RightBot->SetScale3D({ 1116.0f , 466.0f });
		MidNight_Cloud_RightBot->SetRelativeLocation({ 650.0f, -200.0f });
	}
	{
		std::shared_ptr<class USpriteRenderer> MidNight_Cliff1 = CreateDefaultSubObject<USpriteRenderer>();
		MidNight_Cliff1->SetSprite("03_MidnightImage", 9);
		MidNight_Cliff1->SetupAttachment(RootComponent);
		MidNight_Cliff1->SetScale3D({ 224.0f , 546.0f });
		MidNight_Cliff1->SetRelativeLocation({ -806.0f, -200.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> MidNight_Cliff2 = CreateDefaultSubObject<USpriteRenderer>();
		MidNight_Cliff2->SetSprite("03_MidnightImage", 10);
		MidNight_Cliff2->SetupAttachment(RootComponent);
		MidNight_Cliff2->SetScale3D({ 248.0f , 654.0f });
		MidNight_Cliff2->SetRelativeLocation({ 792.0f, -210.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> MidNight_Floor = CreateDefaultSubObject<USpriteRenderer>();
		MidNight_Floor->SetSprite("03_MidnightImage", 11);
		MidNight_Floor->SetupAttachment(RootComponent);
		MidNight_Floor->SetScale3D({ 1832.0f , 952.0f });
		MidNight_Floor->SetRelativeLocation({ 0.0f, -440.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> MidNight_Stone1 = CreateDefaultSubObject<USpriteRenderer>();
		MidNight_Stone1->SetSprite("03_MidnightImage", 12);
		MidNight_Stone1->SetupAttachment(RootComponent);
		MidNight_Stone1->SetScale3D({ 180.0f , 130.0f });
		MidNight_Stone1->SetRelativeLocation({ -340.0f, -246.0f });
		MidNight_Stone1->SetOrder(1);
	}


	{
		std::shared_ptr<class USpriteRenderer> MidNight_Stone2 = CreateDefaultSubObject<USpriteRenderer>();
		MidNight_Stone2->SetSprite("03_MidnightImage", 13);
		MidNight_Stone2->SetupAttachment(RootComponent);
		MidNight_Stone2->SetScale3D({ 312.0f , 114.0f });
		MidNight_Stone2->SetRelativeLocation({ 300.0f, -246.0f });
		MidNight_Stone2->SetOrder(1);
	}

	{
		std::shared_ptr<class USpriteRenderer> MidNight_Fog_BottomLeft = CreateDefaultSubObject<USpriteRenderer>();
		MidNight_Fog_BottomLeft->SetSprite("03_MidnightImage", 14);
		MidNight_Fog_BottomLeft->SetupAttachment(RootComponent);
		MidNight_Fog_BottomLeft->SetScale3D({ 972.0f , 366.0f });
		MidNight_Fog_BottomLeft->SetRelativeLocation({ -600.0f, -400.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> MidNight_Fog_BottomRight = CreateDefaultSubObject<USpriteRenderer>();
		MidNight_Fog_BottomRight->SetSprite("03_MidnightImage", 14);
		MidNight_Fog_BottomRight->SetupAttachment(RootComponent);
		MidNight_Fog_BottomRight->SetScale3D({ 972.0f , 366.0f });
		MidNight_Fog_BottomRight->SetRelativeLocation({ 600.0f, -400.0f });
	}
}

AMidNight::~AMidNight()
{

}

void AMidNight::BeginPlay()
{
	AActor::BeginPlay();
}

void AMidNight::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}
