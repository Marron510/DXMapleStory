#pragma once

#include <EngineCore/Actor.h>


class ANoon : public AActor
{
public:
	// 持失切 社瑚切
	ANoon();
	~ANoon();

	// delete funcion

	ANoon(const ANoon& _Other) = delete;
	ANoon(ANoon&& _Other) noexcept = delete;
	ANoon& operator=(const ANoon& _Other) = delete;
	ANoon& operator=(ANoon&& _Other) noexcept = delete;


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	std::shared_ptr<class USpriteRenderer> Noon;
};

