#pragma once
#include <EngineCore/Actor.h>
#include <EngineBase/FSMStateManager.h>
#include <EngineBase/EngineRandom.h>

class ASeren : public AActor
{
public:
	ASeren();
	~ASeren();

	// delete funcion

	ASeren(const ASeren& _Other) = delete;
	ASeren(ASeren&& _Other) noexcept = delete;
	ASeren& operator=(const ASeren& _Other) = delete;
	ASeren& operator=(ASeren&& _Other) noexcept = delete;

	void StateInit();
	
	// 공통
	void Idle(float _DeltaTime);
	void Walk(float _DeltaTime);
	void Rush(float _DeltaTime);
	void Sting(float _DeltaTime);
	void SwordAura(float _DeltaTime);
	void SmallLaser(float _DeltaTime);

	void Die(float _DeltaTime);
	
	
	// 맵패턴

	void SmallAtomInit();
	void DropAtomSetting(float _DeltaTime);
	void DropAtom1(float _DeltaTime);
	void DropAtom2(float _DeltaTime);
	void DropAtom3(float _DeltaTime);
	void DropAtom4(float _DeltaTime);
	void DropAtom5(float _DeltaTime);
	void DropAtom6(float _DeltaTime);
	void DropAtom7(float _DeltaTime);


	void FloorExplosionInit();
	void FloorExplosionSetting(float _DeltaTime);
	void FloorExplosion1(float _DeltaTime);
	void FloorExplosion2(float _DeltaTime);
	void FloorExplosion3(float _DeltaTime);
	void FloorExplosion4(float _DeltaTime);
	void FloorExplosion5(float _DeltaTime);
	void FloorExplosion6(float _DeltaTime);
	void FloorExplosion7(float _DeltaTime);
	void FloorExplosionCheck(float _DeltaTime);

	std::shared_ptr<class USerenCollision> GetSerenCollision()
	{
		return Collision;
	}
	std::shared_ptr<class USpriteRenderer> GetSerenRender()
	{
		return SerenRender;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	// 플레이어 -> 세렌은 플레이어 알아야함
	class APlayer* Player = nullptr;
	FVector CurPlayerLocation = FVector::ZERO;

	// 세렌
	std::shared_ptr<class USpriteRenderer> SerenRender;

	// 세렌 콜리전
	std::shared_ptr<class USerenCollision> Collision;
	std::shared_ptr<class UCollision> CheckCollision;
	std::shared_ptr<class UCollision> OutRangeCollision;

	std::shared_ptr<class UCollision> StingCollision;
	std::shared_ptr<class UCollision> RushCollision;
	
	// 세렌 스킬 
	// 레이저
	std::shared_ptr<class ASmall8Laser> Small8Laser;
	
	// 바닥 스킬
	std::shared_ptr<class AFloorSkill> FloorSkill1;
	std::shared_ptr<class AFloorSkill> FloorSkill2;
	std::shared_ptr<class AFloorSkill> FloorSkill3;
	std::shared_ptr<class AFloorSkill> FloorSkill4;
	std::shared_ptr<class AFloorSkill> FloorSkill5;
	std::shared_ptr<class AFloorSkill> FloorSkill6;
	std::shared_ptr<class AFloorSkill> FloorSkill7;

	// 천장 스킬
	std::shared_ptr<class ASmallAtom> SmallAtom1;
	std::shared_ptr<class ASmallAtom> SmallAtom2;
	std::shared_ptr<class ASmallAtom> SmallAtom3;
	std::shared_ptr<class ASmallAtom> SmallAtom4;
	std::shared_ptr<class ASmallAtom> SmallAtom5;
	std::shared_ptr<class ASmallAtom> SmallAtom6;
	std::shared_ptr<class ASmallAtom> SmallAtom7;



	UFSMStateManager SerenFSM;

	// 근거리 원거리 체크

	bool bIsInRange = false;

	// 상태 체크
	bool bIsIdle= true;
	bool bIsSting = false;
	bool bIsRush = false;
	bool bIsSwordAura = false;
	bool bIsSmalllaser= false;
	bool bIsDead = false;
	bool bIsAuraDir = false;
	bool bIsAuraLeft = false;
	bool bIsAuraCheck = false;

	// 맵패턴 상태 체크
	bool bIsExplosion1 = false;
	bool bIsExplosion2 = false;
	bool bIsExplosion3 = false;
	bool bIsExplosion4 = false;
	bool bIsExplosion5 = false;
	bool bIsExplosion6 = false;
	bool bIsExplosion7 = false;


	// 플레이어 위치 - 세렌 위치
	FVector DifferentLocation = FVector::ZERO;

	void SerenDeathCheck();
	
	// 맵 시작 끝 X좌표 
	float MapstartX = 1200.0f;
	float MapEndX = 3500.0f;

	// 세렌 스킬 횟수
	int StingCount = 0; // 최대 2회

	// 세렌 콜리전 거리

	float OutRangeDistance = 2000.0f;
	float InRangeDistance = 800.0f;

	// 러쉬 거리
	float RushDistance = 645.0f;

	// 세렌 스킬 데미지
	float StingDamage = 10.0f;
	float RushDamage = 10.0f;
	float AuraDamage = 30.0f;


	// 쿨타임
	float SkillCoolTime = 0.0f;
	float AuraCoolTime = 1.0f;
	float StimgCoolTime = 1.0f;
	float RushCoolTime = 3.0f;
	
	// 맵패턴 쿨타임
	float Floor1CoolTime = 10.0f;
	float Floor2CoolTime = 8.0f;
	float Floor3CoolTime = 14.0f;
	float Floor4CoolTime = 19.0f;
	float Floor5CoolTime = 12.0f;
	float Floor6CoolTime = 7.0f;
	float Floor7CoolTime = 5.0f;

	class UEngineRandom ExplosionRandom1;
	class UEngineRandom ExplosionRandom2;
	class UEngineRandom ExplosionRandom3;
	class UEngineRandom ExplosionRandom4;
	class UEngineRandom ExplosionRandom5;
	class UEngineRandom ExplosionRandom6;
	class UEngineRandom ExplosionRandom7;

	class UEngineRandom SmallAtomRandom1;
	class UEngineRandom SmallAtomRandom2;
	class UEngineRandom SmallAtomRandom3;
	class UEngineRandom SmallAtomRandom4;
	class UEngineRandom SmallAtomRandom5;
	class UEngineRandom SmallAtomRandom6;
	class UEngineRandom SmallAtomRandom7;

	class UEngineRandom SmallAtomLocationRandom1;
	class UEngineRandom SmallAtomLocationRandom2;
	class UEngineRandom SmallAtomLocationRandom3;
	class UEngineRandom SmallAtomLocationRandom4;
	class UEngineRandom SmallAtomLocationRandom5;
	class UEngineRandom SmallAtomLocationRandom6;
	class UEngineRandom SmallAtomLocationRandom7;

	float SmallAtom1CoolTime = 15.0f;
	float SmallAtom2CoolTime = 20.0f;
	float SmallAtom3CoolTime = 12.0f;
	float SmallAtom4CoolTime = 10.0f;
	float SmallAtom5CoolTime = 7.0f;
	float SmallAtom6CoolTime = 16.0f;
	float SmallAtom7CoolTime = 22.0f;

	bool bIsAtom1Init = false;
	bool bIsAtom2Init = false;
	bool bIsAtom3Init = false;
	bool bIsAtom4Init = false;
	bool bIsAtom5Init = false;
	bool bIsAtom6Init = false;
	bool bIsAtom7Init = false;

	float AuraSpeed = 160.0f;
	bool bIsAuraSpawn = false;

};

