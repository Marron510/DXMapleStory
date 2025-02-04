#pragma once
#include "Bar.h"

class USerenGage1 : public UBar
{
public:
	// 持失切 社瑚切
	USerenGage1();
	~USerenGage1();

	// delete funcion

	USerenGage1(const USerenGage1& _Other) = delete;
	USerenGage1(USerenGage1&& _Other) noexcept = delete;
	USerenGage1& operator=(const USerenGage1& _Other) = delete;
	USerenGage1& operator=(USerenGage1&& _Other) noexcept = delete;

	void Tick(float _DeltaTime) override;

	void Render(UEngineCamera* Camera, float _DeltaTime) override;
	void BarLerp(float _StartPercent, float _EndPercent, float _f, bool& _bIsChange) override;
	void GageLogic(float _DeltaTime);
protected:

private:
	class APlayer* Player;
	bool bIsGageOn = false;

	float BindTime = 3.0f;

};

