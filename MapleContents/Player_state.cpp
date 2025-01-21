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
	// 제자리에서 이동전환
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

	// Idle 하이킥 데몰리션
	if (true == UEngineInput::IsDown('W'))
	{
		bIsZeroGravity = true;
		FSM.ChangeState(ECharacterState::Air);
	}
	// Idle 레전더리 스피어
	if (true == UEngineInput::IsDown('G')) { GravityForce = FVector::DOWN * 4.0f; FSM.ChangeState(ECharacterState::LegendarySpear); }

	// 체공
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


	
	// 엎드려서 점프(아래점프)
	//if (UEngineInput::IsDown('C')) { FSM.ChangeState(ECharacterState::IdleJump); }
}




void APlayer::Walk(float _DeltaTime)
{
	Gravity(_DeltaTime);
	WalkUseSkill(_DeltaTime);
	
	// 1. 걸으면서 좌우클릭 
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

	
	// 2. 걸으면서 점프
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
		

	// 3. 걸으면서 스킬 사용
	// Idle 레전더리 스피어
	if (true == UEngineInput::IsDown('G')) { GravityForce = FVector::DOWN * 4.0f; FSM.ChangeState(ECharacterState::LegendarySpear); }
	
	// 4. 이동이 멈출 때 Idle 상태로 전환
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

	// 1. 점프 실행
	if (true == bIsJumping && false == bIsZeroGravity) { AddActorLocation(JumpVelocity * _DeltaTime); }
	if (true == UEngineInput::IsDown(VK_LEFT)){ SetActorRelativeScale3D(FVector(1.0f, 1.0f, 1.0f)); }
	if (true == UEngineInput::IsDown(VK_RIGHT)) { SetActorRelativeScale3D(FVector(-1.0f, 1.0f, 1.0f)); }
	
	// 2. 윗 점프
	if (true == UEngineInput::IsDown('C') && true == UEngineInput::IsPress(VK_UP)) { FSM.ChangeState(ECharacterState::UpJump); }

	
	// 점프 후 움직임
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

	// 점프 리프 토네이도
	if (true == UEngineInput::IsDown('D')) { FSM.ChangeState(ECharacterState::LeafTornado); }
	
	// 점프 레전더리 스피어
	if (true == UEngineInput::IsDown('G')) { FSM.ChangeState(ECharacterState::Air); }

	// 점프 롤링 문썰트
	if (true == UEngineInput::IsDown('E')) { FSM.ChangeState(ECharacterState::Air); }


	// 3. 스킬 애니메이션이 끝나면 점프 애니메이션으로 전환
	if (true == PlayerRenderer->IsCurAnimationEnd()) { bIsZeroGravity = false; PlayerRenderer->ChangeAnimation("Jump"); }
	
	// 점프 끝날 때 까지 이동
	//if (true == UEngineInput::IsUp('C') && true == bIsGround) { bIsJumpMoveEnd = true; }
	if (true == UEngineInput::IsFree('C') && true == bIsGround)	{ bIsJumpMoveEnd = true; }
	
	// 4. 착지 시 Idle 상태로 전환
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

	// 1. 점프 실행
	if (false == UEngineInput::IsPress('E') && false == bIsZeroGravity ||
		false == UEngineInput::IsPress('W') && false == bIsZeroGravity)
	{
		AddActorLocation(JumpVelocity * _DeltaTime);
	}

	// 2. 걸으면서 점프 후 윗 점프
	if (true == UEngineInput::IsDown('C') && true == UEngineInput::IsPress(VK_UP)) {FSM.ChangeState(ECharacterState::WalkUpJump); }

	// 걸으면서 점프 후 리프 토네이도
	if (true == UEngineInput::IsDown('D')) { FSM.ChangeState(ECharacterState::LeafTornado); }
	
	// 걸으면서 점프 후 레전더리 스피어
	if (true == UEngineInput::IsDown('G')) { FSM.ChangeState(ECharacterState::Air); }

	// 걸으면서 점프 후 리프 롤링 문썰트
	if (true == UEngineInput::IsDown('E')) { FSM.ChangeState(ECharacterState::Air); }

	// 걸으면서 점프 후 하이킥 데몰리션??
	if (true == UEngineInput::IsDown('W'))
	{
		FSM.ChangeState(ECharacterState::Air);
	}

	// 왼쪽 방향으로 점프
	if (false == bIsJumpRight )
	{
		AddActorLocation(FVector(-PlayerSpeed * JumpMove * _DeltaTime, 0.0f, 0.0f));
	}

	// 오른쪽 방향으로 점프
	else if (true == bIsJumpRight)
	{
		AddActorLocation(FVector(PlayerSpeed * JumpMove * _DeltaTime, 0.0f, 0.0f));
	}
	// 점프 후 왼쪽 방향으로 약간 이동
	if (true == UEngineInput::IsPress(VK_LEFT) && true == bIsJumpRight)
	{
		SetActorRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
		AddActorLocation(FVector(-PlayerSpeed * SlowJumpMove * _DeltaTime, 0.0f, 0.0f));
	}
	// 점프 후 오른쪽 방향으로 약간 이동
	if (true == UEngineInput::IsPress(VK_RIGHT) && false == bIsJumpRight)
	{
		SetActorRelativeScale3D(FVector(-1.0f, 1.0f, 1.0f));
		AddActorLocation(FVector(PlayerSpeed * SlowJumpMove * _DeltaTime, 0.0f, 0.0f));
	}

	// 점프 후 왼쪽 방향보기
	if (true == UEngineInput::IsPress(VK_LEFT))	{ SetActorRelativeScale3D(FVector(1.0f, 1.0f, 1.0f)); }
	// 점프 후 오른쪽 방향보기
	if (true == UEngineInput::IsPress(VK_RIGHT)) { SetActorRelativeScale3D(FVector(-1.0f, 1.0f, 1.0f)); }
	
	
	// 스킬 애니메이션일 끝나면 점프 애니메이션으로 전환
	if (true == PlayerRenderer->IsCurAnimationEnd()) { bIsZeroGravity = false; PlayerRenderer->ChangeAnimation("Jump"); }


	// 3. 착지 시 Idle 상태로 전환
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

	// 점프 후 왼쪽 방향으로 약간 이동
	if (true == UEngineInput::IsPress(VK_LEFT) && true == bIsJumpRight)
	{
		SetActorRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
		AddActorLocation(FVector(-PlayerSpeed * SlowJumpMove * _DeltaTime, 0.0f, 0.0f));
	}
	// 점프 후 오른쪽 방향으로 약간 이동
	if (true == UEngineInput::IsPress(VK_RIGHT) && false == bIsJumpRight)
	{
		SetActorRelativeScale3D(FVector(-1.0f, 1.0f, 1.0f));
		AddActorLocation(FVector(PlayerSpeed * SlowJumpMove * _DeltaTime, 0.0f, 0.0f));
	}

	// 점프 후 왼쪽 방향보기
	if (true == UEngineInput::IsPress(VK_LEFT)) { SetActorRelativeScale3D(FVector(1.0f, 1.0f, 1.0f)); }
	// 점프 후 오른쪽 방향보기
	if (true == UEngineInput::IsPress(VK_RIGHT)) { SetActorRelativeScale3D(FVector(-1.0f, 1.0f, 1.0f)); }

	// 윗 점프 리프 토네이도
	if (true == UEngineInput::IsDown('D')) { GravityForce = FVector::DOWN * 6.0f; FSM.ChangeState(ECharacterState::LeafTornado); }
	if (true == UEngineInput::IsDown('E')) { FSM.ChangeState(ECharacterState::Air); }
	if (true == UEngineInput::IsDown('G')) { FSM.ChangeState(ECharacterState::Air); }
	// 사용 가능한 스킬(이동 중 멈춤)  -> 리프 토네이도(완), 롤링 문썰트(완), G 키
	// 사용 가능한 스킬(이동 중 안멈춤)  -> 유니콘, 엔릴, 스듀
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

	// 윗점프 실행
	if (false == bIsJumpRight) { AddActorLocation(FVector(-PlayerSpeed * JumpMove * _DeltaTime, 500.0f * UpJumpPower, 0.0f)); }
	else if (true == bIsJumpRight) { AddActorLocation(FVector(PlayerSpeed * JumpMove * _DeltaTime, 500.0f * UpJumpPower, 0.0f)); }

	if (true == bIsGround)
	{
		FSM.ChangeState(ECharacterState::Idle);
		return;
	}

	// 점프 후 왼쪽 방향으로 약간 이동
	if (true == UEngineInput::IsPress(VK_LEFT) && true == bIsJumpRight)
	{
		SetActorRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
		AddActorLocation(FVector(-PlayerSpeed * SlowJumpMove * _DeltaTime, 0.0f, 0.0f));
	}
	// 점프 후 오른쪽 방향으로 약간 이동
	if (true == UEngineInput::IsPress(VK_RIGHT) && false == bIsJumpRight)
	{
		SetActorRelativeScale3D(FVector(-1.0f, 1.0f, 1.0f));
		AddActorLocation(FVector(PlayerSpeed * SlowJumpMove * _DeltaTime, 0.0f, 0.0f));
	}

	// 점프 후 왼쪽 방향보기
	if (true == UEngineInput::IsPress(VK_LEFT)) { SetActorRelativeScale3D(FVector(1.0f, 1.0f, 1.0f)); }
	// 점프 후 오른쪽 방향보기
	if (true == UEngineInput::IsPress(VK_RIGHT)) { SetActorRelativeScale3D(FVector(-1.0f, 1.0f, 1.0f)); }

	// 스킬 애니메이션일 끝나면 점프 애니메이션으로 전환
	if (true == PlayerRenderer->IsCurAnimationEnd()) { bIsZeroGravity = false; PlayerRenderer->ChangeAnimation("Jump"); }

	// 사용 가능한 스킬(이동 중 멈춤)  -> 리프 토네이도(완), 롤링 문썰트(완), G 키
	if (true == UEngineInput::IsDown('D')) { GravityForce = FVector::DOWN * 6.0f; FSM.ChangeState(ECharacterState::LeafTornado); }
	if (true == UEngineInput::IsDown('E')) { FSM.ChangeState(ECharacterState::Air); }
	if (true == UEngineInput::IsDown('G')) { FSM.ChangeState(ECharacterState::Air); }
	// 사용 가능한 스킬(이동 중 안멈춤)  -> 유니콘, 엔릴, 스듀


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

	// 스킬 애니메이션이 끝나면 점프 애니메이션으로 전환
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
	// 레쓰 오브 엔릴
	if (UEngineInput::IsPress('A')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("Wrath"); }

	// 스트라이크 듀얼 샷
	if (UEngineInput::IsPress('S')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("StrikeDualShot"); }

	// 차지 드라이브
	if (UEngineInput::IsPress('Q')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("Charge"); }

	// 유니콘 스파이크
	if (UEngineInput::IsPress('R')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("Unicorn"); }

	// 레전더리 스피어
	if (UEngineInput::IsPress('G')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("LegendarySpear"); }

	// 하이킥 데몰리션
	{
		if (UEngineInput::IsPress('W')) { PlayerRenderer->ChangeAnimation("HighKick"); }
		if (UEngineInput::IsDown('W')) { AddActorLocation(FVector(0.0f, 200.0f));  bIsZeroGravity = true;
		}
	}


}


