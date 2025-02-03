#pragma once
#include <EngineCore/GameInstance.h>
#include <EngineCore/Widget.h>

#include "MapleStruct.h"

class MapleInstance : public UGameInstance
{
public:
	// 持失切 社瑚切
	MapleInstance();
	~MapleInstance();

	// delete funcion

	MapleInstance(const MapleInstance& _Other) = delete;
	MapleInstance(MapleInstance&& _Other) noexcept = delete;
	MapleInstance& operator=(const MapleInstance& _Other) = delete;
	MapleInstance& operator=(MapleInstance&& _Other) noexcept = delete;


	FPlayerStatus Status;
	
	FSerenStatus1 SerenStatus1;

	UWidget* InvenWidget;


protected:

private:

};

