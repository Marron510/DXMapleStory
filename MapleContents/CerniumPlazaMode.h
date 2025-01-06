#pragma once
#include <EngineCore/Actor.h>

class ACerniumPlazaMode : public AActor
{
public:
	// ������ �Ҹ���
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


	std::shared_ptr<class ACerniumPlaza> Plaza;
	std::shared_ptr<class ACameraActor> Camera;

	std::shared_ptr<class AManyu> Manyu;

	std::shared_ptr<class USpriteRenderer> BigTree_Left;
	std::shared_ptr<class USpriteRenderer> BigTree_Right;

};

