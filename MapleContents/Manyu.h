#pragma once

#include <EngineCore/Actor.h>

class AManyu : public AActor
{
public:
	// 持失切 社瑚切
	AManyu();
	~AManyu();

	// delete funcion

	AManyu(const AManyu& _Other) = delete;
	AManyu(AManyu&& _Other) noexcept = delete;
	AManyu& operator=(const AManyu& _Other) = delete;
	AManyu& operator=(AManyu&& _Other) noexcept = delete;


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	std::shared_ptr<class USpriteRenderer> Manyurenderer;
};

