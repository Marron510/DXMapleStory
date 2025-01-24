#pragma once

#include <EngineCore/Actor.h>


class ASmallAtom : public AActor
{
public:
	// 持失切 社瑚切
	ASmallAtom();
	~ASmallAtom();

	// delete funcion

	ASmallAtom(const ASmallAtom& _Other) = delete;
	ASmallAtom(ASmallAtom&& _Other) noexcept = delete;
	ASmallAtom& operator=(const ASmallAtom& _Other) = delete;
	ASmallAtom& operator=(ASmallAtom&& _Other) noexcept = delete;


	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	
	void Create();
	
	void Move(float _DeltaTime);
	void Restart();

	bool GetIsEnd()
	{
		return bIsEnd;
	}

protected:

private:
	std::shared_ptr<class USpriteRenderer> SmallAtom;
	std::shared_ptr<class UCollision> Collision;

	class APlayer* Player = nullptr;
	bool bIsStart = false;
	bool bIsEnd = false;

	float AtomDamage = 10.0f;
	float AtomSpeed = 100.0f;
};

