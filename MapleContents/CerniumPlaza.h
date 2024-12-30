#pragma once
#include <EngineCore/Actor.h>

class ACerniumPlaza : public AActor
{
public:
	// ������ �Ҹ���
	ACerniumPlaza();
	~ACerniumPlaza();

	// delete funcion

	ACerniumPlaza(const ACerniumPlaza& _Other) = delete;
	ACerniumPlaza(ACerniumPlaza&& _Other) noexcept = delete;
	ACerniumPlaza& operator=(const ACerniumPlaza& _Other) = delete;
	ACerniumPlaza& operator=(ACerniumPlaza&& _Other) noexcept = delete;


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

