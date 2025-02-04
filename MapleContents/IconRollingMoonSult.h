#pragma once

#include "Icon.h"

class UIconRollingMoonSult : public UIcon
{
public:
	// 持失切 社瑚切
	UIconRollingMoonSult();
	~UIconRollingMoonSult();

	// delete funcion

	UIconRollingMoonSult(const UIconRollingMoonSult& _Other) = delete;
	UIconRollingMoonSult(UIconRollingMoonSult&& _Other) noexcept = delete;
	UIconRollingMoonSult& operator=(const UIconRollingMoonSult& _Other) = delete;
	UIconRollingMoonSult& operator=(UIconRollingMoonSult&& _Other) noexcept = delete;

	void Tick(float _DeltaTime) override;

	void Render(UEngineCamera* Camera, float _DeltaTime) override;


protected:

private:

};

