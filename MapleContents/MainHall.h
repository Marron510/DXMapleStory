#pragma once

#include <EngineCore/Actor.h>

class AMainHall: public AActor
{
public:
	// 持失切 社瑚切
	AMainHall();
	~AMainHall();

	// delete funcion

	AMainHall(const AMainHall& _Other) = delete;
	AMainHall(AMainHall&& _Other) noexcept = delete;
	AMainHall& operator=(const AMainHall& _Other) = delete;
	AMainHall& operator=(AMainHall&& _Other) noexcept = delete;


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> MainHall;
	
};

