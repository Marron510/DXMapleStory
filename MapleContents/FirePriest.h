#pragma once

#include <EngineCore/CameraActor.h>

class AFirePriest : public AActor
{
public:
	// ������ �Ҹ���
	AFirePriest();
	~AFirePriest();

	// delete funcion

	AFirePriest(const AFirePriest& _Other) = delete;
	AFirePriest(AFirePriest&& _Other) noexcept = delete;
	AFirePriest& operator=(const AFirePriest& _Other) = delete;
	AFirePriest& operator=(AFirePriest&& _Other) noexcept = delete;


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	std::shared_ptr<class USpriteRenderer> FirePriestrenderer;
};

