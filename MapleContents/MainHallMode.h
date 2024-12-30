#pragma once

#include <EngineCore/Actor.h>

class AMainHallMode : public AActor
{
public:
	// ������ �Ҹ���
	AMainHallMode();
	~AMainHallMode();

	// delete funcion

	AMainHallMode(const AMainHallMode& _Other) = delete;
	AMainHallMode(AMainHallMode&& _Other) noexcept = delete;
	AMainHallMode& operator=(const AMainHallMode& _Other) = delete;
	AMainHallMode& operator=(AMainHallMode&& _Other) noexcept = delete;

	void Tick(float _DeltaTime);

protected:

private:
	std::shared_ptr<class APlayer> Player;
	
	std::shared_ptr<class AMainHall> MainHall;
	std::shared_ptr<class ACameraActor> Camera;
};

