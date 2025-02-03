#pragma once
#include "TransformObject.h"
#include "EngineDataStruct.h"
#include "RenderUnit.h"

class UWidget : public UObject, public UTransformObject
{
	friend AHUD;

public:
	// constrcuter destructer
	ENGINEAPI UWidget();
	ENGINEAPI ~UWidget();

	// delete Function
	UWidget(const UWidget& _Other) = delete;
	UWidget(UWidget&& _Other) noexcept = delete;
	UWidget& operator=(const UWidget& _Other) = delete;
	UWidget& operator=(UWidget&& _Other) noexcept = delete;

	ENGINEAPI virtual void Tick(float _DeltaTime);
	ENGINEAPI virtual void Render(class UEngineCamera* Camera, float _DeltaTime);

	ENGINEAPI class ULevel* GetWorld();


	ENGINEAPI void SetHoverEvent(std::function<void()> _Value)
	{
		Hover = _Value;
	}

	ENGINEAPI void SetDownEvent(std::function<void()> _Value)
	{
		Down = _Value;
	}

	ENGINEAPI void SetUpEvent(std::function<void()> _Value)
	{
		Up = _Value;
	}

	template<typename Type>
	Type* GetGameInstance()
	{
		return dynamic_cast<Type*>(GetGameInstance());
	}

	ENGINEAPI class UGameInstance* GetGameInstance();


private:
	std::function<void()> Hover;
	std::function<void()> Down;
	std::function<void()> Up;

	class AHUD* HUD;

};

