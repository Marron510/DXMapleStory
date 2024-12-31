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
	{
		Noon = GetWorld()->SpawnActor<ANoon>();
	}

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

	// 플레이어
	{
		Player = GetWorld()->SpawnActor<APlayer>();
		Player->SetActorLocation(FVector{ 0.0f, -150.0f });
	}


}

ATheBoundaryOfTheWorld::~ATheBoundaryOfTheWorld()
{

}

void ATheBoundaryOfTheWorld::Tick(float _DeltaTime)
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
		Camera->AddRelativeLocation(FVector{ 0.0f, 300.0f * _DeltaTime, 0.0f });
	}

	if (UEngineInput::IsPress('S'))
	{
		Camera->AddRelativeLocation(FVector{ 0.0f, -300.0f * _DeltaTime, 0.0f });
	}
}



void ATheBoundaryOfTheWorld::ChangeMapState()
{
	if (UEngineInput::IsPress('P'))
	{

	}
	
}
