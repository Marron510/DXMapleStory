#include "PreCompile.h"
#include "IconHighKick.h"


UIconHighKick::UIconHighKick()
{
	SetSprite("SkillIcon", 3);
	SetSpritePivot(FVector(0.0f, 0.5f));
	FVector WindowSize = GEngine->GetMainWindow().GetWindowSize();
	FVector WidgetSize = GetWorldScale3D();
	SetWorldLocation(FVector(158.0f, -321.0f));
}

UIconHighKick::~UIconHighKick()
{

}


void UIconHighKick::Tick(float _DeltaTime)
{
	UIcon::Tick(_DeltaTime);
}

void UIconHighKick::Render(UEngineCamera* Camera, float _DeltaTime)
{
	UIcon::Render(Camera, _DeltaTime);
}