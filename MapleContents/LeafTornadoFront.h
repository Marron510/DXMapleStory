#pragma once
#include "SkillManager.h"

class ALeafTornadoFront: public ASkillManager
{
public:
	// 持失切 社瑚切
	ALeafTornadoFront();
	~ALeafTornadoFront();

	// delete funcion

	ALeafTornadoFront(const ALeafTornadoFront& _Other) = delete;
	ALeafTornadoFront(ALeafTornadoFront&& _Other) noexcept = delete;
	ALeafTornadoFront& operator=(const ALeafTornadoFront& _Other) = delete;
	ALeafTornadoFront& operator=(ALeafTornadoFront&& _Other) noexcept = delete;


	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

protected:
	
	
private:
	std::shared_ptr<class UTimeEventComponent> TimeEventComponent;
	std::shared_ptr<class USpriteRenderer> LeafTornadoFront;

	float FrontSkillZPos = -4.5f;
	float BackSkillZPos = -3.9f;
};

