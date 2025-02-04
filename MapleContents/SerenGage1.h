#pragma once
#include "Bar.h"

class SerenGage1 : public UBar
{
public:
	// 持失切 社瑚切
	SerenGage1();
	~SerenGage1();

	// delete funcion

	SerenGage1(const SerenGage1& _Other) = delete;
	SerenGage1(SerenGage1&& _Other) noexcept = delete;
	SerenGage1& operator=(const SerenGage1& _Other) = delete;
	SerenGage1& operator=(SerenGage1&& _Other) noexcept = delete;

	void Tick(float _DeltaTime) override;

	void Render(UEngineCamera* Camera, float _DeltaTime) override;

protected:

private:

};

