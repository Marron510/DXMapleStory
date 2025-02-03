#include "PreCompile.h"
#include "UnicornSpike.h"

#include <EnginePlatform/EngineInput.h>

#include <EngineCore/TimeEventComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>

#include "MapleEnum.h"
#include "SerenCollision.h"
#include "Player.h"


float AUnicornSpike::UnicornSpikeCoolTime = 0.0f;

AUnicornSpike::AUnicornSpike()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	UnicornSpike = CreateDefaultSubObject<USpriteRenderer>();
	UnicornSpike->SetupAttachment(RootComponent);

	UnicornSpikeHit = CreateDefaultSubObject<USpriteRenderer>();
	UnicornSpikeHit->SetupAttachment(RootComponent);

	UnicornSpike->CreateAnimation("UnicornSpike", "UnicornSpike", 0, 15, 0.08f, false);
	UnicornSpike->CreateAnimation("None", "WrathOfEnril", 14, 14, 0.01f, false);
	UnicornSpike->ChangeAnimation("None");

	UnicornSpike->SetRelativeLocation(FVector{ -200.0f, -136.0f, static_cast<float>(EMapleZEnum::Player_Skill_Front) });

	UnicornSpikeHit->CreateAnimation("UnicornSpikeHit", "UnicornSpikeHit", 0, 6, 0.1f, false);
	UnicornSpikeHit->CreateAnimation("None", "WrathOfEnril", 14, 14, 0.01f, false);
	UnicornSpikeHit->ChangeAnimation("None");

	UnicornSpikeHit->SetRelativeLocation(FVector{ 0.0f, 0.0f, 0.0f });



	Collision = CreateDefaultSubObject<UCollision>();
	Collision->SetupAttachment(RootComponent);
	Collision->SetCollisionProfileName("PlayerSKill");

	Collision->SetScale3D({ 700.0f, 220.0f });
	Collision->SetRelativeLocation(FVector{ -280.0f, 80.0f , static_cast<float>(EMapleZEnum::Player) });
	Collision->SetCollisionEnter([](UCollision* _This, UCollision* _Other)
		{
		});

}

AUnicornSpike::~AUnicornSpike()
{

}


void AUnicornSpike::BeginPlay()
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
					UnicornSpikeHit->ChangeAnimation("UnicornSpikeHit");
					UnicornSpikeHit->SetRelativeLocation(FVector{ DiffLocation, 0.0f,  static_cast<float>(EMapleZEnum::Player_Skill_Front) + 20.0f });
					bIsHit = true;
					static_cast<USerenCollision*>(_Other)->Damage(UnicornSpikeAtt);
					this->bIsCanUse = true;
				}
				else if (false == Player->GetbIsDirLeft())
				{
					float DiffLocation = _Other->GetWorldLocation().X - Player->GetActorLocation().X;
					UnicornSpikeHit->ChangeAnimation("UnicornSpikeHit");
					UnicornSpikeHit->SetRelativeLocation(FVector{ -DiffLocation, 0.0f,  static_cast<float>(EMapleZEnum::Player_Skill_Front) + 20.0f });
					bIsHit = true;
					static_cast<USerenCollision*>(_Other)->Damage(UnicornSpikeAtt);
					this->bIsCanUse = true;
				}
			}

			this->bIsCanUse = false;
		});


}

void AUnicornSpike::Tick(float _DeltaTime)
{
	ASkillManager::Tick(_DeltaTime);

	UnicornSpikeCoolTime -= _DeltaTime;

	if (true == bIsHit && true == UnicornSpikeHit->IsCurAnimationEnd())
	{
		UnicornSpikeHit->ChangeAnimation("None");
		bIsHit = false;
	}

	if (true == UnicornSpike->IsCurAnimationEnd())
	{
		UnicornSpike->ChangeAnimation("None");
		Collision->SetActive(false);
		UnicornSpike->SetActive(false);
		bIsCanUse = true;
	}

	if (0.0f >= UnicornSpikeCoolTime &&UEngineInput::IsPress('R'))
	{
		UnicornSpike->ChangeAnimation("UnicornSpike");
		UnicornSpike->SetActive(true);
		Collision->SetActive(true);
		UnicornSpikeCoolTime = 5.0f;
	}
}
