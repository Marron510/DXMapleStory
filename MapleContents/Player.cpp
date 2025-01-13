#include "PreCompile.h"
#include "Player.h"

#include <EnginePlatform/EngineInput.h>
#include <EnginePlatform/EngineWinImage.h>>

#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/TimeEventComponent.h>
#include <EngineCore/Collision.h>
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
	PlayerRenderer->SetRelativeLocation(FVector{ 0.0f, 0.0f, static_cast<float>(EMapleZEnum::Player) });
	PlayerRenderer->BillboardOn();
	

	// 콜리전
	MoveCollision = CreateDefaultSubObject<UCollision>();
	MoveCollision->SetupAttachment(RootComponent);
	MoveCollision->SetCollisionProfileName("MoveDot");

	MoveCollision->SetScale3D({ 20.0f, 5.0f });
	MoveCollision->SetRelativeLocation(FVector{ 4.0f, 5.0f, static_cast<float>(EMapleZEnum::Player) });
	MoveCollision->SetCollisionEnter([this](UCollision* _This, UCollision* _Other)
		{
			//GravityForce = FVector::ZERO;
			bIsGround = true;
		});
	MoveCollision->SetCollisionStay([this](UCollision* _This, UCollision* _Other)
		{
			//GravityForce = FVector::ZERO;
		});
	MoveCollision->SetCollisionEnd([this](UCollision* _This, UCollision* _Other)
		{
			bIsGround = false;
		});
	//상태
	PlayerRenderer->CreateAnimation("Idle", "Idle.png", 0, 3, 0.7f);
	PlayerRenderer->CreateAnimation("Walk", "Walk.png", 0, 3, 0.08f);
	PlayerRenderer->CreateAnimation("Prone", "Prone.png", 0, 0, 0.046f);
	PlayerRenderer->CreateAnimation("ProneAttack", "Prone.png", 0, 1, 0.1f);
	PlayerRenderer->CreateAnimation("Jump", "Jump.png", 0, 0, 0.1f);



	// 스킬
	PlayerRenderer->CreateAnimation("Tornado", "LeafTornado.png", 0, 8, 0.096f);
	PlayerRenderer->CreateAnimation("Rolling", "Rolling.png", 0, 8, 0.1f);
	PlayerRenderer->CreateAnimation("StrikeDualShot", "StrikeDualShot.png", 0, 6, 0.08f);
	PlayerRenderer->CreateAnimation("Charge", "Charge.png", 0, 8, 0.08f);
	PlayerRenderer->CreateAnimation("Wrath", "Wrath.png", 0, 4, 0.17f);
	PlayerRenderer->CreateAnimation("Unicorn", "Unicorn.png", 0, 4, 0.14f);
	PlayerRenderer->CreateAnimation("LegendarySpear", "LegendarySpear.png", 0, 11, 0.046f);
	PlayerRenderer->CreateAnimation("ProneAttack", "Prone.png", 0, 1, 0.1f);
	PlayerRenderer->CreateAnimation("HighKick", "HighKick", 0, 0, 0.6f);


	//
	PlayerRenderer->ChangeAnimation("Idle");
	
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


void APlayer::Gravity(float _DeltaTime)
{
	if (false == MoveCollision->IsColliding())
	{
		GravityForce += FVector::DOWN * 3.0f * _DeltaTime;
	}
	else if (true == MoveCollision->IsColliding())
	{
		GravityForce = FVector::ZERO;
	}

	AddActorLocation(GravityForce);
}

//void APlayer::GravityZero()
//{
//	GravityForce += FVector::DOWN * 600.0f;
//	AddActorLocation(GravityForce * _DeltaTime);
//}


