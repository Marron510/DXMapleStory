#pragma once
#include <EngineCore/GameMode.h>

class ACerniumPlazaMode : public AGameMode
{
public:
	// 생성자 소멸자
	ACerniumPlazaMode();
	~ACerniumPlazaMode();

	// delete funcion

	ACerniumPlazaMode(const ACerniumPlazaMode& _Other) = delete;
	ACerniumPlazaMode(ACerniumPlazaMode&& _Other) noexcept = delete;
	ACerniumPlazaMode& operator=(const ACerniumPlazaMode& _Other) = delete;
	ACerniumPlazaMode& operator=(ACerniumPlazaMode&& _Other) noexcept = delete;

	void BeginPlay();
	void Tick(float _DeltaTime);

	void GetSpriteLocation();
	void UpdateSprite(float _DeltaTime);
	void UpdateSpriteLocation(std::shared_ptr<class USpriteRenderer>& Sprite, float _DeltaTime);


	void ChargeDriveActive();
	void HighKickActive();
protected:

private:
	// 플레이어
	std::shared_ptr<class APlayer> Player;

	// 플레이어 스킬

	std::shared_ptr<class AWrathOfEnril> WrathOfEnril;
	std::shared_ptr<class ALeafTornado> LeafTornadoFront;
	std::shared_ptr<class AStrikeDualShot> StrikeDualShot;
	std::shared_ptr<class ARollingMoonSult> RollingMoonSult;
	std::shared_ptr<class AChargeDrive> ChargeDrive;
	std::shared_ptr<class AHighKick> HighKick;


	// 맵
	std::shared_ptr<class ACerniumPlaza> Plaza;
	std::shared_ptr<class AManyu> Manyu;
	std::shared_ptr<class USpriteRenderer> BigTree_Left;
	std::shared_ptr<class USpriteRenderer> BigTree_Right;

	float MapSizeHalfX = 2415.0f;
	float MapSizeHalfY = 795.0f;
	float MapSizeDefaultY = 1203.0f;



	std::shared_ptr<class USpriteRenderer> Plaza_Back = nullptr;
	std::shared_ptr<class USpriteRenderer> Plaza_Mid = nullptr;
	std::shared_ptr<class USpriteRenderer> Flag0 = nullptr;
	std::shared_ptr<class USpriteRenderer> Flag1 = nullptr;
	std::shared_ptr<class USpriteRenderer> Flag2 = nullptr;
	std::shared_ptr<class USpriteRenderer> Flag3 = nullptr;
	std::shared_ptr<class USpriteRenderer> Flag4 = nullptr;
	std::shared_ptr<class USpriteRenderer> Flag5 = nullptr;

	// 카메라
	std::shared_ptr<class ACameraActor> Camera;

	
	FVector PlazaRenderScale = FVector{ 4830.0f ,1590.0f , 8000};
	float SpeedMultiplier = 0.0f;
	float PreviousPlayerLocation = 0.0f;

	float Velocity = 0.0f;

};

