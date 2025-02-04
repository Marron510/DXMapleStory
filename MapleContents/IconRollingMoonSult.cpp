#include "PreCompile.h"
#include "IconRollingMoonSult.h"


UIconRollingMoonSult::UIconRollingMoonSult()
{
	SetSprite("SkillIcon", 8);
	SetSpritePivot(FVector(0.0f, 0.5f));
	FVector WindowSize = GEngine->GetMainWindow().GetWindowSize();
	FVector WidgetSize = GetWorldScale3D();
	SetWorldLocation(FVector(193.0f, -321.0f));
}

UIconRollingMoonSult::~UIconRollingMoonSult()
{

}


void UIconRollingMoonSult::Tick(float _DeltaTime)
{
	UIcon::Tick(_DeltaTime);
}

void UIconRollingMoonSult::Render(UEngineCamera* Camera, float _DeltaTime)
{
	UIcon::Render(Camera, _DeltaTime);
}