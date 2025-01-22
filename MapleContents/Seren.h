#pragma once
#include <EngineCore/Actor.h>
#include <EngineBase/FSMStateManager.h>

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
	
	void Die(float _DeltaTime);

	std::shared_ptr<class USerenCollision> GetSerenCollision()
	{
		return Collision;
	}


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	// 플레이어 -> 세렌은 플레이어 알아야함
	class APlayer* Player = nullptr;
	FVector CurPlayerLocation = FVector::ZERO;

	std::shared_ptr<class USpriteRenderer> SerenRender;

	std::shared_ptr<class USerenCollision> Collision;
	std::shared_ptr<class UCollision> CheckCollision;
	std::shared_ptr<class UCollision> OutRangeCollision;

	std::shared_ptr<class UCollision> StingCollision;
	std::shared_ptr<class UCollision> RushCollision;
	

	UFSMStateManager SerenFSM;

	// 근거리 원거리 체크

	bool bIsInRange = false;

	// 상태 체크
	bool bIsIdle= true;
	bool bIsSting = false;
	bool bIsRush = false;
	bool bIsDead = false;

	// 플레이어 위치 - 세렌 위치
	FVector DifferentLocation = FVector::ZERO;

	void SerenDeathCheck();


	void PlayerLocationCheck(float _DeltaTime);

	// 세렌 스킬 횟수
	int StingCount = 0; // 최대 2회

	// 세렌 스킬 데미지
	float StingDamage = 10.0f;
	float RushDamage = 10.0f;
	float AuraDamage = 30.0f;


	// 쿨타임
	float SkillCoolTime = 0.0f;
	float StimgCoolTime = 1.5f;
	float RushCoolTime = 3.0f;
};

