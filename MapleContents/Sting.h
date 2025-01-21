#pragma once

#include <EngineCore/Actor.h>

class ASting : public AActor
{
public:
	// ������ �Ҹ���
	ASting();
	~ASting();

	// delete funcion

	ASting(const ASting& _Other) = delete;
	ASting(ASting&& _Other) noexcept = delete;
	ASting& operator=(const ASting& _Other) = delete;
	ASting& operator=(ASting&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

protected:

private:

	std::shared_ptr<class UCollision> StingCollision;

};

