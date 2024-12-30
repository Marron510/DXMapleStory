#pragma once

#include <EngineCore/Actor.h>

class ADawnPriest : public AActor
{
public:
	// 持失切 社瑚切
	ADawnPriest();
	~ADawnPriest();

	// delete funcion

	ADawnPriest(const ADawnPriest& _Other) = delete;
	ADawnPriest(ADawnPriest&& _Other) noexcept = delete;
	ADawnPriest& operator=(const ADawnPriest& _Other) = delete;
	ADawnPriest& operator=(ADawnPriest&& _Other) noexcept = delete;


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	std::shared_ptr<class USpriteRenderer> ADawnPriestenderer;
};

