#include "PreCompile.h"
#include "CerniumPlazaMode.h"

#include <EngineCore/CameraActor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineGUIWindow.h>
#include <EngineCore/EngineGUI.h>
#include <EngineCore/imgui.h>
#include <EnginePlatform/EngineInput.h>


#include "CerniumPlaza.h"

#include "DawnPriest.h"
#include "Player.h"


ACerniumPlazaMode::ACerniumPlazaMode()
{
	
	// ��
	{
		Plaza= GetWorld()->SpawnActor<ACerniumPlaza>();
	}
	
	// ���

	//������Ʈ
	{
		DawnPriest = GetWorld()->SpawnActor<ADawnPriest>();
		DawnPriest->SetActorLocation(FVector{ 0.0f, -230.0f });
	}
	
	// �÷��̾�
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