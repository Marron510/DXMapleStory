#include "PreCompile.h"
#include "MapleContentsCore.h"
#include <EngineCore/Level.h>
#include "TitleGameMode.h"


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

	UEngineCore::CreateLevel<ATitleGameMode, APawn>("Titlelevel");
	UEngineCore::OpenLevel("Titlelevel");

}

void UMapleContentsCore::EngineTick(float _DeltaTime)
{

}

void UMapleContentsCore::EngineEnd()
{

}