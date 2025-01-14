#include "PreCompile.h"
#include "Widget.h"
#include "HUD.h"
#include "RenderUnit.h"

UWidget::UWidget()
{
	// 기하구조를 가진 녀석이라는 것을 알려준다.
	RenderUnit.TransformObject = this;
	RenderUnit.SetMesh("Rect");
	RenderUnit.SetMaterial("SpriteMaterial");

	RenderUnit.ConstantBufferLinkData("ResultColor", ColorData);
	RenderUnit.ConstantBufferLinkData("FSpriteData", SpriteData);
	RenderUnit.ConstantBufferLinkData("FUVValue", UVValue);


	UVValue.PlusUVValue = { 0.0f, 0.0f, 0.0f, 0.0f };
	SpriteData.CuttingPos = { 0.0f, 0.0f };
	SpriteData.CuttingSize = { 1.0f, 1.0f };
	SpriteData.Pivot = { 0.5f, 0.5f };

	ColorData.PlusColor = { 0.0f, 0.0f, 0.0f, 0.0f };
	ColorData.MulColor = { 1.0f, 1.0f, 1.0f, 1.0f };
}

UWidget::~UWidget()
{
}

void UWidget::Render(UEngineCamera* Camera, float _DeltaTime)
{
	// RenderUnit.Render();
}

ULevel* UWidget::GetWorld()
{
	return HUD->GetWorld();
}