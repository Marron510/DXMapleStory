#include "PreCompile.h"
#include "Noon.h"


#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>



ANoon::ANoon()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	
	RootComponent = Default;

	{
		std::shared_ptr<class USpriteRenderer> Noon_Sky = CreateDefaultSubObject<USpriteRenderer>();
		Noon_Sky->SetSprite("01_NoonImage", 0);
		Noon_Sky->SetupAttachment(RootComponent);
		Noon_Sky->SetScale3D({ 1832.0f , 952.0f });
		Noon_Sky->SetRelativeLocation({ 0.0f, -500.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> Noon_Moon_LeftUp = CreateDefaultSubObject<USpriteRenderer>();
		Noon_Moon_LeftUp->SetSprite("01_NoonImage", 1);
		Noon_Moon_LeftUp->SetupAttachment(RootComponent);
		Noon_Moon_LeftUp->SetScale3D({ 748.0f , 474.0f });
		Noon_Moon_LeftUp->SetRelativeLocation({ -340.0f, 100.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> Noon_Moon_CenterUp = CreateDefaultSubObject<USpriteRenderer>();
		Noon_Moon_CenterUp->SetSprite("01_NoonImage", 2);
		Noon_Moon_CenterUp->SetupAttachment(RootComponent);
		Noon_Moon_CenterUp->SetScale3D({ 420.0f , 314.0f });
		Noon_Moon_CenterUp->SetRelativeLocation({ 20.0f, 300.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> Noon_Cloud_CenterBack = CreateDefaultSubObject<USpriteRenderer>();
		Noon_Cloud_CenterBack->SetSprite("01_NoonImage", 15);
		Noon_Cloud_CenterBack->SetupAttachment(RootComponent);
		Noon_Cloud_CenterBack->SetScale3D({ 532.0f , 200.0f });
		Noon_Cloud_CenterBack->SetRelativeLocation({ 200.0f, 190.0f });
	}


	{
		std::shared_ptr<class USpriteRenderer> Noon_Moon_RightMid = CreateDefaultSubObject<USpriteRenderer>();
		Noon_Moon_RightMid->SetSprite("01_NoonImage", 3);
		Noon_Moon_RightMid->SetupAttachment(RootComponent);
		Noon_Moon_RightMid->SetScale3D({ 420.0f , 314.0f });
		Noon_Moon_RightMid->SetRelativeLocation({ 340.0f, 0.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> Noon_Castle = CreateDefaultSubObject<USpriteRenderer>();
		Noon_Castle->SetSprite("01_NoonImage", 4);
		Noon_Castle->SetupAttachment(RootComponent);
		Noon_Castle->SetScale3D({ 584.0f , 74.0f });
		Noon_Castle->SetRelativeLocation({ -50.0f, -54.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> Noon_Cloud_LeftBottomBack = CreateDefaultSubObject<USpriteRenderer>();
		Noon_Cloud_LeftBottomBack->SetSprite("01_NoonImage", 5);
		Noon_Cloud_LeftBottomBack->SetupAttachment(RootComponent);
		Noon_Cloud_LeftBottomBack->SetScale3D({ 1600.0f , 220.0f });
		Noon_Cloud_LeftBottomBack->SetRelativeLocation({ -760.0f, -210.0f });
	}

	

	{
		std::shared_ptr<class USpriteRenderer> Noon_Cloud_LeftCenter = CreateDefaultSubObject<USpriteRenderer>();
		Noon_Cloud_LeftCenter->SetSprite("01_NoonImage", 6);
		Noon_Cloud_LeftCenter->SetupAttachment(RootComponent);
		Noon_Cloud_LeftCenter->SetScale3D({ 496.0f , 210.0f });
		Noon_Cloud_LeftCenter->SetRelativeLocation({ -310.0f, 40.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> Noon_Cloud_RightUP = CreateDefaultSubObject<USpriteRenderer>();
		Noon_Cloud_RightUP->SetSprite("01_NoonImage", 6);
		Noon_Cloud_RightUP->SetupAttachment(RootComponent);
		Noon_Cloud_RightUP->SetScale3D({ 496.0f , 210.0f });
		Noon_Cloud_RightUP->SetRelativeLocation({ 580.0f, 190.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> Noon_Cloud_LeftBot = CreateDefaultSubObject<USpriteRenderer>();
		Noon_Cloud_LeftBot->SetSprite("01_NoonImage", 7);
		Noon_Cloud_LeftBot->SetupAttachment(RootComponent);
		Noon_Cloud_LeftBot->SetScale3D({ 1166.0f , 466.0f });
		Noon_Cloud_LeftBot->SetRelativeLocation({ -600.0f, -250.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> Noon_Cloud_RightBot = CreateDefaultSubObject<USpriteRenderer>();
		Noon_Cloud_RightBot->SetSprite("01_NoonImage", 7);
		Noon_Cloud_RightBot->SetupAttachment(RootComponent);
		Noon_Cloud_RightBot->SetScale3D({ 1166.0f , 466.0f });
		Noon_Cloud_RightBot->SetRelativeLocation({ 650.0f, -250.0f });
	}
	{
		std::shared_ptr<class USpriteRenderer> Noon_Cliff1 = CreateDefaultSubObject<USpriteRenderer>();
		Noon_Cliff1->SetSprite("01_NoonImage", 9);
		Noon_Cliff1->SetupAttachment(RootComponent);
		Noon_Cliff1->SetScale3D({ 224.0f , 534.0f });
		Noon_Cliff1->SetRelativeLocation({ -806.0f, -200.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> Noon_Cliff2 = CreateDefaultSubObject<USpriteRenderer>();
		Noon_Cliff2->SetSprite("01_NoonImage", 10);
		Noon_Cliff2->SetupAttachment(RootComponent);
		Noon_Cliff2->SetScale3D({ 252.0f , 654.0f });
		Noon_Cliff2->SetRelativeLocation({ 792.0f, -210.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> Noon_Floor = CreateDefaultSubObject<USpriteRenderer>();
		Noon_Floor->SetSprite("01_NoonImage", 11);
		Noon_Floor->SetupAttachment(RootComponent);
		Noon_Floor->SetScale3D({ 1832.0f , 952.0f });
		Noon_Floor->SetRelativeLocation({ 0.0f, -440.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> Noon_Stone1 = CreateDefaultSubObject<USpriteRenderer>();
		Noon_Stone1->SetSprite("01_NoonImage", 12);
		Noon_Stone1->SetupAttachment(RootComponent);
		Noon_Stone1->SetScale3D({ 176.0f , 130.0f });
		Noon_Stone1->SetRelativeLocation({ -340.0f, -246.0f });
	}


	{
		std::shared_ptr<class USpriteRenderer> Noon_Stone2 = CreateDefaultSubObject<USpriteRenderer>();
		Noon_Stone2->SetSprite("01_NoonImage", 13);
		Noon_Stone2->SetupAttachment(RootComponent);
		Noon_Stone2->SetScale3D({ 304.0f , 114.0f });
		Noon_Stone2->SetRelativeLocation({ 300.0f, -246.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> Noon_Fog_BottomLeft = CreateDefaultSubObject<USpriteRenderer>();
		Noon_Fog_BottomLeft->SetSprite("01_NoonImage", 14);
		Noon_Fog_BottomLeft->SetupAttachment(RootComponent);
		Noon_Fog_BottomLeft->SetScale3D({ 1056.0f , 410.0f });
		Noon_Fog_BottomLeft->SetRelativeLocation({ -600.0f, -476.0f });
	}


	{
		std::shared_ptr<class USpriteRenderer> Noon_Fog_BottomRight = CreateDefaultSubObject<USpriteRenderer>();
		Noon_Fog_BottomRight->SetSprite("01_NoonImage", 14);
		Noon_Fog_BottomRight->SetupAttachment(RootComponent);
		Noon_Fog_BottomRight->SetScale3D({ 1056.0f , 410.0f });
		Noon_Fog_BottomRight->SetRelativeLocation({ 600.0f, -476.0f });
	}
}

ANoon::~ANoon()
{

}

void ANoon::BeginPlay()
{
	AActor::BeginPlay();
}

void ANoon::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}
