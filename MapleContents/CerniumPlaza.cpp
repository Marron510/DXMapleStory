#include "PreCompile.h"
#include "CerniumPlaza.h"
#include <EngineCore/SpriteRenderer.h>

#include <EngineCore/DefaultSceneComponent.h>


ACerniumPlaza::ACerniumPlaza()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;
	
	{
		Plaza = CreateDefaultSubObject<USpriteRenderer>();
		Plaza->SetSprite("Cernium", 0);
		Plaza->SetupAttachment(RootComponent);
		Plaza->SetScale3D({ 4830.0f , 1590.0f });
		Plaza->SetRelativeLocation({ 0, -390 });
	}

	{
		BuildingLeft_0 = CreateDefaultSubObject<USpriteRenderer>();
		BuildingLeft_0->SetSprite("Cernium", 1);
		BuildingLeft_0->SetupAttachment(RootComponent);
		BuildingLeft_0->SetScale3D({ 478.0f , 678.0f });
		BuildingLeft_0->SetRelativeLocation({ -500, -100 });
	}
	
	{
		BuildingLeft_1 = CreateDefaultSubObject<USpriteRenderer>();
		BuildingLeft_1->SetSprite("Cernium", 2);
		BuildingLeft_1->SetupAttachment(RootComponent);
		BuildingLeft_1->SetScale3D({ 1200.0f , 1200.0f });
		BuildingLeft_1->SetRelativeLocation({ -1200, -390 });
	}

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