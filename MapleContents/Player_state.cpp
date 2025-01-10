#include "PreCompile.h"


#include <EngineBase/FSMStateManager.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/TimeEventComponent.h>

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
	PlayerGroundCheck(GravityForce * _DeltaTime);
	Gravity(_DeltaTime);
	UseSkill(_DeltaTime);
	

	if (UEngineInput::IsPress(VK_LEFT)){ FSM.ChangeState(ECharacterState::Walk); return; }
	if (UEngineInput::IsPress(VK_RIGHT)) { FSM.ChangeState(ECharacterState::Walk); return; }
	if (UEngineInput::IsPress(VK_DOWN)){ FSM.ChangeState(ECharacterState::Prone); return; }
	if (UEngineInput::IsPress(VK_UP))
	{
		FSM.ChangeState(ECharacterState::Walk);

	}
	
	if (false == bIsGround)
	{
		FSM.ChangeState(ECharacterState::Air);
	}


	// ���ڸ����� ���� ���

	if (UEngineInput::IsPress('C')) { bIsJumping = true; FSM.ChangeState(ECharacterState::IdleJump); return; }


}


void APlayer::Prone(float _DeltaTime)
{
	PlayerGroundCheck(GravityForce * _DeltaTime);
	Gravity(_DeltaTime);
	UseSkill(_DeltaTime);
	if (UEngineInput::IsUp(VK_DOWN))
	{
		FSM.ChangeState(ECharacterState::Idle);
		return;
	}


	
	// ������� ����
	if (UEngineInput::IsDown('C')) { FSM.ChangeState(ECharacterState::IdleJump); }
}




