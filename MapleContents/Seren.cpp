#include "PreCompile.h"
#include "Seren.h"
#include <EnginePlatform/EngineInput.h>

#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>


ASeren::ASeren()
{

	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	SerenRender = CreateDefaultSubObject<USpriteRenderer>();

	SerenRender->SetupAttachment(RootComponent);

	// 정오 스킬 애니메이션 
	{
		SerenRender->CreateAnimation("NoonSerenStand", "NoonSerenStand", 0, 14, 0.09f);
		SerenRender->CreateAnimation("NoonSerenRush", "NoonSerenRush", 0, 35, 0.072f, false);
		SerenRender->CreateAnimation("NoonSerenSting", "NoonSerenSting", 0, 20, 0.07f, false);
		SerenRender->CreateAnimation("NoonSerenStunLaser", "NoonSerenStunLaser", 0, 21, 0.13f, false);
		SerenRender->CreateAnimation("NoonSerenEightLaser", "NoonSerenEightLaser", 0, 27, 0.11f, false);
		SerenRender->CreateAnimation("NoonSerenHit", "NoonSerenHit", 0, 0, 0.09f, false);
		SerenRender->CreateAnimation("NoonSerenDie", "NoonSerenDie", 0, 37, 0.1f, false);
	}
	
	// 세렌 석양 애니메이션
	{
		SerenRender->CreateAnimation("SunSetSerenFirstAttack", "SunSetSerenFirstAttack", 0, 38, 0.06f, false);
		SerenRender->CreateAnimation("SunSetSerenSecondAttack", "SunSetSerenSecondAttack", 0, 36, 0.06f, false);
		SerenRender->CreateAnimation("SunSetSerenThirdAttack", "SunSetSerenThirdAttack", 0, 39, 0.06f, false);
		SerenRender->CreateAnimation("SunSetSerenDie", "SunSetSerenDie", 0, 36, 0.06f, false);
	}

	SerenRender->ChangeAnimation("NoonSerenStand");
}

ASeren::~ASeren()
{

}

void ASeren::BeginPlay()
{
	AActor::BeginPlay();
}

void ASeren::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	
	if (UEngineInput::IsPress('U'))
	{
		SerenRender->ChangeAnimation("SunSetSerenSecondAttack");
	}
}
