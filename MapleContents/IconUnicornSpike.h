#pragma once

#include "Icon.h"

class UIconUnicornSpike : public UIcon
{
public:
	// 持失切 社瑚切
	UIconUnicornSpike();
	~UIconUnicornSpike();

	// delete funcion

	UIconUnicornSpike(const UIconUnicornSpike& _Other) = delete;
	UIconUnicornSpike(UIconUnicornSpike&& _Other) noexcept = delete;
	UIconUnicornSpike& operator=(const UIconUnicornSpike& _Other) = delete;
	UIconUnicornSpike& operator=(UIconUnicornSpike&& _Other) noexcept = delete;

	void Tick(float _DeltaTime) override;

	void Render(UEngineCamera* Camera, float _DeltaTime) override;

protected:

private:

};

