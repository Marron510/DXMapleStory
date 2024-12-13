#pragma once
#include <EngineCore/IContentsCore.h>

class UMapleContentsCore : public IContentsCore
{
public:
	// 持失切 社瑚切
	UMapleContentsCore();
	~UMapleContentsCore();

	// delete funcion

	UMapleContentsCore(const UMapleContentsCore& _Other) = delete;
	UMapleContentsCore(UMapleContentsCore&& _Other) noexcept = delete;
	UMapleContentsCore& operator=(const UMapleContentsCore& _Other) = delete;
	UMapleContentsCore& operator=(UMapleContentsCore&& _Other) noexcept = delete;


protected:
	void EngineStart(UEngineInitData& _Data);
	void EngineTick(float _DeltaTime);
	void EngineEnd();
private:

};

