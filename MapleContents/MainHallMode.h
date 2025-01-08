#pragma once

#include <EngineCore/GameMode.h>

class AMainHallMode : public AGameMode
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
	// �÷��̾�
	std::shared_ptr<class APlayer> Player;

	// ����
	std::shared_ptr<class ASeren> Seren;

	// ��
	std::shared_ptr<class AMainHall> MainHall;

	// ī�޶�
	std::shared_ptr<class ACameraActor> Camera;
};

