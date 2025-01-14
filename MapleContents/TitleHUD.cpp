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

	std::shared_ptr<UWidget> Button = CreateWidget<UWidget>(-1);

}

void ATitleHUD::Tick(float _DeltaTime)
{
	AHUD::Tick(_DeltaTime);
}


