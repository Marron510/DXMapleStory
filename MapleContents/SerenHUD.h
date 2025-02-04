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
	
	// ���� ��ġ
	FVector LevelLocation = FVector(-70.0f, -320.0f);
	FVector FirstLocation = FVector(-54.0f, -320.0f);
	FVector SecondLocation = FVector(-46.0f, -320.0f);
	FVector ThirdLocation = FVector(-38.0f, -320.0f);

	// �̸� ��ġ
	FVector NameLocation = FVector(-12.0f, -310.0f);

	// HP ǥ�� ��ġ
	FVector MaxHpLocation = FVector(-26.2f, -334.2f);
	FVector CurHpLocation = FVector(5.0f, -334.2f);

	// MP ǥ�� ��ġ
	FVector MaxMpLocation = FVector(-26.2f, -349.2f);
	FVector CurMpLocation = FVector(5.0f, -349.2f);

	//exp �� ��ġ
	FVector ExpBarLocation = FVector(0.0f, -379.0f);

	// ��ųUI ��ġ
	FVector SkillBarLocation = FVector(402.0f, -338.0f);
	FVector SkillFoldBarLocation = FVector(119.0f, -338.0f);

	// ���� ������ ��ġ
	FVector GageBackLocation = FVector(-500.0f, 202.0f);
	FVector GageBallLocation = FVector(-501.0f, 202.0f);

	// ���� HP�� ��ġ
	FVector BossHPLocation = FVector(0.0f, 360.0f);
};

