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
	FSM.CreateState(ECharacterState::UpJump, std::bind(&APlayer::UpJump, this, std::placeholders::_1),
		[this]()
		{
			PlayerRenderer->ChangeAnimation("Jump");
		}
	);
	FSM.CreateState(ECharacterState::WalkUpJump, std::bind(&APlayer::WalkUpJump, this, std::placeholders::_1),
		[this]()
		{
			PlayerRenderer->ChangeAnimation("Jump");
		}
	);
	FSM.CreateState(ECharacterState::LeafTornado, std::bind(&APlayer::LeafTornado, this, std::placeholders::_1),
		[this]()
		{
			PlayerRenderer->ChangeAnimation("Tornado");
		}
	);
	FSM.CreateState(ECharacterState::WrathOfEnril, std::bind(&APlayer::WrathOfEnril, this, std::placeholders::_1),
		[this]()
		{
			PlayerRenderer->ChangeAnimation("Wrath");
		}
	);
	FSM.CreateState(ECharacterState::LegendarySpear, std::bind(&APlayer::LegendarySpear, this, std::placeholders::_1),
		[this]()
		{
			PlayerRenderer->ChangeAnimation("LegendarySpear");
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
	Gravity(_DeltaTime);
	IdleUseSkill(_DeltaTime);
	

	if (UEngineInput::IsPress(VK_LEFT) && true == MoveCollision->IsColliding()){ FSM.ChangeState(ECharacterState::Walk); return; }
	if (UEngineInput::IsPress(VK_RIGHT) && true == MoveCollision->IsColliding()) { FSM.ChangeState(ECharacterState::Walk); return; }
	if (UEngineInput::IsPress(VK_DOWN) && true == MoveCollision->IsColliding()){ FSM.ChangeState(ECharacterState::Prone); return; }
	//if (UEngineInput::IsPress(VK_UP))
	//{
	//	FSM.ChangeState(ECharacterState::Walk);
	//	return;
	//}

	if (UEngineInput::IsPress('C')) { bIsJumping = true; FSM.ChangeState(ECharacterState::IdleJump); return; }

	// Idle ����ű ��������
	if (true == UEngineInput::IsDown('W'))
	{
		bIsZeroGravity = true;
		FSM.ChangeState(ECharacterState::Air);
	}
	// Idle �������� ���Ǿ�
	if (true == UEngineInput::IsDown('G')) { GravityForce = FVector::DOWN * 4.0f; FSM.ChangeState(ECharacterState::LegendarySpear); }

	// ü��
	if (false == bIsJumping  && false == bIsGround)
	{
		FSM.ChangeState(ECharacterState::Air);
		return;
	}

	if (true == PlayerRenderer->IsCurAnimationEnd())
	{
		FSM.ChangeState(ECharacterState::Idle);
	}
	
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
	WalkUseSkill(_DeltaTime);
	
	// 1. �����鼭 �¿�Ŭ�� 
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

	if (UEngineInput::IsPress(VK_LEFT)) { AddActorLocation(-CurrentVelocity * _DeltaTime); }
	if (UEngineInput::IsPress(VK_RIGHT)) { AddActorLocation(CurrentVelocity * _DeltaTime); }

	
	// 2. �����鼭 ����
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
		

	// 3. �����鼭 ��ų ���
	// Idle �������� ���Ǿ�
	if (true == UEngineInput::IsDown('G')) { GravityForce = FVector::DOWN * 4.0f; FSM.ChangeState(ECharacterState::LegendarySpear); }
	
	// 4. �̵��� ���� �� Idle ���·� ��ȯ
	if (UEngineInput::IsUp(VK_LEFT) && true == MoveCollision->IsColliding() || UEngineInput::IsUp(VK_RIGHT) && true == MoveCollision->IsColliding())
	{
		FSM.ChangeState(ECharacterState::Idle);
		return;
	}


}

void APlayer::IdleJump(float _DeltaTime)
{
	Gravity(_DeltaTime);
	AirUseSkill(_DeltaTime);

	JumpVelocity = JumpPower;
	TargetJumpVelocity = FVector::ZERO;

	
	if (false == bIsGround)
	{
		TargetJumpVelocity = JumpPower;
	}

	JumpVelocity.Y = UEngineMath::Lerp(JumpVelocity.Y, TargetJumpVelocity.Y, _DeltaTime * 5.0f);

	// 1. ���� ����
	if (true == bIsJumping && false == bIsZeroGravity) { AddActorLocation(JumpVelocity * _DeltaTime); }
	if (true == UEngineInput::IsDown(VK_LEFT)){ SetActorRelativeScale3D(FVector(1.0f, 1.0f, 1.0f)); }
	if (true == UEngineInput::IsDown(VK_RIGHT)) { SetActorRelativeScale3D(FVector(-1.0f, 1.0f, 1.0f)); }
	
	// 2. �� ����
	if (true == UEngineInput::IsDown('C') && true == UEngineInput::IsPress(VK_UP)) { FSM.ChangeState(ECharacterState::UpJump); }

	
	// ���� �� ������
	if (true == UEngineInput::IsPress(VK_LEFT))
	{
		SetActorRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
		AddActorLocation(FVector(-PlayerSpeed * SlowJumpMove * _DeltaTime, 0.0f, 0.0f));
	}
	if (true == UEngineInput::IsPress(VK_RIGHT))
	{
		SetActorRelativeScale3D(FVector(-1.0f, 1.0f, 1.0f));
		AddActorLocation(FVector(PlayerSpeed * SlowJumpMove * _DeltaTime, 0.0f, 0.0f));
	}

	// ���� ���� ����̵�
	if (true == UEngineInput::IsDown('D')) { FSM.ChangeState(ECharacterState::LeafTornado); }
	
	// ���� �������� ���Ǿ�
	if (true == UEngineInput::IsDown('G')) { FSM.ChangeState(ECharacterState::Air); }

	// ���� �Ѹ� ����Ʈ
	if (true == UEngineInput::IsDown('E')) { FSM.ChangeState(ECharacterState::Air); }


	// 3. ��ų �ִϸ��̼��� ������ ���� �ִϸ��̼����� ��ȯ
	if (true == PlayerRenderer->IsCurAnimationEnd()) { bIsZeroGravity = false; PlayerRenderer->ChangeAnimation("Jump"); }
	
	// ���� ���� �� ���� �̵�
	//if (true == UEngineInput::IsUp('C') && true == bIsGround) { bIsJumpMoveEnd = true; }
	if (true == UEngineInput::IsFree('C') && true == bIsGround)	{ bIsJumpMoveEnd = true; }
	
	// 4. ���� �� Idle ���·� ��ȯ
	if (true == bIsJumpMoveEnd && bIsGround == true)
	{
		bIsJumpMoveEnd = false;
		FSM.ChangeState(ECharacterState::Idle);
		return;
	}

}

void APlayer::WalkJump(float _DeltaTime)
{
	Gravity(_DeltaTime);
	AirUseSkill(_DeltaTime);

	JumpVelocity = JumpPower; 
	TargetJumpVelocity = FVector::ZERO; 

	if (false == bIsGround)
	{
		TargetJumpVelocity = JumpPower;
	}

	JumpVelocity.Y = UEngineMath::Lerp(JumpVelocity.Y, TargetJumpVelocity.Y, _DeltaTime * 5.0f);

	// 1. ���� ����
	if (false == UEngineInput::IsPress('E') && false == bIsZeroGravity ||
		false == UEngineInput::IsPress('W') && false == bIsZeroGravity)
	{
		AddActorLocation(JumpVelocity * _DeltaTime);
	}

	// 2. �����鼭 ���� �� �� ����
	if (true == UEngineInput::IsDown('C') && true == UEngineInput::IsPress(VK_UP)) {FSM.ChangeState(ECharacterState::WalkUpJump); }

	// �����鼭 ���� �� ���� ����̵�
	if (true == UEngineInput::IsDown('D')) { FSM.ChangeState(ECharacterState::LeafTornado); }
	
	// �����鼭 ���� �� �������� ���Ǿ�
	if (true == UEngineInput::IsDown('G')) { FSM.ChangeState(ECharacterState::Air); }

	// �����鼭 ���� �� ���� �Ѹ� ����Ʈ
	if (true == UEngineInput::IsDown('E')) { FSM.ChangeState(ECharacterState::Air); }

	// �����鼭 ���� �� ����ű ��������??
	if (true == UEngineInput::IsDown('W'))
	{
		FSM.ChangeState(ECharacterState::Air);
	}

	// ���� �������� ����
	if (false == bIsJumpRight )
	{
		AddActorLocation(FVector(-PlayerSpeed * JumpMove * _DeltaTime, 0.0f, 0.0f));
	}

	// ������ �������� ����
	else if (true == bIsJumpRight)
	{
		AddActorLocation(FVector(PlayerSpeed * JumpMove * _DeltaTime, 0.0f, 0.0f));
	}
	// ���� �� ���� �������� �ణ �̵�
	if (true == UEngineInput::IsPress(VK_LEFT) && true == bIsJumpRight)
	{
		SetActorRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
		AddActorLocation(FVector(-PlayerSpeed * SlowJumpMove * _DeltaTime, 0.0f, 0.0f));
	}
	// ���� �� ������ �������� �ణ �̵�
	if (true == UEngineInput::IsPress(VK_RIGHT) && false == bIsJumpRight)
	{
		SetActorRelativeScale3D(FVector(-1.0f, 1.0f, 1.0f));
		AddActorLocation(FVector(PlayerSpeed * SlowJumpMove * _DeltaTime, 0.0f, 0.0f));
	}

	// ���� �� ���� ���⺸��
	if (true == UEngineInput::IsPress(VK_LEFT))	{ SetActorRelativeScale3D(FVector(1.0f, 1.0f, 1.0f)); }
	// ���� �� ������ ���⺸��
	if (true == UEngineInput::IsPress(VK_RIGHT)) { SetActorRelativeScale3D(FVector(-1.0f, 1.0f, 1.0f)); }
	
	
	// ��ų �ִϸ��̼��� ������ ���� �ִϸ��̼����� ��ȯ
	if (true == PlayerRenderer->IsCurAnimationEnd()) { bIsZeroGravity = false; PlayerRenderer->ChangeAnimation("Jump"); }


	// 3. ���� �� Idle ���·� ��ȯ
	if (true == UEngineInput::IsUp('C') && true == bIsGround) {	bIsJumpMoveEnd = true; }
	if (true == UEngineInput::IsFree('C') && true == bIsGround) { bIsJumpMoveEnd = true; }

	if (true == bIsJumpMoveEnd && bIsGround == true)
	{
		bIsJumpMoveEnd = false;
		FSM.ChangeState(ECharacterState::Idle);
		return;
	}

}

void APlayer::UpJump(float _DeltaTime)
{
	Gravity(_DeltaTime);
	AirUseSkill(_DeltaTime);

	JumpVelocity = JumpPower;
	TargetJumpVelocity = FVector::ZERO;

	if (false == bIsGround)
	{
		TargetJumpVelocity = JumpPower;
	}

	JumpVelocity.Y = UEngineMath::Lerp(JumpVelocity.Y, TargetJumpVelocity.Y, _DeltaTime * 5.0f);

	AddActorLocation(JumpPower * UpJumpPower);

	if (true == bIsGround)
	{
		FSM.ChangeState(ECharacterState::Idle);
		return;
	}

	// ���� �� ���� �������� �ణ �̵�
	if (true == UEngineInput::IsPress(VK_LEFT) && true == bIsJumpRight)
	{
		SetActorRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
		AddActorLocation(FVector(-PlayerSpeed * SlowJumpMove * _DeltaTime, 0.0f, 0.0f));
	}
	// ���� �� ������ �������� �ణ �̵�
	if (true == UEngineInput::IsPress(VK_RIGHT) && false == bIsJumpRight)
	{
		SetActorRelativeScale3D(FVector(-1.0f, 1.0f, 1.0f));
		AddActorLocation(FVector(PlayerSpeed * SlowJumpMove * _DeltaTime, 0.0f, 0.0f));
	}

	// ���� �� ���� ���⺸��
	if (true == UEngineInput::IsPress(VK_LEFT)) { SetActorRelativeScale3D(FVector(1.0f, 1.0f, 1.0f)); }
	// ���� �� ������ ���⺸��
	if (true == UEngineInput::IsPress(VK_RIGHT)) { SetActorRelativeScale3D(FVector(-1.0f, 1.0f, 1.0f)); }

	// �� ���� ���� ����̵�
	if (true == UEngineInput::IsDown('D')) { GravityForce = FVector::DOWN * 6.0f; FSM.ChangeState(ECharacterState::LeafTornado); }
	if (true == UEngineInput::IsDown('E')) { FSM.ChangeState(ECharacterState::Air); }
	if (true == UEngineInput::IsDown('G')) { FSM.ChangeState(ECharacterState::Air); }
	// ��� ������ ��ų(�̵� �� ����)  -> ���� ����̵�(��), �Ѹ� ����Ʈ(��), G Ű
	// ��� ������ ��ų(�̵� �� �ȸ���)  -> ������, ����, ����
}

void APlayer::WalkUpJump(float _DeltaTime)
{
	Gravity(_DeltaTime);
	AirUseSkill(_DeltaTime);

	JumpVelocity = JumpPower;
	TargetJumpVelocity = FVector::ZERO;

	if (false == bIsGround)
	{
		TargetJumpVelocity = JumpPower;
	}

	JumpVelocity.Y = UEngineMath::Lerp(JumpVelocity.Y, TargetJumpVelocity.Y, _DeltaTime * 5.0f);

	// ������ ����
	if (false == bIsJumpRight) { AddActorLocation(FVector(-PlayerSpeed * JumpMove * _DeltaTime, 500.0f * UpJumpPower, 0.0f)); }
	else if (true == bIsJumpRight) { AddActorLocation(FVector(PlayerSpeed * JumpMove * _DeltaTime, 500.0f * UpJumpPower, 0.0f)); }

	if (true == bIsGround)
	{
		FSM.ChangeState(ECharacterState::Idle);
		return;
	}

	// ���� �� ���� �������� �ణ �̵�
	if (true == UEngineInput::IsPress(VK_LEFT) && true == bIsJumpRight)
	{
		SetActorRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
		AddActorLocation(FVector(-PlayerSpeed * SlowJumpMove * _DeltaTime, 0.0f, 0.0f));
	}
	// ���� �� ������ �������� �ణ �̵�
	if (true == UEngineInput::IsPress(VK_RIGHT) && false == bIsJumpRight)
	{
		SetActorRelativeScale3D(FVector(-1.0f, 1.0f, 1.0f));
		AddActorLocation(FVector(PlayerSpeed * SlowJumpMove * _DeltaTime, 0.0f, 0.0f));
	}

	// ���� �� ���� ���⺸��
	if (true == UEngineInput::IsPress(VK_LEFT)) { SetActorRelativeScale3D(FVector(1.0f, 1.0f, 1.0f)); }
	// ���� �� ������ ���⺸��
	if (true == UEngineInput::IsPress(VK_RIGHT)) { SetActorRelativeScale3D(FVector(-1.0f, 1.0f, 1.0f)); }

	// ��ų �ִϸ��̼��� ������ ���� �ִϸ��̼����� ��ȯ
	if (true == PlayerRenderer->IsCurAnimationEnd()) { bIsZeroGravity = false; PlayerRenderer->ChangeAnimation("Jump"); }

	// ��� ������ ��ų(�̵� �� ����)  -> ���� ����̵�(��), �Ѹ� ����Ʈ(��), G Ű
	if (true == UEngineInput::IsDown('D')) { GravityForce = FVector::DOWN * 6.0f; FSM.ChangeState(ECharacterState::LeafTornado); }
	if (true == UEngineInput::IsDown('E')) { FSM.ChangeState(ECharacterState::Air); }
	if (true == UEngineInput::IsDown('G')) { FSM.ChangeState(ECharacterState::Air); }
	// ��� ������ ��ų(�̵� �� �ȸ���)  -> ������, ����, ����


}


void APlayer::Air(float _DeltaTime)
{
	
	Gravity(_DeltaTime);
	AirUseSkill(_DeltaTime);

	if (true == bIsGround)
	{
		FSM.ChangeState(ECharacterState::Idle);
		return;
	}

	// ��ų �ִϸ��̼��� ������ ���� �ִϸ��̼����� ��ȯ
	if (true == PlayerRenderer->IsCurAnimationEnd())
	{
		bIsZeroGravity = false;
		PlayerRenderer->ChangeAnimation("Jump");
	}
	

	if (true == UEngineInput::IsDown('D'))
	{
		FSM.ChangeState(ECharacterState::LeafTornado);
		return;
	}

	if (true == UEngineInput::IsDown('G'))
	{
		FSM.ChangeState(ECharacterState::LegendarySpear);
		return;
	}

	
}

void APlayer::LeafTornado(float _DeltaTime)
{
	Gravity(_DeltaTime);
	AirUseSkill(_DeltaTime);

	JumpVelocity = JumpPower;
	TargetJumpVelocity = FVector::ZERO;

	if (false == bIsGround)
	{
		TargetJumpVelocity = JumpPower;
	}

	JumpVelocity.Y = UEngineMath::Lerp(JumpVelocity.Y, TargetJumpVelocity.Y, _DeltaTime * 5.0f);

	AddActorLocation(JumpPower * 0.025f);

	if (true == bIsGround)
	{
		FSM.ChangeState(ECharacterState::Idle);
		return;
	}
	if (true == PlayerRenderer->IsCurAnimationEnd() && false == bIsGround)
	{
		GravityForce = FVector::DOWN * 4.0f;
		FSM.ChangeState(ECharacterState::Air);
		return;
	}
}

void APlayer::LegendarySpear(float _DeltaTime)
{
	Gravity(_DeltaTime);
	AirUseSkill(_DeltaTime);
	

	JumpVelocity = JumpPower;
	TargetJumpVelocity = FVector::ZERO;

	if (false == bIsGround)
	{
		TargetJumpVelocity = JumpPower;
	}

	JumpVelocity.Y = UEngineMath::Lerp(JumpVelocity.Y, TargetJumpVelocity.Y, _DeltaTime * 5.0f);
	
	if (true == bIsGround)
	{
		AddActorLocation(JumpVelocity * 0.3f);
		bIsZeroGravity = true;
		return;
	}


	if (true == bIsGround)
	{
		FSM.ChangeState(ECharacterState::Idle);
		return;
	}
	if (true == PlayerRenderer->IsCurAnimationEnd() && false == bIsGround)
	{
		GravityForce = FVector::DOWN * 6.0f;
		FSM.ChangeState(ECharacterState::Air);
		return;
	}
}

void APlayer::WrathOfEnril(float _DeltaTime)
{

	Gravity(_DeltaTime);

	
	if (true == PlayerRenderer->IsCurAnimationEnd())
	{
		FSM.ChangeState(ECharacterState::Idle);
	}
}



void APlayer::IdleUseSkill(float _DeltaTime)
{
	// ���� ���� ����
	if (UEngineInput::IsPress('A')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("Wrath"); }

	// ��Ʈ����ũ ��� ��
	if (UEngineInput::IsPress('S')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("StrikeDualShot"); }

	// ���� ����̺�
	if (UEngineInput::IsPress('Q')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("Charge"); }

	// ������ ������ũ
	if (UEngineInput::IsPress('R')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("Unicorn"); }

	// �������� ���Ǿ�
	if (UEngineInput::IsPress('G')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("LegendarySpear"); }

	// ����ű ��������
	{
		if (UEngineInput::IsPress('W')) { PlayerRenderer->ChangeAnimation("HighKick"); }
		if (UEngineInput::IsDown('W')) { AddActorLocation(FVector(0.0f, 200.0f));  bIsZeroGravity = true;
		}
	}


}


void APlayer::WalkUseSkill(float _DeltaTime)
{
	// ���� ���� ����
	if (UEngineInput::IsPress('A')) { FSM.ChangeState(ECharacterState::WrathOfEnril);}

	// ��Ʈ����ũ ��� ��
	if (UEngineInput::IsPress('S')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("StrikeDualShot"); }

	// ���� ����̺�
	if (UEngineInput::IsPress('Q')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("Charge"); }

	// ������ ������ũ
	if (UEngineInput::IsPress('R')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("Unicorn"); }

	// �������� ���Ǿ�
	if (UEngineInput::IsPress('G')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("LegendarySpear"); }

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

	// ���� ����̵� 
	//if (UEngineInput::IsPress('D')) { bIsSkillUsing = true; }

	// �Ѹ� ���Ʈ
	if (UEngineInput::IsPress('E')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("Rolling"); bIsZeroGravity = true; }

	// ������ ������ũ
	if (UEngineInput::IsPress('R')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("Unicorn"); }

	// �������� ���Ǿ�
	if (UEngineInput::IsPress('G')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("LegendarySpear"); bIsZeroGravity = true;
	}

	// ����ű ��������
	{
		if (UEngineInput::IsPress('W')) { PlayerRenderer->ChangeAnimation("HighKick"); bIsZeroGravity = true;}
		if (UEngineInput::IsDown('W')) { AddActorLocation(FVector(0.0f, 200.0f));  }
		
	}
}
