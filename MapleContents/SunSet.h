#pragma once

#include <EngineCore/Actor.h>


class ASunSet : public AActor
{
public:
	// 持失切 社瑚切
	ASunSet();
	~ASunSet();

	// delete funcion

	ASunSet(const ASunSet& _Other) = delete;
	ASunSet(ASunSet&& _Other) noexcept = delete;
	ASunSet& operator=(const ASunSet& _Other) = delete;
	ASunSet& operator=(ASunSet&& _Other) noexcept = delete;


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	std::shared_ptr<class USpriteRenderer> SunSet;
};

