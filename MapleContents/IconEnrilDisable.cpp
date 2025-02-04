#include "PreCompile.h"
#include "IconEnrilDisable.h"


UIconEnrilDisable::UIconEnrilDisable()
{
	SetSprite("SkillIcon", 2);
	SetSpritePivot(FVector(0.0f, 0.5f));
	FVector WindowSize = GEngine->GetMainWindow().GetWindowSize();
	FVector WidgetSize = GetWorldScale3D();
	SetWorldLocation(FVector(123.0f, -356.0f));
}

UIconEnrilDisable::~UIconEnrilDisable()
{

}

void UIconEnrilDisable::Tick(float _DeltaTime)
{
	UIcon::Tick(_DeltaTime);
}

void UIconEnrilDisable::BarLerp(float _StartPercent, float _EndPercent, float _DeltaTime, bool& _bIsChange)
{
	UIcon::BarLerp(_StartPercent, _EndPercent, _DeltaTime, _bIsChange);
}
