#pragma once

#include <EngineCore/Actor.h> 


class ASmall8Laser : public AActor
{
public:
	// ������ �Ҹ���
	ASmall8Laser();
	~ASmall8Laser();

	// delete funcion

	ASmall8Laser(const ASmall8Laser& _Other) = delete;
	ASmall8Laser(ASmall8Laser&& _Other) noexcept = delete;
	ASmall8Laser& operator=(const ASmall8Laser& _Other) = delete;
	ASmall8Laser& operator=(ASmall8Laser&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	std::shared_ptr<class USpriteRenderer> GetLaser1()
	{
		return Laser1;
	}

protected:

private:
	std::shared_ptr<class USpriteRenderer> Laser1; // ����
	std::shared_ptr<class USpriteRenderer> Laser2; // ����
	std::shared_ptr<class USpriteRenderer> Laser3; // ���� �밢
	std::shared_ptr<class USpriteRenderer> Laser4; // ������ �밢

	std::shared_ptr<class UCollision> Collision1;  // ����
	std::shared_ptr<class UCollision> Collision2;  // ����
	std::shared_ptr<class UCollision> Collision3;  // ���� �밢
	std::shared_ptr<class UCollision> Collision4;  // ������ �밢


	class APlayer* Player = nullptr;

	float WaitTime = 1.3f;
	float HitTime = 1.3f;
	float LaserDamage = 15000.0f;
	float LaserSpeed = 0.1f;
};

