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
	void ASting(float _DeltaTime);
	
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
	

	UFSMStateManager SerenFSM;


	bool bIsIdle= true;
	bool bIsSting = false;
	bool bIsDead = false;

	void SerenDeathCheck();


	void PlayerLocationCheck(float _DeltaTime);

	float SkillCoolTime = 0.0f;
	float StimgCoolTime = 3.0f;
};

