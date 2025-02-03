#include "PreCompile.h"
#include "StrikeDualShot_Ball.h"


#include <EnginePlatform/EngineInput.h>

#include <EngineCore/TimeEventComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>

#include "MapleEnum.h"
#include "SerenCollision.h"
#include "Player.h"

AStrikeDualShot_Ball::AStrikeDualShot_Ball()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	StrikeDualShot_Ball = CreateDefaultSubObject<USpriteRenderer>();
	StrikeDualShot_Ball->SetupAttachment(RootComponent);

	StrikeDualShot_Ball->CreateAnimation("StrikeDualShot_Ball", "StrikeDualShotBall", 0, 1, 0.04f);
	StrikeDualShot_Ball->CreateAnimation("StrikeDualShotHit", "StrikeDualShotHit", 0, 10, 0.08f);

	StrikeDualShot_Ball->CreateAnimation("None", "WrathOfEnril", 14, 14, 0.01f, false);

	StrikeDualShot_Ball->ChangeAnimation("None");


	Collision = CreateDefaultSubObject<UCollision>();
	Collision->SetupAttachment(RootComponent);
	Collision->SetCollisionProfileName("PlayerSKill");

	Collision->SetScale3D({ 4.0f, 4.0f });

	Collision->SetCollisionEnter([this](UCollision* _This, UCollision* _Other)
		{
			if (_Other->GetCollisionProfileName() == "MONSTER")
			{
				static_cast<USerenCollision*>(_Other)->Damage(StrikeDualShotAtt);
				StrikeDualShot_Ball->ChangeAnimation("StrikeDualShotHit");

				if (true == Player->GetbIsDirLeft())
				{
					StrikeDualShot_Ball->SetWorldLocation(_Other->GetWorldLocation() + FVector::DOWN * 120.0f + FVector::RIGHT * 100.0f);
				}
				else if (false == Player->GetbIsDirLeft())
				{
					StrikeDualShot_Ball->SetWorldLocation(_Other->GetWorldLocation() + FVector::UP * 80.0f + FVector::LEFT * 100.0f);
				}

				bIsHit = true;
			}

		});
}

AStrikeDualShot_Ball::~AStrikeDualShot_Ball()
{

}

void AStrikeDualShot_Ball::BeginPlay()
{
	ASkillManager::BeginPlay();
	Player = dynamic_cast<APlayer*>(GetWorld()->GetMainPawn());
	FVector SpawnLocation = Player->GetActorLocation();

	if (true == Player->GetbIsDirLeft())
	{
		SetActorRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
		StrikeDualShot_Ball->SetRelativeLocation(FVector{ -50.0f, 30.0f , static_cast<float>(EMapleZEnum::Player_Skill_Front) } + SpawnLocation);
		Collision->SetRelativeLocation(FVector{ -100.0f, 46.0f , static_cast<float>(EMapleZEnum::Player_Skill_Front) } + SpawnLocation);
		StrikeDualShot_Ball->ChangeAnimation("StrikeDualShot_Ball");
		BallSpawnLocation = StrikeDualShot_Ball->GetWorldLocation();
		LeftShot = true;
		DirCheck = true;
	}
	else if (false == Player->GetbIsDirLeft())
	{
		StrikeDualShot_Ball->SetRotation(FVector{ 0.0f, 0.0f, 180.0f });
		StrikeDualShot_Ball->SetRelativeLocation(FVector{ 50.0f, 62.0f, 0.0f } + SpawnLocation);
		Collision->SetRelativeLocation(FVector{ 100.0f, 46.0f, 0.0f } + SpawnLocation);
		StrikeDualShot_Ball->ChangeAnimation("StrikeDualShot_Ball");
		BallSpawnLocation = StrikeDualShot_Ball->GetWorldLocation();
		LeftShot = false;
		DirCheck = true;
	}


}

void AStrikeDualShot_Ball::Tick(float _DeltaTime)
{
	ASkillManager::Tick(_DeltaTime);
	if (true == LeftShot && true == DirCheck && false == bIsHit)
	{
		AddActorLocation(FVector::LEFT * _DeltaTime * 600.0f);
	}
	else if (false == LeftShot && true == DirCheck && false == bIsHit)
	{
		AddActorLocation(FVector::RIGHT * _DeltaTime * 600.0f);
	}

	if (true == bIsHit && true == StrikeDualShot_Ball->IsCurAnimationEnd())
	{
		this->Destroy();
	}

	Playerlocation = Player->GetActorLocation().X;

	Curlocation = Collision->GetWorldLocation().X;


	DifferLocation = Playerlocation - Curlocation;

	if (true)
	{

	}

	if (Length <= BallSpawnLocation.X - Curlocation && true == LeftShot)
	{
		this->Destroy();
		return;
	}

	if (Length <= Curlocation - BallSpawnLocation.X && false == LeftShot)
	{
		this->Destroy();
		return;
	}

}
