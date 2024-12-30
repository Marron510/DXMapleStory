#pragma once
#include <EngineCore/Actor.h>

class ACerniumPlazaMode : public AActor
{
public:
	// 持失切 社瑚切
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
	std::shared_ptr<class APlayer> Player;


	//NPC
	std::shared_ptr<class ADawnPriest> DawnPriest;
	std::shared_ptr<class ACerniumPlaza> Plaza;
	std::shared_ptr<class ACameraActor> Camera;
};

