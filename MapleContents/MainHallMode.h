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

	void BeginPlay();
	void Tick(float _DeltaTime);

	void GetSpriteRender();
	void UpdateSprite(float _DeltaTime);
	void UpdateSpriteLocation(std::shared_ptr<class USpriteRenderer>& Sprite, float _DeltaTime);

protected:

private:
	// �÷��̾�
	class APlayer* Player;

	// ����
	std::shared_ptr<class ASeren> Seren;

	// ��
	std::shared_ptr<class AMainHall> MainHall;

	// ī�޶�
	std::shared_ptr<class ACameraActor> Camera;

	std::shared_ptr<class USpriteRenderer> MainHall_Sky = nullptr;
	std::shared_ptr<class USpriteRenderer> MainHall_Center = nullptr;
	std::shared_ptr<class USpriteRenderer> MainHall_Pillar_Left = nullptr;
	std::shared_ptr<class USpriteRenderer> MainHall_Pillar_Right = nullptr;


	float MapSizeHalfX = 2274.0f;
	float MapSizeHalfY = 858.0f;
	float MapSizeDefaultY = 1203.0f;

	float SpeedMultiplier = 0.0f;

	float PreviousPlayerLocation = 0.0f;

	float Velocity = 0.0f;

};

