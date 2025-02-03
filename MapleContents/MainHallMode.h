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

	void BeginPlay();
	void Tick(float _DeltaTime);

	void GetSpriteRender();
	void UpdateSprite(float _DeltaTime);
	void UpdateSpriteLocation(std::shared_ptr<class USpriteRenderer>& Sprite, float _DeltaTime);

protected:

private:
	// 플레이어
	class APlayer* Player;

	// 플레이어 스킬

	std::shared_ptr<class AWrathOfEnril> WrathOfEnril;
	std::shared_ptr<class ALeafTornado> LeafTornadoFront;
	std::shared_ptr<class AStrikeDualShot> StrikeDualShot;
	std::shared_ptr<class AIshtar> Ishtar;
	std::shared_ptr<class ARollingMoonSult> RollingMoonSult;
	std::shared_ptr<class AChargeDrive> ChargeDrive;
	std::shared_ptr<class AHighKick> HighKick;
	std::shared_ptr<class AUnicornSpike> UnicornSpike;
	std::shared_ptr<class ALegendarySpear> LegendarySpear;
	std::shared_ptr<class ARoyalKnight> RoyalKnight;

	// 세렌
	std::shared_ptr<class ASeren> Seren;

	// 세렌 스킬
	std::shared_ptr<class ASting> Sting;

	// 맵
	std::shared_ptr<class AMainHall> MainHall;

	// 카메라
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

