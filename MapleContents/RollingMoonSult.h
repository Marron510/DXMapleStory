#pragma once
#include "SkillManager.h"

class ARollingMoonSult : public ASkillManager
{
public:
	// 持失切 社瑚切
	ARollingMoonSult();
	~ARollingMoonSult();

	// delete funcion

	ARollingMoonSult(const ARollingMoonSult& _Other) = delete;
	ARollingMoonSult(ARollingMoonSult&& _Other) noexcept = delete;
	ARollingMoonSult& operator=(const ARollingMoonSult& _Other) = delete;
	ARollingMoonSult& operator=(ARollingMoonSult&& _Other) noexcept = delete;
	
	void BeginPlay();
	void Tick(float _DeltaTime);


	static float RollingMoonSultCoolTime;

protected:

private:
	std::shared_ptr<class USpriteRenderer> RollingMoonSult;
	std::shared_ptr<class USpriteRenderer> RollingMoonSultHit;
	std::shared_ptr<class UCollision> Collision;

	class APlayer* Player = nullptr;
	bool bIsCanUse = false;
	bool bIsHit = false;
	float RollingMoonSultAtt = 5.0f;
};

