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
	
	class APlayer* Player = nullptr;
	FVector DifferentLocation = FVector::ZERO;
	
	// �÷��̾� ��ġüũ �ߴ���?
	bool bLocationCheck = false;
	
	// ������
	float AuraDamage = 20000.0f;
	float AuraSpeed = 160.0f;
	float AuraGage = 10.0f;

	float MapstartX = 1200.0f;
	float MapEndX = 3500.0f;
};

