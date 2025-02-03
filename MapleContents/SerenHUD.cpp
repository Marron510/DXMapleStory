#include "PreCompile.h"
#include "SerenHUD.h"
#include <EngineCore/ImageWidget.h>

#include "PlayerHpBar.h"
#include "PlayerMpBar.h"
#include "PlayerHpBarEffect.h"
#include "PlayerMpBarEffect.h"

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


	// Hp, MP 바
	{
		std::shared_ptr<UPlayerHpBar> PlayerHpBar = CreateWidget<UPlayerHpBar>(-1);
		std::shared_ptr<UPlayerMpBar> PlayerMpBar = CreateWidget<UPlayerMpBar>(-1);
		std::shared_ptr<UPlayerHpBarEffect> PlayerHpBarEffect = CreateWidget<UPlayerHpBarEffect>(-1);
		std::shared_ptr<UPlayerMpBarEffect> PlayerMpBarEffect = CreateWidget<UPlayerMpBarEffect>(-1);


		PlayerHpBar->SetPlayerHpBarEffect(PlayerHpBarEffect.get());
		PlayerMpBar->SetPlayerMpBarEffect(PlayerMpBarEffect.get());
	}

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


	// 레벨

	{
		std::shared_ptr<UImageWidget> Level = CreateWidget<UImageWidget>(-1);
		Level->SetTexture("Lv.png", true, 1.0f);
		Level->SetRelativeLocation(LevelLocation);
	}

	{
		std::shared_ptr<UImageWidget> First = CreateWidget<UImageWidget>(-1);
		First->SetTexture("2.png", true, 1.0f);
		First->SetRelativeLocation(FirstLocation);
	}

	{
		std::shared_ptr<UImageWidget> Second = CreateWidget<UImageWidget>(-1);
		Second->SetTexture("8.png", true, 1.0f);
		Second->SetRelativeLocation(SecondLocation);
	}

	{
		std::shared_ptr<UImageWidget> Third = CreateWidget<UImageWidget>(-1);
		Third->SetTexture("0.png", true, 1.0f);
		Third->SetRelativeLocation(ThirdLocation);
	}


	// 이 사이에 exp 바 넣어야 함

	{
		std::shared_ptr<UImageWidget> ExpBarCover = CreateWidget<UImageWidget>(-1);
		ExpBarCover->SetTexture("EXPBarcover.png", true, 1.0f);
		ExpBarCover->SetRelativeLocation(ExpBarLocation);
	}

	// 스킬 바

	{
		std::shared_ptr<UImageWidget> ExpBarCover = CreateWidget<UImageWidget>(-1);
		ExpBarCover->SetTexture("Skill_Layer.png", true, 1.0f);
		ExpBarCover->SetRelativeLocation(SkillBarLocation);
	}
	{
		std::shared_ptr<UImageWidget> ExpBarCover = CreateWidget<UImageWidget>(-1);
		ExpBarCover->SetTexture("QuickSkill.png", true, 1.0f);
		ExpBarCover->SetRelativeLocation(SkillBarLocation);
	}

	{
		std::shared_ptr<UImageWidget> ExpBarCover = CreateWidget<UImageWidget>(-1);
		ExpBarCover->SetTexture("Skill_Fold.png", true, 1.0f);
		ExpBarCover->SetRelativeLocation(SkillFoldBarLocation);
	}


	// 세렌 빛 게이지
	{
		std::shared_ptr<UImageWidget> GageUI_Back = CreateWidget<UImageWidget>(-1);
		GageUI_Back->SetTexture("GageUI_Back.png", true);
		GageUI_Back->SetRelativeLocation(GageBackLocation);
	}

	{
		std::shared_ptr<UImageWidget> GageUI_Ball = CreateWidget<UImageWidget>(-1);
		GageUI_Ball->SetTexture("GageUI_Ball.png", true);
		GageUI_Ball->SetRelativeLocation(GageBallLocation);
		
	}


}

void ASerenHUD::Tick(float _DeltaTime)
{
	AHUD::Tick(_DeltaTime);
}
