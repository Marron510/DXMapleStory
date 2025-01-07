#pragma once
#include "SkillManager.h"

class ALeafTornadoBack: public ASkillManager
{
public:
	// 持失切 社瑚切
	ALeafTornadoBack();
	~ALeafTornadoBack();

	// delete funcion

	ALeafTornadoBack(const ALeafTornadoBack& _Other) = delete;
	ALeafTornadoBack(ALeafTornadoBack&& _Other) noexcept = delete;
	ALeafTornadoBack& operator=(const ALeafTornadoBack& _Other) = delete;
	ALeafTornadoBack& operator=(ALeafTornadoBack&& _Other) noexcept = delete;


	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

protected:
	
	
private:
	std::shared_ptr<class UTimeEventComponent> TimeEventComponent;
	std::shared_ptr<class USpriteRenderer> LeafTornadoBack;

	float FrontSkillZPos = -4.0f;
	float BackSkillZPos = -3.9f;

};

