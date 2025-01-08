#include "PreCompile.h"
#include "Player.h"

#include <EnginePlatform/EngineInput.h>

#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/TimeEventComponent.h>

#include "MapleEnum.h"

APlayer::APlayer()
{
	
	
	
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;
	
	// 타임이벤터
	TimeEventComponent = CreateDefaultSubObject<UTimeEventComponent>();
	
	// 플레이어
	PlayerRenderer = CreateDefaultSubObject<USpriteRenderer>();

	PlayerRenderer->SetupAttachment(RootComponent);

	
	//상태
	PlayerRenderer->CreateAnimation("Idle", "Idle.png", 0, 3, 0.7f);
	PlayerRenderer->CreateAnimation("Walk", "Walk.png", 0, 3, 0.08f);
	PlayerRenderer->CreateAnimation("Prone", "Prone.png", 0, 0, 0.046f, false);
	PlayerRenderer->CreateAnimation("ProneAttack", "Prone.png", 0, 1, 0.1f, false);
	PlayerRenderer->CreateAnimation("Jump", "Jump.png", 0, 0, 0.1f);

	// 스킬
	PlayerRenderer->CreateAnimation("Tornado", "LeafTornado.png", 0, 8, 0.08f, false);
	PlayerRenderer->CreateAnimation("Rolling", "Rolling.png", 0, 8, 0.1f);
	PlayerRenderer->CreateAnimation("StrikeDualShot", "StrikeDualShot.png", 0, 6, 0.08f);
	PlayerRenderer->CreateAnimation("Charge", "Charge.png", 0, 8, 0.08f);
	PlayerRenderer->CreateAnimation("Wrath", "Wrath.png", 0, 4, 0.17f, false);
	PlayerRenderer->CreateAnimation("Unicorn", "Unicorn.png", 0, 4, 0.14f, false);
	PlayerRenderer->CreateAnimation("LegendarySpear", "LegendarySpear.png", 0, 11, 0.046f, false);
	PlayerRenderer->CreateAnimation("ProneAttack", "Prone.png", 0, 1, 0.1f, false);




	PlayerRenderer->ChangeAnimation("Idle");
	
	PlayerRenderer->SetRelativeLocation(FVector{ 0.0f, 0.0f, static_cast<float>(EMapleZEnum::Player) });
}

APlayer::~APlayer()
{
}



void APlayer::BeginPlay()
{
	APawn::BeginPlay();

	StateInit();

	FSM.ChangeState(ECharacterState::Idle);

}


void APlayer::Tick(float _DeltaTime)
{
	APawn::Tick(_DeltaTime);
	
	FSM.Update(_DeltaTime);
}

