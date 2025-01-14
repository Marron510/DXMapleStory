#pragma once
#include <EngineCore/Collision.h>

class USerenCollision : public UCollision
{
public:
	// ������ �Ҹ���
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

protected:

private:
	float Hp = 100.0f;
};

