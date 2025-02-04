#include "PreCompile.h"
#include "Icon.h"


UIcon::UIcon()
{
	SetSpritePivot(FVector{0.5f, 1.0f});
}

UIcon::~UIcon()
{

}

void UIcon::Tick(float _DeltaTime)
{
	UImageWidget::Tick(_DeltaTime);
}

void UIcon::Render(UEngineCamera* Camera, float _DeltaTime)
{
	UImageWidget::Render(Camera, _DeltaTime);
}



void UIcon::BarLerp(float _StartPercent, float _EndPercent, float _f, bool& _bIsChange)
{
	bool& bIsChange = _bIsChange;
	float LerpHpPercent = UEngineMath::Lerp(StartPercent, TargetPercent, UEngineMath::Clamp(_f * 3.0f, 0.0f, 1.0f));
	SetSpriteCuttingSize(FVector(LerpHpPercent, 1.0f));
	if (LerpHpPercent == TargetPercent) {
		bIsChange = false;
		CurTime = 0.0f;
	}
}
