#include "PreCompile.h"
#include "Icon.h"


UIcon::UIcon()
{

}

UIcon::~UIcon()
{

}

void UIcon::Tick(float _DeltaTime)
{
	UFontWidget::Tick(_DeltaTime);
}

void UIcon::Render(UEngineCamera* Camera, float _DeltaTime)
{
	UFontWidget::Render(Camera, _DeltaTime);
}
