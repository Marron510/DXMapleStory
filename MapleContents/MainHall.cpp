#include "PreCompile.h"
#include "MainHall.h"


#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>

#include "MapleEnum.h"

AMainHall::AMainHall()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// ÄÝ¸®Àü
	Collision = CreateDefaultSubObject<UCollision>();
	Collision->SetupAttachment(RootComponent);
	Collision->SetCollisionProfileName("Ground");

	Collision->SetScale3D({ 2274.0f, 300.0f });
	Collision->SetRelativeLocation(FVector{ MapSizeHalfX, -430.0f - MapSizeDefaultY,  static_cast<float>(EMapleZEnum::Player) });

	{
		MainHall_Sky = CreateDefaultSubObject<USpriteRenderer>();
		MainHall_Sky->SetSprite("MainHall", 4);
		MainHall_Sky->SetupAttachment(RootComponent);
		MainHall_Sky->SetScale3D({ 1266.0f , 476.0f });
		MainHall_Sky->SetRelativeLocation({ MapSizeHalfX,  - MapSizeDefaultY - 86.0f, static_cast<float>(EMapleZEnum::BackGround_Back) });
	}

	{
		MainHall_Center = CreateDefaultSubObject<USpriteRenderer>();
		MainHall_Center->SetSprite("MainHall", 1);
		MainHall_Center->SetupAttachment(RootComponent);
		MainHall_Center->SetScale3D({ 564.0f , 388.0f });
		MainHall_Center->SetRelativeLocation({ MapSizeHalfX,  - MapSizeDefaultY - 104.0f , static_cast<float>(EMapleZEnum::BackGround_Mid) });
	}

	{
		MainHall = CreateDefaultSubObject<USpriteRenderer>();
		MainHall->SetSprite("MainHall", 0);
		MainHall->SetupAttachment(RootComponent);
		MainHall->SetScale3D({ 2290.0f , 304.0f });
		MainHall->SetRelativeLocation({ MapSizeHalfX, -390.0f - MapSizeDefaultY, static_cast<float>(EMapleZEnum::BackGround_Front)});
	}


	{
		std::shared_ptr<class USpriteRenderer> MainHall_Wall_Left = CreateDefaultSubObject<USpriteRenderer>();
		MainHall_Wall_Left->SetSprite("MainHall", 5);
		MainHall_Wall_Left->SetupAttachment(RootComponent);
		MainHall_Wall_Left->SetScale3D({ 810.0f , 920.0f });
		MainHall_Wall_Left->SetRelativeLocation({ MapSizeHalfX - 710.0f,- MapSizeDefaultY - 330.0f,  static_cast<float>(EMapleZEnum::Building_Back) });
	}

	{
		std::shared_ptr<class USpriteRenderer> MainHall_Wall_Right = CreateDefaultSubObject<USpriteRenderer>();
		MainHall_Wall_Right->SetSprite("MainHall", 6);
		MainHall_Wall_Right->SetupAttachment(RootComponent);
		MainHall_Wall_Right->SetScale3D({ 810.0f , 892.0f });
		MainHall_Wall_Right->SetRelativeLocation({ MapSizeHalfX + 710.0f, - MapSizeDefaultY - 310.0f,  static_cast<float>(EMapleZEnum::Building_Back) });
	}

	{
		MainHall_Pillar_Left = CreateDefaultSubObject<USpriteRenderer>();
		MainHall_Pillar_Left->SetSprite("MainHall", 2);
		MainHall_Pillar_Left->SetupAttachment(RootComponent);
		MainHall_Pillar_Left->SetScale3D({ 1054.0f , 748.0f });
		MainHall_Pillar_Left->SetRelativeLocation({ MapSizeHalfX - 520.0f, -240.0f - MapSizeDefaultY,  static_cast<float>(EMapleZEnum::Building_Front) });
	}

	{
		MainHall_Pillar_Right = CreateDefaultSubObject<USpriteRenderer>();
		MainHall_Pillar_Right->SetSprite("MainHall", 3);
		MainHall_Pillar_Right->SetupAttachment(RootComponent);
		MainHall_Pillar_Right->SetScale3D({ 1050.0f , 748.0f });
		MainHall_Pillar_Right->SetRelativeLocation({ MapSizeHalfX + 520.0f, -240.0f - MapSizeDefaultY,  static_cast<float>(EMapleZEnum::Building_Front) });
	}




}

AMainHall::~AMainHall()
{
}


void AMainHall::BeginPlay()
{
	AActor::BeginPlay();
}

void AMainHall::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);


}
