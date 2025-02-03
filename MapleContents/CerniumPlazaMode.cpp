#include "PreCompile.h"
#include "CerniumPlazaMode.h"

#include <EngineCore/CameraActor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/TransformObject.h>
#include <EngineCore/EngineGUIWindow.h>

#include <EnginePlatform/EngineWinImage.h>
#include <EnginePlatform/EngineInput.h>

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/EngineCamera.h>
#include <EngineCore/Collision.h>

#include "MapleInstance.h"

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

// 세렌 임시 삭제 예정
#include "Seren.h"

#include "Player.h"
#include "SkillManager.h"
#include "WrathOfEnril.h"
#include "LeafTornado.h"
#include "StrikeDualShot.h"
#include "RollingMoonSult.h"
#include "ChargeDrive.h"
#include "HighKick.h"
#include "UnicornSpike.h"
#include "LegendarySpear.h"


ACerniumPlazaMode::ACerniumPlazaMode()
{
	
	// 몬스터 콜리전
	GetWorld()->CreateCollisionProfile("Monster");
	GetWorld()->CreateCollisionProfile("MonsterSkill");
	GetWorld()->CreateCollisionProfile("Check");

	// 플레이어 콜리전
	GetWorld()->CreateCollisionProfile("Player");
	GetWorld()->CreateCollisionProfile("PlayerSKill");

	// 발판 콜리전
	GetWorld()->CreateCollisionProfile("Platform");
	GetWorld()->CreateCollisionProfile("Ground");
	GetWorld()->CreateCollisionProfile("MoveDot");

	// 콜리전 링크
	GetWorld()->LinkCollisionProfile("PlayerSKill", "Monster");
	GetWorld()->LinkCollisionProfile("MonsterSkill", "Player");
	GetWorld()->LinkCollisionProfile("Check", "Player");

	GetWorld()->LinkCollisionProfile("MoveDot", "Ground");
	GetWorld()->LinkCollisionProfile("MoveDot", "Platform");
	GetWorld()->LinkCollisionProfile("Monster", "Player");

	// 맵
	{
		Plaza= GetWorld()->SpawnActor<ACerniumPlaza>();
	}


	

#pragma region
	//프리스트

	{
		std::shared_ptr<class ADawnPriest> DawnPriest = GetWorld()->SpawnActor<ADawnPriest>();
		DawnPriest->AddRelativeLocation(FVector{ -1500.0f + MapSizeHalfX, -230.0f - MapSizeDefaultY, static_cast<float>(EMapleZEnum::NPC_9) });
		DawnPriest->SetActorRelativeScale3D(FVector{ -1.0f, 1.0f, 1.0f });
	}

	{
		std::shared_ptr<class ADawnPriest> DawnPriest = GetWorld()->SpawnActor<ADawnPriest>();
		DawnPriest->AddRelativeLocation(FVector{ -1430.0f + MapSizeHalfX, -150.0f - MapSizeDefaultY, static_cast<float>(EMapleZEnum::NPC_9) });
		DawnPriest->SetActorRelativeScale3D(FVector{ -1.0f, 1.0f, 1.0f });
	}

	{
		std::shared_ptr<class ADawnPriest> DawnPriest = GetWorld()->SpawnActor<ADawnPriest>();
		DawnPriest->AddRelativeLocation(FVector{ -1600.0f + MapSizeHalfX, -180.0f - MapSizeDefaultY, static_cast<float>(EMapleZEnum::NPC_9) });
		DawnPriest->SetActorRelativeScale3D(FVector{ -1.0f, 1.0f, 1.0f });
	}

	{
		std::shared_ptr<class AFirePriest> FirePriest = GetWorld()->SpawnActor<AFirePriest>();
		FirePriest->AddRelativeLocation(FVector{ 1500.0f + MapSizeHalfX, -230.0f - MapSizeDefaultY , static_cast<float>(EMapleZEnum::NPC_9) });
	}

	{
		std::shared_ptr<class AFirePriest> FirePriest = GetWorld()->SpawnActor<AFirePriest>();
		FirePriest->AddRelativeLocation(FVector{ 1430.0f + MapSizeHalfX, -150.0f - MapSizeDefaultY, static_cast<float>(EMapleZEnum::NPC_9) });
	}

	{
		std::shared_ptr<class AFirePriest> FirePriest = GetWorld()->SpawnActor<AFirePriest>();
		FirePriest->AddRelativeLocation(FVector{ 1600.0f + MapSizeHalfX, -180.0f - MapSizeDefaultY , static_cast<float>(EMapleZEnum::NPC_9) });
	}

	// 마을주민 왼쪽

	{
		std::shared_ptr<class AHate> Hate = GetWorld()->SpawnActor<AHate>();
		Hate->AddRelativeLocation(FVector{ -1090.0f + MapSizeHalfX, -130.0f - MapSizeDefaultY, static_cast<float>(EMapleZEnum::NPC_9) });
		Hate->SetActorRelativeScale3D(FVector{ -1.0f , 1.0f, 1.0f });
	}

	{
		std::shared_ptr<class AShirine> Shirine = GetWorld()->SpawnActor<AShirine>();
		Shirine->AddRelativeLocation(FVector{ -1190.0f + MapSizeHalfX, -130.0f - MapSizeDefaultY, static_cast<float>(EMapleZEnum::NPC_9) });
		Shirine->SetActorRelativeScale3D(FVector{ -1.0f, 1.0f, 1.0f });
	}

	{
		std::shared_ptr<class AShorn> Shorn = GetWorld()->SpawnActor<AShorn>();
		Shorn->AddRelativeLocation(FVector{ -1290.0f + MapSizeHalfX, -130.0f - MapSizeDefaultY , static_cast<float>(EMapleZEnum::NPC_9) });
		Shorn->SetActorRelativeScale3D(FVector{ -1.0f, 1.0f, 1.0f });
	}

	{
		std::shared_ptr<class AOldMan> OldMan = GetWorld()->SpawnActor<AOldMan>();
		OldMan->AddRelativeLocation(FVector{ -550.0f + MapSizeHalfX, -230.0f - MapSizeDefaultY, static_cast<float>(EMapleZEnum::NPC_9) });
	}

	// 마을주민 오른쪽
	
	{
		std::shared_ptr<class AJoy> Joy = GetWorld()->SpawnActor<AJoy>();
		Joy->AddRelativeLocation(FVector{ 300.0f + MapSizeHalfX, -230.0f - MapSizeDefaultY , static_cast<float>(EMapleZEnum::NPC_9) });
	}

	{
		std::shared_ptr<class ADuglas> Duglas = GetWorld()->SpawnActor<ADuglas>();
		Duglas->AddRelativeLocation(FVector{ 800.0f + MapSizeHalfX, -130.0f - MapSizeDefaultY , static_cast<float>(EMapleZEnum::NPC_9) });
	}


	{
		std::shared_ptr<class AElbis> Elbis = GetWorld()->SpawnActor<AElbis>();
		Elbis->AddRelativeLocation(FVector{ 580.0f + MapSizeHalfX, -110.0f - MapSizeDefaultY, static_cast<float>(EMapleZEnum::NPC_9) });
	}


	{
		std::shared_ptr<class AManyu> Manyu = GetWorld()->SpawnActor<AManyu>();
		Manyu->AddRelativeLocation(FVector{ 600.0f + MapSizeHalfX, -230.0f - MapSizeDefaultY, static_cast<float>(EMapleZEnum::NPC_9) });
	}
#pragma endregion
	
	


	

	

}

