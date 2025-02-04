#include "PreCompile.h"
#include "IconCharge.h"


IconCharge::IconCharge()
{

}

IconCharge::~IconCharge()
{

}

void IconCharge::Tick(float _DeltaTime)
{
	UIcon::Tick(_DeltaTime);
}

void IconCharge::Render(UEngineCamera* Camera, float _DeltaTime)
{
	UIcon::Render(Camera, _DeltaTime);
}
