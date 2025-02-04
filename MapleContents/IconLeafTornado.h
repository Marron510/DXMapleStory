#pragma once

#include "Icon.h"

class UIconLeafTornado : public UIcon
{
public:
	// 持失切 社瑚切
	UIconLeafTornado();
	~UIconLeafTornado();

	// delete funcion

	UIconLeafTornado(const UIconLeafTornado& _Other) = delete;
	UIconLeafTornado(UIconLeafTornado&& _Other) noexcept = delete;
	UIconLeafTornado& operator=(const UIconLeafTornado& _Other) = delete;
	UIconLeafTornado& operator=(UIconLeafTornado&& _Other) noexcept = delete;

	void Tick(float _DeltaTime) override;

	void Render(UEngineCamera* Camera, float _DeltaTime) override;

protected:

private:

};

