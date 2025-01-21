#include "PreCompile.h"
#include "RoyalKnight.h"

#include <EnginePlatform/EngineInput.h>

#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>
#include <EngineCore/TimeEventComponent.h>

#include "MapleEnum.h"

bool ARoyalKnight::bLoyalKnightsOn = false;

ARoyalKnight::ARoyalKnight()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	TimeEventComponent = CreateDefaultSubObject<UTimeEventComponent>();

	RoyalKnight = CreateDefaultSubObject<USpriteRenderer>();
	RoyalKnight->SetupAttachment(RootComponent);

	RoyalKnight->CreateAnimation("RoyalKnightsStart", "RoyalKnightsStart", 0, 32, 0.07f, false);
	RoyalKnight->CreateAnimation("RoyalKnightsLoop", "RoyalKnightsLoop", 0, 23, 0.1f);
	RoyalKnight->CreateAnimation("RoyalKnightsEnd", "RoyalKnightsEnd", 0, 13, 0.1f, false);

	RoyalKnight->CreateAnimation("None", "WrathOfEnril", 14, 14, 0.01f, false);
	RoyalKnight->ChangeAnimation("None");

	RoyalKnight->SetRelativeLocation(FVector{ 0.0f, 0.0f, static_cast<float>(EMapleZEnum::Player_Skill_Back) });
}

ARoyalKnight::~ARoyalKnight()
{

}

void ARoyalKnight::BeginPlay()
{
	ASkillManager::BeginPlay();
}

void ARoyalKnight::Tick(float _DeltaTime)
{
	ASkillManager::Tick(_DeltaTime);

	if (false == bIsRoyalEnd && UEngineInput::IsDown('1'))
	{
		RoyalKnight->ChangeAnimation("RoyalKnightsStart");
		RoyalKnight->SetActive(true);
		bIsRoyalStart = true;
	}

	if (true == RoyalKnight->IsCurAnimationEnd())
	{
		int a = 0;
	}

	if (true == bIsRoyalStart && true == RoyalKnight->IsCurAnimationEnd())
	{
		RoyalKnight->ChangeAnimation("RoyalKnightsLoop");
		bIsRoyalStart = false;
		bLoyalKnightsOn = true;
		bIsRoyalLoop = true;
		TimeEventComponent->AddEndEvent(10.0f, [this]()
			{
				this->bIsRoyalLoop = false;
				this->bIsRoyalEnd = true;
			}, true
		);
	}

	

	if (true == bIsRoyalLoop && UEngineInput::IsDown('1'))
	{
		RoyalKnight->ChangeAnimation("RoyalKnightsEnd");
		// 강제종료 조건
	}


	// 조건에 강제종료 조건 추가
	if (false == bIsRoyalLoop && true== bIsRoyalEnd)
	{
		RoyalKnight->ChangeAnimation("RoyalKnightsEnd");

		if (true == RoyalKnight->IsCurAnimationEnd())
		{
			bIsRoyalEnd = false;
			bLoyalKnightsOn = false;
			RoyalKnight->ChangeAnimation("None");
		}
	}

}
