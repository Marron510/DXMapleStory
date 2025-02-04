#include "PreCompile.h"
#include "IconLegendarySpearDisable.h"


UIconLegendarySpearDisable::UIconLegendarySpearDisable()
{
	SetSprite("SkillIcon", 7);
	SetSpritePivot(FVector(0.0f, 0.5f));
	FVector WindowSize = GEngine->GetMainWindow().GetWindowSize();
	FVector WidgetSize = GetWorldScale3D();
	SetWorldLocation(FVector(263.0f, -356.0f));
}

UIconLegendarySpearDisable::~UIconLegendarySpearDisable()
{

}


void UIconLegendarySpearDisable::Tick(float _DeltaTime)
{
	UIcon::Tick(_DeltaTime);
}

void UIconLegendarySpearDisable::BarLerp(float _StartPercent, float _EndPercent, float _DeltaTime, bool& _bIsChange)
{
	UIcon::BarLerp(_StartPercent, _EndPercent, _DeltaTime, _bIsChange);
}
