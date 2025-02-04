#pragma once
#include "Icon.h"


class UIconEnrilDisable : public UIcon
{
public:
	// 持失切 社瑚切
	UIconEnrilDisable();
	~UIconEnrilDisable();

	// delete funcion

	UIconEnrilDisable(const UIconEnrilDisable& _Other) = delete;
	UIconEnrilDisable(UIconEnrilDisable&& _Other) noexcept = delete;
	UIconEnrilDisable& operator=(const UIconEnrilDisable& _Other) = delete;
	UIconEnrilDisable& operator=(UIconEnrilDisable&& _Other) noexcept = delete;

	void Tick(float _DeltaTime) override;
	void BarLerp(float _StartPercent, float _EndPercent, float _DeltaTime, bool& _bIsChange) override;


protected:

private:

};

