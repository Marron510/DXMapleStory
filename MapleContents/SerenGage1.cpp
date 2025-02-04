#include "PreCompile.h"
#include "SerenGage1.h"
#include "MapleInstance.h"

#include <EngineBase/EngineMath.h>

USerenGage1::USerenGage1()
{
	SetSprite("Phase1_Gage");
	SetSpritePivot(FVector{ 0.5f, 1.0f });
}

USerenGage1::~USerenGage1()
{

}

void USerenGage1::Tick(float _DeltaTime)
{
	UBar::Tick(_DeltaTime);

	if (GetGameInstance<MapleInstance>()->SerenStatus1.bIsGageChange)
	{
		CurTime += _DeltaTime;
		
		StartPercent = GetGameInstance<MapleInstance>()->SerenStatus1.PrevGagePercent;
		TargetPercent = GetGameInstance<MapleInstance>()->SerenStatus1.CurGagePercent;
		BarLerp(StartPercent, TargetPercent, CurTime, GetGameInstance<MapleInstance>()->SerenStatus1.bIsGageChange);
	}
}

void USerenGage1::Render(UEngineCamera* Camera, float _DeltaTime)
{
	UBar::Render(Camera, _DeltaTime);
}

void USerenGage1::BarLerp(float _StartPercent, float _EndPercent, float _f, bool& _bIsChange)
{
	bool& bIsChange = _bIsChange;
	float LerpGagePercent = UEngineMath::Lerp(StartPercent, TargetPercent, UEngineMath::Clamp(_f * 3.0f, 0.0f, 1.0f));
	
	
	/*float4 value = FVector{0.0f, LerpGagePercent, 0.0f, 0.0f};
	SetUVvalue(static_cast<FUVValue>(value));
	if (LerpGagePercent == TargetPercent) {
		bIsChange = false;
		CurTime = 0.0f;
	}*/
}
