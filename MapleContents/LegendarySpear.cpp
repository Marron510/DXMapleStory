#include "PreCompile.h"
#include "LegendarySpear.h"

#include <EnginePlatform/EngineInput.h>

#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>

#include "MapleInstance.h"
#include "MapleEnum.h"
#include "SerenCollision.h"
#include "Player.h"

float ALegendarySpear::LegendarySpearCoolTime = 0.0f;

ALegendarySpear::ALegendarySpear()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	LegendarySpearFront = CreateDefaultSubObject<USpriteRenderer>();
	LegendarySpearMid = CreateDefaultSubObject<USpriteRenderer>();
	LegendarySpearHit = CreateDefaultSubObject<USpriteRenderer>();

	LegendarySpearFront->SetupAttachment(RootComponent);
	LegendarySpearMid->SetupAttachment(RootComponent);
	LegendarySpearHit->SetupAttachment(RootComponent);

	LegendarySpearFront->CreateAnimation("LegendarySpearFront", "LegendarySpearFront", 0, 23, 0.052f, false);
	LegendarySpearFront->CreateAnimation("None", "WrathOfEnril", 14, 14, 0.01f, false);

	LegendarySpearMid->CreateAnimation("LegendarySpearMid", "LegendarySpearMid", 0, 19, 0.042f, false);
	LegendarySpearMid->CreateAnimation("None", "WrathOfEnril", 14, 14, 0.01f, false);

	LegendarySpearHit->CreateAnimation("LegendarySpearHit", "LegendarySpearHit", 0, 10, 0.1f, false);
	LegendarySpearHit->CreateAnimation("None", "WrathOfEnril", 14, 14, 0.01f, false);

	LegendarySpearFront->ChangeAnimation("None");
	LegendarySpearMid->ChangeAnimation("None");
	LegendarySpearHit->ChangeAnimation("None");

	LegendarySpearFront->SetRelativeLocation(FVector{ -500.0f, -260.0f, static_cast<float>(EMapleZEnum::Player_Skill_Front) });
	LegendarySpearMid->SetRelativeLocation(FVector{ 0.0f, -250.0f, static_cast<float>(EMapleZEnum::Player_Skill_Front) - 20.0f });
	LegendarySpearHit->SetRelativeLocation(FVector{ 0.0f, 0.0f, 0.0f });




	
	Collision = CreateDefaultSubObject<UCollision>();
	Collision->SetupAttachment(RootComponent);
	Collision->SetCollisionProfileName("PlayerSKill");

	Collision->SetScale3D({ 800.0f, 500.0f });
	Collision->SetRelativeLocation(FVector{ -460.0f, 50.0f, static_cast<float>(EMapleZEnum::Player) });
}

ALegendarySpear::~ALegendarySpear()
{
	
}

void ALegendarySpear::BeginPlay()
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
					float DiffLocationX = _Other->GetWorldLocation().X - Player->GetActorLocation().X;
					LegendarySpearHit->ChangeAnimation("LegendarySpearHit");
					LegendarySpearHit->SetRelativeLocation(FVector{ DiffLocationX,  -80.0f,  static_cast<float>(EMapleZEnum::Player_Skill_Front) + 20.0f });
					bIsHit = true;
					static_cast<USerenCollision*>(_Other)->Damage(LegendarySpearAtt);
					this->bIsCanUse = true;
				}
				else if (false == Player->GetbIsDirLeft())
				{
					float DiffLocationX = _Other->GetWorldLocation().X - Player->GetActorLocation().X;
					LegendarySpearHit->ChangeAnimation("LegendarySpearHit");
					LegendarySpearHit->SetRelativeLocation(FVector{ -DiffLocationX, -80.0f,  static_cast<float>(EMapleZEnum::Player_Skill_Front) + 20.0f });
					bIsHit = true;
					static_cast<USerenCollision*>(_Other)->Damage(LegendarySpearAtt);
					this->bIsCanUse = true;
				}
			}

			this->bIsCanUse = false;
		});
}

void ALegendarySpear::Tick(float _DeltaTime)
{
	ASkillManager::Tick(_DeltaTime);

	LegendarySpearCoolTime -= _DeltaTime;

	if (true == bIsHit && true == LegendarySpearHit->IsCurAnimationEnd())
	{
		LegendarySpearHit->ChangeAnimation("None");
		bIsHit = false;
	}

	if (true == LegendarySpearFront->IsCurAnimationEnd())
	{
		LegendarySpearFront->ChangeAnimation("None");
		LegendarySpearMid->ChangeAnimation("None");
		Collision->SetActive(false);
		LegendarySpearFront->SetActive(false);
		LegendarySpearMid->SetActive(false);
		bIsCanUse = true;
	}

	if (0.0f >= LegendarySpearCoolTime && UEngineInput::IsPress('G'))
	{
		LegendarySpearFront->ChangeAnimation("LegendarySpearFront");
		LegendarySpearMid->ChangeAnimation("LegendarySpearMid");
		Collision->SetActive(true);
		LegendarySpearFront->SetActive(true);
		LegendarySpearMid->SetActive(true);
		LegendarySpearCoolTime = 5.0f;
	}
}
