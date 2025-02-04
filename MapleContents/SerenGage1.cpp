#include "PreCompile.h"
#include "SerenGage1.h"


SerenGage1::SerenGage1()
{
	SetSprite("GageUI_Ball");
	SetSpritePivot(FVector{ 0.5f, 1.0f });
}

SerenGage1::~SerenGage1()
{

}

void SerenGage1::Tick(float _DeltaTime)
{
	UBar::Tick(_DeltaTime);
}

void SerenGage1::Render(UEngineCamera* Camera, float _DeltaTime)
{
	UBar::Render(Camera, _DeltaTime);
}
