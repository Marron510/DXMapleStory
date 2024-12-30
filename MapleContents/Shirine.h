#pragma once

#include <EngineCore/Actor.h>

class AShirine : public AActor
{
public:
	// ������ �Ҹ���
	AShirine();
	~AShirine();

	// delete funcion

	AShirine(const AShirine& _Other) = delete;
	AShirine(AShirine&& _Other) noexcept = delete;
	AShirine& operator=(const AShirine& _Other) = delete;
	AShirine& operator=(AShirine&& _Other) noexcept = delete;


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	std::shared_ptr<class USpriteRenderer> Shirinerenderer;
};

