#pragma once
#include <EngineCore/Pawn.h>
#include <EngineBase/FSMStateManager.h>
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

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> PlayerRenderer;

	std::shared_ptr<class UTimeEventComponent> TimeEventComponent;
	
	UFSMStateManager FSM;

	float PlayerSpeed = 300.0f;


	bool bIsGround = false;
	bool bIsCharge = false;
	bool bIsHighKick = false;
	void StateInit();

	void Idle(float _DeltaTime);
	void Prone(float _DeltaTime);
	void Walk(float _DeltaTime);
	void Jump(float _DeltaTime);
	void UseSkill(float _DeltaTime);
};

