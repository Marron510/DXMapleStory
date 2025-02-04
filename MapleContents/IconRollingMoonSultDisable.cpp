#include "PreCompile.h"
#include "IconRollingMoonSultDisable.h"


IconRollingMoonSultDisable::IconRollingMoonSultDisable()
{

}

IconRollingMoonSultDisable::~IconRollingMoonSultDisable()
{

}

void IconRollingMoonSultDisable::Tick(float _DeltaTime)
{
	UIcon::Tick(_DeltaTime);
}

void IconRollingMoonSultDisable::BarLerp(float _StartPercent, float _EndPercent, float _DeltaTime, bool& _bIsChange)
{
	UIcon::BarLerp(_StartPercent, _EndPercent, _DeltaTime, _bIsChange);
}
