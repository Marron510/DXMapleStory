#include "PreCompile.h"
#include "CerniumPlazaMode.h"

#include <EngineCore/CameraActor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineGUIWindow.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/EngineCamera.h>

#include "CerniumPlaza.h"
#include "MapleEnum.h"

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
#include "LeafTornado.h"
#include "StrikeDualShot.h"
#include "RollingMoonSult.h"


ACerniumPlazaMode::ACerniumPlazaMode()
{

	
	// 맵
	{
		Plaza= GetWorld()->SpawnActor<ACerniumPlaza>();
	}
	
	
#pragma region
	//프리스트

	{
		std::shared_ptr<class ADawnPriest> DawnPriest = GetWorld()->SpawnActor<ADawnPriest>();
		DawnPriest->AddRelativeLocation(FVector{ -1500.0f, -230.0f , static_cast<float>(EMapleZEnum::NPC_9) });
		DawnPriest->SetActorRelativeScale3D(FVector{ -1.0f, 1.0f, 1.0f });
	}

	{
		std::shared_ptr<class ADawnPriest> DawnPriest = GetWorld()->SpawnActor<ADawnPriest>();
		DawnPriest->AddRelativeLocation(FVector{ -1430.0f, -150.0f , static_cast<float>(EMapleZEnum::NPC_9) });
		DawnPriest->SetActorRelativeScale3D(FVector{ -1.0f, 1.0f, 1.0f });
	}

	{
		std::shared_ptr<class ADawnPriest> DawnPriest = GetWorld()->SpawnActor<ADawnPriest>();
		DawnPriest->AddRelativeLocation(FVector{ -1600.0f, -180.0f , static_cast<float>(EMapleZEnum::NPC_9) });
		DawnPriest->SetActorRelativeScale3D(FVector{ -1.0f, 1.0f, 1.0f });
	}

	{
		std::shared_ptr<class AFirePriest> FirePriest = GetWorld()->SpawnActor<AFirePriest>();
		FirePriest->AddRelativeLocation(FVector{ 1500.0f, -230.0f , static_cast<float>(EMapleZEnum::NPC_9) });
	}

	{
		std::shared_ptr<class AFirePriest> FirePriest = GetWorld()->SpawnActor<AFirePriest>();
		FirePriest->AddRelativeLocation(FVector{ 1430.0f, -150.0f , static_cast<float>(EMapleZEnum::NPC_9) });
	}

	{
		std::shared_ptr<class AFirePriest> FirePriest = GetWorld()->SpawnActor<AFirePriest>();
		FirePriest->AddRelativeLocation(FVector{ 1600.0f, -180.0f , static_cast<float>(EMapleZEnum::NPC_9) });
	}

	// 마을주민 왼쪽

	{
		std::shared_ptr<class AHate> Hate = GetWorld()->SpawnActor<AHate>();
		Hate->AddRelativeLocation(FVector{ -1090.0f, -130.0f , static_cast<float>(EMapleZEnum::NPC_9) });
		Hate->SetActorRelativeScale3D(FVector{ -1.0f, 1.0f, 1.0f });
	}

	{
		std::shared_ptr<class AShirine> Shirine = GetWorld()->SpawnActor<AShirine>();
		Shirine->AddRelativeLocation(FVector{ -1190.0f, -130.0f , static_cast<float>(EMapleZEnum::NPC_9) });
		Shirine->SetActorRelativeScale3D(FVector{ -1.0f, 1.0f, 1.0f });
	}

	{
		std::shared_ptr<class AShorn> Shorn = GetWorld()->SpawnActor<AShorn>();
		Shorn->AddRelativeLocation(FVector{ -1290.0f, -130.0f , static_cast<float>(EMapleZEnum::NPC_9) });
		Shorn->SetActorRelativeScale3D(FVector{ -1.0f, 1.0f, 1.0f });
	}

	{
		std::shared_ptr<class AOldMan> OldMan = GetWorld()->SpawnActor<AOldMan>();
		OldMan->AddRelativeLocation(FVector{ -550.0f, -230.0f , static_cast<float>(EMapleZEnum::NPC_9) });
	}

	// 마을주민 오른쪽
	
	{
		std::shared_ptr<class AJoy> Joy = GetWorld()->SpawnActor<AJoy>();
		Joy->AddRelativeLocation(FVector{ 300.0f, -230.0f , static_cast<float>(EMapleZEnum::NPC_9) });
	}

	{
		std::shared_ptr<class ADuglas> Duglas = GetWorld()->SpawnActor<ADuglas>();
		Duglas->AddRelativeLocation(FVector{ 800.0f, -130.0f , static_cast<float>(EMapleZEnum::NPC_9) });
	}


	{
		std::shared_ptr<class AElbis> Elbis = GetWorld()->SpawnActor<AElbis>();
		Elbis->AddRelativeLocation(FVector{ 580.0f, -110.0f , static_cast<float>(EMapleZEnum::NPC_9) });
	}


	{
		std::shared_ptr<class AManyu> Manyu = GetWorld()->SpawnActor<AManyu>();
		Manyu->AddRelativeLocation(FVector{ 600.0f, -230.0f , static_cast<float>(EMapleZEnum::NPC_9) });
	}
#pragma endregion
	
	// 플레이어 스킬
	{
		LeafTornadoFront = GetWorld()->SpawnActor<ALeafTornado>();
		WrathOfEnril = GetWorld()->SpawnActor<AWrathOfEnril>();
		StrikeDualShot = GetWorld()->SpawnActor<AStrikeDualShot>();
		RollingMoonSult = GetWorld()->SpawnActor<ARollingMoonSult>();
	}
	
	// 플레이어
	{
		Player = GetWorld()->SpawnActor<APlayer>();
		Player->AddRelativeLocation(FVector{ 0.0f, -230.0f});
	}
	
	{
		LeafTornadoFront->AttachToActor(Player.get());
		WrathOfEnril->AttachToActor(Player.get());
		StrikeDualShot->AttachToActor(Player.get());
		RollingMoonSult->AttachToActor(Player.get());
	}

	{
		Camera = GetWorld()->GetMainCamera();
		Camera->AddRelativeLocation(FVector{ 0.0f, 230.0f , -1000.0f });
		Camera->AttachToActor(Player.get());
		Camera->GetCameraComponent()->SetZSort(0, true);
	}



}

ACerniumPlazaMode::~ACerniumPlazaMode()
{

}

void ACerniumPlazaMode::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}