ACerniumPlazaMode::~ACerniumPlazaMode()
{

}

void ACerniumPlazaMode::BeginPlay()
{
	AGameMode::BeginPlay();
	// 플레이어 스킬
	{
		LeafTornadoFront = GetWorld()->SpawnActor<ALeafTornado>();
		WrathOfEnril = GetWorld()->SpawnActor<AWrathOfEnril>();
		StrikeDualShot = GetWorld()->SpawnActor<AStrikeDualShot>();
		RollingMoonSult = GetWorld()->SpawnActor<ARollingMoonSult>();
		HighKick = GetWorld()->SpawnActor<AHighKick>();
		ChargeDrive = GetWorld()->SpawnActor<AChargeDrive>();
		UnicornSpike = GetWorld()->SpawnActor<AUnicornSpike>();
		LegendarySpear = GetWorld()->SpawnActor<ALegendarySpear>();
	}

	// 플레이어
	{
		Player = dynamic_cast<APlayer*>(GetWorld()->GetMainPawn());
		Player->SetActorLocation(FVector{ MapSizeHalfX, -MapSizeHalfY - 650.0f, static_cast<float>(EMapleZEnum::Player) });
		PreviousPlayerLocation = Player->GetActorLocation().X;
	}

	LeafTornadoFront->AttachToActor(Player);
	WrathOfEnril->AttachToActor(Player);
	StrikeDualShot->AttachToActor(Player);
	RollingMoonSult->AttachToActor(Player);
	ChargeDrive->AttachToActor(Player);
	HighKick->AttachToActor(Player);
	UnicornSpike->AttachToActor(Player);
	LegendarySpear->AttachToActor(Player);

	Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector{ 0.0f, 260.0f , -1000.0f });
	Camera->AttachToActor(Player);
	Camera->GetCameraComponent()->SetZSort(0, true);

	GetSpriteRender();
	
	
}

