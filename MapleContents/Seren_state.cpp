#include "PreCompile.h"
#include "Seren.h"


#include <EngineBase/FSMStateManager.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/TimeEventComponent.h>
#include <EngineCore/Collision.h>


#include "EventCharacter.h"
#include"MapleEnum.h"



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
	
	int a = 0;
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