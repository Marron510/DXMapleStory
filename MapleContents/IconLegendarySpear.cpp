#include "PreCompile.h"
#include "IconLegendarySpear.h"


UIconLegendarySpear::UIconLegendarySpear()
{
	SetSprite("SkillIcon", 6);
	SetSpritePivot(FVector(0.0f, 0.5f));
	FVector WindowSize = GEngine->GetMainWindow().GetWindowSize();
	FVector WidgetSize = GetWorldScale3D();
	SetWorldLocation(FVector(263.0f, -356.0f));
}

UIconLegendarySpear::~UIconLegendarySpear()
{

}


void UIconLegendarySpear::Tick(float _DeltaTime)
{
	UIcon::Tick(_DeltaTime);
}

void UIconLegendarySpear::Render(UEngineCamera* Camera, float _DeltaTime)
{
	UIcon::Render(Camera, _DeltaTime);
}
