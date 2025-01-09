#pragma once

#include "SkillManager.h"

class AHighKick : public ASkillManager
{
public:
	// 持失切 社瑚切
	AHighKick();
	~AHighKick();

	// delete funcion

	AHighKick(const AHighKick& _Other) = delete;
	AHighKick(AHighKick&& _Other) noexcept = delete;
	AHighKick& operator=(const AHighKick& _Other) = delete;
	AHighKick& operator=(AHighKick&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

protected:

private:
	std::shared_ptr<class USpriteRenderer> HighKick;

	std::shared_ptr<class UCollision> Collision;
};

