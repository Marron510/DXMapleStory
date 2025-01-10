#include "PreCompile.h"


#include <EngineBase/FSMStateManager.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/TimeEventComponent.h>
#include <EngineCore/Collision.h>

#include "Player.h"
#include "EventCharacter.h"
#include "MapleEnum.h"

#include "WrathOfEnril.h"




void APlayer::StateInit()
{
	FSM.CreateState(ECharacterState::Idle, std::bind(&APlayer::Idle, this, std::placeholders::_1),
		[this]()
		{
			PlayerRenderer->ChangeAnimation("Idle");
		}
	);

	FSM.CreateState(ECharacterState::Prone, std::bind(&APlayer::Prone, this, std::placeholders::_1),
		[this]()
		{
			PlayerRenderer->ChangeAnimation("Prone");
		}
	);

	FSM.CreateState(ECharacterState::Walk, std::bind(&APlayer::Walk, this, std::placeholders::_1),
		[this]()
		{
			PlayerRenderer->ChangeAnimation("Walk");
		}
	);
	FSM.CreateState(ECharacterState::IdleJump, std::bind(&APlayer::IdleJump, this, std::placeholders::_1),
		[this]()
		{
			PlayerRenderer->ChangeAnimation("Jump");
		}
	);

	FSM.CreateState(ECharacterState::WalkJump, std::bind(&APlayer::WalkJump, this, std::placeholders::_1),
		[this]()
		{
			PlayerRenderer->ChangeAnimation("Jump");
		}
	);
	/*FSM.CreateState(ECharacterState::LeafJump, std::bind(&APlayer::LeafJump, this, std::placeholders::_1),
		[this]()
		{
			PlayerRenderer->ChangeAnimation("Tornado");
		}
	);*/
	FSM.CreateState(ECharacterState::Air, std::bind(&APlayer::Air, this, std::placeholders::_1),
		[this]()
		{
			PlayerRenderer->ChangeAnimation("Jump");
		}
	);

	
}




void APlayer::Idle(float _DeltaTime)
{
	// ���ڸ����� �̵���ȯ
	Gravity(_DeltaTime);
	IdleUseSkill(_DeltaTime);
	

	if (UEngineInput::IsPress(VK_LEFT) && true == MoveCollision->IsColliding()){ FSM.ChangeState(ECharacterState::Walk); return; }
	if (UEngineInput::IsPress(VK_RIGHT) && true == MoveCollision->IsColliding()) { FSM.ChangeState(ECharacterState::Walk); return; }
	if (UEngineInput::IsPress(VK_DOWN) && true == MoveCollision->IsColliding()){ FSM.ChangeState(ECharacterState::Prone); return; }
	if (UEngineInput::IsPress(VK_UP))
	{
		FSM.ChangeState(ECharacterState::Walk);
		return;
	}

	if (UEngineInput::IsPress('C')) { bIsJumping = true; FSM.ChangeState(ECharacterState::IdleJump); return; }


	// ü��
	/*if (false == MoveCollision->IsColliding())
	{
		FSM.ChangeState(ECharacterState::Air);
		return;
	}*/


	
}


void APlayer::Prone(float _DeltaTime)
{
	Gravity(_DeltaTime);
	IdleUseSkill(_DeltaTime);
	
	
	if (UEngineInput::IsUp(VK_DOWN) && true == MoveCollision->IsColliding())
	{
		FSM.ChangeState(ECharacterState::Idle);
		return;
	}


	
	// ������� ����(�Ʒ�����)
	//if (UEngineInput::IsDown('C')) { FSM.ChangeState(ECharacterState::IdleJump); }
}




