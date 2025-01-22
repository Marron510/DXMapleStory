#include "PreCompile.h"
#include "SerenHUD.h"
#include <EngineCore/ImageWidget.h>

ASerenHUD::ASerenHUD()
{

}

ASerenHUD::~ASerenHUD()
{

}

void ASerenHUD::BeginPlay()
{
	AHUD::BeginPlay();
	{
		std::shared_ptr<UImageWidget> PlayerBarBack = CreateWidget<UImageWidget>(-1);
		PlayerBarBack->SetTexture("PlayerBarBack.png", true, 1.0f);
		PlayerBarBack->SetRelativeLocation(StatusBackLocation);
	}

	//  이 사이에 Hp, MP 바 넣어야함

	{
		std::shared_ptr<UImageWidget> CenterStatus = CreateWidget<UImageWidget>(-1);
		CenterStatus->SetTexture("PlayerBar.png", true, 1.0f);
		CenterStatus->SetRelativeLocation(StatusLocation);
	}


	{
		std::shared_ptr<UImageWidget> ExpBarBack = CreateWidget<UImageWidget>(-1);
		ExpBarBack->SetTexture("EXPBar.png", true, 1.0f);
		ExpBarBack->SetRelativeLocation(ExpBarLocation);
	}

	// 이 사이에 exp 바 넣어야 함

	{
		std::shared_ptr<UImageWidget> ExpBarCover = CreateWidget<UImageWidget>(-1);
		ExpBarCover->SetTexture("EXPBarcover.png", true, 1.0f);
		ExpBarCover->SetRelativeLocation(ExpBarLocation);
	}
}

void ASerenHUD::Tick(float _DeltaTime)
{
	AHUD::Tick(_DeltaTime);
}
