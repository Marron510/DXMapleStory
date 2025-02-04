#pragma once

#include "Icon.h"

class UIconStrikeDualShot : public UIcon
{
public:
	// 持失切 社瑚切
	UIconStrikeDualShot();
	~UIconStrikeDualShot();

	// delete funcion

	UIconStrikeDualShot(const UIconStrikeDualShot& _Other) = delete;
	UIconStrikeDualShot(UIconStrikeDualShot&& _Other) noexcept = delete;
	UIconStrikeDualShot& operator=(const UIconStrikeDualShot& _Other) = delete;
	UIconStrikeDualShot& operator=(UIconStrikeDualShot&& _Other) noexcept = delete;

	void Tick(float _DeltaTime) override;

	void Render(UEngineCamera* Camera, float _DeltaTime) override;

protected:

private:

};

