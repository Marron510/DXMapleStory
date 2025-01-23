#include "PreCompile.h"
#include "Seren.h"
#include <EnginePlatform/EngineInput.h>

#include <EngineCore/Level.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>
#include <EngineCore/Pawn.h>

#include "MapleEnum.h"
#include "SerenCollision.h"
#include "EventCharacter.h"
#include "Player.h"
#include "MapleInstance.h"

ASeren::ASeren()
{

	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	SerenRender = CreateDefaultSubObject<USpriteRenderer>();

	SerenRender->SetupAttachment(RootComponent);

	// 1페 애니메이션 
	{
		SerenRender->CreateAnimation("Phase1_Stand", "Phase1_Stand", 0, 15, 0.09f);
		SerenRender->CreateAnimation("Phase1_Sting", "Phase1_Sting", 0, 20, 0.04f, false);
		SerenRender->CreateAnimation("Phase1_Rush", "Phase1_Rush", 0, 34, 0.05f, false);
		SerenRender->CreateAnimation("Phase1_SwordAura", "Phase1_SwordAura", 0, 29, 0.05f, false);
		SerenRender->CreateAnimation("Phase1_Laser", "Phase1_Laser", 0, 26, 0.1f, false);
	}

	// 정오 스킬 애니메이션 
	{
		SerenRender->CreateAnimation("NoonSerenStand", "NoonSerenStand", 0, 14, 0.09f);
		SerenRender->CreateAnimation("NoonSerenRush", "NoonSerenRush", 0, 35, 0.072f, false);
		SerenRender->CreateAnimation("NoonSerenSting", "NoonSerenSting", 0, 20, 0.04f, false);
		SerenRender->CreateAnimation("NoonSerenStunLaser", "NoonSerenStunLaser", 0, 21, 0.13f, false);
		SerenRender->CreateAnimation("NoonSerenEightLaser", "NoonSerenEightLaser", 0, 27, 0.11f, false);
		SerenRender->CreateAnimation("NoonSerenHit", "NoonSerenHit", 0, 0, 0.09f, false);
		SerenRender->CreateAnimation("NoonSerenDie", "NoonSerenDie", 0, 37, 0.1f, false);
	}
	
	// 세렌 석양 애니메이션
	{
		SerenRender->CreateAnimation("SunSetSerenFirstAttack", "SunSetSerenFirstAttack", 0, 38, 0.06f, false);
		SerenRender->CreateAnimation("SunSetSerenSecondAttack", "SunSetSerenSecondAttack", 0, 36, 0.06f, false);
		SerenRender->CreateAnimation("SunSetSerenThirdAttack", "SunSetSerenThirdAttack", 0, 39, 0.06f, false);
		SerenRender->CreateAnimation("SunSetSerenDie", "SunSetSerenDie", 0, 36, 0.06f, false);
	}

	SerenRender->SetRelativeLocation(FVector{ 0.0f, -290.0f ,  static_cast<float>(EMapleZEnum::Monster) });
	SerenRender->ChangeAnimation("NoonSerenStand");

	// 콜리젼
	{
		Collision = CreateDefaultSubObject<USerenCollision>();
		Collision->SetupAttachment(RootComponent);
		Collision->SetCollisionProfileName("Monster");

		Collision->SetScale3D({ 80.0f, 140.0f });
		Collision->SetRelativeLocation(FVector{ 10.0f, 80.0f , static_cast<float>(EMapleZEnum::Monster) });
		Collision->SetCollisionEnter([](UCollision* _This, UCollision* _Other)
			{

			});
	}

	{
		CheckCollision = CreateDefaultSubObject<UCollision>();
		CheckCollision->SetupAttachment(RootComponent);
		CheckCollision->SetCollisionProfileName("Check");

		CheckCollision->SetScale3D({ 500.0f, 200.0f });
		CheckCollision->SetRelativeLocation(FVector{ 10.0f, 80.0f , static_cast<float>(EMapleZEnum::Monster) });
		
	}

	{
		OutRangeCollision = CreateDefaultSubObject<UCollision>();
		OutRangeCollision->SetupAttachment(RootComponent);
		OutRangeCollision->SetCollisionProfileName("Check");

		OutRangeCollision->SetScale3D({ 1000.0f, 200.0f });
		OutRangeCollision->SetRelativeLocation(FVector{ 10.0f, 80.0f , static_cast<float>(EMapleZEnum::Monster) });

	}

	{
		StingCollision = CreateDefaultSubObject<UCollision>();
		StingCollision->SetupAttachment(RootComponent);
		StingCollision->SetCollisionProfileName("MonsterSkill");

		StingCollision->SetScale3D({ 300.0f, 30.0f });
		StingCollision->SetRelativeLocation(FVector{ -80.0f, 80.0f , static_cast<float>(EMapleZEnum::Monster) });
		StingCollision->SetActive(false);
	}

	{
		RushCollision = CreateDefaultSubObject<UCollision>();
		RushCollision->SetupAttachment(RootComponent);
		RushCollision->SetCollisionProfileName("MonsterSkill");
		
		RushCollision->SetScale3D({ 700.0f, 30.0f });
		RushCollision->SetRelativeLocation(FVector{ -300.0f, 80.0f , static_cast<float>(EMapleZEnum::Monster) });
		RushCollision->SetActive(false);
	}

}

ASeren::~ASeren()
{

}

void ASeren::BeginPlay()
{
	AActor::BeginPlay();
	Player = dynamic_cast<APlayer*>(GetWorld()->GetMainPawn());
	

	StateInit();
	SerenFSM.ChangeState(ESerenState::Idle);
	
	//std::shared_ptr<class ASting> sting = GetWorld()->SpawnActor<class ASting>();
}

void ASeren::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	
	SerenFSM.Update(_DeltaTime);
	

	// 세렌 죽음 체크
	SerenDeathCheck();
}


void ASeren::SerenDeathCheck()
{
	if (true == bIsDead)
	{
		return;
	}

	if (0 >= Collision->GetHp() && false == bIsDead)
	{
		Collision->SetActive(false);
		SerenFSM.ChangeState(ESerenState::Die);
		bIsDead = true;
	}

}


void ASeren::PlayerLocationCheck(float _DeltaTime)
{

}

