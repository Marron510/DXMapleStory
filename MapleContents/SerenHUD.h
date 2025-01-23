#pragma once
#include <EngineCore/HUD.h>

class ASerenHUD : public AHUD
{
public:
	// ������ �Ҹ���
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



	// ��ġ
	FVector StatusLocation = FVector(0.0f, -342.0f);
	FVector StatusBackLocation = FVector(0.0f, -352.0f);
	FVector LevelLocation = FVector(-70.0f, -320.0f);
	FVector FirstLocation = FVector(-50.0f, -320.0f);
	FVector SecondLocation = FVector(-40.0f, -320.0f);
	FVector ThirdLocation = FVector(-30.0f, -320.0f);

	FVector ExpBarLocation = FVector(0.0f, -379.0f);
	FVector SkillBarLocation = FVector(402.0f, -338.0f);
	FVector SkillFoldBarLocation = FVector(119.0f, -338.0f);

};

