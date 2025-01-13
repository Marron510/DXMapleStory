#include "PreCompile.h"
#include "LeafTornado.h"

#include <EnginePlatform/EngineInput.h>

#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>


#include "MapleEnum.h"

ALeafTornado::ALeafTornado()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	LeafTornadoFront = CreateDefaultSubObject<USpriteRenderer>();
	LeafTornadoBack = CreateDefaultSubObject<USpriteRenderer>();
	
	LeafTornadoFront->SetupAttachment(RootComponent);
	LeafTornadoBack->SetupAttachment(RootComponent);
	
	LeafTornadoFront->CreateAnimation("LeafTornadoDown", "LeafTornadoDown", 0, 11, 0.072f, false);
	LeafTornadoFront->CreateAnimation("None", "WrathOfEnril", 14, 14, 0.01f, false);

	LeafTornadoBack->CreateAnimation("LeafTornadoUp", "LeafTornadoUp", 0, 11, 0.072f, false);
	LeafTornadoBack->CreateAnimation("None", "WrathOfEnril", 14, 14, 0.01f, false);

	LeafTornadoFront->ChangeAnimation("None");
	LeafTornadoBack->ChangeAnimation("None");

	LeafTornadoFront->SetRelativeLocation(FVector{ 25.0f, -400.0f, static_cast<float>(EMapleZEnum::Player_Skill_Front) });
	LeafTornadoBack->SetRelativeLocation(FVector{ 0.0f, -440.0f, static_cast<float>(EMapleZEnum::Player_Skill_Back)  });


	Collision = CreateDefaultSubObject<UCollision>();
	Collision->SetupAttachment(RootComponent);
	Collision->SetCollisionProfileName("Player");

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
