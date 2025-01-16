#include "PreCompile.h"
#include "Seren.h"


#include <EngineBase/FSMStateManager.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/TimeEventComponent.h>
#include <EngineCore/Collision.h>

#include "CerniumPlazaMode.h"
#include "EventCharacter.h"
#include "MapleEnum.h"
#include "Player.h"


void ASeren::StateInit()
{

	//4개의 세렌 모두 똑같이 행동하는 것 ( Idle, Walk, Rush, Die, Hit)
	SerenFSM.CreateState(ESerenState::NoonIdle, std::bind(&ASeren::Idle, this, std::placeholders::_1),
		[this]()
		{
			SerenRender->ChangeAnimation("NoonSerenStand");
		}
	);

	SerenFSM.CreateState(ESerenState::NoonWalk, std::bind(&ASeren::Walk, this, std::placeholders::_1),
		[this]()
		{
			SerenRender->ChangeAnimation("NoonSerenStand");
		}
	);

	SerenFSM.CreateState(ESerenState::NoonRush, std::bind(&ASeren::Rush, this, std::placeholders::_1),
		[this]()
		{
			SerenRender->ChangeAnimation("NoonSerenRush");
		}
	);
	SerenFSM.CreateState(ESerenState::NoonSting, std::bind(&ASeren::Sting, this, std::placeholders::_1),
		[this]()
		{
			SerenRender->ChangeAnimation("NoonSerenSting");
		}
	);

	SerenFSM.CreateState(ESerenState::NoonDie, std::bind(&ASeren::Die, this, std::placeholders::_1),
		[this]()
		{
			SerenRender->ChangeAnimation("NoonSerenDie");
		}
	);
	
}


void ASeren::Idle(float _DeltaTime)
{
	FVector SerenLocation = GetActorLocation();
	FVector DifferentLocation = CurPlayerLocation - SerenLocation;
	DifferentLocation.Normalize();

	if (0 < DifferentLocation.X)
	{
		SetActorRelativeScale3D(FVector{ -1.0f, 1.0f, 1.0f });
	}
	else if(0 >= DifferentLocation.X)
	{
		SetActorRelativeScale3D(FVector{ 1.0f, 1.0f, 1.0f });
	}

	AddActorLocation(FVector(DifferentLocation.X * _DeltaTime * 50.0f, 0.0f, 0.0f));
}

void ASeren::Walk(float _DeltaTime)
{
	
}

void ASeren::Rush(float _DeltaTime)
{

}


void ASeren::Sting(float _DeltaTime)
{

}

void ASeren::Die(float _DeltaTime)
{

}