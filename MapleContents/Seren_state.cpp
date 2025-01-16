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

	//4개의 세렌 모두 똑같이 행동하는 것 ( Idle, Walk, Die, Hit)
	SerenFSM.CreateState(ESerenState::NoonIdle, std::bind(&ASeren::Idle, this, std::placeholders::_1),
		[this]()
		{
			SerenRender->ChangeAnimation("NoonSerenStand");
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
	FVector loc =  GetWorld()->GetMainPawn()->GetActorTransform().RelativeLocation;
	int a = 0;
}

void ASeren::Die(float _DeltaTime)
{

}