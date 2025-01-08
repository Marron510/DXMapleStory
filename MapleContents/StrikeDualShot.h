#pragma once
#include "SkillManager.h"

class AStrikeDualShot : public ASkillManager
{
public:
	// 持失切 社瑚切
	AStrikeDualShot();
	~AStrikeDualShot();

	// delete funcion

	AStrikeDualShot(const AStrikeDualShot& _Other) = delete;
	AStrikeDualShot(AStrikeDualShot&& _Other) noexcept = delete;
	AStrikeDualShot& operator=(const AStrikeDualShot& _Other) = delete;
	AStrikeDualShot& operator=(AStrikeDualShot&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

protected:

private:
	std::shared_ptr<class USpriteRenderer> StrikeDaulShotFront = nullptr;
	std::shared_ptr<class USpriteRenderer> StrikeDaulShotBack = nullptr;
};