void APlayer::WalkUseSkill(float _DeltaTime)
{
	// 레쓰 오브 엔릴
	if (UEngineInput::IsPress('A')) { FSM.ChangeState(ECharacterState::WrathOfEnril);}

	// 스트라이크 듀얼 샷
	if (UEngineInput::IsPress('S')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("StrikeDualShot"); }

	// 차지 드라이브
	if (UEngineInput::IsPress('Q')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("Charge"); }

	// 유니콘 스파이크
	if (UEngineInput::IsPress('R')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("Unicorn"); }

	// 레전더리 스피어
	if (UEngineInput::IsPress('G')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("LegendarySpear"); }

	// 하이킥 데몰리션
	{
		if (UEngineInput::IsPress('W')) { PlayerRenderer->ChangeAnimation("HighKick"); }
		if (UEngineInput::IsDown('W')) { AddActorLocation(FVector(0.0f, 200.0f)); }
	}
}

void APlayer::AirUseSkill(float _DeltaTime)
{
	// 레쓰 오브 엔릴
	if (UEngineInput::IsPress('A')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("Wrath"); }

	// 스트라이크 듀얼 샷
	if (UEngineInput::IsPress('S')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("StrikeDualShot"); }

	// 리프 토네이도 
	//if (UEngineInput::IsPress('D')) { bIsSkillUsing = true; }

	// 롤링 어썰트
	if (UEngineInput::IsPress('E')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("Rolling"); bIsZeroGravity = true; }

	// 유니콘 스파이크
	if (UEngineInput::IsPress('R')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("Unicorn"); }

	// 레전더리 스피어
	if (UEngineInput::IsPress('G')) { bIsSkillUsing = true; PlayerRenderer->ChangeAnimation("LegendarySpear"); bIsZeroGravity = true;
	}

	// 하이킥 데몰리션
	{
		if (UEngineInput::IsPress('W')) { PlayerRenderer->ChangeAnimation("HighKick"); bIsZeroGravity = true;}
		if (UEngineInput::IsDown('W')) { AddActorLocation(FVector(0.0f, 200.0f));  }
		
	}
}
