#include "PreCompile.h"
#include "IconEnril.h"


UIconEnril::UIconEnril()
{
	SetSprite("SkillIcon", 1);
	SetSpritePivot(FVector(0.0f, 0.5f));
	FVector WindowSize = GEngine->GetMainWindow().GetWindowSize();
	FVector WidgetSize = GetWorldScale3D();
	SetWorldLocation(FVector(123.0f, -356.0f));
}

UIconEnril::~UIconEnril()
{

}

void UIconEnril::Tick(float _DeltaTime)
{
	UIcon::Tick(_DeltaTime);
}

void UIconEnril::Render(UEngineCamera* Camera, float _DeltaTime)
{
	UIcon::Render(Camera, _DeltaTime);
}
