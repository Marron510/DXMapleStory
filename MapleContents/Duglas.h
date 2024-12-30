#pragma once

#include <EngineCore/Actor.h>


class ADuglas : public AActor
{
public:
	// 持失切 社瑚切
	ADuglas();
	~ADuglas();

	// delete funcion

	ADuglas(const ADuglas& _Other) = delete;
	ADuglas(ADuglas&& _Other) noexcept = delete;
	ADuglas& operator=(const ADuglas& _Other) = delete;
	ADuglas& operator=(ADuglas&& _Other) noexcept = delete;


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	std::shared_ptr<class USpriteRenderer> Duglasrenderer;
};