void APlayer::Walk(float _DeltaTime)
{
	Gravity(_DeltaTime);
	IdleUseSkill(_DeltaTime);

	if (UEngineInput::IsPress(VK_LEFT) && true == MoveCollision->IsColliding())
	{
		TargetVelocity = FVector(PlayerSpeed, 0.0f, 0.0f);
		SetActorRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
	}

	if (UEngineInput::IsPress(VK_RIGHT) && true == MoveCollision->IsColliding())
	{
		TargetVelocity = FVector(PlayerSpeed, 0.0f, 0.0f);
		SetActorRelativeScale3D(FVector(-1.0f, 1.0f, 1.0f));
	}

	CurrentVelocity.X = UEngineMath::Lerp(CurrentVelocity.X, TargetVelocity.X, _DeltaTime * 2.0f);


	// ����
		
	if (UEngineInput::IsDown('C') && UEngineInput::IsPress(VK_LEFT))
	{ 
		bIsJumpRight = false; 
		FSM.ChangeState(ECharacterState::WalkJump); 
		return;
	}

	if (UEngineInput::IsDown('C') && UEngineInput::IsPress(VK_RIGHT)) 
	{
		bIsJumpRight = true; 
		FSM.ChangeState(ECharacterState::WalkJump);
		return;
	}
		
	// �̵��� ���� �� Idle ���·� ��ȯ
	if (UEngineInput::IsUp(VK_LEFT) && true == MoveCollision->IsColliding() || UEngineInput::IsUp(VK_RIGHT) && true == MoveCollision->IsColliding())
	{
		FSM.ChangeState(ECharacterState::Idle);
		return;
	}

	

	// ĳ���� �̵�
	if (UEngineInput::IsPress(VK_LEFT))
	{
		AddActorLocation(-CurrentVelocity * _DeltaTime);
	}
	if (UEngineInput::IsPress(VK_RIGHT))
	{
		AddActorLocation(CurrentVelocity * _DeltaTime);
	}


}

void APlayer::IdleJump(float _DeltaTime)
{
	bIsGround = false;
	Gravity(_DeltaTime);
	AirUseSkill(_DeltaTime);

	JumpVelocity = JumpPower;
	TargetJumpVelocity = FVector::ZERO;

	
	if (false == bIsGround)
	{
		TargetJumpVelocity = JumpPower;
	}

	JumpVelocity.Y = UEngineMath::Lerp(JumpVelocity.Y, TargetJumpVelocity.Y, _DeltaTime * 5.0f);

	// ���� ����
	if (true == bIsJumping)
	{
		AddActorLocation(JumpVelocity * _DeltaTime);
	}
	


	if (true == UEngineInput::IsDown(VK_LEFT))
	{
		SetActorRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
	}

	if (true == UEngineInput::IsDown(VK_RIGHT))
	{

		SetActorRelativeScale3D(FVector(-1.0f, 1.0f, 1.0f));

	}
	/*
	if (UEngineInput::IsDown('D') && true == bIsLeafUsing)
	{
		FSM.ChangeState(ECharacterState::LeafJump);
	}*/


	// ��ų ����
	if (true == bIsSkillUsing && true == MoveCollision->IsColliding())
	{
		bIsJumping = false;
		
		if (true == PlayerRenderer->IsCurAnimationEnd())
		{
			bIsSkillUsing = false;
			FSM.ChangeState(ECharacterState::Idle);
		}
	}

	else if (true == bIsSkillUsing && false == MoveCollision->IsColliding())
		{
			bIsJumping = true;

			if (true == PlayerRenderer->IsCurAnimationEnd())
			{
				bIsSkillUsing = false;
				FSM.ChangeState(ECharacterState::Air);
				return;
			}
		}
	// ��ų ��� ���ҽ�
	else if (false == bIsSkillUsing && true == MoveCollision->IsColliding())
	{
		bIsGround = true;
		FSM.ChangeState(ECharacterState::Idle);
		return;
	}
}

