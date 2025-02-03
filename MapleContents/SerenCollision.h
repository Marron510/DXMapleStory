#pragma once
#include <EngineCore/Collision.h>
#include <EngineBase/EngineDebug.h>

class USerenCollision : public UCollision
{
public:
	// 持失切 社瑚切
	USerenCollision();
	~USerenCollision();

	// delete funcion

	USerenCollision(const USerenCollision& _Other) = delete;
	USerenCollision(USerenCollision&& _Other) noexcept = delete;
	USerenCollision& operator=(const USerenCollision& _Other) = delete;
	USerenCollision& operator=(USerenCollision&& _Other) noexcept = delete;



	float GetHp()
	{
		return Hp;
	}

	void Damage(float _Attack)
	{
		Hp -= _Attack;
	}

	bool GetIsDamaged()
	{
		return bIsDamaged;
	}
	
protected:

private:
	float Hp = 1000.0f;
	bool bIsDamaged = false;
};

