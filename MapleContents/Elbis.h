#pragma once

#include <EngineCore/Actor.h>


class AElbis : public AActor
{
public:
	// 持失切 社瑚切
	AElbis();
	~AElbis();

	// delete funcion

	AElbis(const AElbis& _Other) = delete;
	AElbis(AElbis&& _Other) noexcept = delete;
	AElbis& operator=(const AElbis& _Other) = delete;
	AElbis& operator=(AElbis&& _Other) noexcept = delete;


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	std::shared_ptr<class USpriteRenderer> Elbisrenderer;
};

