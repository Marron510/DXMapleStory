#include "PreCompile.h"
#include "PlayerCurMPFont.h"
#include "MapleInstance.h"


UPlayerCurMPFont::UPlayerCurMPFont()
{
	SetFont("메이플스토리 Bold");
}

UPlayerCurMPFont::~UPlayerCurMPFont()
{

}


void UPlayerCurMPFont::Tick(float _DeltaTime)
{
	UMapleFont::Tick(_DeltaTime);
	FCurMp = GetGameInstance<MapleInstance>()->Status.CurMp;
	ICurMp = static_cast<int>(FCurMp);
	CurMPstr = std::to_string(ICurMp);
	SetText("/ " + CurMPstr);
}

void UPlayerCurMPFont::Render(UEngineCamera* Camera, float _DeltaTime)
{
	UMapleFont::Render(Camera, _DeltaTime);
}
