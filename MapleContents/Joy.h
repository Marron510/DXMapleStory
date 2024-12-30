#pragma once

#include <EngineCore/Actor.h>

class AJoy : public AActor
{
public:
	// 持失切 社瑚切
	AJoy();
	~AJoy();

	// delete funcion

	AJoy(const AJoy& _Other) = delete;
	AJoy(AJoy&& _Other) noexcept = delete;
	AJoy& operator=(const AJoy& _Other) = delete;
	AJoy& operator=(AJoy&& _Other) noexcept = delete;


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	std::shared_ptr<class USpriteRenderer> Joyrenderer;
};

