#include "PreCompile.h"
#include "SerenHUD.h"


ASerenHUD::ASerenHUD()
{

}

ASerenHUD::~ASerenHUD()
{

}

void ASerenHUD::BeginPlay()
{
	AHUD::BeginPlay();
}

void ASerenHUD::Tick(float _DeltaTime)
{
	AHUD::Tick(_DeltaTime);
}
