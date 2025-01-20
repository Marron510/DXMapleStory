#include "PreCompile.h"
#include "MapleContentsCore.h"

#include <EngineCore/Level.h>
#include <EngineCore/EngineTexture.h>
#include <EngineCore/EngineSprite.h>

#include "TitleGameMode.h"
#include "CerniumPlazaMode.h"
#include "MainHallMode.h"
#include "TheBoundaryOfTheWorld.h"
#include "TitleHUD.h"
#include "CerniumHUD.h"
#include "Player.h"
#include "MapleInstance.h"
#include "LoadingGamdMode.h"

CreateContentsCoreDefine(UMapleContentsCore);

UMapleContentsCore::UMapleContentsCore()
{

}

UMapleContentsCore::~UMapleContentsCore()
{

}


void UMapleContentsCore::EngineStart(UEngineInitData& _Data)
{

	GEngine->CreateGameInstance<MapleInstance>();

	_Data.WindowPos = { 100, 100 };
	_Data.WindowSize = { 1366, 768 };


	
	

	






	UEngineCore::CreateLevel<ALoadingGamdMode, APawn, AHUD>("LoadingLevel");

	UEngineCore::OpenLevel("LoadingLevel");
}

void UMapleContentsCore::EngineTick(float _DeltaTime)
{
	IContentsCore::EngineTick(_DeltaTime);
}

void UMapleContentsCore::EngineEnd()
{
	IContentsCore::EngineEnd();
}
