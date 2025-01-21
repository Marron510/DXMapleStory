#pragma once
#include "SkillManager.h"

class ARoyalKnight : public ASkillManager
{
public:
	// 持失切 社瑚切
	ARoyalKnight();
	~ARoyalKnight();

	// delete funcion

	ARoyalKnight(const ARoyalKnight& _Other) = delete;
	ARoyalKnight(ARoyalKnight&& _Other) noexcept = delete;
	ARoyalKnight& operator=(const ARoyalKnight& _Other) = delete;
	ARoyalKnight& operator=(ARoyalKnight&& _Other) noexcept = delete;
	
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	static bool bLoyalKnightsOn;

protected:

private:
	std::shared_ptr<class USpriteRenderer> RoyalKnight;
	std::shared_ptr<class UTimeEventComponent> TimeEventComponent;
	
	bool bIsRoyalStart = false;
	bool bIsRoyalLoop = false;
	bool bIsRoyalEnd = false;
};

