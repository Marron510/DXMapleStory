#include "PreCompile.h"
#include "CerniumPlazaMode.h"

#include <EngineCore/CameraActor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineGUIWindow.h>
#include <EnginePlatform/EngineInput.h>


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


ACerniumPlazaMode::ACerniumPlazaMode()
{
	
	// ¸Ê
	{
		Plaza= GetWorld()->SpawnActor<ACerniumPlaza>();
	}
	
	// ±ê¹ß

	//ÇÁ¸®½ºÆ®

	{
		std::shared_ptr<class ADawnPriest> DawnPriest = GetWorld()->SpawnActor<ADawnPriest>();
		DawnPriest->SetActorLocation(FVector{ -1500.0f, -230.0f });
		DawnPriest->SetActorRelativeScale3D(FVector{ -1.0f, 1.0f, 1.0f });
	}

	{
		std::shared_ptr<class ADawnPriest> DawnPriest = GetWorld()->SpawnActor<ADawnPriest>();
		DawnPriest->SetActorLocation(FVector{ -1430.0f, -150.0f });
		DawnPriest->SetActorRelativeScale3D(FVector{ -1.0f, 1.0f, 1.0f });
	}

	{
		std::shared_ptr<class ADawnPriest> DawnPriest = GetWorld()->SpawnActor<ADawnPriest>();
		DawnPriest->SetActorLocation(FVector{ -1600.0f, -180.0f });
		DawnPriest->SetActorRelativeScale3D(FVector{ -1.0f, 1.0f, 1.0f });
	}

	{
		std::shared_ptr<class AFirePriest> FirePriest = GetWorld()->SpawnActor<AFirePriest>();
		FirePriest->SetActorLocation(FVector{ 1500.0f, -230.0f });
	}

	{
		std::shared_ptr<class AFirePriest> FirePriest = GetWorld()->SpawnActor<AFirePriest>();
		FirePriest->SetActorLocation(FVector{ 1430.0f, -150.0f });
	}

	{
		std::shared_ptr<class AFirePriest> FirePriest = GetWorld()->SpawnActor<AFirePriest>();
		FirePriest->SetActorLocation(FVector{ 1600.0f, -180.0f });
	}

	// ¸¶À»ÁÖ¹Î ¿ÞÂÊ

	{
		std::shared_ptr<class AHate> Hate = GetWorld()->SpawnActor<AHate>();
		Hate->SetActorLocation(FVector{ -1090.0f, -130.0f });
		Hate->SetActorRelativeScale3D(FVector{ -1.0f, 1.0f, 1.0f });
	}

	{
		std::shared_ptr<class AShirine> Shirine = GetWorld()->SpawnActor<AShirine>();
		Shirine->SetActorLocation(FVector{ -1190.0f, -130.0f });
		Shirine->SetActorRelativeScale3D(FVector{ -1.0f, 1.0f, 1.0f });
	}

	{
		std::shared_ptr<class AShorn> Shorn = GetWorld()->SpawnActor<AShorn>();
		Shorn->SetActorLocation(FVector{ -1290.0f, -130.0f });
		Shorn->SetActorRelativeScale3D(FVector{ -1.0f, 1.0f, 1.0f });
	}

	{
		std::shared_ptr<class AOldMan> OldMan = GetWorld()->SpawnActor<AOldMan>();
		OldMan->SetActorLocation(FVector{ -550.0f, -230.0f });
	}

	// ¸¶À»ÁÖ¹Î ¿À¸¥ÂÊ
	
	{
		std::shared_ptr<class AJoy> Joy = GetWorld()->SpawnActor<AJoy>();
		Joy->SetActorLocation(FVector{ 300.0f, -230.0f });
	}

	{
		std::shared_ptr<class ADuglas> Duglas = GetWorld()->SpawnActor<ADuglas>();
		Duglas->SetActorLocation(FVector{ 800.0f, -130.0f });
	}


	{
		std::shared_ptr<class AElbis> Elbis = GetWorld()->SpawnActor<AElbis>();
		Elbis->SetActorLocation(FVector{ 580.0f, -110.0f });
	}


	{
		std::shared_ptr<class AManyu> Manyu = GetWorld()->SpawnActor<AManyu>();
		Manyu->SetActorLocation(FVector{ 600.0f, -230.0f });
	}


	

	// ÇÃ·¹ÀÌ¾î
	{
		Player = GetWorld()->SpawnActor<APlayer>();
		Player->SetActorLocation(FVector{ 0.0f, -230.0f });
	}

	Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation({ 0.0f, 0.0f, -1000.0f, 1.0f });

	
}

ACerniumPlazaMode::~ACerniumPlazaMode()
{

}

void ACerniumPlazaMode::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	if (UEngineInput::IsPress('A'))
	{
		Camera->AddRelativeLocation(FVector{ -300.0f * _DeltaTime, 0.0f, 0.0f });
	}

	if (UEngineInput::IsPress('D'))
	{
		Camera->AddRelativeLocation(FVector{ 300.0f * _DeltaTime, 0.0f, 0.0f });
	}


	if (UEngineInput::IsPress('W'))
	{
		Camera->AddRelativeLocation(FVector{  0.0f, 300.0f * _DeltaTime, 0.0f });
	}

	if (UEngineInput::IsPress('S'))
	{
		Camera->AddRelativeLocation(FVector{ 0.0f, -300.0f * _DeltaTime, 0.0f });
	}

}