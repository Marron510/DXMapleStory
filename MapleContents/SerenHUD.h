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
	
	// 레벨 위치
	FVector LevelLocation = FVector(-70.0f, -320.0f);
	FVector FirstLocation = FVector(-54.0f, -320.0f);
	FVector SecondLocation = FVector(-46.0f, -320.0f);
	FVector ThirdLocation = FVector(-38.0f, -320.0f);

	// 이름 위치
	FVector NameLocation = FVector(-12.0f, -310.0f);

	// HP 표시 위치
	FVector MaxHpLocation = FVector(-26.2f, -334.2f);
	FVector CurHpLocation = FVector(5.0f, -334.2f);

	// MP 표시 위치
	FVector MaxMpLocation = FVector(-26.2f, -349.2f);
	FVector CurMpLocation = FVector(5.0f, -349.2f);

	//exp 바 위치
	FVector ExpBarLocation = FVector(0.0f, -379.0f);

	// 스킬UI 위치
	FVector SkillBarLocation = FVector(402.0f, -338.0f);
	FVector SkillFoldBarLocation = FVector(119.0f, -338.0f);

	// 세렌 게이지 위치
	FVector GageBackLocation = FVector(-500.0f, 202.0f);
	FVector GageBallLocation = FVector(-501.0f, 202.0f);

	// 세렌 HP바 위치
	FVector BossHPLocation = FVector(0.0f, 360.0f);
};

