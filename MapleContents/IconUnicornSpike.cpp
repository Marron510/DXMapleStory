#include "PreCompile.h"
#include "IconUnicornSpike.h"


UIconUnicornSpike::UIconUnicornSpike()
{
	SetSprite("SkillIcon", 12);
	SetSpritePivot(FVector(0.0f, 0.5f));
	FVector WindowSize = GEngine->GetMainWindow().GetWindowSize();
	FVector WidgetSize = GetWorldScale3D();
	SetWorldLocation(FVector(228.0f, -321.0f));
}

UIconUnicornSpike::~UIconUnicornSpike()
{

}


void UIconUnicornSpike::Tick(float _DeltaTime)
{
	UIcon::Tick(_DeltaTime);
}

void UIconUnicornSpike::Render(UEngineCamera* Camera, float _DeltaTime)
{
	UIcon::Render(Camera, _DeltaTime);
}
