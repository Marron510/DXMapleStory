#pragma once
#include <EngineCore/GameMode.h>
#include <atomic>
#include <EnginePlatform/EngineThread.h>

class ALoadingGamdMode : public AGameMode
{
public:
	// 持失切 社瑚切
	ALoadingGamdMode();
	~ALoadingGamdMode();

	// delete funcion

	ALoadingGamdMode(const ALoadingGamdMode& _Other) = delete;
	ALoadingGamdMode(ALoadingGamdMode&& _Other) noexcept = delete;
	ALoadingGamdMode& operator=(const ALoadingGamdMode& _Other) = delete;
	ALoadingGamdMode& operator=(ALoadingGamdMode&& _Other) noexcept = delete;

	void Tick(float _DeltaTime);

protected:
	void LevelChangeStart() override;
private:
	std::atomic<int> LoadingCount = 0;

	std::atomic<bool> ThreadLoadingInit = false;

	std::atomic<bool> ThreadLoadingEnd = false;
	UEngineThread Thread;
};

