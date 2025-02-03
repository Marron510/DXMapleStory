#include "PreCompile.h"
#include "PlayerHpBar.h"

#include "MapleInstance.h"
#include "Boss1HpBar.h"


UBoss1HpBar::UBoss1HpBar()
{
	SetSprite("Phase1_HPBar");
	SetSpritePivot(FVector(0.0f, 0.5f));
	FVector WindowSize = GEngine->GetMainWindow().GetWindowSize();
	FVector WidgetSize = GetWorldScale3D();
	SetWorldLocation(FVector( -332.0f,+ WidgetSize.hY() + 376.0f));
}

UBoss1HpBar::~UBoss1HpBar()
{

}

void UBoss1HpBar::Tick(float _DeltaTime)
{
	UImageWidget::Tick(_DeltaTime);

	if (GetGameInstance<MapleInstance>()->SerenStatus1.bIsHpChange)
	{
		CurTime += _DeltaTime;
		StartPercent = GetGameInstance<MapleInstance>()->SerenStatus1.PrevHpPercent;
		TargetPercent = GetGameInstance<MapleInstance>()->SerenStatus1.CurHpPercent;
		BarLerp(StartPercent, TargetPercent, CurTime, GetGameInstance<MapleInstance>()->SerenStatus1.bIsHpChange);
	}
}


