#pragma once
#include "SkillManager.h"

class AUnicornSpike : public ASkillManager
{
public:
	// 持失切 社瑚切
	AUnicornSpike();
	~AUnicornSpike();

	// delete funcion

	AUnicornSpike(const AUnicornSpike& _Other) = delete;
	AUnicornSpike(AUnicornSpike&& _Other) noexcept = delete;
	AUnicornSpike& operator=(const AUnicornSpike& _Other) = delete;
	AUnicornSpike& operator=(AUnicornSpike&& _Other) noexcept = delete;
	
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

protected:

private:
	std::shared_ptr<class USpriteRenderer> UnicornSpike;

	std::shared_ptr<class UCollision> Collision;
};

