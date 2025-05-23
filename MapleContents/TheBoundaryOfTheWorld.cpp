#include "Precompile.h"
#include "TheBoundaryOfTheWorld.h"


#include <EngineCore/CameraActor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>

#include "Noon.h"
#include "SunSet.h"
#include "MidNight.h"
#include "Dawn.h"

#include "Seren.h"
#include "Player.h"


ATheBoundaryOfTheWorld::ATheBoundaryOfTheWorld()
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



	/*{
		Noon = GetWorld()->SpawnActor<ANoon>();
	}*/

	/*{
		SunSet = GetWorld()->SpawnActor<ASunSet>();
	}

	{
		MidNight = GetWorld()->SpawnActor<AMidNight>();
	}

	{
		Dawn = GetWorld()->SpawnActor<ADawn>();
	}*/

	
	// 카메라
	{
		Camera = GetWorld()->GetMainCamera();
		Camera->SetActorLocation({ 0.0f, 0.0f, -1000.0f, 1.0f });
	}
	// 세렌
	{
		Seren = GetWorld()->SpawnActor<ASeren>();
		Seren->SetActorLocation(FVector{ 50.0f, -435.0f });
	}



}

ATheBoundaryOfTheWorld::~ATheBoundaryOfTheWorld()
{

}

void ATheBoundaryOfTheWorld::BeginPlay()
{
	AGameMode::BeginPlay();

	// 플레이어
	{
		Player = dynamic_cast<APlayer*>(GetWorld()->GetMainPawn());
		Player->SetActorLocation(FVector{ 0.0f, -150.0f });
	}

}

void ATheBoundaryOfTheWorld::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

}



void ATheBoundaryOfTheWorld::ChangeMapState()
{
	if (UEngineInput::IsPress('P'))
	{

	}
	
}
