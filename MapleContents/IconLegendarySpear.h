#pragma once

#include "Icon.h"

class UIconLegendarySpear : public UIcon
{
public:
	// 持失切 社瑚切
	UIconLegendarySpear();
	~UIconLegendarySpear();

	// delete funcion

	UIconLegendarySpear(const UIconLegendarySpear& _Other) = delete;
	UIconLegendarySpear(UIconLegendarySpear&& _Other) noexcept = delete;
	UIconLegendarySpear& operator=(const UIconLegendarySpear& _Other) = delete;
	UIconLegendarySpear& operator=(UIconLegendarySpear&& _Other) noexcept = delete;

	void Tick(float _DeltaTime) override;

	void Render(UEngineCamera* Camera, float _DeltaTime) override;

protected:

private:
	
};

