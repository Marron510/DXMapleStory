#pragma once

#include "SkillManager.h"

class AIshtar : public ASkillManager
{
public:
	// 持失切 社瑚切
	AIshtar();
	~AIshtar();

	// delete funcion

	AIshtar(const AIshtar& _Other) = delete;
	AIshtar(AIshtar&& _Other) noexcept = delete;
	AIshtar& operator=(const AIshtar& _Other) = delete;
	AIshtar& operator=(AIshtar&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;


protected:

private:
	std::shared_ptr<class USpriteRenderer> Ishtar;

};

