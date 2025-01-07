#pragma once
#include "SkillManager.h"

class ALeafTornadoBack: public ASkillManager
{
public:
	// ������ �Ҹ���
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

};

