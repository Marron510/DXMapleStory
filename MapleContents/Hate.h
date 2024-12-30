#pragma once

#include <EngineCore/Actor.h>

class AHate : public AActor
{
public:
	// 持失切 社瑚切
	AHate();
	~AHate();

	// delete funcion

	AHate(const AHate& _Other) = delete;
	AHate(AHate&& _Other) noexcept = delete;
	AHate& operator=(const AHate& _Other) = delete;
	AHate& operator=(AHate&& _Other) noexcept = delete;


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	std::shared_ptr<class USpriteRenderer> Haterenderer;
};

