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
#include "Aura.h"


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

	DropAtomSetting(_DeltaTime);
}


void ASeren::SerenDeathCheck()
{
	if (true == bIsDead)
	{
		return;
	}

	if (0 >= GetGameInstance<MapleInstance>()->SerenStatus1.CurHp && false == bIsDead)
	{
		Collision->SetActive(false);
		SerenFSM.ChangeState(ESerenState::Die);
		bIsDead = true;
	}
}

void ASeren::SmallAtomInit()
{
	// x축 위치
	{
		SmallAtom1 = GetWorld()->SpawnActor<ASmallAtom>();
		SmallAtom1->SetActorLocation(FVector{ MapstartX + 200.0f, -458.0f });
		SmallAtom1->SetActive(false);
	}

	{
		SmallAtom2 = GetWorld()->SpawnActor<ASmallAtom>();
		SmallAtom2->SetActorLocation(FVector{ MapstartX + 500.0f, -458.0f });
		SmallAtom2->SetActive(false);
	}

	{
		SmallAtom3 = GetWorld()->SpawnActor<ASmallAtom>();
		SmallAtom3->SetActorLocation(FVector{ MapstartX + 800.0f, -458.0f });
		SmallAtom3->SetActive(false);
	}

	{
		SmallAtom4 = GetWorld()->SpawnActor<ASmallAtom>();
		SmallAtom4->SetActorLocation(FVector{ MapstartX + 1000.0f, -458.0f });
		SmallAtom4->SetActive(false);
	}

	{
		SmallAtom5 = GetWorld()->SpawnActor<ASmallAtom>();
		SmallAtom5->SetActorLocation(FVector{ MapstartX + 1200.0f, -458.0f });
		SmallAtom5->SetActive(false);
	}

	{
		SmallAtom6 = GetWorld()->SpawnActor<ASmallAtom>();
		SmallAtom6->SetActorLocation(FVector{ MapstartX + 1600.0f, -458.0f });
		SmallAtom6->SetActive(false);
	}

	{
		SmallAtom7 = GetWorld()->SpawnActor<ASmallAtom>();
		SmallAtom7->SetActorLocation(FVector{ MapstartX + 1900.0f, -458.0f });
		SmallAtom7->SetActive(false);
	}



}

void ASeren::DropAtomSetting(float _DeltaTime)
{
	DropAtom1(_DeltaTime);
	DropAtom2(_DeltaTime);
	DropAtom3(_DeltaTime);
	DropAtom4(_DeltaTime);
	DropAtom5(_DeltaTime);
	DropAtom6(_DeltaTime);
	DropAtom7(_DeltaTime);
}

void ASeren::DropAtom1(float _DeltaTime)
{
	SmallAtom1CoolTime -= _DeltaTime;

	if (0.0f >= SmallAtom1CoolTime && false == bIsAtom1Init)
	{
		SmallAtom1->SetActive(true);
		bIsAtom1Init = true;
	}

	if (false == SmallAtom1->GetIsEnd())
	{
		return;
	}
	
	if (0.0f >= SmallAtom1CoolTime)
	{
		SmallAtom1->Restart();
		float AtomLocation = SmallAtomLocationRandom1.Randomfloat(1400.0f, 3300.0f);
		SmallAtom1->SetActorLocation(FVector{ AtomLocation , -458.0f});
		SmallAtom1CoolTime = SmallAtomRandom1.Randomfloat(3.0f, 15.0f);
		return;
	}
}

void ASeren::DropAtom2(float _DeltaTime)
{
	SmallAtom2CoolTime -= _DeltaTime;

	if (0.0f >= SmallAtom2CoolTime && false == bIsAtom2Init)
	{
		SmallAtom2->SetActive(true);
		bIsAtom2Init = true;
	}

	if (false == SmallAtom2->GetIsEnd())
	{
		return;
	}

	if (0.0f >= SmallAtom2CoolTime)
	{
		SmallAtom2->Restart();
		float AtomLocation2 = SmallAtomLocationRandom2.Randomfloat(1700.0f, 3100.0f);
		SmallAtom2->SetActorLocation(FVector{ AtomLocation2, -458.0f });
		SmallAtom2CoolTime = SmallAtomRandom2.Randomfloat(4.0f, 15.0f);
		return;
	}
}

