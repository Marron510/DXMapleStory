#pragma once
#include "TransformObject.h"
#include "EngineDataStruct.h"
#include "RenderUnit.h"

// ���� : �������� ���Ѵٰ� �����ϰ�
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
	// �÷��̽� ��Ʈ new �Ҷ� ����� �༮�̹Ƿ� �ʱ�ȭ�� �ϸ� �ȵȴ�.
	class AHUD* HUD;

	URenderUnit RenderUnit;
};

