#include "PreCompile.h"
#include "MainHallMode.h"

#include <EngineCore/CameraActor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/TransformObject.h>
#include <EngineCore/EngineGUIWindow.h>

#include <EnginePlatform/EngineWinImage.h>
#include <EnginePlatform/EngineInput.h>

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/EngineCamera.h>
#include <EngineCore/Collision.h>

#include "MainHall.h"
#include "MapleEnum.h"

#include "SkillManager.h"
#include "WrathOfEnril.h"
#include "LeafTornado.h"
#include "StrikeDualShot.h"
#include "RollingMoonSult.h"
#include "ChargeDrive.h"
#include "HighKick.h"
#include "UnicornSpike.h"
#include "LegendarySpear.h"
#include "RoyalKnight.h"

#include "Seren.h"
#include "SerenCollision.h"
#include "Player.h"

AMainHallMode::AMainHallMode()
{
	// 몬스터 콜리전
	GetWorld()->CreateCollisionProfile("Monster");
	GetWorld()->CreateCollisionProfile("MonsterSkill");
	
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
	GetWorld()->LinkCollisionProfile("MoveDot", "Ground");
	GetWorld()->LinkCollisionProfile("MoveDot", "Platform");
	GetWorld()->LinkCollisionProfile("Monster", "Player");


	{
		MainHall = GetWorld()->SpawnActor<AMainHall>();
	}

}

AMainHallMode::~AMainHallMode()
{
}

void AMainHallMode::BeginPlay()
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
		RoyalKnight = GetWorld()->SpawnActor<ARoyalKnight>();
	}

	// 플레이어
	{
		Player = dynamic_cast<APlayer*>(GetWorld()->GetMainPawn());
		Player->SetActorLocation(FVector{ MapSizeHalfX, -MapSizeHalfY, static_cast<float>(EMapleZEnum::Player) });
	}

	LeafTornadoFront->AttachToActor(Player);
	WrathOfEnril->AttachToActor(Player);
	StrikeDualShot->AttachToActor(Player);
	RollingMoonSult->AttachToActor(Player);
	ChargeDrive->AttachToActor(Player);
	HighKick->AttachToActor(Player);
	UnicornSpike->AttachToActor(Player);
	LegendarySpear->AttachToActor(Player);
	RoyalKnight->AttachToActor(Player);

	// 카메라
	{
		Camera = GetWorld()->GetMainCamera();
		Camera->SetActorLocation(FVector{ 0.0f, 290.0f , -1000.0f });
		Camera->AttachToActor(Player);
		Camera->GetCameraComponent()->SetZSort(0, true);
	}

	// 세렌
	{
		Seren = GetWorld()->SpawnActor<ASeren>();
		Seren->SetActorLocation(FVector{ MapSizeHalfX, -MapSizeHalfY - 240.0f ,static_cast<float>(EMapleZEnum::Monster) - 300.0f});
	}

	GetSpriteRender();
}

void AMainHallMode::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	
	UpdateSprite(_DeltaTime);
}

void AMainHallMode::GetSpriteRender()
{
	MainHall_Sky = MainHall->GetMainHall_Sky();
	MainHall_Center = MainHall->GetMainHall_Center();
	MainHall_Pillar_Left = MainHall->GetMainHall_Pillar_Left();
	MainHall_Pillar_Right = MainHall->GetMainHall_Pillar_Right();


}


void AMainHallMode::UpdateSprite(float _DeltaTime)
{
	float CurrentPlayerLocation = Player->GetActorLocation().X;
	Velocity = (CurrentPlayerLocation - PreviousPlayerLocation) / _DeltaTime;

	UpdateSpriteLocation(MainHall_Sky, _DeltaTime);
	UpdateSpriteLocation(MainHall_Center, _DeltaTime);
	UpdateSpriteLocation(MainHall_Pillar_Left, _DeltaTime);
	UpdateSpriteLocation(MainHall_Pillar_Right, _DeltaTime);
	

	PreviousPlayerLocation = Player->GetActorLocation().X;
}

void AMainHallMode::UpdateSpriteLocation(std::shared_ptr<USpriteRenderer>& Sprite, float _DeltaTime)
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
		SpeedMultiplier = 0.03f;
		break;
	case EMapleZEnum::BackGround_Mid:
		SpeedMultiplier = 0.06f;
		break;
	case EMapleZEnum::Building_Front:
		SpeedMultiplier = 0.03f;
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