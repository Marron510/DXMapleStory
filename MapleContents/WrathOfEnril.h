#pragma once
#include "SkillManager.h"

class AWrathOfEnril: public ASkillManager
{
public:
	// 持失切 社瑚切
	AWrathOfEnril();
	~AWrathOfEnril();

	// delete funcion

	AWrathOfEnril(const AWrathOfEnril& _Other) = delete;
	AWrathOfEnril(AWrathOfEnril&& _Other) noexcept = delete;
	AWrathOfEnril& operator=(const AWrathOfEnril& _Other) = delete;
	AWrathOfEnril& operator=(AWrathOfEnril&& _Other) noexcept = delete;


	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	std::shared_ptr<class USpriteRenderer> GetWrathOfEnril()
	{
		return WrathOfEnril;
	}

	static float WrathOfEnrilCoolTime;

protected:
	
	
private:
	std::shared_ptr<class USpriteRenderer> WrathOfEnril;
	std::shared_ptr<class USpriteRenderer> WrathOfEnrilHit;
	std::shared_ptr<class UCollision> Collision;

	bool bIsCanUse = false;
	bool bIsHit = false;
	float WrathOfEnrilAtt = 50.0f;
};

