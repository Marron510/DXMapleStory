#include "PreCompile.h"
#include "Seren.h"

#include <EngineBase/EngineRandom.h>

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
#include "FloorSkill.h"
#include "SmallAtom.h"

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
		Collision->SetRelativeLocation(FVector{ -16.0f, 80.0f , static_cast<float>(EMapleZEnum::Monster) });
		Collision->SetCollisionEnter([](UCollision* _This, UCollision* _Other)
			{

			});
	}

	{
		CheckCollision = CreateDefaultSubObject<UCollision>();
		CheckCollision->SetupAttachment(RootComponent);
		CheckCollision->SetCollisionProfileName("Check");

		CheckCollision->SetScale3D({ InRangeDistance, 200.0f });
		CheckCollision->SetRelativeLocation(FVector{ 10.0f, 80.0f , static_cast<float>(EMapleZEnum::Monster) });
		
	}

	{
		OutRangeCollision = CreateDefaultSubObject<UCollision>();
		OutRangeCollision->SetupAttachment(RootComponent);
		OutRangeCollision->SetCollisionProfileName("Check");

		OutRangeCollision->SetScale3D({ OutRangeDistance, 200.0f });
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
	
	FloorExplosionInit();
	SmallAtomInit();





}

void ASeren::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	
	SerenFSM.Update(_DeltaTime);

	// 세렌 죽음 체크
	SerenDeathCheck();

	// 맵패턴
	
	FloorExplosionSetting(_DeltaTime);
	FloorExplosionCheck(_DeltaTime);
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

void ASeren::SmallAtomInit()
{
	{
		SmallAtom1 = GetWorld()->SpawnActor<ASmallAtom>();
		SmallAtom1->SetActorLocation(FVector{ 2274.0f, -858.0f });
	}

}


void ASeren::DropAtom(float _DeltaTime)
{
	
	// 스톤은 다섯개 바닥에 닿으면 애니메이션 바꾸고 
	// 콜리전이 플레이어랑 닿으면 에너지 증가 <= 중요
	// 위에서 랜덤 위치(x)에 다시 소환

}

void ASeren::FloorExplosionInit()
{
	{
		FloorSkill1 = GetWorld()->SpawnActor<AFloorSkill>();
		FloorSkill1->SetActorLocation(FVector{ 2274.0f, -858.0f });
	}

	{
		FloorSkill2 = GetWorld()->SpawnActor<AFloorSkill>();
		FloorSkill2->SetActorLocation(FVector{ 1974.0f, -858.0f, 10.0f });
	}

	{
		FloorSkill3 = GetWorld()->SpawnActor<AFloorSkill>();
		FloorSkill3->SetActorLocation(FVector{ 1674.0f, -858.0f });
	}

	{
		FloorSkill4 = GetWorld()->SpawnActor<AFloorSkill>();
		FloorSkill4->SetActorLocation(FVector{ 1374.0f, -858.0f, 10.0f });
	}

	{
		FloorSkill5 = GetWorld()->SpawnActor<AFloorSkill>();
		FloorSkill5->SetActorLocation(FVector{ 2574.0f, -858.0f });
	}

	{
		FloorSkill6 = GetWorld()->SpawnActor<AFloorSkill>();
		FloorSkill6->SetActorLocation(FVector{ 2874.0f, -858.0f });
	}

	{
		FloorSkill7 = GetWorld()->SpawnActor<AFloorSkill>();
		FloorSkill7->SetActorLocation(FVector{ 3174.0f, -858.0f });
	}
}

void ASeren::FloorExplosionSetting(float _DeltaTime)
{
	FloorExplosion1(_DeltaTime);
	FloorExplosion2(_DeltaTime);
	FloorExplosion3(_DeltaTime);
	FloorExplosion4(_DeltaTime);
	FloorExplosion5(_DeltaTime);
	FloorExplosion6(_DeltaTime);
	FloorExplosion7(_DeltaTime);
}

void ASeren::FloorExplosion1(float _DeltaTime)
{
	Floor1CoolTime -= _DeltaTime;


	if (true == FloorSkill1->GetFloorSkill()->IsCurAnimationEnd() && true == bIsExplosion1)
	{
		Floor1CoolTime = ExplosionRandom1.Randomfloat(5.0f, 19.0f);
		bIsExplosion1 = false;
	}

	if (0 >= Floor1CoolTime && false == bIsExplosion1)
	{
		FloorSkill1->SetActive(true);
		bIsExplosion1 = true;
	}
}


