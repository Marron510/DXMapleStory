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


ACerniumPlazaMode::ACerniumPlazaMode()
{

	
	// ��
	{
		Plaza= GetWorld()->SpawnActor<ACerniumPlaza>();
	}
	
	

	//������Ʈ

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

	// �����ֹ� ����

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

	// �����ֹ� ������
	
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

	// �÷��̾�
	{
		Player = GetWorld()->SpawnActor<APlayer>();
		Player->SetActorLocation(FVector{ 0.0f, -230.0f , -3.5f });
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

	if (UEngineInput::IsPress(VK_LEFT))
	{
		Camera->AddRelativeLocation(FVector{ -300.0f * _DeltaTime, 0.0f, 0.0f });
	}

	if (UEngineInput::IsPress(VK_RIGHT))
	{
		Camera->AddRelativeLocation(FVector{ 300.0f * _DeltaTime, 0.0f, 0.0f });
	}


	if (UEngineInput::IsPress(VK_UP))
	{
		Camera->AddRelativeLocation(FVector{  0.0f, 300.0f * _DeltaTime, 0.0f });
	}

	//if (UEngineInput::IsPress(VK_DOWN))
	//{
	//	Camera->AddRelativeLocation(FVector{ 0.0f, -300.0f * _DeltaTime, 0.0f });
	//}

}