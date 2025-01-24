#include "PreCompile.h"
#include "Small8Laser.h"


#include <EnginePlatform/EngineInput.h>

#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>
#include <EngineCore/TimeEventComponent.h>

#include "MapleInstance.h"
#include "MapleEnum.h"
#include "Seren.h"
#include "Player.h"

ASmall8Laser::ASmall8Laser()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;
	{
		// 가로
		Laser1 = CreateDefaultSubObject<USpriteRenderer>();
		Laser1->SetupAttachment(RootComponent);

		Laser1->CreateAnimation("Phase1_8Laser", "Phase1_8Laser", 0, 22, LaserSpeed, false);
		Laser1->ChangeAnimation("Phase1_8Laser");
		Laser1->SetRelativeLocation(FVector{ 0.0f, -44.0f, static_cast<float>(EMapleZEnum::Monster) + 50.0f });

		// 세로
		Laser2 = CreateDefaultSubObject<USpriteRenderer>();
		Laser2->SetupAttachment(RootComponent);

		Laser2->CreateAnimation("Phase1_8Laser", "Phase1_8Laser", 0, 22, LaserSpeed, false);
		Laser2->ChangeAnimation("Phase1_8Laser");
		Laser2->SetRelativeLocation(FVector{ 110.0f, -44.0f, static_cast<float>(EMapleZEnum::Monster) + 55.0f });
		Laser2->SetRotation(FVector{ 0.0f, 0.0f, 90.0f });

		// 왼쪽 대각
		Laser3 = CreateDefaultSubObject<USpriteRenderer>();
		Laser3->SetupAttachment(RootComponent);

		Laser3->CreateAnimation("Phase1_8Laser", "Phase1_8Laser", 0, 22, LaserSpeed, false);
		Laser3->ChangeAnimation("Phase1_8Laser");
		Laser3->SetRelativeLocation(FVector{ -76.0f, -44.0f, static_cast<float>(EMapleZEnum::Monster) + 60.0f });
		Laser3->SetRotation(FVector{ 0.0f, 0.0f, -45.0f });

		// 오른쪽 대각
		Laser4 = CreateDefaultSubObject<USpriteRenderer>();
		Laser4->SetupAttachment(RootComponent);

		Laser4->CreateAnimation("Phase1_8Laser", "Phase1_8Laser", 0, 22, LaserSpeed, false);
		Laser4->ChangeAnimation("Phase1_8Laser");
		Laser4->SetRelativeLocation(FVector{ 62.0f, -44.0f, static_cast<float>(EMapleZEnum::Monster) + 65.0f });
		Laser4->SetRotation(FVector{ 0.0f, 0.0f, 45.0f });
	}

	{
		Collision1 = CreateDefaultSubObject<UCollision>();
		Collision1->SetupAttachment(RootComponent);
		Collision1->SetCollisionProfileName("MonsterSkill");
		Collision1->SetScale3D({ 2000.0f, 10.0f });
		Collision1->SetRelativeLocation(FVector{ 00.0f, 84.0f, static_cast<float>(EMapleZEnum::Monster_Skill)});
		Collision1->SetActive(false);
	}

	{
		Collision2 = CreateDefaultSubObject<UCollision>();
		Collision2->SetupAttachment(RootComponent);
		Collision2->SetCollisionProfileName("MonsterSkill");
		Collision2->SetScale3D({ 2000.0f, 10.0f });
		Collision2->SetRelativeLocation(FVector{ -34.0f, 50.0f, static_cast<float>(EMapleZEnum::Monster_Skill) });
		Collision2->SetRotation(FVector{ 0.0f, 0.0f, 45.0f });
		Collision2->SetActive(false);
	}

	{
		Collision3 = CreateDefaultSubObject<UCollision>();
		Collision3->SetupAttachment(RootComponent);
		Collision3->SetCollisionProfileName("MonsterSkill");
		Collision3->SetScale3D({ 2000.0f, 10.0f });
		Collision3->SetRelativeLocation(FVector{ -26.0f, 90.0f, static_cast<float>(EMapleZEnum::Monster_Skill) });
		Collision3->SetRotation(FVector{ 0.0f, 0.0f, 90.0f });
		Collision3->SetActive(false);
	}
	{
		Collision4 = CreateDefaultSubObject<UCollision>();
		Collision4->SetupAttachment(RootComponent);
		Collision4->SetCollisionProfileName("MonsterSkill");
		Collision4->SetScale3D({ 2000.0f, 10.0f });
		Collision4->SetRelativeLocation(FVector{ 16.0f, 40.0f, static_cast<float>(EMapleZEnum::Monster_Skill) });
		Collision4->SetRotation(FVector{ 0.0f, 0.0f, -45.0f });
		Collision4->SetActive(false);
	}
}

ASmall8Laser::~ASmall8Laser()
{

}

void ASmall8Laser::BeginPlay()
{
	AActor::BeginPlay();

	Player = dynamic_cast<APlayer*>(GetWorld()->GetMainPawn());


}

void ASmall8Laser::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	WaitTime -= _DeltaTime;

	if (0 >= WaitTime)
	{
		Collision1->SetActive(true);
		Collision2->SetActive(true);
		Collision3->SetActive(true);
		Collision4->SetActive(true);
	}

	Collision1->SetCollisionStay([this](UCollision* _This, UCollision* _Other)
		{
			GetGameInstance<MapleInstance>()->Status.Hp -= LaserDamage;
			float Curhp = GetGameInstance<MapleInstance>()->Status.Hp;
			Player->bIsdamageOn();
			Collision1->SetActive(false);
			WaitTime = HitTime;
		});
	Collision2->SetCollisionStay([this](UCollision* _This, UCollision* _Other)
		{
			GetGameInstance<MapleInstance>()->Status.Hp -= LaserDamage;
			float Curhp = GetGameInstance<MapleInstance>()->Status.Hp;
			Player->bIsdamageOn();
			Collision2->SetActive(false);
			WaitTime = HitTime;
		});
	Collision3->SetCollisionStay([this](UCollision* _This, UCollision* _Other)
		{
			GetGameInstance<MapleInstance>()->Status.Hp -= LaserDamage;
			float Curhp = GetGameInstance<MapleInstance>()->Status.Hp;
			Player->bIsdamageOn();
			Collision3->SetActive(false);
			WaitTime = HitTime;
		});
	Collision4->SetCollisionStay([this](UCollision* _This, UCollision* _Other)
		{
			GetGameInstance<MapleInstance>()->Status.Hp -= LaserDamage;
			float Curhp = GetGameInstance<MapleInstance>()->Status.Hp;
			Player->bIsdamageOn();
			Collision4->SetActive(false);
			WaitTime = HitTime;
		});

	
}

