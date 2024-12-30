#pragma once

#include <EngineCore/Actor.h>

class AShorn : public AActor
{
public:
	// 持失切 社瑚切
	AShorn();
	~AShorn();

	// delete funcion

	AShorn(const AShorn& _Other) = delete;
	AShorn(AShorn&& _Other) noexcept = delete;
	AShorn& operator=(const AShorn& _Other) = delete;
	AShorn& operator=(AShorn&& _Other) noexcept = delete;


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	std::shared_ptr<class USpriteRenderer> Shornrenderer;
};