void ASeren::FloorExplosion2(float _DeltaTime)
{
	Floor2CoolTime -= _DeltaTime;


	if (true == FloorSkill2->GetFloorSkill()->IsCurAnimationEnd() && true == bIsExplosion2)
	{
		Floor2CoolTime = ExplosionRandom2.Randomfloat(5.0f, 18.0f);
		bIsExplosion2 = false;
	}

	if (0 >= Floor2CoolTime && false == bIsExplosion2)
	{
		FloorSkill2->SetActive(true);
		bIsExplosion2 = true;
	}
}


void ASeren::FloorExplosion3(float _DeltaTime)
{
	Floor3CoolTime -= _DeltaTime;


	if (true == FloorSkill3->GetFloorSkill()->IsCurAnimationEnd() && true == bIsExplosion3)
	{
		Floor3CoolTime = ExplosionRandom1.Randomfloat(5.0f, 17.0f);
		bIsExplosion3 = false;
	}

	if (0 >= Floor3CoolTime && false == bIsExplosion3)
	{
		FloorSkill3->SetActive(true);
		bIsExplosion3 = true;
	}
}


void ASeren::FloorExplosion4(float _DeltaTime)
{
	Floor4CoolTime -= _DeltaTime;


	if (true == FloorSkill4->GetFloorSkill()->IsCurAnimationEnd() && true == bIsExplosion4)
	{
		Floor4CoolTime = ExplosionRandom4.Randomfloat(5.0f, 18.0f);
		bIsExplosion4 = false;
	}

	if (0 >= Floor4CoolTime && false == bIsExplosion4)
	{
		FloorSkill4->SetActive(true);
		bIsExplosion4 = true;
	}
}


void ASeren::FloorExplosion5(float _DeltaTime)
{
	Floor5CoolTime -= _DeltaTime;


	if (true == FloorSkill5->GetFloorSkill()->IsCurAnimationEnd() && true == bIsExplosion5)
	{
		Floor5CoolTime = ExplosionRandom5.Randomfloat(5.0f, 19.0f);
		bIsExplosion5 = false;
	}

	if (0 >= Floor5CoolTime && false == bIsExplosion5)
	{
		FloorSkill5->SetActive(true);
		bIsExplosion5 = true;
	}
}


void ASeren::FloorExplosion6(float _DeltaTime)
{
	Floor6CoolTime -= _DeltaTime;


	if (true == FloorSkill6->GetFloorSkill()->IsCurAnimationEnd() && true == bIsExplosion6)
	{
		Floor6CoolTime = ExplosionRandom6.Randomfloat(5.0f, 20.0f);
		bIsExplosion6 = false;
	}

	if (0 >= Floor6CoolTime && false == bIsExplosion6)
	{
		FloorSkill6->SetActive(true);
		bIsExplosion6 = true;
	}
}


void ASeren::FloorExplosion7(float _DeltaTime)
{
	Floor7CoolTime -= _DeltaTime;


	if (true == FloorSkill7->GetFloorSkill()->IsCurAnimationEnd() && true == bIsExplosion7)
	{
		Floor7CoolTime = ExplosionRandom7.Randomfloat(5.0f, 20.0f);
		bIsExplosion7 = false;
	}

	if (0 >= Floor7CoolTime && false == bIsExplosion7)
	{
		FloorSkill7->SetActive(true);
		bIsExplosion7 = true;
	}
}




void ASeren::FloorExplosionCheck(float _DeltaTime)
{
	if (false == bIsExplosion1)
	{
		FloorSkill1->SetActive(false);
	}

	if (false == bIsExplosion2)
	{
		FloorSkill2->SetActive(false);
	}

	if (false == bIsExplosion3)
	{
		FloorSkill3->SetActive(false);
	}

	if (false == bIsExplosion4)
	{
		FloorSkill4->SetActive(false);
	}

	if (false == bIsExplosion5)
	{
		FloorSkill5->SetActive(false);
	}

	if (false == bIsExplosion6)
	{
		FloorSkill6->SetActive(false);
	}

	if (false == bIsExplosion7)
	{
		FloorSkill7->SetActive(false);
	}
}