void APlayer::WalkJump(float _DeltaTime)
{
	bIsGround = false;
	//PlayerGroundCheck(GravityForce * _DeltaTime);
	Gravity(_DeltaTime);
	AirUseSkill(_DeltaTime);

	//JumpVelocity = JumpPower; 
	//TargetJumpVelocity = FVector::ZERO; 

	//if (false == bIsGround)
	//{
	//	TargetJumpVelocity = JumpPower;
	//}

	//JumpVelocity.Y = UEngineMath::Lerp(JumpVelocity.Y, TargetJumpVelocity.Y, _DeltaTime * 5.0f);

	//// ���� ����
	//AddActorLocation(JumpVelocity * _DeltaTime);





	//if (false == bIsJumpRight )
	//{
	//	AddActorLocation(FVector(-PlayerSpeed * _DeltaTime, 0.0f, 0.0f));
	//}

	//else if (true == bIsJumpRight)
	//{
	//	AddActorLocation(FVector(PlayerSpeed * _DeltaTime, 0.0f, 0.0f));
	//}
	//
	//if (true == UEngineInput::IsDown(VK_LEFT))
	//{
	//	SetActorRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
	//}
	//if (true == UEngineInput::IsDown(VK_RIGHT))
	//{
	//	SetActorRelativeScale3D(FVector(-1.0f, 1.0f, 1.0f));
	//}



	//// ���� �� Idle ���·� ��ȯ
	//if (true == UEngineInput::IsUp(VK_RIGHT) || true == UEngineInput::IsUp(VK_LEFT))
	//{
	//	bIsJumpMoveEnd = true;
	//}
	//if (true == bIsJumpMoveEnd && 0.00000000001f > TargetJumpVelocity.Y)
	//{
	//	bIsJumpMoveEnd = false;
	//	AddActorLocation(FVector::UP * 6.0f);
	//	FSM.ChangeState(ECharacterState::Idle);
	//	return;
	//}
}



void APlayer::Air(float _DeltaTime)
{
	//PlayerGroundCheck(GravityForce * _DeltaTime);
	Gravity(_DeltaTime);
	AirUseSkill(_DeltaTime);

	if (true == MoveCollision->IsColliding())
	{
		FSM.ChangeState(ECharacterState::Idle);
		return;
	}

}




void APlayer::IdleUseSkill(float _DeltaTime)
{
	// ���� ���� ����
	if (UEngineInput::IsPress('A')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("Wrath"); }

	// ��Ʈ����ũ ��� ��
	if (UEngineInput::IsPress('S')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("StrikeDualShot"); }

	// ����� �ٷ� ĳ���� Idle ��ȯ
	if (UEngineInput::IsUp('S')) { bIsSkillUsing = true; FSM.ChangeState(ECharacterState::Idle); }

	// ���� ����̺�
	if (UEngineInput::IsPress('Q')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("Charge"); }

	// ����ű ��������
	{
		if (UEngineInput::IsPress('W')) { PlayerRenderer->ChangeAnimation("HighKick"); }
		if (UEngineInput::IsDown('W')) { AddActorLocation(FVector(0.0f, 200.0f)); }
	}
}

void APlayer::AirUseSkill(float _DeltaTime)
{
	// ���� ���� ����
	if (UEngineInput::IsPress('A')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("Wrath"); }

	// ��Ʈ����ũ ��� ��
	if (UEngineInput::IsPress('S')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("StrikeDualShot"); }

	// ����� �ٷ� ĳ���� Idle ��ȯ
	if (UEngineInput::IsUp('S')) { bIsSkillUsing = true; FSM.ChangeState(ECharacterState::Air); }

	// ���� ����̵� 
	if (UEngineInput::IsPress('D')) { bIsSkillUsing = true; /*PlayerRenderer->ChangeAnimation("Tornado");*/
	bIsLeafUsing = true;
	}

	// �Ѹ� ���Ʈ
	if (UEngineInput::IsPress('E')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("Rolling"); }

	// ����ű ��������
	{
		if (UEngineInput::IsPress('W')) { PlayerRenderer->ChangeAnimation("HighKick"); }
		if (UEngineInput::IsDown('W')) { AddActorLocation(FVector(0.0f, 200.0f)); }
	}
}
