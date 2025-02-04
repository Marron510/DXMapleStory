#pragma once
#include <EngineCore/ImageWidget.h>

class UIcon : public UImageWidget
{
public:
	// 持失切 社瑚切
	UIcon();
	~UIcon();

	// delete funcion

	UIcon(const UIcon& _Other) = delete;
	UIcon(UIcon&& _Other) noexcept = delete;
	UIcon& operator=(const UIcon& _Other) = delete;
	UIcon& operator=(UIcon&& _Other) noexcept = delete;

	void Tick(float _DeltaTime) override;

	void Render(UEngineCamera* Camera, float _DeltaTime) override;

	virtual void BarLerp(float _StartPercent, float _EndPercent, float _DeltaTime, bool& _bIsChange);

	void SetCurTime(float _CurTime) { CurTime = _CurTime; }

protected:
	float CurTime = 0.0f;
	float StartPercent;
	float TargetPercent;

private:
};

