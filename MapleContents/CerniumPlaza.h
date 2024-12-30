#pragma once
#include <EngineCore/Actor.h>

class ACerniumPlaza : public AActor
{
public:
	// 持失切 社瑚切
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
	std::shared_ptr<class USpriteRenderer> Plaza;
	std::shared_ptr<class USpriteRenderer> Smithy;
	std::shared_ptr<class USpriteRenderer> Potion;
	std::shared_ptr<class USpriteRenderer> BuildingLeft_0;
	std::shared_ptr<class USpriteRenderer> BuildingLeft_1;
	std::shared_ptr<class USpriteRenderer> BuildingRight_0;
	std::shared_ptr<class USpriteRenderer> BuildingRight_1;
	

};

