#pragma once
#include <EngineCore/Pawn.h>
#include <EngineBase/FSMStateManager.h>
#include <EnginePlatform/EngineWinImage.h>
#include "EventCharacter.h"


class APlayer : public APawn, public AEventCharacter
{
public:
	// constrcuter destructer
	APlayer();
	~APlayer();

	// delete Function
	APlayer(const APlayer& _Other) = delete;
	APlayer(APlayer&& _Other) noexcept = delete;
	APlayer& operator=(const APlayer& _Other) = delete;
	APlayer& operator=(APlayer&& _Other) noexcept = delete;



	std::shared_ptr<class USpriteRenderer> GetRenderer()
	{
		return PlayerRenderer;
	}

	bool IsGround()
	{
		return bIsGround;
	}

	void bIsdamageOn()
	{
		bIsdamage = true; 
	}
	bool GetbIsDirLeft()
	{
		return bIsDirLeft;
	}

	// 데미지 체크
	bool bIsdamage = false;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;



private:
	std::shared_ptr<class USpriteRenderer> PlayerRenderer;
	
	std::shared_ptr<class UCollision> PlayerCollision;
	std::shared_ptr<class UCollision> MoveCollision;

	std::shared_ptr<class UTimeEventComponent> TimeEventComponent;
	
	UFSMStateManager FSM;

	// 콜리전

	float PlayerSpeed = 260.0f;
	float JumpMove = 0.85f;
	float SlowJumpMove = 0.2f;
	float UpJumpPower = 0.04f;
	FVector GravityForce = FVector::ZERO;
	FVector JumpPower = FVector(0.0f, 600.0f);
	FVector DoubleJumpPower = FVector(0.0f, 800.0f);
	
	FVector CurrentVelocity = FVector::ZERO; // 현재 이동 속도
	FVector TargetVelocity = FVector::ZERO;         // 목표 이동 속도

	FVector JumpVelocity = FVector::ZERO;        
	FVector TargetJumpVelocity = FVector::ZERO;

	bool bIsGround = false;
	bool bIsCharge = false;
	bool bIsJumping = false;
	bool bIsJumpRight = false;
	bool bIsJumpMoveEnd= false;
	bool bIsIdleJump = true;
	bool bIsDirLeft = true;


	bool bIsLeafUsing = false;
	bool bIsHighKick = false;
	
	bool bIsSkillUsing = false;
	bool bIsZeroGravity = false;

	void StateInit();

	// 움직임
	void Idle(float _DeltaTime);
	void Prone(float _DeltaTime);
	//void Hit(float _DeltaTime);
	void Walk(float _DeltaTime);
	void IdleJump(float _DeltaTime);
	void WalkJump(float _DeltaTime);
	void Air(float _DeltaTime);
	void UpJump(float _DeltaTime);
	void WalkUpJump(float _DeltaTime);
	
	//스킬
	void LeafTornado(float _DeltaTime);
	void WrathOfEnril(float _DeltaTime);
	void LegendarySpear(float _DeltaTime);
	void Ishtar(float _DeltaTime);

	void IdleUseSkill(float _DeltaTime);
	void WalkUseSkill(float _DeltaTime);
	void AirUseSkill(float _DeltaTime);

	void Gravity(float _DeltaTime);


	// 이슈 화살 생성 시간
	float IshballTime = 0.2f;
	// 이슈 위치
	int IshNum = 0;


	// 무적 시간
	float CanDamageTime = 0.0f;
	float invincibilityTime = 2.0f;
};

