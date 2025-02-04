#include "PreCompile.h"
#include "BindUI.h"
#include <EngineBase/FSMStateManager.h>

#include "MapleInstance.h"
#include "Player.h"

UBindUI::UBindUI()
{
	CreateAnimation("BindEffect", "BindEffect", 0, 16, 0.10f);
	CreateAnimation("None", "WrathOfEnril", 14, 14, 0.01f, false);
	SetAnimationPivot("BindEffect", FVector(0.5f, 1.0f));
	ChangeAnimation("None");
	SetRelativeLocation(FVector(0.0f, 400.0f));
	Player = dynamic_cast<APlayer*>(GetWorld()->GetMainPawn());
}

UBindUI::~UBindUI()
{

}

void UBindUI::Tick(float _DeltaTime)
{
	UImageWidget::Tick(_DeltaTime);
	
	
	if (Player->GetFSM().GetCurrentStateKey() == static_cast<int>(ECharacterState::MapBind))
	{
		ChangeAnimation("BindEffect");
		bIsActive = true;
	}

	if (true == IsCurAnimationEnd() && true == bIsActive)
	{
		SetActive(false);
		ChangeAnimation("None");
		bIsActive = false;
	}
	
	CurGage = GetGameInstance<MapleInstance>()->SerenStatus1.CurGage;
}

void UBindUI::Render(UEngineCamera* Camera, float _DeltaTime)
{
	UImageWidget::Render(Camera, _DeltaTime);
	
}
