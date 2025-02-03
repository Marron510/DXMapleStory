#pragma once
#include "SkillManager.h"

class AStrikeDualShot_Ball : public ASkillManager
{
public:
	// 持失切 社瑚切
	AStrikeDualShot_Ball();
	~AStrikeDualShot_Ball();

	// delete funcion

	AStrikeDualShot_Ball(const AStrikeDualShot_Ball& _Other) = delete;
	AStrikeDualShot_Ball(AStrikeDualShot_Ball&& _Other) noexcept = delete;
	AStrikeDualShot_Ball& operator=(const AStrikeDualShot_Ball& _Other) = delete;
	AStrikeDualShot_Ball& operator=(AStrikeDualShot_Ball&& _Other) noexcept = delete;


	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

protected:

private:
	class APlayer* Player = nullptr;

	std::shared_ptr<class USpriteRenderer> StrikeDualShot_Ball;

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
	float StrikeDualShotAtt = 1.0f;
};

