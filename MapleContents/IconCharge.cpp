#include "PreCompile.h"
#include "IconCharge.h"


UIconCharge::UIconCharge()
{
	SetSprite("SkillIcon", 0);
	SetSpritePivot(FVector(0.0f, 0.5f));
	FVector WindowSize = GEngine->GetMainWindow().GetWindowSize();
	FVector WidgetSize = GetWorldScale3D();
	SetWorldLocation(FVector(123.0f, -321.0f));
}

UIconCharge::~UIconCharge()
{

}

void UIconCharge::Tick(float _DeltaTime)
{
	UIcon::Tick(_DeltaTime);
}

void UIconCharge::Render(UEngineCamera* Camera, float _DeltaTime)
{
	UIcon::Render(Camera, _DeltaTime);
}
