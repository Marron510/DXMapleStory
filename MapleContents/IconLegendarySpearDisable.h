#pragma once
#include "Icon.h"

class UIconLegendarySpearDisable : public UIcon
{
public:
	// ������ �Ҹ���
	UIconLegendarySpearDisable();
	~UIconLegendarySpearDisable();

	// delete funcion

	UIconLegendarySpearDisable(const UIconLegendarySpearDisable& _Other) = delete;
	UIconLegendarySpearDisable(UIconLegendarySpearDisable&& _Other) noexcept = delete;
	UIconLegendarySpearDisable& operator=(const UIconLegendarySpearDisable& _Other) = delete;
	UIconLegendarySpearDisable& operator=(UIconLegendarySpearDisable&& _Other) noexcept = delete;

	void Tick(float _DeltaTime) override;
	void BarLerp(float _StartPercent, float _EndPercent, float _DeltaTime, bool& _bIsChange) override;


protected:

private:

};

