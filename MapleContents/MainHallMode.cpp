#include "PreCompile.h"
#include "MainHallMode.h"

#include <EngineCore/CameraActor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>

#include "MainHall.h"


#include "Seren.h"
#include "Player.h"

AMainHallMode::AMainHallMode()
{
	{
		MainHall = GetWorld()->SpawnActor<AMainHall>();
	}


	Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation({ 0.0f, 0.0f, -1000.0f, 1.0f });

	// ¼¼·»
	{
		std::shared_ptr<class ASeren> Seren = GetWorld()->SpawnActor<ASeren>();
		Seren->SetActorLocation(FVector{ 50.0f, -185.0f });
	}

	{
		Player = GetWorld()->SpawnActor<APlayer>();
		Player->SetActorLocation(FVector{ 0.0f, -275.0f });
	}

}

AMainHallMode::~AMainHallMode()
{
}

void AMainHallMode::Tick(float _DeltaTime)
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