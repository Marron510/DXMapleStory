#include "PreCompile.h"
#include "CerniumPlaza.h"
#include <EngineCore/SpriteRenderer.h>

#include <EngineCore/DefaultSceneComponent.h>


ACerniumPlaza::ACerniumPlaza()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;


}


ACerniumPlaza::~ACerniumPlaza()
{
}

void ACerniumPlaza::BeginPlay()
{
	AActor::BeginPlay();
}

void ACerniumPlaza::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	
}