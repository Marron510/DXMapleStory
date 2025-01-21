#include "PreCompile.h"
#include "Sting.h"

#include <EnginePlatform/EngineInput.h>

#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>


#include "MapleEnum.h"



ASting::ASting()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	StingCollision = CreateDefaultSubObject<UCollision>();
	StingCollision->SetupAttachment(RootComponent);
	StingCollision->SetCollisionProfileName("MonsterSkill");

	StingCollision->SetScale3D({ 80.0f, 30.0f });
	StingCollision->SetRelativeLocation(FVector{ -50.0f, 80.0f , static_cast<float>(EMapleZEnum::Monster) });
	StingCollision->SetActive(false);
	
}

ASting::~ASting()
{

}

void ASting::BeginPlay()
{
	AActor::BeginPlay();
}

void ASting::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);



}
