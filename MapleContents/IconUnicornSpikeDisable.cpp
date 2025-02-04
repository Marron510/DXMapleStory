#include "PreCompile.h"
#include "IconUnicornSpikeDisable.h"


UIconUnicornSpikeDisable::UIconUnicornSpikeDisable()
{
	SetSprite("SkillIcon", 13);
	SetSpritePivot(FVector(0.0f, 0.5f));
	FVector WindowSize = GEngine->GetMainWindow().GetWindowSize();
	FVector WidgetSize = GetWorldScale3D();
	SetWorldLocation(FVector(228.0f, -321.0f));
}

UIconUnicornSpikeDisable::~UIconUnicornSpikeDisable()
{

}

void UIconUnicornSpikeDisable::Tick(float _DeltaTime)
{
	UIcon::Tick(_DeltaTime);
}

void UIconUnicornSpikeDisable::BarLerp(float _StartPercent, float _EndPercent, float _DeltaTime, bool& _bIsChange)
{
	UIcon::BarLerp(_StartPercent, _EndPercent, _DeltaTime, _bIsChange);
}
