#include "PreCompile.h"
#include "IconIshtar.h"


UIconIshtar::UIconIshtar()
{
	SetSprite("SkillIcon", 4);
	SetSpritePivot(FVector(0.0f, 0.5f));
	FVector WindowSize = GEngine->GetMainWindow().GetWindowSize();
	FVector WidgetSize = GetWorldScale3D();
	SetWorldLocation(FVector(298.0f, -356.0f));
}

UIconIshtar::~UIconIshtar()
{

}


void UIconIshtar::Tick(float _DeltaTime)
{
	UIcon::Tick(_DeltaTime);
}

void UIconIshtar::Render(UEngineCamera* Camera, float _DeltaTime)
{
	UIcon::Render(Camera, _DeltaTime);
}