#pragma once

#include <EngineCore/Actor.h>

class AMainHall: public AActor
{
public:
	// 持失切 社瑚切
	AMainHall();
	~AMainHall();

	// delete funcion

	AMainHall(const AMainHall& _Other) = delete;
	AMainHall(AMainHall&& _Other) noexcept = delete;
	AMainHall& operator=(const AMainHall& _Other) = delete;
	AMainHall& operator=(AMainHall&& _Other) noexcept = delete;

	std::shared_ptr<class USpriteRenderer> GetMainHall_Sky()
	{
		return MainHall_Sky;
	}

	std::shared_ptr<class USpriteRenderer> GetMainHall_Center()
	{
		return MainHall_Center;
	}

	std::shared_ptr<class USpriteRenderer> GetMainHall_Pillar_Left()
	{
		return MainHall_Pillar_Left;
	}

	std::shared_ptr<class USpriteRenderer> GetMainHall_Pillar_Right()
	{
		return MainHall_Pillar_Right;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;




private:

	std::shared_ptr<class UCollision> Collision;

	std::shared_ptr<class USpriteRenderer> MainHall;
	std::shared_ptr<class USpriteRenderer> MainHall_Sky;
	std::shared_ptr<class USpriteRenderer> MainHall_Center;
	std::shared_ptr<class USpriteRenderer> MainHall_Pillar_Left;
	std::shared_ptr<class USpriteRenderer> MainHall_Pillar_Right;

	float MapSizeHalfX = 2274.0f;
	float MapSizeHalfY = 858.0f;
	float MapSizeDefaultY = 810.0f;
	
};

