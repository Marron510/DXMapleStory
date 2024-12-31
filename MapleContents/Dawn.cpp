#include "PreCompile.h"
#include "Dawn.h"


#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>


ADawn::ADawn()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();

	RootComponent = Default;

	{
		std::shared_ptr<class USpriteRenderer> Dawn_Sky = CreateDefaultSubObject<USpriteRenderer>();
		Dawn_Sky->SetSprite("03_MidnightImage", 0);
		Dawn_Sky->SetupAttachment(RootComponent);
		Dawn_Sky->SetScale3D({ 1832.0f , 952.0f });
		Dawn_Sky->SetRelativeLocation({ 0.0f, -500.0f }); 
	}

	{
		std::shared_ptr<class USpriteRenderer> Dawn_Moon_LeftUp = CreateDefaultSubObject<USpriteRenderer>();
		Dawn_Moon_LeftUp->SetSprite("03_MidnightImage", 1);
		Dawn_Moon_LeftUp->SetupAttachment(RootComponent);
		Dawn_Moon_LeftUp->SetScale3D({ 748.0f , 514.0f });
		Dawn_Moon_LeftUp->SetRelativeLocation({ -340.0f, 40.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> Dawn_Moon_CenterUp = CreateDefaultSubObject<USpriteRenderer>();
		Dawn_Moon_CenterUp->SetSprite("03_MidnightImage", 2);
		Dawn_Moon_CenterUp->SetupAttachment(RootComponent);
		Dawn_Moon_CenterUp->SetScale3D({ 536.0f , 546.0f });
		Dawn_Moon_CenterUp->SetRelativeLocation({ 20.0f, 120.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> Dawn_Cloud_CenterBack = CreateDefaultSubObject<USpriteRenderer>();
		Dawn_Cloud_CenterBack->SetSprite("03_MidnightImage", 15);
		Dawn_Cloud_CenterBack->SetupAttachment(RootComponent);
		Dawn_Cloud_CenterBack->SetScale3D({ 534.0f , 200.0f });
		Dawn_Cloud_CenterBack->SetRelativeLocation({ 200.0f, 150.0f });
	}


	{
		std::shared_ptr<class USpriteRenderer> Dawn_Moon_RightMid = CreateDefaultSubObject<USpriteRenderer>();
		Dawn_Moon_RightMid->SetSprite("03_MidnightImage", 2);
		Dawn_Moon_RightMid->SetupAttachment(RootComponent);
		Dawn_Moon_RightMid->SetScale3D({ 536.0f , 546.0f });
		Dawn_Moon_RightMid->SetRelativeLocation({ 300.0f, -100.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> Dawn_Castle = CreateDefaultSubObject<USpriteRenderer>();
		Dawn_Castle->SetSprite("03_MidnightImage", 4);
		Dawn_Castle->SetupAttachment(RootComponent);
		Dawn_Castle->SetScale3D({ 590.0f , 76.0f });
		Dawn_Castle->SetRelativeLocation({ -50.0f, -44.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> Dawn_Cloud_LeftBottomBack = CreateDefaultSubObject<USpriteRenderer>();
		Dawn_Cloud_LeftBottomBack->SetSprite("03_MidnightImage", 5);
		Dawn_Cloud_LeftBottomBack->SetupAttachment(RootComponent);
		Dawn_Cloud_LeftBottomBack->SetScale3D({ 1600.0f , 220.0f });
		Dawn_Cloud_LeftBottomBack->SetRelativeLocation({ -760.0f, -210.0f });
	}



	{
		std::shared_ptr<class USpriteRenderer> Dawn_Cloud_LeftCenter = CreateDefaultSubObject<USpriteRenderer>();
		Dawn_Cloud_LeftCenter->SetSprite("03_MidnightImage", 6);
		Dawn_Cloud_LeftCenter->SetupAttachment(RootComponent);
		Dawn_Cloud_LeftCenter->SetScale3D({ 496.0f , 210.0f });
		Dawn_Cloud_LeftCenter->SetRelativeLocation({ -310.0f, -20.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> Dawn_Cloud_RightUP = CreateDefaultSubObject<USpriteRenderer>();
		Dawn_Cloud_RightUP->SetSprite("03_MidnightImage", 6);
		Dawn_Cloud_RightUP->SetupAttachment(RootComponent);
		Dawn_Cloud_RightUP->SetScale3D({ 496.0f , 210.0f });
		Dawn_Cloud_RightUP->SetRelativeLocation({ 580.0f, 150.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> Dawn_Cloud_RightBack = CreateDefaultSubObject<USpriteRenderer>();
		Dawn_Cloud_RightBack->SetSprite("03_MidnightImage", 8);
		Dawn_Cloud_RightBack->SetupAttachment(RootComponent);
		Dawn_Cloud_RightBack->SetScale3D({ 1440.0f , 440.0f });
		Dawn_Cloud_RightBack->SetRelativeLocation({ 1000.0f, 100.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> Dawn_Cloud_LeftBot = CreateDefaultSubObject<USpriteRenderer>();
		Dawn_Cloud_LeftBot->SetSprite("03_MidnightImage", 7);
		Dawn_Cloud_LeftBot->SetupAttachment(RootComponent);
		Dawn_Cloud_LeftBot->SetScale3D({ 1116.0f , 466.0f });
		Dawn_Cloud_LeftBot->SetRelativeLocation({ -600.0f, -250.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> Dawn_Cloud_RightBot = CreateDefaultSubObject<USpriteRenderer>();
		Dawn_Cloud_RightBot->SetSprite("03_MidnightImage", 7);
		Dawn_Cloud_RightBot->SetupAttachment(RootComponent);
		Dawn_Cloud_RightBot->SetScale3D({ 1068.0f , 466.0f });
		Dawn_Cloud_RightBot->SetRelativeLocation({ 650.0f, -200.0f });
	}
	{
		std::shared_ptr<class USpriteRenderer> Dawn_Cliff1 = CreateDefaultSubObject<USpriteRenderer>();
		Dawn_Cliff1->SetSprite("03_MidnightImage", 9);
		Dawn_Cliff1->SetupAttachment(RootComponent);
		Dawn_Cliff1->SetScale3D({ 224.0f , 546.0f });
		Dawn_Cliff1->SetRelativeLocation({ -806.0f, -200.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> Dawn_Cliff2 = CreateDefaultSubObject<USpriteRenderer>();
		Dawn_Cliff2->SetSprite("03_MidnightImage", 10);
		Dawn_Cliff2->SetupAttachment(RootComponent);
		Dawn_Cliff2->SetScale3D({ 248.0f , 654.0f });
		Dawn_Cliff2->SetRelativeLocation({ 792.0f, -210.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> Dawn_Floor = CreateDefaultSubObject<USpriteRenderer>();
		Dawn_Floor->SetSprite("03_MidnightImage", 11);
		Dawn_Floor->SetupAttachment(RootComponent);
		Dawn_Floor->SetScale3D({ 1832.0f , 952.0f });
		Dawn_Floor->SetRelativeLocation({ 0.0f, -440.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> Dawn_Stone1 = CreateDefaultSubObject<USpriteRenderer>();
		Dawn_Stone1->SetSprite("03_MidnightImage", 12);
		Dawn_Stone1->SetupAttachment(RootComponent);
		Dawn_Stone1->SetScale3D({ 180.0f , 130.0f });
		Dawn_Stone1->SetRelativeLocation({ -340.0f, -246.0f });
	}


	{
		std::shared_ptr<class USpriteRenderer> Dawn_Stone2 = CreateDefaultSubObject<USpriteRenderer>();
		Dawn_Stone2->SetSprite("03_MidnightImage", 13);
		Dawn_Stone2->SetupAttachment(RootComponent);
		Dawn_Stone2->SetScale3D({ 312.0f , 114.0f });
		Dawn_Stone2->SetRelativeLocation({ 300.0f, -246.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> Dawn_Fog_BottomLeft = CreateDefaultSubObject<USpriteRenderer>();
		Dawn_Fog_BottomLeft->SetSprite("03_MidnightImage", 14);
		Dawn_Fog_BottomLeft->SetupAttachment(RootComponent);
		Dawn_Fog_BottomLeft->SetScale3D({ 972.0f , 366.0f });
		Dawn_Fog_BottomLeft->SetRelativeLocation({ -600.0f, -400.0f });
	}

	{
		std::shared_ptr<class USpriteRenderer> Dawn_Fog_BottomRight = CreateDefaultSubObject<USpriteRenderer>();
		Dawn_Fog_BottomRight->SetSprite("03_MidnightImage", 14);
		Dawn_Fog_BottomRight->SetupAttachment(RootComponent);
		Dawn_Fog_BottomRight->SetScale3D({ 972.0f , 366.0f });
		Dawn_Fog_BottomRight->SetRelativeLocation({ 600.0f, -400.0f });
	}
}

ADawn::~ADawn()
{

}

void ADawn::BeginPlay()
{
	AActor::BeginPlay();
}


void ADawn::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}