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
			SerenRender->ChangeAnimation("Phase1_Stand");
		}
	);

	SerenFSM.CreateState(ESerenState::Walk, std::bind(&ASeren::Walk, this, std::placeholders::_1),
		[this]()
		{
			SerenRender->ChangeAnimation("Phase1_Stand");
		}
	);

	SerenFSM.CreateState(ESerenState::Rush, std::bind(&ASeren::Rush, this, std::placeholders::_1),
		[this]()
		{
			SerenRender->ChangeAnimation("Phase1_Rush");
		}
	);
	SerenFSM.CreateState(ESerenState::Sting, std::bind(&ASeren::ASting, this, std::placeholders::_1),
		[this]()
		{
			SerenRender->ChangeAnimation("Phase1_Sting");
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



	// 99. 죽음 체크
}

void ASeren::Walk(float _DeltaTime)
{
	SkillCoolTime -= _DeltaTime;

	// 스킬 사용 가능 여부 확인(근거리, 원거리)

	CheckCollision->SetCollisionStay([this, _DeltaTime](UCollision* _This, UCollision* _Other)
		{

			

			bIsInRange = true;

			if( 0 >= SkillCoolTime)
			{
				this->StingCollision->SetActive(true);
				SerenFSM.ChangeState(ESerenState::Sting);
				return;
			}

		});

	// 근거리 -> 원거리
	CheckCollision->SetCollisionEnd([this, _DeltaTime](UCollision* _This, UCollision* _Other)
		{
			bIsInRange = false;
		});


	// 러쉬 스킬
	OutRangeCollision->SetCollisionStay([this, _DeltaTime](UCollision* _This, UCollision* _Other)
		{
				// 원거리 일 때만 사용 가능
				if (0 >= SkillCoolTime && false == bIsInRange)
				{
					this->RushCollision->SetActive(true);
					SerenFSM.ChangeState(ESerenState::Rush);
					return;
				}
		});


	CurPlayerLocation = Player->GetActorLocation();
	// 이동 로직
	FVector SerenLocation = GetActorLocation();
	DifferentLocation = CurPlayerLocation - SerenLocation;
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
	if (true == SerenRender->IsCurAnimationEnd() && true == bIsRush)
	{
		SkillCoolTime = StimgCoolTime;
		RushCollision->SetActive(false);
		bIsRush = false;
		bIsIdle = true;
		if (0.0f > DifferentLocation.X)
		{
			AddActorLocation(FVector{ -690.0f, 0.0f });
			SerenFSM.ChangeState(ESerenState::Idle);
			return;
		}
		if (0.0f < DifferentLocation.X)
		{
			AddActorLocation(FVector{ 690.0f, 0.0f });
			SerenFSM.ChangeState(ESerenState::Idle);
			return;
		}
	}

	RushCollision->SetCollisionStay([this, _DeltaTime](UCollision* _This, UCollision* _Other)
		{
			if (true == _Other->IsColliding() && true == SerenRender->IsCurAnimationEnd())
			{
				GetGameInstance<MapleInstance>()->Status.Hp -= 5.0f;
				float Curhp = GetGameInstance<MapleInstance>()->Status.Hp;
				bIsRush = true;
			}
		});

	if (true == SerenRender->IsCurAnimationEnd())
	{
		bIsRush = true;
	}
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
	Collision->SetActive(false);
	CheckCollision->SetActive(false);
	OutRangeCollision->SetActive(false);
}