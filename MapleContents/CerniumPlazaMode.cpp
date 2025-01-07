#include "PreCompile.h"
#include "CerniumPlazaMode.h"

#include <EngineCore/CameraActor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineGUIWindow.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/DefaultSceneComponent.h>

#include "CerniumPlaza.h"

#include "DawnPriest.h"
#include "FirePriest.h"
#include "Hate.h"
#include "Shirine.h"
#include "Shorn.h"
#include "Joy.h"
#include "OldMan.h"
#include "Duglas.h"
#include "Manyu.h"
#include "Elbis.h"


#include "Player.h"
#include "SkillManager.h"
#include "WrathOfEnril.h"



ACerniumPlazaMode::ACerniumPlazaMode()
{

	
	// 맵
	{
		Plaza= GetWorld()->SpawnActor<ACerniumPlaza>();
	}
	
	

	//프리스트

	{
		std::shared_ptr<class ADawnPriest> DawnPriest = GetWorld()->SpawnActor<ADawnPriest>();
		DawnPriest->SetActorLocation(FVector{ -1500.0f, -230.0f , -3.4f });
		DawnPriest->SetActorRelativeScale3D(FVector{ -1.0f, 1.0f, 1.0f });
	}

	{
		std::shared_ptr<class ADawnPriest> DawnPriest = GetWorld()->SpawnActor<ADawnPriest>();
		DawnPriest->SetActorLocation(FVector{ -1430.0f, -150.0f , -3.4f });
		DawnPriest->SetActorRelativeScale3D(FVector{ -1.0f, 1.0f, 1.0f });
	}

	{
		std::shared_ptr<class ADawnPriest> DawnPriest = GetWorld()->SpawnActor<ADawnPriest>();
		DawnPriest->SetActorLocation(FVector{ -1600.0f, -180.0f , -3.4f });
		DawnPriest->SetActorRelativeScale3D(FVector{ -1.0f, 1.0f, 1.0f });
	}

	{
		std::shared_ptr<class AFirePriest> FirePriest = GetWorld()->SpawnActor<AFirePriest>();
		FirePriest->SetActorLocation(FVector{ 1500.0f, -230.0f , -3.4f });
	}

	{
		std::shared_ptr<class AFirePriest> FirePriest = GetWorld()->SpawnActor<AFirePriest>();
		FirePriest->SetActorLocation(FVector{ 1430.0f, -150.0f , -3.4f });
	}

	{
		std::shared_ptr<class AFirePriest> FirePriest = GetWorld()->SpawnActor<AFirePriest>();
		FirePriest->SetActorLocation(FVector{ 1600.0f, -180.0f , -3.4f });
	}

	// 마을주민 왼쪽

	{
		std::shared_ptr<class AHate> Hate = GetWorld()->SpawnActor<AHate>();
		Hate->SetActorLocation(FVector{ -1090.0f, -130.0f , -3.4f });
		Hate->SetActorRelativeScale3D(FVector{ -1.0f, 1.0f, 1.0f });
	}

	{
		std::shared_ptr<class AShirine> Shirine = GetWorld()->SpawnActor<AShirine>();
		Shirine->SetActorLocation(FVector{ -1190.0f, -130.0f , -3.4f });
		Shirine->SetActorRelativeScale3D(FVector{ -1.0f, 1.0f, 1.0f });
	}

	{
		std::shared_ptr<class AShorn> Shorn = GetWorld()->SpawnActor<AShorn>();
		Shorn->SetActorLocation(FVector{ -1290.0f, -130.0f , -3.4f });
		Shorn->SetActorRelativeScale3D(FVector{ -1.0f, 1.0f, 1.0f });
	}

	{
		std::shared_ptr<class AOldMan> OldMan = GetWorld()->SpawnActor<AOldMan>();
		OldMan->SetActorLocation(FVector{ -550.0f, -230.0f , -3.4f });
	}

	// 마을주민 오른쪽
	
	{
		std::shared_ptr<class AJoy> Joy = GetWorld()->SpawnActor<AJoy>();
		Joy->SetActorLocation(FVector{ 300.0f, -230.0f , -3.4f });
	}

	{
		std::shared_ptr<class ADuglas> Duglas = GetWorld()->SpawnActor<ADuglas>();
		Duglas->SetActorLocation(FVector{ 800.0f, -130.0f , -3.4f });
	}


	{
		std::shared_ptr<class AElbis> Elbis = GetWorld()->SpawnActor<AElbis>();
		Elbis->SetActorLocation(FVector{ 580.0f, -110.0f , -3.4f });
	}


	{
		std::shared_ptr<class AManyu> Manyu = GetWorld()->SpawnActor<AManyu>();
		Manyu->SetActorLocation(FVector{ 600.0f, -230.0f , -3.4f });
	}


	

	



	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	{
		BigTree_Left = CreateDefaultSubObject<USpriteRenderer>();
		BigTree_Left->SetSprite("Cernium", 11);
		BigTree_Left->SetupAttachment(RootComponent);
		BigTree_Left->SetRelativeLocation({ -2180, -420 , -4.2f });
	}

	{
		BigTree_Right = CreateDefaultSubObject<USpriteRenderer>();
		BigTree_Right->SetSprite("Cernium", 12);
		BigTree_Right->SetupAttachment(RootComponent);
		BigTree_Right->SetRelativeLocation({ 2200, -420, -4.2f });
	}

	// 플레이어
	{
		Player = GetWorld()->SpawnActor<APlayer>();
		Player->SetActorLocation(FVector{ 0.0f, -230.0f , -3.5f });
	}
	
	// 플레이어 스킬
	{
		WrathOfEnril = GetWorld()->SpawnActor<AWrathOfEnril>();
		WrathOfEnril->AttachToActor(Player.get());
	}


	Camera = GetWorld()->GetMainCamera();
	Camera->AttachToActor(Player.get());
	Camera->AddRelativeLocation({ 0.0f, 230.0f , -1000.0f});

}

ACerniumPlazaMode::~ACerniumPlazaMode()
{

}

void ACerniumPlazaMode::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}