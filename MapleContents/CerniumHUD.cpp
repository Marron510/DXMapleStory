#include "PreCompile.h"
#include "CerniumHUD.h"
#include <EngineCore/Widget.h>

ACerniumHUD::ACerniumHUD()
{

}

ACerniumHUD::~ACerniumHUD()
{

}


void ACerniumHUD::BeginPlay()
{
	AHUD::BeginPlay();
}
void ACerniumHUD::Tick(float _DeltaTime)
{
	AHUD::Tick(_DeltaTime);
}