void ASeren::DropAtom3(float _DeltaTime)
{
	SmallAtom3CoolTime -= _DeltaTime;

	if (0.0f >= SmallAtom3CoolTime && false == bIsAtom3Init)
	{
		SmallAtom3->SetActive(true);
		bIsAtom3Init = true;
	}

	if (false == SmallAtom3->GetIsEnd())
	{
		return;
	}

	if (0.0f >= SmallAtom3CoolTime)
	{
		SmallAtom3->Restart();
		float AtomLocation3 = SmallAtomLocationRandom3.Randomfloat(1800.0f, 2700.0f);
		SmallAtom3->SetActorLocation(FVector{ AtomLocation3 , -458.0f });
		SmallAtom3CoolTime = SmallAtomRandom3.Randomfloat(5.0f, 15.0f);
		return;
	}
}

void ASeren::DropAtom4(float _DeltaTime)
{
	SmallAtom4CoolTime -= _DeltaTime;

	if (0.0f >= SmallAtom4CoolTime && false == bIsAtom4Init)
	{
		SmallAtom4->SetActive(true);
		bIsAtom4Init = true;
	}

	if (false == SmallAtom4->GetIsEnd())
	{
		return;
	}

	if (0.0f >= SmallAtom4CoolTime)
	{
		SmallAtom4->Restart();
		float AtomLocation4 = SmallAtomLocationRandom4.Randomfloat(2500.0f, 3300.0f);
		SmallAtom4->SetActorLocation(FVector{ AtomLocation4 , -458.0f });
		SmallAtom4CoolTime = SmallAtomRandom4.Randomfloat(3.0f, 15.0f);
		return;
	}
}

void ASeren::DropAtom5(float _DeltaTime)
{
	SmallAtom5CoolTime -= _DeltaTime;

	if (0.0f >= SmallAtom5CoolTime && false == bIsAtom5Init)
	{
		SmallAtom5->SetActive(true);
		bIsAtom5Init = true;
	}

	if (false == SmallAtom5->GetIsEnd())
	{
		return;
	}

	if (0.0f >= SmallAtom5CoolTime)
	{
		SmallAtom5->Restart();
		float AtomLocation5 = SmallAtomLocationRandom5.Randomfloat(1400.0f, 1900.0f);
		SmallAtom5->SetActorLocation(FVector{ AtomLocation5 , -458.0f });
		SmallAtom5CoolTime = SmallAtomRandom5.Randomfloat(4.0f, 15.0f);
		return;
	}

}


void ASeren::DropAtom6(float _DeltaTime)
{
	SmallAtom6CoolTime -= _DeltaTime;

	if (0.0f >= SmallAtom6CoolTime && false == bIsAtom6Init)
	{
		SmallAtom6->SetActive(true);
		bIsAtom6Init = true;
	}

	if (false == SmallAtom6->GetIsEnd())
	{
		return;
	}

	if (0.0f >= SmallAtom6CoolTime)
	{
		SmallAtom6->Restart();
		float AtomLocation6 = SmallAtomLocationRandom6.Randomfloat(2300.0f, 2600.0f);
		SmallAtom6->SetActorLocation(FVector{ AtomLocation6 , -458.0f });
		SmallAtom6CoolTime = SmallAtomRandom6.Randomfloat(3.0f, 15.0f);
		return;
	}
}

void ASeren::DropAtom7(float _DeltaTime)
{
	SmallAtom7CoolTime -= _DeltaTime;

	if (0.0f >= SmallAtom7CoolTime && false == bIsAtom7Init)
	{
		SmallAtom7->SetActive(true);
		bIsAtom7Init = true;
	}

	if (false == SmallAtom7->GetIsEnd())
	{
		return;
	}

	if (0.0f >= SmallAtom7CoolTime)
	{
		SmallAtom7->Restart();
		float AtomLocation7 = SmallAtomLocationRandom7.Randomfloat(1400.0f, 3300.0f);
		SmallAtom7->SetActorLocation(FVector{ AtomLocation7 , -458.0f });
		SmallAtom7CoolTime = SmallAtomRandom7.Randomfloat(3.0f, 15.0f);
		return;
	}
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
		FloorSkill1->SetActive(false);
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
		FloorSkill2->SetActive(false);
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
		FloorSkill3->SetActive(false);
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
		FloorSkill4->SetActive(false);
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
		FloorSkill5->SetActive(false);
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
		FloorSkill6->SetActive(false);
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
		FloorSkill7->SetActive(false);
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