void APlayer::Walk(float _DeltaTime)
{
	PlayerGroundCheck(GravityForce * _DeltaTime);
	Gravity(_DeltaTime);
	UseSkill(_DeltaTime);

	if (UEngineInput::IsPress(VK_LEFT))
	{
		TargetVelocity = FVector(PlayerSpeed, 0.0f, 0.0f);
		SetActorRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
	}

	if (UEngineInput::IsPress(VK_RIGHT))
	{
		TargetVelocity = FVector(PlayerSpeed, 0.0f, 0.0f);
		SetActorRelativeScale3D(FVector(-1.0f, 1.0f, 1.0f));
	}

	CurrentVelocity.X = UEngineMath::Lerp(CurrentVelocity.X, TargetVelocity.X, _DeltaTime * 2.0f);


	// ü��

	if (false == bIsGround && true == UEngineInput::IsPress(VK_RIGHT) )
	{
		int a = 0;
	}
	
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
	if (UEngineInput::IsUp(VK_LEFT) || UEngineInput::IsUp(VK_RIGHT))
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
	PlayerGroundCheck(GravityForce * _DeltaTime);
	JumpGravity(_DeltaTime);
	UseSkill(_DeltaTime);

	JumpVelocity = JumpPower;
	TargetJumpVelocity = FVector::ZERO;

	
	if (false == bIsGround)
	{
		TargetJumpVelocity = JumpPower;
	}

	JumpVelocity.Y = UEngineMath::Lerp(JumpVelocity.Y, TargetJumpVelocity.Y, _DeltaTime * 5.0f);

	if (true == bIsJumping)
	{
		// ���� ����
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
	
	if (true == bIsLeafUsing)
	{
		AddActorLocation(JumpVelocity * 0.8f * _DeltaTime);
	}

	// ���� �� Idle ���·� ��ȯ



	// ��ų ����
	if (true == bIsSkillUsing && 0.00001f > TargetJumpVelocity.Y)
	{
		bIsJumping = false;
		

		if (true == PlayerRenderer->IsCurAnimationEnd())
		{
			AddActorLocation(FVector::UP * 4.0f);
			bIsSkillUsing = false;
			bIsLeafUsing = false;
			FSM.ChangeState(ECharacterState::Idle);
		}
	}

	else if (true == bIsSkillUsing && 0.00001f < TargetJumpVelocity.Y)
		{
			bIsJumping = true;

			if (true == PlayerRenderer->IsCurAnimationEnd())
			{
				AddActorLocation(FVector::UP *4.0f);
				bIsSkillUsing = false;
				FSM.ChangeState(ECharacterState::Air);
				return;
			}
		}
	// ��ų ��� ���ҽ�
	else if (false == bIsSkillUsing && 0.00001f > TargetJumpVelocity.Y)
	{
		AddActorLocation(FVector::UP * 4.0f);
		FSM.ChangeState(ECharacterState::Idle);
		return;
	}
	
	//if (0.00001f > TargetJumpVelocity.Y)
	//{
	//	AddActorLocation(FVector::UP * 10.0f);
	//	FSM.ChangeState(ECharacterState::Idle);
	//}

}

void APlayer::WalkJump(float _DeltaTime)
{
	bIsGround = false;
	//bIsJumpMoveEnd = false;
	PlayerGroundCheck(GravityForce * _DeltaTime);
	JumpGravity(_DeltaTime);
	UseSkill(_DeltaTime);

	JumpVelocity = JumpPower; 
	TargetJumpVelocity = FVector::ZERO; 

	if (false == bIsGround)
	{
		TargetJumpVelocity = JumpPower;
	}

	JumpVelocity.Y = UEngineMath::Lerp(JumpVelocity.Y, TargetJumpVelocity.Y, _DeltaTime * 5.0f);

	// ���� ����
	AddActorLocation(JumpVelocity * _DeltaTime);





	if (false == bIsJumpRight )
	{
		AddActorLocation(FVector(-PlayerSpeed * _DeltaTime, 0.0f, 0.0f));
	}

	else if (true == bIsJumpRight)
	{
		AddActorLocation(FVector(PlayerSpeed * _DeltaTime, 0.0f, 0.0f));
	}
	
	if (true == UEngineInput::IsDown(VK_LEFT))
	{
		SetActorRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
	}
	if (true == UEngineInput::IsDown(VK_RIGHT))
	{
		SetActorRelativeScale3D(FVector(-1.0f, 1.0f, 1.0f));
	}

	// ���� �� Idle ���·� ��ȯ
	if (true == UEngineInput::IsUp(VK_RIGHT) || true == UEngineInput::IsUp(VK_LEFT))
	{
		bIsJumpMoveEnd = true;
	}
	if (true == bIsJumpMoveEnd && 0.00000000001f > TargetJumpVelocity.Y)
	{
		bIsJumpMoveEnd = false;
		AddActorLocation(FVector::UP * 6.0f);
		FSM.ChangeState(ECharacterState::Idle);
		return;
	}

}


void APlayer::Air(float _DeltaTime)
{
	PlayerGroundCheck(GravityForce * _DeltaTime);
	Gravity(_DeltaTime);
	UseSkill(_DeltaTime);

	if (true == bIsGround )
	{
		FSM.ChangeState(ECharacterState::Idle);
		return;
	}

}

void APlayer::UseSkill(float _DeltaTime)
{
	// ���� ���� ����
	if (UEngineInput::IsPress('A')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("Wrath"); }

	// ��Ʈ����ũ ��� ��
	if (UEngineInput::IsPress('S')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("StrikeDualShot"); }

	// ����� �ٷ� ĳ���� Idle ��ȯ
	if (UEngineInput::IsUp('S')) { bIsSkillUsing = true; FSM.ChangeState(ECharacterState::Idle); }

	// ���� ����̵� 
	if (UEngineInput::IsPress('D')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("Tornado");
	
	}

	// �Ѹ� ���Ʈ
	if (UEngineInput::IsPress('E')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("Rolling"); }

	// ���� ����̺�
	if (UEngineInput::IsPress('Q')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("Charge"); }

	// ����ű ��������
	{
		if (UEngineInput::IsPress('W')) { PlayerRenderer->ChangeAnimation("HighKick"); }
		if (UEngineInput::IsDown('W')) { AddActorLocation(FVector(0.0f, 200.0f)); }
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
	if (UEngineInput::IsPress('D')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("Tornado");
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
