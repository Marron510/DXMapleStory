#pragma once

#include "Icon.h"

class UIconUnicornSpikeDisable : public UIcon
{
public:
	// 持失切 社瑚切
	UIconUnicornSpikeDisable();
	~UIconUnicornSpikeDisable();

	// delete funcion

	UIconUnicornSpikeDisable(const UIconUnicornSpikeDisable& _Other) = delete;
	UIconUnicornSpikeDisable(UIconUnicornSpikeDisable&& _Other) noexcept = delete;
	UIconUnicornSpikeDisable& operator=(const UIconUnicornSpikeDisable& _Other) = delete;
	UIconUnicornSpikeDisable& operator=(UIconUnicornSpikeDisable&& _Other) noexcept = delete;

	void Tick(float _DeltaTime) override;
	void BarLerp(float _StartPercent, float _EndPercent, float _DeltaTime, bool& _bIsChange) override;

protected:

private:

};

