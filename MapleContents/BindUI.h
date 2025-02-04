#pragma once

#include <EngineCore/ImageWidget.h>

class UBindUI : public UImageWidget
{
public:
	// 持失切 社瑚切
	UBindUI();
	~UBindUI();

	// delete funcion

	UBindUI(const UBindUI& _Other) = delete;
	UBindUI(UBindUI&& _Other) noexcept = delete;
	UBindUI& operator=(const UBindUI& _Other) = delete;
	UBindUI& operator=(UBindUI&& _Other) noexcept = delete;

	void Tick(float _DeltaTime) override;
	void Render(UEngineCamera* Camera, float _DeltaTime) override;

protected:

private:
	class APlayer* Player;
	bool bIsActive = false;
	float CurGage = 0.0f;
};

