#include "PreCompile.h"
#include "FloorSkill.h"


#include <EnginePlatform/EngineInput.h>

#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>
#include <EngineCore/TimeEventComponent.h>

#include "MapleInstance.h"
#include "MapleEnum.h"
#include "Player.h"


AFloorSkill::AFloorSkill()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	FloorSkill = CreateDefaultSubObject<USpriteRenderer>();
	FloorSkill->SetupAttachment(RootComponent);

	FloorSkill->CreateAnimation("Phase1_FloorSkill", "Phase1_FloorSkill", 0, 19, 0.1f);
	FloorSkill->ChangeAnimation("Phase1_FloorSkill");

	FloorSkill->SetRelativeLocation(FVector{ 0.0f, FloorY, static_cast<float>(EMapleZEnum::Monster_Skill) });


	Collision = CreateDefaultSubObject<UCollision>();
	Collision->SetupAttachment(RootComponent);
	Collision->SetCollisionProfileName("MonsterSKill");

	Collision->SetScale3D({ 240.0f, 400.0f });
	Collision->SetRelativeLocation(FVector{ 10.0f, -30.0f , static_cast<float>(EMapleZEnum::Monster_Skill) });
	Collision->SetActive(false);
}

AFloorSkill::~AFloorSkill()
{

}

void AFloorSkill::BeginPlay()
{
	AActor::BeginPlay();
	Player = dynamic_cast<APlayer*>(GetWorld()->GetMainPawn());
	
}

void AFloorSkill::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	

	if (true == this->IsActive() && false == HitCheck)
	{
		Collision->SetActive(false);
		WaitTime = HitTime;
		HitCheck = true;

	}

	WaitTime -= _DeltaTime;

	if (0 >= WaitTime && true == HitCheck)
	{
		Collision->SetActive(true);
	}
	

	Collision->SetCollisionStay([this](UCollision* _This, UCollision* _Other)
		{
			GetGameInstance<MapleInstance>()->Status.TakeDamage(ExplosionDamage);
			GetGameInstance<MapleInstance>()->SerenStatus1.IncreaseGage(FloorGage);
			//float Curhp = GetGameInstance<MapleInstance>()->Status.CurHp;
			Player->bIsdamageOn();
			Collision->SetActive(false);
			HitCheck = false;
		});

	if (true == FloorSkill->IsCurAnimationEnd())
	{
		HitCheck = false;
	}
}
