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
	
	// ����
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
	// �÷��̾� -> ������ �÷��̾� �˾ƾ���
	class APlayer* Player = nullptr;
	FVector CurPlayerLocation = FVector::ZERO;

	std::shared_ptr<class USpriteRenderer> SerenRender;

	std::shared_ptr<class USerenCollision> Collision;
	std::shared_ptr<class UCollision> CheckCollision;
	std::shared_ptr<class UCollision> OutRangeCollision;

	std::shared_ptr<class UCollision> StingCollision;
	std::shared_ptr<class UCollision> RushCollision;
	

	UFSMStateManager SerenFSM;

	// �ٰŸ� ���Ÿ� üũ

	bool bIsInRange = false;

	// ���� üũ
	bool bIsIdle= true;
	bool bIsSting = false;
	bool bIsRush = false;
	bool bIsDead = false;

	// �÷��̾� ��ġ - ���� ��ġ
	FVector DifferentLocation = FVector::ZERO;

	void SerenDeathCheck();


	void PlayerLocationCheck(float _DeltaTime);

	// ���� ��ų Ƚ��
	int StingCount = 0; // �ִ� 2ȸ

	// ���� ��ų ������
	float StingDamage = 10.0f;
	float RushDamage = 10.0f;
	float AuraDamage = 30.0f;


	// ��Ÿ��
	float SkillCoolTime = 0.0f;
	float StimgCoolTime = 1.5f;
	float RushCoolTime = 3.0f;
};

