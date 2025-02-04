#pragma once

#include "MapleFont.h"

class UPlayerCurMPFont : public UMapleFont
{
public:
	// 持失切 社瑚切
	UPlayerCurMPFont();
	~UPlayerCurMPFont();

	// delete funcion

	UPlayerCurMPFont(const UPlayerCurMPFont& _Other) = delete;
	UPlayerCurMPFont(UPlayerCurMPFont&& _Other) noexcept = delete;
	UPlayerCurMPFont& operator=(const UPlayerCurMPFont& _Other) = delete;
	UPlayerCurMPFont& operator=(UPlayerCurMPFont&& _Other) noexcept = delete;

	void Tick(float _DeltaTime) override;

	void Render(UEngineCamera* Camera, float _DeltaTime) override;
protected:

private:
	float FCurMp = 0.0f;
	int ICurMp = 0;
	std::string CurMPstr = "";
};

