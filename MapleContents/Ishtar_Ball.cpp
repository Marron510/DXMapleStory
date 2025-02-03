#include "PreCompile.h"
#include "Ishtar_Ball.h"


#include <EnginePlatform/EngineInput.h>

#include <EngineCore/TimeEventComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>

#include "MapleEnum.h"
#include "SerenCollision.h"
#include "Player.h"

AIshtar_Ball::AIshtar_Ball()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	Ishtar_Ball = CreateDefaultSubObject<USpriteRenderer>();
	Ishtar_Ball->SetupAttachment(RootComponent);

	Ishtar_Ball->CreateAnimation("Ishtar_Ball", "IshBall", 0, 5, 0.0614f);

		Ishtar_Ball->CreateAnimation("None", "WrathOfEnril", 14, 14, 0.01f, false);	

	Ishtar_Ball->ChangeAnimation("None");
	

	Collision = CreateDefaultSubObject<UCollision>();
	Collision->SetupAttachment(RootComponent);
	Collision->SetCollisionProfileName("PlayerSKill");

	Collision->SetScale3D({ 4.0f, 4.0f });

	/*Collision->SetCollisionEnter([this](UCollision* _This, UCollision* _Other)
		{
			UEngineDebug::OutPutString("enter");
			this->bIsCanUse = true;
		});*/
}

AIshtar_Ball::~AIshtar_Ball()
{

}

void AIshtar_Ball::BeginPlay()
{
	ASkillManager::BeginPlay();
	Player = dynamic_cast<APlayer*>(GetWorld()->GetMainPawn());
	FVector SpawnLocation = Player->GetActorLocation();
	
	if (true == Player->GetbIsDirLeft())
	{
		SetActorRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
		Ishtar_Ball->SetRelativeLocation(FVector{ -50.0f, 30.0f , static_cast<float>(EMapleZEnum::Player_Skill_Front) } + SpawnLocation);
		Collision->SetRelativeLocation(FVector{ -100.0f, 46.0f , static_cast<float>(EMapleZEnum::Player_Skill_Front) } + SpawnLocation);
		Ishtar_Ball->ChangeAnimation("Ishtar_Ball");
		BallSpawnLocation = Ishtar_Ball->GetWorldLocation();
		LeftShot = true;
		DirCheck = true;
	}
	else if(false == Player->GetbIsDirLeft())
	{
		Ishtar_Ball->SetRotation(FVector{0.0f, 0.0f, 180.0f});
		Ishtar_Ball->SetRelativeLocation(FVector{ 50.0f, 62.0f, 0.0f } + SpawnLocation);
		Collision->SetRelativeLocation(FVector{ 100.0f, 46.0f, 0.0f }+ SpawnLocation);
		Ishtar_Ball->ChangeAnimation("Ishtar_Ball");
		BallSpawnLocation = Ishtar_Ball->GetWorldLocation();
		LeftShot = false;
		DirCheck = true;
	} 

	
}

void AIshtar_Ball::Tick(float _DeltaTime)
{
	ASkillManager::Tick(_DeltaTime);
	if (true == LeftShot && true == DirCheck)
	{
		AddActorLocation(FVector::LEFT * _DeltaTime * 600.0f);
	}
	else if (false == LeftShot && true == DirCheck)
	{
		AddActorLocation(FVector::RIGHT * _DeltaTime * 600.0f);
	}

	Playerlocation = Player->GetActorLocation().X;
	
	Curlocation = Collision->GetWorldLocation().X;

	
	DifferLocation = Playerlocation - Curlocation;



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
