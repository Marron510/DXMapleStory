#pragma once

#include <EngineCore/GameMode.h>

class AMainHallMode : public AGameMode
{
public:
	// 생성자 소멸자
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
	// 플레이어
	std::shared_ptr<class APlayer> Player;

	// 세렌
	std::shared_ptr<class ASeren> Seren;

	// 맵
	std::shared_ptr<class AMainHall> MainHall;

	// 카메라
	std::shared_ptr<class ACameraActor> Camera;
};

