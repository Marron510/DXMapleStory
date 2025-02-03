#include "PreCompile.h"
#include "PlayerMpBar.h"
#include "MapleInstance.h"
#include "PlayerMpBarEffect.h"

UPlayerMpBar::UPlayerMpBar() 
{
	SetSprite("Player_MpBar");
	SetSpritePivot(FVector(0.0f, 0.5f));
	FVector WindowSize = GEngine->GetMainWindow().GetWindowSize();
	FVector WidgetSize = GetWorldScale3D();
	SetWorldLocation(FVector(-77.0f, -WindowSize.hY() + WidgetSize.hY() + 26.0f));
}

UPlayerMpBar::~UPlayerMpBar() 
{

}

void UPlayerMpBar::Tick(float _DeltaTime)
{
	UBar::Tick(_DeltaTime);
	if (GetGameInstance<MapleInstance>()->Status.bIsMpChange)
	{
		CurTime += _DeltaTime;
		if (!bIsPlayEffect)
		{
			PlayerMpBarEffect->SetActive(true);
		}
		StartPercent = GetGameInstance<MapleInstance>()->Status.PrevMpPercent;
		TargetPercent = GetGameInstance<MapleInstance>()->Status.CurMpPercent;
		BarLerp(StartPercent, TargetPercent, CurTime, GetGameInstance<MapleInstance>()->Status.bIsMpChange);
	}
	else 
	{
		PlayerMpBarEffect->SetCurTime(0.0f);
		PlayerMpBarEffect->SetActive(false);
		bIsPlayEffect = false;
	}
}


