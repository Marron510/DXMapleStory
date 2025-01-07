#pragma once
#include <EngineCore/Actor.h>

class ACerniumPlazaMode : public AActor
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

	void Tick(float _DeltaTime);

protected:

private:
	// 플레이어
	std::shared_ptr<class APlayer> Player;

	// 플레이어 스킬

	std::shared_ptr<class AWrathOfEnril> WrathOfEnril;
	std::shared_ptr<class ALeafTornadoFront> LeafTornadoFront;
	std::shared_ptr<class ALeafTornadoBack> LeafTornadoBack;




	// 맵
	std::shared_ptr<class ACerniumPlaza> Plaza;
	std::shared_ptr<class AManyu> Manyu;
	std::shared_ptr<class USpriteRenderer> BigTree_Left;
	std::shared_ptr<class USpriteRenderer> BigTree_Right;

	// 카메라
	std::shared_ptr<class ACameraActor> Camera;

	



};

