#include "PreCompile.h"
#include "TitleHUD.h"
#include <EngineCore/Widget.h>


ATitleHUD::ATitleHUD()
{

}

ATitleHUD::~ATitleHUD()
{

}


void ATitleHUD::BeginPlay()
{
	AHUD::BeginPlay();

	CreateWidget<UWidget>();

}

void ATitleHUD::Tick(float _DeltaTime)
{
	AHUD::Tick(_DeltaTime);
}


