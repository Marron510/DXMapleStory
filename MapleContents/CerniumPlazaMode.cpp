#include "PreCompile.h"
#include "CerniumPlazaMode.h"

#include <EngineCore/CameraActor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineGUIWindow.h>
#include <EngineCore/EngineGUI.h>
#include <EngineCore/imgui.h>
#include <EnginePlatform/EngineInput.h>
#include "CerniumPlaza.h"
#include "Player.h"

ACerniumPlazaMode::ACerniumPlazaMode()
{
	
	// ¸Ê
	{
		Plaza= GetWorld()->SpawnActor<ACerniumPlaza>();
	}
	
	// ±ê¹ß

	// ÇÃ·¹ÀÌ¾î
	{
		Player = GetWorld()->SpawnActor<APlayer>();
		Player->SetActorLocation(FVector{ 0.0f, -230.0f });
	}

	Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation({ 0.0f, 0.0f, -10.0f, 1.0f });

	
}

ACerniumPlazaMode::~ACerniumPlazaMode()
{

}

void ACerniumPlazaMode::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	Camera->;

}