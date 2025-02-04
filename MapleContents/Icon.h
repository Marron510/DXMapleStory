#pragma once
#include <EngineCore/FontWidget.h>

class UIcon : public UFontWidget
{
public:
	// 持失切 社瑚切
	UIcon();
	~UIcon();

	// delete funcion

	UIcon(const UIcon& _Other) = delete;
	UIcon(UIcon&& _Other) noexcept = delete;
	UIcon& operator=(const UIcon& _Other) = delete;
	UIcon& operator=(UIcon&& _Other) noexcept = delete;

	void Tick(float _DeltaTime) override;

	void Render(UEngineCamera* Camera, float _DeltaTime) override;

protected:

private:

};

