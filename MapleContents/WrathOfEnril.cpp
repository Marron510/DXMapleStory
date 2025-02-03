#include "PreCompile.h"
#include "WrathOfEnril.h"

#include <EnginePlatform/EngineInput.h>

#include <EngineCore/TimeEventComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>

#include "MapleEnum.h"
#include "SerenCollision.h"
#include "Player.h"


float AWrathOfEnril::WrathOfEnrilCoolTime = 0.0f;

AWrathOfEnril::AWrathOfEnril()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	WrathOfEnril = CreateDefaultSubObject<USpriteRenderer>();
	WrathOfEnril->SetupAttachment(RootComponent);

	WrathOfEnrilHit = CreateDefaultSubObject<USpriteRenderer>();
	WrathOfEnrilHit->SetupAttachment(RootComponent);

	WrathOfEnril->CreateAnimation("WrathOfEnril", "WrathOfEnril", 0, 13, 0.0614f, false);
	WrathOfEnril->CreateAnimation("None", "WrathOfEnril", 14, 14, 0.01f, false);
	WrathOfEnril->ChangeAnimation("None");

	WrathOfEnrilHit->CreateAnimation("WrathOfEnrilHit", "WrathOfEnrilHit", 0, 7, 0.09f, false);
	WrathOfEnrilHit->CreateAnimation("None", "WrathOfEnril", 14, 14, 0.01f, false);
	WrathOfEnrilHit->ChangeAnimation("None");
	WrathOfEnrilHit->SetRelativeLocation(FVector{ 0.0f, 0.0f, 0.0f });

	Collision = CreateDefaultSubObject<UCollision>();
	Collision->SetupAttachment(RootComponent);
	Collision->SetCollisionProfileName("PlayerSKill");

	Collision->SetScale3D({ 640.0f, 340.0f });
	Collision->SetRelativeLocation(FVector{ -330.0f, 120.0f , static_cast<float>(EMapleZEnum::Player) });
	Collision->SetActive(false);

	WrathOfEnril->SetRelativeLocation(FVector{ -230.0f, -220.0f, static_cast<float>(EMapleZEnum::Player_Skill_Front)});

}

AWrathOfEnril::~AWrathOfEnril()
{

}

void AWrathOfEnril::BeginPlay()
{
	ASkillManager::BeginPlay();
	Player = dynamic_cast<APlayer*>(GetWorld()->GetMainPawn());

	

	Collision->SetCollisionStay([this](UCollision* _This, UCollision* _Other)
		{
			if (this->bIsCanUse == false)
			{
				return;
			}

			if (_Other->GetCollisionProfileName() == "MONSTER")
			{
				if (true == Player->GetbIsDirLeft())
				{
					float DiffLocation = _Other->GetWorldLocation().X - Player->GetActorLocation().X;
					WrathOfEnrilHit->ChangeAnimation("WrathOfEnrilHit");
					WrathOfEnrilHit->SetRelativeLocation(FVector{ DiffLocation, 0.0f,  static_cast<float>(EMapleZEnum::Player_Skill_Front) + 20.0f});
					bIsHit = true;
					static_cast<USerenCollision*>(_Other)->Damage(WrathOfEnrilAtt);
					this->bIsCanUse = true;
				}
				else if (false == Player->GetbIsDirLeft())
				{
					float DiffLocation = _Other->GetWorldLocation().X - Player->GetActorLocation().X;
					WrathOfEnrilHit->ChangeAnimation("WrathOfEnrilHit");
					WrathOfEnrilHit->SetRelativeLocation(FVector{ -DiffLocation, 0.0f,  static_cast<float>(EMapleZEnum::Player_Skill_Front) + 20.0f});
					bIsHit = true;
					static_cast<USerenCollision*>(_Other)->Damage(WrathOfEnrilAtt);
					this->bIsCanUse = true;
				}
			}

			this->bIsCanUse = false;
		});
}

void AWrathOfEnril::Tick(float _DeltaTime)
{
	ASkillManager::Tick(_DeltaTime);

	WrathOfEnrilCoolTime -= _DeltaTime;
	


	if (true == bIsHit && true == WrathOfEnrilHit->IsCurAnimationEnd())
	{
		WrathOfEnrilHit->ChangeAnimation("None");
		bIsHit = false;
	}

	if (true == WrathOfEnril->IsCurAnimationEnd())
	{
		WrathOfEnril->ChangeAnimation("None");
		WrathOfEnril->SetActive(false);
		Collision->SetActive(false);
		bIsCanUse = true;
		
	}

	if (WrathOfEnrilCoolTime <= 0 && UEngineInput::IsPress('A'))
	{
		WrathOfEnril->ChangeAnimation("WrathOfEnril");
		WrathOfEnril->SetActive(true);
		Collision->SetActive(true);
		WrathOfEnrilCoolTime = 5.0f;
	}
}
