#include "PreCompile.h"
#include "LeafTornado.h"

#include <EnginePlatform/EngineInput.h>

#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>

#include "MapleInstance.h"
#include "MapleEnum.h"

ALeafTornado::ALeafTornado()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	LeafTornadoFront = CreateDefaultSubObject<USpriteRenderer>();
	LeafTornadoBack = CreateDefaultSubObject<USpriteRenderer>();
	
	LeafTornadoFront->SetupAttachment(RootComponent);
	LeafTornadoBack->SetupAttachment(RootComponent);
	
	LeafTornadoFront->CreateAnimation("LeafTornadoDown", "LeafTornadoDown", 0, 11, 0.06f, false);
	LeafTornadoFront->CreateAnimation("None", "WrathOfEnril", 14, 14, 0.01f, false);

	LeafTornadoBack->CreateAnimation("LeafTornadoUp", "LeafTornadoUp", 0, 11, 0.06f, false);
	LeafTornadoBack->CreateAnimation("None", "WrathOfEnril", 14, 14, 0.01f, false);

	LeafTornadoFront->ChangeAnimation("None");
	LeafTornadoBack->ChangeAnimation("None");

	LeafTornadoFront->SetRelativeLocation(FVector{ 25.0f, -400.0f, static_cast<float>(EMapleZEnum::Player_Skill_Front) });
	LeafTornadoBack->SetRelativeLocation(FVector{ 0.0f, -440.0f, static_cast<float>(EMapleZEnum::Player_Skill_Back)  });


	Collision = CreateDefaultSubObject<UCollision>();
	Collision->SetupAttachment(RootComponent);
	Collision->SetCollisionProfileName("PlayerSKill");

	Collision->SetScale3D({ 560.0f, 240.0f });
	Collision->SetRelativeLocation(FVector{ 0.0f, -120.0f, static_cast<float>(EMapleZEnum::Player) });
	Collision->SetCollisionEnter([](UCollision* _This, UCollision* _Other)
		{
		});

}

ALeafTornado::~ALeafTornado()
{

}

void ALeafTornado::BeginPlay()
{
	ASkillManager::BeginPlay();

	//Player = dynamic_cast<APlayer*>(GetWorld()->GetMainPawn());

	//Collision->SetCollisionStay([this](UCollision* _This, UCollision* _Other)
	//	{
	//		if (this->bIsCanUse == false)
	//		{
	//			return;
	//		}

	//		if (_Other->GetCollisionProfileName() == "MONSTER")
	//		{
	//			if (true == Player->GetbIsDirLeft())
	//			{
	//				float DiffLocationX = _Other->GetWorldLocation().X - Player->GetActorLocation().X;
	//				LegendarySpearHit->ChangeAnimation("LegendarySpearHit");
	//				LegendarySpearHit->SetRelativeLocation(FVector{ DiffLocationX,  -80.0f,  static_cast<float>(EMapleZEnum::Player_Skill_Front) + 20.0f });
	//				bIsHit = true;
	//				GetGameInstance<MapleInstance>()->SerenStatus1.TakeDamage(LegendarySpearAtt);
	//				//static_cast<USerenCollision*>(_Other)->Damage(LegendarySpearAtt);
	//				this->bIsCanUse = true;
	//			}
	//			else if (false == Player->GetbIsDirLeft())
	//			{
	//				float DiffLocationX = _Other->GetWorldLocation().X - Player->GetActorLocation().X;
	//				LegendarySpearHit->ChangeAnimation("LegendarySpearHit");
	//				LegendarySpearHit->SetRelativeLocation(FVector{ -DiffLocationX, -80.0f,  static_cast<float>(EMapleZEnum::Player_Skill_Front) + 20.0f });
	//				bIsHit = true;
	//				GetGameInstance<MapleInstance>()->SerenStatus1.TakeDamage(LegendarySpearAtt);
	//				//static_cast<USerenCollision*>(_Other)->Damage(LegendarySpearAtt);
	//				this->bIsCanUse = true;
	//			}
	//		}

	//		this->bIsCanUse = false;
	//	});

}

void ALeafTornado::Tick(float _DeltaTime)
{
	ASkillManager::Tick(_DeltaTime);

	if (true == LeafTornadoFront->IsCurAnimationEnd())
	{
		LeafTornadoFront->ChangeAnimation("None");
		LeafTornadoBack->ChangeAnimation("None");
		Collision->SetActive(false);
		LeafTornadoFront->SetActive(false);
		LeafTornadoBack->SetActive(false);
	}

	if (UEngineInput::IsPress('D'))
	{
		LeafTornadoFront->ChangeAnimation("LeafTornadoDown");
		LeafTornadoBack->ChangeAnimation("LeafTornadoUp");
		Collision->SetActive(true);
		LeafTornadoFront->SetActive(true);
		LeafTornadoBack->SetActive(true);
	}
}
