#pragma once

#include <EngineCore/Actor.h> 

class AAura : public AActor
{
public:
	// ������ �Ҹ���
	AAura();
	~AAura();

	// delete funcion

	AAura(const AAura& _Other) = delete;
	AAura(AAura&& _Other) noexcept = delete;
	AAura& operator=(const AAura& _Other) = delete;
	AAura& operator=(AAura&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void Move(float _DeltaTime);
protected:

private:
	std::shared_ptr<class USpriteRenderer> Aura;
	std::shared_ptr<class UCollision> Collision;
	

	FVector DifferentLocation = FVector::ZERO;
	
	// �÷��̾� ��ġüũ �ߴ���?
	bool bLocationCheck = false;
	
	// ������
	float AuraDamage = 30.0f;
};

