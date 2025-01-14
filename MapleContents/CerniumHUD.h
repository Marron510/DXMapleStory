#pragma once
#include <EngineCore/HUD.h>

class ACerniumHUD : public AHUD
{
public:
	// 持失切 社瑚切
	ACerniumHUD();
	~ACerniumHUD();

	// delete funcion

	ACerniumHUD(const ACerniumHUD& _Other) = delete;
	ACerniumHUD(ACerniumHUD&& _Other) noexcept = delete;
	ACerniumHUD& operator=(const ACerniumHUD& _Other) = delete;
	ACerniumHUD& operator=(ACerniumHUD&& _Other) noexcept = delete;

	void BeginPlay();
	void Tick(float _DeltaTime);

protected:

private:

};

