#pragma once

#include <EngineCore/Actor.h>

class ATheBoundaryOfTheWorld : public AActor
{
public:
	// ������ �Ҹ���
	ATheBoundaryOfTheWorld();
	~ATheBoundaryOfTheWorld();

	// delete funcion

	ATheBoundaryOfTheWorld(const ATheBoundaryOfTheWorld& _Other) = delete;
	ATheBoundaryOfTheWorld(ATheBoundaryOfTheWorld&& _Other) noexcept = delete;
	ATheBoundaryOfTheWorld& operator=(const ATheBoundaryOfTheWorld& _Other) = delete;
	ATheBoundaryOfTheWorld& operator=(ATheBoundaryOfTheWorld&& _Other) noexcept = delete;

	void Tick(float _DeltaTime);

protected:

private:
	// �÷��̾�
	std::shared_ptr<class APlayer> Player;

	// ����
	std::shared_ptr<class ASeren> Seren;

	// ��
	std::shared_ptr<class ANoon> Noon;
	//std::shared_ptr<class ASunSet> SunSet;
	//std::shared_ptr<class AMidNight> MidNight;
	//std::shared_ptr<class ADawn> Dawn;

	// ī�޶�
	std::shared_ptr<class ACameraActor> Camera;

};

