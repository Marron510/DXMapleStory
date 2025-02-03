#include "PreCompile.h"
#include "RollingMoonSult.h"

#include <EnginePlatform/EngineInput.h>

#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>

#include "MapleInstance.h"
#include "MapleEnum.h"
#include "SerenCollision.h"
#include "Player.h"


float ARollingMoonSult::RollingMoonSultCoolTime = 0.0f;

ARollingMoonSult::ARollingMoonSult()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	RollingMoonSult = CreateDefaultSubObject<USpriteRenderer>();
	RollingMoonSult->SetupAttachment(RootComponent);

	RollingMoonSultHit = CreateDefaultSubObject<USpriteRenderer>();
	RollingMoonSultHit->SetupAttachment(RootComponent);


	RollingMoonSult->CreateAnimation("RollingMoonSult", "RollingMoonSult", 0, 8, 0.07f, false);
	RollingMoonSult->CreateAnimation("None", "WrathOfEnril", 14, 14, 0.01f, false);
	RollingMoonSult->ChangeAnimation("None");

	RollingMoonSult->SetRelativeLocation(FVector{ 0.0f, -100.0f, static_cast<float>(EMapleZEnum::Player_Skill_Front)});

	RollingMoonSultHit->CreateAnimation("RollingMoonSultHit", "RollingMoonSultHit", 0, 5, 0.1f, false);
	RollingMoonSultHit->CreateAnimation("None", "WrathOfEnril", 14, 14, 0.01f, false);
	RollingMoonSultHit->ChangeAnimation("None");

	RollingMoonSultHit->SetRelativeLocation(FVector{ 0.0f, 0.0f, 0.0f });


	Collision = CreateDefaultSubObject<UCollision>();
	Collision->SetupAttachment(RootComponent);
	Collision->SetCollisionProfileName("PlayerSKill");

	Collision->SetScale3D({ 230.0f, 260.0f });
	Collision->SetRelativeLocation(FVector{ 0.0f, 36.0f , static_cast<float>(EMapleZEnum::Player) });

}

ARollingMoonSult::~ARollingMoonSult()
{

}

void ARollingMoonSult::BeginPlay()
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
					RollingMoonSultHit->ChangeAnimation("RollingMoonSultHit");
					RollingMoonSultHit->SetRelativeLocation(FVector{ DiffLocation, 0.0f,  static_cast<float>(EMapleZEnum::Player_Skill_Front) + 20.0f });
					bIsHit = true;
					static_cast<USerenCollision*>(_Other)->Damage(RollingMoonSultAtt);
					this->bIsCanUse = true;
				}
				else if (false == Player->GetbIsDirLeft())
				{
					float DiffLocation = _Other->GetWorldLocation().X - Player->GetActorLocation().X;
					RollingMoonSultHit->ChangeAnimation("RollingMoonSultHit");
					RollingMoonSultHit->SetRelativeLocation(FVector{ -DiffLocation, 0.0f,  static_cast<float>(EMapleZEnum::Player_Skill_Front) + 20.0f });
					bIsHit = true;
					static_cast<USerenCollision*>(_Other)->Damage(RollingMoonSultAtt);
					this->bIsCanUse = true;
				}
			}

			this->bIsCanUse = false;
		});

}

void ARollingMoonSult::Tick(float _DeltaTime)
{
	ASkillManager::Tick(_DeltaTime);

	RollingMoonSultCoolTime -= _DeltaTime;

	if (true == bIsHit && true == RollingMoonSultHit->IsCurAnimationEnd())
	{
		RollingMoonSultHit->ChangeAnimation("None");
		bIsHit = false;
	}

	if (true == RollingMoonSult->IsCurAnimationEnd())
	{
		RollingMoonSult->ChangeAnimation("None");
		Collision->SetActive(false);
		RollingMoonSult->SetActive(false);
		bIsCanUse = true;
	}

	if (0.0f >= RollingMoonSultCoolTime && UEngineInput::IsPress('E'))
	{
		RollingMoonSult->ChangeAnimation("RollingMoonSult");
		RollingMoonSult->SetActive(true);
		Collision->SetActive(true);
		RollingMoonSultCoolTime = 5.0f;
	}
}
