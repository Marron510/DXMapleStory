#pragma once

#include <EngineCore/Actor.h>


class ADawn : public AActor
{
public:
	// 持失切 社瑚切
	ADawn();
	~ADawn();

	// delete funcion

	ADawn(const ADawn& _Other) = delete;
	ADawn(ADawn&& _Other) noexcept = delete;
	ADawn& operator=(const ADawn& _Other) = delete;
	ADawn& operator=(ADawn&& _Other) noexcept = delete;


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	std::shared_ptr<class USpriteRenderer> Dawn;
};

