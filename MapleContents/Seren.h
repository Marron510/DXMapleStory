#pragma once
#include <EngineCore/Actor.h>

class ASeren : public AActor
{
public:
	ASeren();
	~ASeren();

	// delete funcion

	ASeren(const ASeren& _Other) = delete;
	ASeren(ASeren&& _Other) noexcept = delete;
	ASeren& operator=(const ASeren& _Other) = delete;
	ASeren& operator=(ASeren&& _Other) noexcept = delete;

	

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> Seren;
};

