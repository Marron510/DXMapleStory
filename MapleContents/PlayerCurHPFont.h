#pragma once
#include "MapleFont.h"

class UPlayerCurHPFont : public UMapleFont
{
public:
	// 持失切 社瑚切
	UPlayerCurHPFont();
	~UPlayerCurHPFont();

	// delete funcion

	UPlayerCurHPFont(const UPlayerCurHPFont& _Other) = delete;
	UPlayerCurHPFont(UPlayerCurHPFont&& _Other) noexcept = delete;
	UPlayerCurHPFont& operator=(const UPlayerCurHPFont& _Other) = delete;
	UPlayerCurHPFont& operator=(UPlayerCurHPFont&& _Other) noexcept = delete;


	void Tick(float _DeltaTime) override;

	void Render(UEngineCamera* Camera, float _DeltaTime) override;

protected:

private:
	float FCurHp = 0.0f;
	int ICurHp = 0;
	std::string CurHPstr = "";
};

