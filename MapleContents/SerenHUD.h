#pragma once
#include <EngineCore/HUD.h>

class ASerenHUD : public AHUD
{
public:
	// 생성자 소멸자
	ASerenHUD();
	~ASerenHUD();

	// delete funcion

	ASerenHUD(const ASerenHUD& _Other) = delete;
	ASerenHUD(ASerenHUD&& _Other) noexcept = delete;
	ASerenHUD& operator=(const ASerenHUD& _Other) = delete;
	ASerenHUD& operator=(ASerenHUD&& _Other) noexcept = delete;

	void BeginPlay();
	void Tick(float _DeltaTime);

protected:

private:



	// 위치
	FVector StatusLocation = FVector(0.0f, -342.0f);
	FVector StatusBackLocation = FVector(0.0f, -352.0f);
	FVector ExpBarLocation = FVector(0.0f, -379.0f);
	FVector SkillBarLocation = FVector(402.0f, -338.0f);
	FVector SkillFoldBarLocation = FVector(119.0f, -338.0f);

};

