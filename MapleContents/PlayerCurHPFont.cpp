#include "PreCompile.h"
#include "PlayerCurHPFont.h"
#include "MapleInstance.h"

UPlayerCurHPFont::UPlayerCurHPFont()
{
	SetFont("메이플스토리 Bold");
}

UPlayerCurHPFont::~UPlayerCurHPFont()
{

}

void UPlayerCurHPFont::Tick(float _DeltaTime)
{
	UMapleFont::Tick(_DeltaTime);
	
	FCurHp = GetGameInstance<MapleInstance>()->Status.CurHp;
	ICurHp = static_cast<int>(FCurHp);
	CurHPstr = std::to_string(ICurHp);
	SetText("/ " + CurHPstr);

}

void UPlayerCurHPFont::Render(UEngineCamera* Camera, float _DeltaTime)
{
	UMapleFont::Render(Camera, _DeltaTime);
}
