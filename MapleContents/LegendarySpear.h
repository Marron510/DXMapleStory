#pragma once
#include "SkillManager.h"

class ALegendarySpear : public ASkillManager
{
public:
	// 持失切 社瑚切
	ALegendarySpear();
	~ALegendarySpear();

	// delete funcion

	ALegendarySpear(const ALegendarySpear& _Other) = delete;
	ALegendarySpear(ALegendarySpear&& _Other) noexcept = delete;
	ALegendarySpear& operator=(const ALegendarySpear& _Other) = delete;
	ALegendarySpear& operator=(ALegendarySpear&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	static float LegendarySpearCoolTime;

protected:

private:
	std::shared_ptr<class USpriteRenderer> LegendarySpearFront;
	std::shared_ptr<class USpriteRenderer> LegendarySpearMid;
	std::shared_ptr<class USpriteRenderer> LegendarySpearHit;

	std::shared_ptr<class UCollision> Collision;


	class APlayer* Player = nullptr;
	bool bIsCanUse = false;
	bool bIsHit = false;
	float LegendarySpearAtt = 50.0f;
};

