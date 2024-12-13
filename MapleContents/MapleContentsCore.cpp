#include "PreCompile.h"
#include "MapleContentsCore.h"

CreateContentsCoreDefine(UMapleContentsCore);

UMapleContentsCore::UMapleContentsCore()
{

}

UMapleContentsCore::~UMapleContentsCore()
{

}


void UMapleContentsCore::EngineStart(UEngineInitData& _Data)
{

	_Data.WindowPos = { 100, 100 };
	_Data.WindowSize = { 1366, 768 };

}

void UMapleContentsCore::EngineTick(float _DeltaTime)
{

}

void UMapleContentsCore::EngineEnd()
{

}