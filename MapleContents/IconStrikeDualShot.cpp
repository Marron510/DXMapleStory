#include "PreCompile.h"
#include "IconStrikeDualShot.h"


UIconStrikeDualShot::UIconStrikeDualShot()
{
	SetSprite("SkillIcon", 10);
	SetSpritePivot(FVector(0.0f, 0.5f));
	FVector WindowSize = GEngine->GetMainWindow().GetWindowSize();
	FVector WidgetSize = GetWorldScale3D();
	SetWorldLocation(FVector(158.0f, -356.0f));
}

UIconStrikeDualShot::~UIconStrikeDualShot()
{

}

void UIconStrikeDualShot::Tick(float _DeltaTime)
{
	UIcon::Tick(_DeltaTime);
}

void UIconStrikeDualShot::Render(UEngineCamera* Camera, float _DeltaTime)
{
	UIcon::Render(Camera, _DeltaTime);
}