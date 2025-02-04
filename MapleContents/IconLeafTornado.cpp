#include "PreCompile.h"
#include "IconLeafTornado.h"


UIconLeafTornado::UIconLeafTornado()
{
	SetSprite("SkillIcon", 5);
	SetSpritePivot(FVector(0.0f, 0.5f));
	FVector WindowSize = GEngine->GetMainWindow().GetWindowSize();
	FVector WidgetSize = GetWorldScale3D();
	SetWorldLocation(FVector(193.0f, -356.0f));
}

UIconLeafTornado::~UIconLeafTornado()
{

}

void UIconLeafTornado::Tick(float _DeltaTime)
{
	UIcon::Tick(_DeltaTime);
}

void UIconLeafTornado::Render(UEngineCamera* Camera, float _DeltaTime)
{
	UIcon::Render(Camera, _DeltaTime);
}
