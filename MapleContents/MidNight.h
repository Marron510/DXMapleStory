#pragma once

#include <EngineCore/Actor.h>


class AMidNight : public AActor
{
public:
	// 持失切 社瑚切
	AMidNight();
	~AMidNight();

	// delete funcion

	AMidNight(const AMidNight& _Other) = delete;
	AMidNight(AMidNight&& _Other) noexcept = delete;
	AMidNight& operator=(const AMidNight& _Other) = delete;
	AMidNight& operator=(AMidNight&& _Other) noexcept = delete;


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	std::shared_ptr<class USpriteRenderer> MidNight;
};

