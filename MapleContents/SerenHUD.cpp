#include "PreCompile.h"
#include "SerenHUD.h"

#include <EngineCore/ImageWidget.h>
#include <EngineCore/FontWidget.h>


#include "PlayerHpBar.h"
#include "PlayerMpBar.h"
#include "PlayerHpBarEffect.h"
#include "PlayerMpBarEffect.h"
#include "Boss1HpBar.h"
#include "MapleInstance.h"
#include "PlayerCurHPFont.h"
#include "PlayerCurMPFont.h"

// 세렌 게이지
#include "SerenGage1.h"

// 스킬 UI
#include "IconCharge.h"
#include "IconEnril.h"
#include "IconHighKick.h"
#include "IconLeafTornado.h"
#include "IconIshtar.h"
#include "IconLegendarySpear.h"
#include "IconUnicornSpike.h"
#include "IconStrikeDualShot.h"
#include "IconRollingMoonSult.h"
#include "BindUI.h"

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

	// 현재 HP, MP
	{
		std::shared_ptr<UPlayerCurHPFont> CurHPWidget = CreateWidget<UPlayerCurHPFont>(5);
		CurHPWidget->SetColor(UColor::WHITE);
		CurHPWidget->SetScale(10.6f);
		CurHPWidget->SetRelativeLocation(CurHpLocation);
	}

	{
		std::shared_ptr<UPlayerCurMPFont> CurMPWidget = CreateWidget<UPlayerCurMPFont>(5);

		CurMPWidget->SetColor(UColor::WHITE);
		CurMPWidget->SetScale(10.6f);
		CurMPWidget->SetRelativeLocation(CurMpLocation);
	}

	// Max HP, MP
	{
		std::shared_ptr<UFontWidget> MaxHPWidget = CreateWidget<UFontWidget>(5);

		MaxHPWidget->SetFont("메이플스토리 Bold");
		float FMaxHp = GetGameInstance<MapleInstance>()->Status.MaxHp;
		int IMaxHp = static_cast<int>(FMaxHp);
		std::string MaxHPstr = std::to_string(IMaxHp);
		MaxHPWidget->SetText(MaxHPstr);
		MaxHPWidget->SetColor(UColor::WHITE);
		MaxHPWidget->SetScale(10.6f);
		MaxHPWidget->SetRelativeLocation(MaxHpLocation);
	}

	{
		std::shared_ptr<UFontWidget> MaxMPWidget = CreateWidget<UFontWidget>(5);

		MaxMPWidget->SetFont("메이플스토리 Bold");
		float FMaxMp = GetGameInstance<MapleInstance>()->Status.MaxMp;
		int IMaxMp = static_cast<int>(FMaxMp);
		std::string MaxMPstr = std::to_string(IMaxMp);
		MaxMPWidget->SetText(MaxMPstr);
		MaxMPWidget->SetColor(UColor::WHITE);
		MaxMPWidget->SetScale(10.6f);
		MaxMPWidget->SetRelativeLocation(MaxMpLocation);
	}

	// 레벨

	{
		std::shared_ptr<UImageWidget> Level = CreateWidget<UImageWidget>(-1);
		Level->SetTexture("Lv.png", true, 1.0f);
		Level->SetRelativeLocation(LevelLocation);
	}

	{
		std::shared_ptr<UImageWidget> First = CreateWidget<UImageWidget>(1);
		First->SetTexture("2.png", true, 1.0f);
		First->SetRelativeLocation(FirstLocation);
	}

	{
		std::shared_ptr<UImageWidget> Second = CreateWidget<UImageWidget>(0);
		Second->SetTexture("8.png", true, 1.0f);
		Second->SetRelativeLocation(SecondLocation);
	}

	{
		std::shared_ptr<UImageWidget> Third = CreateWidget<UImageWidget>(-1);
		Third->SetTexture("0.png", true, 1.0f);
		Third->SetRelativeLocation(ThirdLocation);
	}

	// 이름

	{
		std::shared_ptr<UFontWidget> NameWidget= CreateWidget<UFontWidget>(10002);

		NameWidget->SetFont("메이플스토리 Bold");
		NameWidget->SetText("호두");
		NameWidget->SetColor(UColor::WHITE);
		NameWidget->SetScale(15.0f);
		NameWidget->SetRelativeLocation(NameLocation);
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

	// 스킬 UI

	{
		std::shared_ptr<UIconCharge> IconChargeDrive = CreateWidget<UIconCharge>(0);
		std::shared_ptr<UIconEnril> IconEnril = CreateWidget<UIconEnril>(0);
		std::shared_ptr<UIconHighKick> IconHighKick = CreateWidget<UIconHighKick>(0);
		std::shared_ptr<UIconLeafTornado> IconLeafTornado = CreateWidget<UIconLeafTornado>(0);
		std::shared_ptr<UIconIshtar> IconIshtar = CreateWidget<UIconIshtar>(0);
		std::shared_ptr<UIconLegendarySpear> IconLegendarySpear = CreateWidget<UIconLegendarySpear>(0);
		std::shared_ptr<UIconUnicornSpike> IconUnicornSpike = CreateWidget<UIconUnicornSpike>(0);
		std::shared_ptr<UIconStrikeDualShot> IconStrikeDualShot = CreateWidget<UIconStrikeDualShot>(0);
		std::shared_ptr<UIconRollingMoonSult> IconRollingMoonSult = CreateWidget<UIconRollingMoonSult>(0);
	}

	// 세렌 빛 게이지
	{
		std::shared_ptr<UImageWidget> GageUI_Back = CreateWidget<UImageWidget>(-3);
		GageUI_Back->SetTexture("GageUI_Back.png", true);
		GageUI_Back->SetRelativeLocation(GageBackLocation);
	}

	{
		std::shared_ptr<UImageWidget> GageUI_Ball = CreateWidget<UImageWidget>(-1);
		GageUI_Ball->SetTexture("GageUI_Ball.png", true);
		GageUI_Ball->SetRelativeLocation(GageBallLocation);
	}

	{
		std::shared_ptr<USerenGage1> GageUI_Front = CreateWidget<USerenGage1>(0);
		GageUI_Front->SetRelativeLocation(GageFrontLocation);
	}

	// 세렌 바인드 UI
	
	{
		std::shared_ptr<UBindUI> GageUI_Front = CreateWidget<UBindUI>(1000);
	}

	// 세렌 HP 바
	{
		std::shared_ptr<UImageWidget> GageUI_Back = CreateWidget<UImageWidget>(-1);
		GageUI_Back->SetTexture("Boss1_HPBar.png", true);
		GageUI_Back->SetRelativeLocation(BossHPLocation);
	}



	{
		std::shared_ptr<UBoss1HpBar> BossHpBar = CreateWidget<UBoss1HpBar>(-1);
	}


}

void ASerenHUD::Tick(float _DeltaTime)
{
	AHUD::Tick(_DeltaTime);


	

}
