#pragma once

#include <EngineCore/GameMode.h>

class ATheBoundaryOfTheWorld : public AGameMode
{
public:
	// 생성자 소멸자
	ATheBoundaryOfTheWorld();
	~ATheBoundaryOfTheWorld();

	// delete funcion

	ATheBoundaryOfTheWorld(const ATheBoundaryOfTheWorld& _Other) = delete;
	ATheBoundaryOfTheWorld(ATheBoundaryOfTheWorld&& _Other) noexcept = delete;
	ATheBoundaryOfTheWorld& operator=(const ATheBoundaryOfTheWorld& _Other) = delete;
	ATheBoundaryOfTheWorld& operator=(ATheBoundaryOfTheWorld&& _Other) noexcept = delete;

	void Tick(float _DeltaTime);

	void ChangeMapState();
protected:

private:
	// 플레이어
	std::shared_ptr<class APlayer> Player;

	// 세렌
	std::shared_ptr<class ASeren> Seren;

	// 맵
	std::shared_ptr<class ANoon> Noon;
	std::shared_ptr<class ASunSet> SunSet;
	std::shared_ptr<class AMidNight> MidNight;
	std::shared_ptr<class ADawn> Dawn;

	// 카메라
	std::shared_ptr<class ACameraActor> Camera;

};

