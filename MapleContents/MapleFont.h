#pragma once
#include <EngineCore/FontWidget.h>

class UMapleFont : public UFontWidget
{
public:
	// 持失切 社瑚切
	UMapleFont();
	~UMapleFont();

	// delete funcion

	UMapleFont(const UMapleFont& _Other) = delete;
	UMapleFont(UMapleFont&& _Other) noexcept = delete;
	UMapleFont& operator=(const UMapleFont& _Other) = delete;
	UMapleFont& operator=(UMapleFont&& _Other) noexcept = delete;

	void Tick(float _DeltaTime) override;

	void Render(UEngineCamera* Camera, float _DeltaTime) override;

protected:

private:

};

