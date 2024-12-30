#pragma once

#include <EngineCore/Actor.h>

class AOldMan : public AActor
{
public:
	// 持失切 社瑚切
	AOldMan();
	~AOldMan();

	// delete funcion

	AOldMan(const AOldMan& _Other) = delete;
	AOldMan(AOldMan&& _Other) noexcept = delete;
	AOldMan& operator=(const AOldMan& _Other) = delete;
	AOldMan& operator=(AOldMan&& _Other) noexcept = delete;


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	std::shared_ptr<class USpriteRenderer> OldManrenderer;
};

