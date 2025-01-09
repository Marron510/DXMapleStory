#pragma once
#include "SkillManager.h"

class AChargeDrive : public ASkillManager
{
public:
	// 持失切 社瑚切
	AChargeDrive();
	~AChargeDrive();

	// delete funcion

	AChargeDrive(const AChargeDrive& _Other) = delete;
	AChargeDrive(AChargeDrive&& _Other) noexcept = delete;
	AChargeDrive& operator=(const AChargeDrive& _Other) = delete;
	AChargeDrive& operator=(AChargeDrive&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;


protected:

private:
	std::shared_ptr<class USpriteRenderer> ChargeDrive_Front;
	std::shared_ptr<class USpriteRenderer> ChargeDrive_Back;

	std::shared_ptr<class UCollision> Collision;
};

