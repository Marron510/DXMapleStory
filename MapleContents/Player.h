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
	void SetColImage(std::string_view _ColImageName);


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;



private:
	std::shared_ptr<class USpriteRenderer> PlayerRenderer;
	

	std::shared_ptr<class UCollision> Collision;

	std::shared_ptr<class UTimeEventComponent> TimeEventComponent;
	
	UFSMStateManager FSM;

	// 콜리전
	UEngineWinImage ColImage;

	float PlayerSpeed = 260.0f;
	FVector GravityForce = FVector::DOWN;
	FVector JumpPower = FVector(0.0f, 580.0f);
	
	FVector CurrentVelocity = FVector::ZERO; // 현재 이동 속도
	FVector TargetVelocity = FVector::ZERO;         // 목표 이동 속도

	FVector JumpVelocity = FVector::ZERO;        
	FVector TargetJumpVelocity = FVector::ZERO;

	bool bIsGround = false;
	bool bIsCharge = false;
	bool bIsJumping = false;
	bool bIsJumpRight = false;
	bool bIsJumpMoveEnd= false;
	bool bIsHighKick = false;

	void StateInit();

	void Idle(float _DeltaTime);
	void Prone(float _DeltaTime);
	void Walk(float _DeltaTime);
	void IdleJump(float _DeltaTime);
	void WalkJump(float _DeltaTime);
	void UseSkill(float _DeltaTime);

	void Gravity(float _DeltaTime);
	void AntiGravity(float _DeltaTime);
	void PlayerGroundCheck(FVector _MovePos);
};

