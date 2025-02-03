#pragma once

#include "SkillManager.h"

class AIshtar_Ball : public ASkillManager
{
public:
	// 持失切 社瑚切
	AIshtar_Ball();
	~AIshtar_Ball();

	// delete funcion

	AIshtar_Ball(const AIshtar_Ball& _Other) = delete;
	AIshtar_Ball(AIshtar_Ball&& _Other) noexcept = delete;
	AIshtar_Ball& operator=(const AIshtar_Ball& _Other) = delete;
	AIshtar_Ball& operator=(AIshtar_Ball&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;


protected:

private:
	class APlayer* Player = nullptr;

	std::shared_ptr<class USpriteRenderer> Ishtar_Ball;

	std::shared_ptr<class UCollision> Collision;

	FVector BallSpawnLocation = FVector::ZERO;

	float Curlocation = 0.0f;
	float Playerlocation = 0.0f;
	float DifferLocation = 0.0f;
	float Length = 300.0f;
	int IshNum = 1;

	bool LeftShot = false;
	bool DirCheck = false;
	bool bIsHit = false;
	float IshtarAtt = 1.0f;
};

