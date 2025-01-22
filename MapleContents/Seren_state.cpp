#include "PreCompile.h"
#include "Seren.h"


#include <EngineBase/FSMStateManager.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/TimeEventComponent.h>
#include <EngineCore/Collision.h>

#include "MapleInstance.h"
#include "SerenCollision.h"
#include "CerniumPlazaMode.h"
#include "EventCharacter.h"
#include "MapleEnum.h"
#include "Player.h"

void ASeren::StateInit()
{

	//4개의 세렌 모두 똑같이 행동하는 것 ( Idle, Walk, Rush, Die, Hit)
	SerenFSM.CreateState(ESerenState::Idle, std::bind(&ASeren::Idle, this, std::placeholders::_1),
		[this]()
		{
			SerenRender->ChangeAnimation("NoonSerenStand");
		}
	);

	SerenFSM.CreateState(ESerenState::Walk, std::bind(&ASeren::Walk, this, std::placeholders::_1),
		[this]()
		{
			SerenRender->ChangeAnimation("NoonSerenStand");
		}
	);

	SerenFSM.CreateState(ESerenState::Rush, std::bind(&ASeren::Rush, this, std::placeholders::_1),
		[this]()
		{
			SerenRender->ChangeAnimation("NoonSerenRush");
		}
	);
	SerenFSM.CreateState(ESerenState::Sting, std::bind(&ASeren::ASting, this, std::placeholders::_1),
		[this]()
		{
			SerenRender->ChangeAnimation("NoonSerenSting");
		}
	);

	SerenFSM.CreateState(ESerenState::Die, std::bind(&ASeren::Die, this, std::placeholders::_1),
		[this]()
		{
			SerenRender->ChangeAnimation("NoonSerenDie");
		}
	);
	
}


void ASeren::Idle(float _DeltaTime)
{
	// 0. 세렌 플레이어 향해서 이동

	OutRangeCollision->SetCollisionStay([this](UCollision* _This, UCollision* _Other)
		{
			if (true == bIsIdle)
			{
			SerenFSM.ChangeState(ESerenState::Walk);
			bIsIdle = false;
			return;
			}
		});

	// 1. 근접 콜리전 충돌 시 

	

	// 랜덤값으로 체인지

	// 2. 근접 콜리전에서 벗어날 시




}

void ASeren::Walk(float _DeltaTime)
{
	

	// 스킬 사용 가능 여부 확인(근거리, 원거리)
	CheckCollision->SetCollisionStay([this, _DeltaTime](UCollision* _This, UCollision* _Other)
		{

			SkillCoolTime -= _DeltaTime;

			if( 0 >= SkillCoolTime)
			{
				this->StingCollision->SetActive(true);
				SerenFSM.ChangeState(ESerenState::Sting);
				return;
			}

		});


	CurPlayerLocation = Player->GetActorLocation();
	// 이동 로직
	FVector SerenLocation = GetActorLocation();
	FVector DifferentLocation = CurPlayerLocation - SerenLocation;
	DifferentLocation.Normalize();

	if (0 < DifferentLocation.X)
	{
		SetActorRelativeScale3D(FVector{ -1.0f, 1.0f, 1.0f });
	}
	else if (0 >= DifferentLocation.X)
	{
		SetActorRelativeScale3D(FVector{ 1.0f, 1.0f, 1.0f });
	}

	AddActorLocation(FVector(DifferentLocation.X * _DeltaTime * 50.0f, 0.0f, 0.0f));




}

void ASeren::Rush(float _DeltaTime)
{

}


void ASeren::ASting(float _DeltaTime)
{
	


	if (true == SerenRender->IsCurAnimationEnd() && true == bIsSting)
	{
		SkillCoolTime = StimgCoolTime;
		StingCollision->SetActive(false);
		bIsSting = false;
		bIsIdle = true;
		SerenFSM.ChangeState(ESerenState::Idle);
		return;
	}
	
	
	
	StingCollision->SetCollisionStay([this, _DeltaTime](UCollision* _This, UCollision* _Other)
		{
			if (true == _Other->IsColliding() && true == SerenRender->IsCurAnimationEnd())
			{
				GetGameInstance<MapleInstance>()->Status.Hp -= 5.0f;
				float Curhp = GetGameInstance<MapleInstance>()->Status.Hp;
				bIsSting = true;
			}
		});

	if (true == SerenRender->IsCurAnimationEnd())
	{
		bIsSting = true;
	}

}

void ASeren::Die(float _DeltaTime)
{

}