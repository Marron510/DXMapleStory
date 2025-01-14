#pragma once
#include "TransformObject.h"
#include "EngineDataStruct.h"
#include "RenderUnit.h"

// 설명 : 랜더러를 겸한다고 생각하고
class UWidget : public UObject, public UTransformObject
{
	friend AHUD;

public:
	// constrcuter destructer
	ENGINEAPI UWidget();
	ENGINEAPI ~UWidget();

	URenderUnit& GetRenderUnit()
	{
		return RenderUnit;
	}

	// delete Function
	UWidget(const UWidget& _Other) = delete;
	UWidget(UWidget&& _Other) noexcept = delete;
	UWidget& operator=(const UWidget& _Other) = delete;
	UWidget& operator=(UWidget&& _Other) noexcept = delete;

	void Render(class UEngineCamera* Camera, float _DeltaTime);

	ULevel* GetWorld();

	FResultColor ColorData;
	FUVValue UVValue;
	FSpriteData SpriteData;

private:
	// 플레이스 먼트 new 할때 사용할 녀석이므로 초기화를 하면 안된다.
	class AHUD* HUD;

	URenderUnit RenderUnit;
};

