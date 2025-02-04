#include "PreCompile.h"
#include "SerenGage1.h"
#include "MapleInstance.h"

#include <EngineBase/FSMStateManager.h>
#include <EngineBase/EngineMath.h>

#include "Player.h"

USerenGage1::USerenGage1()
{
	SetSprite("Phase1_Gage");
	SetSpritePivot(FVector{ 0.5f, 1.0f });
	Player = dynamic_cast<APlayer*>(GetWorld()->GetMainPawn());
}

USerenGage1::~USerenGage1()
{

}

void USerenGage1::Tick(float _DeltaTime)
{
	UBar::Tick(_DeltaTime);

	GageLogic(_DeltaTime);
}

void USerenGage1::Render(UEngineCamera* Camera, float _DeltaTime)
{
	UBar::Render(Camera, _DeltaTime);
}

void USerenGage1::BarLerp(float _StartPercent, float _EndPercent, float _f, bool& _bIsChange)
{
	bool& bIsChange = _bIsChange;
	float LerpGagePercent = UEngineMath::Lerp(StartPercent, TargetPercent, UEngineMath::Clamp(_f * 3.0f, 0.0f, 1.0f));
	
	ColorData.Ignore.Y = 1.0f - LerpGagePercent;

	if (LerpGagePercent == TargetPercent) {
		bIsChange = false;
		CurTime = 0.0f;
	}
}


void USerenGage1::GageLogic(float _DeltaTime)
{
	if (GetGameInstance<MapleInstance>()->SerenStatus1.bIsGageChange)
	{
		CurTime += _DeltaTime;

		StartPercent = GetGameInstance<MapleInstance>()->SerenStatus1.PrevGagePercent;
		TargetPercent = GetGameInstance<MapleInstance>()->SerenStatus1.CurGagePercent;

		if (1.0f > TargetPercent)
		{
			BarLerp(StartPercent, TargetPercent, CurTime, GetGameInstance<MapleInstance>()->SerenStatus1.bIsGageChange);
		}
		else if (1.0f <= TargetPercent && false == bIsGageOn)
		{
			Player->GetFSM().ChangeState(ECharacterState::MapBind);
			bIsGageOn = true;
		}
	}

	if (true == bIsGageOn)
	{
		BindTime -= _DeltaTime;
	}

	if (0.0f >= BindTime && true == bIsGageOn)
	{
		GetGameInstance<MapleInstance>()->SerenStatus1.PrevGagePercent = 0.0f;
		GetGameInstance<MapleInstance>()->SerenStatus1.CurGagePercent = 0.0f;
		GetGameInstance<MapleInstance>()->SerenStatus1.PrevGage = 0.0f;
		GetGameInstance<MapleInstance>()->SerenStatus1.CurGage = 0.0f;
		bIsGageOn = false;
		BindTime = 5.0f;
	}
}