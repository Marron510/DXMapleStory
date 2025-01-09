#pragma once
#include "SkillManager.h"

class ALeafTornado: public ASkillManager
{
public:
	// 持失切 社瑚切
	ALeafTornado();
	~ALeafTornado();

	// delete funcion

	ALeafTornado(const ALeafTornado& _Other) = delete;
	ALeafTornado(ALeafTornado&& _Other) noexcept = delete;
	ALeafTornado& operator=(const ALeafTornado& _Other) = delete;
	ALeafTornado& operator=(ALeafTornado&& _Other) noexcept = delete;


	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

protected:
	
	
private:
	std::shared_ptr<class USpriteRenderer> LeafTornadoFront;
	std::shared_ptr<class USpriteRenderer> LeafTornadoBack;

	std::shared_ptr<class UCollision> Collision;
};

