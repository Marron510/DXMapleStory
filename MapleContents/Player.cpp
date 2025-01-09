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
	Collision = CreateDefaultSubObject<UCollision>();
	Collision->SetupAttachment(RootComponent);
	Collision->SetCollisionProfileName("Player");

	Collision->SetScale3D({ 46.0f, 60.0f });
	Collision->SetRelativeLocation(FVector{ 0.0f, 30.0f, static_cast<float>(EMapleZEnum::Player) });
	Collision->SetCollisionEnter([](UCollision* _This, UCollision* _Other)
		{
			_Other->GetActor()->Destroy();
			UEngineDebug::OutPutString("Destroy");
		});
	
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
	PlayerRenderer->CreateAnimation("HighKick", "HighKick", 0, 0, 0.6f, false);


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
	/*PlayerGroundCheck(GravityForce * _DeltaTime);
	Gravity(_DeltaTime);*/
	FSM.Update(_DeltaTime);

}

void APlayer::SetColImage(std::string_view _ColImageName)
{
	UEngineDirectory Dir;
	if (false == Dir.MoveParentToDirectory("MapleResources"))
	{
		MSGASSERT("리소스 폴더를 찾지 못했습니다.");
		return;
	}
	Dir.Append("Image");

	std::string_view ColName = _ColImageName;
	UEngineFile ImageFiles = Dir.GetFile(ColName);

	ColImage.Load(nullptr, ImageFiles.GetPathToString());

}

void APlayer::Gravity(float _DeltaTime)
{
	if (false == bIsGround)
	{
		AddActorLocation(GravityForce * _DeltaTime);
		GravityForce += FVector::DOWN * 1600.0f *_DeltaTime;
	}
	else
	{
		GravityForce = FVector::ZERO;
	}

}


void APlayer::PlayerGroundCheck(FVector _MovePos)
{
	bIsGround = false;

	FVector NextPos = GetActorLocation() - _MovePos;

	NextPos.X = floorf(NextPos.X);
	NextPos.Y = floorf(-NextPos.Y);

	UColor Color = ColImage.GetColor(NextPos, UColor(255, 255, 255, 0));

	int a = 0;

	if (Color == UColor(255, 255, 255, 0 ))
	{
		bIsGround = false;
	}

	else if (Color == UColor(0, 0, 0, 0) || Color == UColor(255, 0, 0, 0))
	{
		bIsGround = true;
	}
}


