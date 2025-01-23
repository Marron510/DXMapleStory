#pragma once

#include <EngineCore/Actor.h> 

class AFloorSkill : public AActor
{
public:
	// 持失切 社瑚切
	AFloorSkill();
	~AFloorSkill();

	// delete funcion

	AFloorSkill(const AFloorSkill& _Other) = delete;
	AFloorSkill(AFloorSkill&& _Other) noexcept = delete;
	AFloorSkill& operator=(const AFloorSkill& _Other) = delete;
	AFloorSkill& operator=(AFloorSkill&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	std::shared_ptr<class USpriteRenderer> GetFloorSkill()
	{
		return FloorSkill;
	}

protected:

private:
	std::shared_ptr<class USpriteRenderer> FloorSkill;
	std::shared_ptr<class UCollision> Collision;

	class APlayer* Player = nullptr;

	float WaitTime = 1.3f;
	float HitTime = 1.3f;
	float ExplosionDamage = 10.0f;
	float FloorY = -280.0f;
};

