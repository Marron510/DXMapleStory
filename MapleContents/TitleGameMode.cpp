#include "PreCompile.h"
#include "TitleGameMode.h"
#include "TitleLogo.h"
#include <EngineCore/CameraActor.h>
#include <EngineCore/SpriteRenderer.h>

ATitleGameMode::ATitleGameMode()
{
	{
		std::shared_ptr<ATitleLogo> Logo = GetWorld()->SpawnActor<ATitleLogo>();
		Logo->SetActorLocation({ 300.0f, 0.0f, 0.0f });
		Logo->GetRenderer()->SetSpriteData({ 0.0f, 0.0f }, { 0.5f, 0.5f });
	}

	{
		std::shared_ptr<ATitleLogo> Logo = GetWorld()->SpawnActor<ATitleLogo>();
		Logo->SetActorLocation({ -300.0f, 0.0f, 0.0f });
	}

	std::shared_ptr<ACameraActor> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation({ 0.0f, 0.0f, -1000.0f, 1.0f });
}

ATitleGameMode::~ATitleGameMode()
{
}

void ATitleGameMode::Tick(float _DeltaTime)
{
	// 부모 호출
	AActor::Tick(_DeltaTime);


}