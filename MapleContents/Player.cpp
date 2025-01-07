#include "PreCompile.h"
#include "Player.h"

#include <EnginePlatform/EngineInput.h>

#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/TimeEventComponent.h>


APlayer::APlayer()
{
	
	
	
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;
	
	// 타임이벤터
	TimeEventComponent = CreateDefaultSubObject<UTimeEventComponent>();
	
	// 플레이어, 스킬 렌더러
	SkillRenderer = CreateDefaultSubObject<USpriteRenderer>(); // 플레이어 뒤
	PlayerRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SubSkillRenderer = CreateDefaultSubObject<USpriteRenderer>(); // 플레이어 앞

	SkillRenderer->SetupAttachment(RootComponent);
	PlayerRenderer->SetupAttachment(RootComponent);
	SubSkillRenderer->SetupAttachment(RootComponent);

	
	// 리프
	SubSkillRenderer->CreateAnimation("LeafTornadoDown", "LeafTornadoDown", 0, 11, 0.05f, false);
	SkillRenderer->CreateAnimation("LeafTornadoUp", "LeafTornadoUp", 0, 11, 0.072f, false);
	// 롤링
	SubSkillRenderer->CreateAnimation("RollingMoonSult", "RollingMoonSult", 0, 8, 0.1f, false);
	// 스듀
	SubSkillRenderer->CreateAnimation("StrikeDualShot", "StrikeDualShot", 0, 10, 0.05f, false);
	SkillRenderer->CreateAnimation("StrikeDualShot_Back", "StrikeDualShot_Back", 0, 6, 0.077f, false);
	// None
	SkillRenderer->CreateAnimation("None", "WrathOfEnril", 14, 14, 0.2f, false);
	SubSkillRenderer->CreateAnimation("None", "WrathOfEnril", 14, 14, 0.2f, false);
	
	//상태
	PlayerRenderer->CreateAnimation("Idle", "Idle.png", 0, 3, 0.7f);
	PlayerRenderer->CreateAnimation("Walk", "Walk.png", 0, 3, 0.08f);
	PlayerRenderer->CreateAnimation("Prone", "Prone.png", 0, 0, 0.046f, false);
	PlayerRenderer->CreateAnimation("ProneAttack", "Prone.png", 0, 1, 0.1f, false);
	PlayerRenderer->CreateAnimation("Jump", "Jump.png", 0, 0, 0.1f);

	// 스킬
	PlayerRenderer->CreateAnimation("Tornado", "LeafTornado.png", 0, 8, 0.09f, false);
	PlayerRenderer->CreateAnimation("Rolling", "Rolling.png", 0, 8, 0.1f);
	PlayerRenderer->CreateAnimation("StrikeDualShot", "StrikeDualShot.png", 0, 6, 0.08f);
	PlayerRenderer->CreateAnimation("Charge", "Charge.png", 0, 8, 0.1f);
	PlayerRenderer->CreateAnimation("Wrath", "Wrath.png", 0, 4, 0.17f, false);
	PlayerRenderer->CreateAnimation("Unicorn", "Unicorn.png", 0, 4, 0.14f, false);
	PlayerRenderer->CreateAnimation("LegendarySpear", "LegendarySpear.png", 0, 11, 0.046f, false);
	PlayerRenderer->CreateAnimation("ProneAttack", "Prone.png", 0, 1, 0.1f, false);




	PlayerRenderer->ChangeAnimation("Idle");
	

	SkillRenderer->ChangeAnimation("None");
	SubSkillRenderer->ChangeAnimation("None");

	PlayerRenderer->SetRelativeLocation(FVector{ 0.0f, 0.0f, PlayerZPos });
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
	

	/*if (true == PlayerRenderer->IsCurAnimationEnd())
	{
		SkillRenderer->ChangeAnimation("None");
		PlayerRenderer->ChangeAnimation("Idle");
		SubSkillRenderer->ChangeAnimation("None");
	}*/

	
	if (UEngineInput::IsDown('C'))
	{
		PlayerRenderer->ChangeAnimation("Jump");
	}




	FSM.Update(_DeltaTime);
}

