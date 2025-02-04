#pragma once

#include "Icon.h"

class IconRollingMoonSultDisable : public UIcon
{
public:
	// ������ �Ҹ���
	IconRollingMoonSultDisable();
	~IconRollingMoonSultDisable();

	// delete funcion

	IconRollingMoonSultDisable(const IconRollingMoonSultDisable& _Other) = delete;
	IconRollingMoonSultDisable(IconRollingMoonSultDisable&& _Other) noexcept = delete;
	IconRollingMoonSultDisable& operator=(const IconRollingMoonSultDisable& _Other) = delete;
	IconRollingMoonSultDisable& operator=(IconRollingMoonSultDisable&& _Other) noexcept = delete;

	void Tick(float _DeltaTime) override;
	void BarLerp(float _StartPercent, float _EndPercent, float _DeltaTime, bool& _bIsChange) override;


protected:

private:

};

