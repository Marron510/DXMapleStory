#pragma once

#include "Icon.h"

class IconCharge : public UIcon
{
public:
	// 持失切 社瑚切
	IconCharge();
	~IconCharge();

	// delete funcion

	IconCharge(const IconCharge& _Other) = delete;
	IconCharge(IconCharge&& _Other) noexcept = delete;
	IconCharge& operator=(const IconCharge& _Other) = delete;
	IconCharge& operator=(IconCharge&& _Other) noexcept = delete;

	void Tick(float _DeltaTime) override;

	void Render(UEngineCamera* Camera, float _DeltaTime) override;

protected:

private:

};

