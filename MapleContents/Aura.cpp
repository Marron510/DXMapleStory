#include "PreCompile.h"
#include "Aura.h"

#include <EnginePlatform/EngineInput.h>

#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>
#include <EngineCore/TimeEventComponent.h>

#include "MapleInstance.h"
#include "MapleEnum.h"
#include "Player.h"

AAura::AAura()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	Aura = CreateDefaultSubObject<USpriteRenderer>();
	Aura->SetupAttachment(RootComponent);

	Aura->CreateAnimation("Phase1_SwordAura_Ball", "Phase1_SwordAura_Ball", 0, 5, 0.07f);
	Aura->ChangeAnimation("Phase1_SwordAura_Ball");

	Aura->SetRelativeLocation(FVector{ 0.0f, -100.0f, static_cast<float>(EMapleZEnum::Monster_Skill) });


	Collision = CreateDefaultSubObject<UCollision>();
	Collision->SetupAttachment(RootComponent);
	Collision->SetCollisionProfileName("MonsterSKill");

	Collision->SetScale3D({ 400.0f, 120.0f });
	Collision->SetRelativeLocation(FVector{ -56.0f, 260.0f , static_cast<float>(EMapleZEnum::Monster_Skill) });
	
}

AAura::~AAura()
{

}

void AAura::BeginPlay()
{
	AActor::BeginPlay();

	Player = dynamic_cast<APlayer*>(GetWorld()->GetMainPawn());

	Collision->SetCollisionStay([this](UCollision* _This, UCollision* _Other)
		{
			GetGameInstance<MapleInstance>()->Status.Hp -= AuraDamage;
			float Curhp = GetGameInstance<MapleInstance>()->Status.Hp;
			Player->bIsdamageOn();
		});
}

void AAura::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	
	Move(_DeltaTime);
}


void AAura::Move(float _DeltaTime)
{

	FVector CurPlayerLocation = Player->GetActorLocation();
	FVector SerenLocation = GetActorLocation();

	if (true == bLocationCheck)
	{

		if (0 < DifferentLocation.X)
		{
			AddActorLocation(FVector{ AuraSpeed * _DeltaTime, 0.0f, 1.0f });
			SetActorRelativeScale3D(FVector{ -1.0f, 1.0f, 1.0f });
		}
		else if (0 >= DifferentLocation.X)
		{
			AddActorLocation(FVector{ -AuraSpeed * _DeltaTime, 0.0f, 1.0f });
			SetActorRelativeScale3D(FVector{ 1.0f, 1.0f, 1.0f });
		}
	}

	if (false == bLocationCheck)
	{
		DifferentLocation = CurPlayerLocation - SerenLocation;
		DifferentLocation.Normalize();
		bLocationCheck = true;
	}

	
	if (MapstartX > this->GetActorLocation().X || MapEndX < this->GetActorLocation().X)
	{
		this->SetActive(false);
	}


}