void ACerniumPlazaMode::Tick(float _DeltaTime)
{
	AGameMode::Tick(_DeltaTime);

	UpdateSprite(_DeltaTime);

	ChargeDriveActive();	
	HighKickActive();

}


void ACerniumPlazaMode::GetSpriteRender()
{
	Plaza_Back = Plaza->GetPlaza_BackRender();
	Plaza_Mid = Plaza->GetPlaza_MidRender();
	Flag0 = Plaza->GetFlag0Render();
	Flag1 = Plaza->GetFlag1Render();
	Flag2 = Plaza->GetFlag2Render();
	Flag3 = Plaza->GetFlag3Render();
	Flag4 = Plaza->GetFlag4Render();
	Flag5 = Plaza->GetFlag5Render();
}

void ACerniumPlazaMode::UpdateSprite(float _DeltaTime)
{
	float CurrentPlayerLocation = Player->GetActorLocation().X;
	Velocity = (CurrentPlayerLocation - PreviousPlayerLocation) / _DeltaTime;

	UpdateSpriteLocation(Plaza_Back, _DeltaTime);
	UpdateSpriteLocation(Plaza_Mid, _DeltaTime);
	UpdateSpriteLocation(Flag0, _DeltaTime);
	UpdateSpriteLocation(Flag1, _DeltaTime);
	UpdateSpriteLocation(Flag2, _DeltaTime);
	UpdateSpriteLocation(Flag3, _DeltaTime);
	UpdateSpriteLocation(Flag4, _DeltaTime);
	UpdateSpriteLocation(Flag5, _DeltaTime);

	PreviousPlayerLocation = Player->GetActorLocation().X;
}

void ACerniumPlazaMode::UpdateSpriteLocation(std::shared_ptr<USpriteRenderer>& Sprite, float _DeltaTime)
{
	if (nullptr == Sprite)
	{
		MSGASSERT("존재하지 않는 스프라이트를 이동시키려고 했습니다.");
		return;
	}

	FVector CurrentLocation = Sprite->GetTransformRef().RelativeLocation;

	switch (static_cast<EMapleZEnum>(static_cast<int>(CurrentLocation.Z)))
	{
	case EMapleZEnum::BackGround_Back:
		SpeedMultiplier = 0.05f;
		break;
	case EMapleZEnum::BackGround_Mid:
		SpeedMultiplier = 0.07f;
		break;
	case EMapleZEnum::Object_Front:
		SpeedMultiplier = 0.05f;
		break;
	default:
		SpeedMultiplier = 0.05f;
		break;
	}

	if (true == UEngineInput::IsPress(VK_LEFT) || true == UEngineInput::IsPress(VK_RIGHT))
	{
		CurrentLocation.X += SpeedMultiplier * Velocity * _DeltaTime;
	}


	Sprite->SetWorldLocation(CurrentLocation);
}

void ACerniumPlazaMode::ChargeDriveActive()
{
	if (false == Player->IsGround())
	{
		ChargeDrive->SetActive(false);
	}
	else if (true == Player->IsGround() && UEngineInput::IsDown('Q'))
	{
		ChargeDrive->SetActive(true);
	}
	
}


void ACerniumPlazaMode::HighKickActive()
{
	if (true == Player->IsGround())
	{
		HighKick->SetActive(false);
	}
	else if (false == Player->IsGround() && UEngineInput::IsPress('W'))
	{
		HighKick->SetActive(true);
	}
}