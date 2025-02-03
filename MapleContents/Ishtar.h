#pragma once

#include "SkillManager.h"

class AIshtar : public ASkillManager
{
public:
	// ������ �Ҹ���
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

