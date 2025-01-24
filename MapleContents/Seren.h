#pragma once
#include <EngineCore/Actor.h>
#include <EngineBase/FSMStateManager.h>
#include <EngineBase/EngineRandom.h>

class ASeren : public AActor
{
public:
	ASeren();
	~ASeren();

	// delete funcion

	ASeren(const ASeren& _Other) = delete;
	ASeren(ASeren&& _Other) noexcept = delete;
	ASeren& operator=(const ASeren& _Other) = delete;
	ASeren& operator=(ASeren&& _Other) noexcept = delete;

	void StateInit();
	
	// ����
	void Idle(float _DeltaTime);
	void Walk(float _DeltaTime);
	void Rush(float _DeltaTime);
	void Sting(float _DeltaTime);
	void SwordAura(float _DeltaTime);
	void SmallLaser(float _DeltaTime);

	void Die(float _DeltaTime);
	
	
	// ������

	void SmallAtomInit();
	void DropAtomSetting(float _DeltaTime);
	void DropAtom1(float _DeltaTime);
	void DropAtom2(float _DeltaTime);
	void DropAtom3(float _DeltaTime);
	void DropAtom4(float _DeltaTime);
	void DropAtom5(float _DeltaTime);
	void DropAtom6(float _DeltaTime);
	void DropAtom7(float _DeltaTime);


	void FloorExplosionInit();
	void FloorExplosionSetting(float _DeltaTime);
	void FloorExplosion1(float _DeltaTime);
	void FloorExplosion2(float _DeltaTime);
	void FloorExplosion3(float _DeltaTime);
	void FloorExplosion4(float _DeltaTime);
	void FloorExplosion5(float _DeltaTime);
	void FloorExplosion6(float _DeltaTime);
	void FloorExplosion7(float _DeltaTime);
	void FloorExplosionCheck(float _DeltaTime);

	std::shared_ptr<class USerenCollision> GetSerenCollision()
	{
		return Collision;
	}
	std::shared_ptr<class USpriteRenderer> GetSerenRender()
	{
		return SerenRender;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	// �÷��̾� -> ������ �÷��̾� �˾ƾ���
	class APlayer* Player = nullptr;
	FVector CurPlayerLocation = FVector::ZERO;

	// ����
	std::shared_ptr<class USpriteRenderer> SerenRender;

	// ���� �ݸ���
	std::shared_ptr<class USerenCollision> Collision;
	std::shared_ptr<class UCollision> CheckCollision;
	std::shared_ptr<class UCollision> OutRangeCollision;

	std::shared_ptr<class UCollision> StingCollision;
	std::shared_ptr<class UCollision> RushCollision;
	
	// ���� ��ų 
	// ������
	std::shared_ptr<class ASmall8Laser> Small8Laser;
	
	// �ٴ� ��ų
	std::shared_ptr<class AFloorSkill> FloorSkill1;
	std::shared_ptr<class AFloorSkill> FloorSkill2;
	std::shared_ptr<class AFloorSkill> FloorSkill3;
	std::shared_ptr<class AFloorSkill> FloorSkill4;
	std::shared_ptr<class AFloorSkill> FloorSkill5;
	std::shared_ptr<class AFloorSkill> FloorSkill6;
	std::shared_ptr<class AFloorSkill> FloorSkill7;

	// õ�� ��ų
	std::shared_ptr<class ASmallAtom> SmallAtom1;
	std::shared_ptr<class ASmallAtom> SmallAtom2;
	std::shared_ptr<class ASmallAtom> SmallAtom3;
	std::shared_ptr<class ASmallAtom> SmallAtom4;
	std::shared_ptr<class ASmallAtom> SmallAtom5;
	std::shared_ptr<class ASmallAtom> SmallAtom6;
	std::shared_ptr<class ASmallAtom> SmallAtom7;



	UFSMStateManager SerenFSM;

	// �ٰŸ� ���Ÿ� üũ

	bool bIsInRange = false;

	// ���� üũ
	bool bIsIdle= true;
	bool bIsSting = false;
	bool bIsRush = false;
	bool bIsSwordAura = false;
	bool bIsSmalllaser= false;
	bool bIsDead = false;
	bool bIsAuraDir = false;
	bool bIsAuraLeft = false;
	bool bIsAuraCheck = false;

	// ������ ���� üũ
	bool bIsExplosion1 = false;
	bool bIsExplosion2 = false;
	bool bIsExplosion3 = false;
	bool bIsExplosion4 = false;
	bool bIsExplosion5 = false;
	bool bIsExplosion6 = false;
	bool bIsExplosion7 = false;


	// �÷��̾� ��ġ - ���� ��ġ
	FVector DifferentLocation = FVector::ZERO;

	void SerenDeathCheck();
	
	// �� ���� �� X��ǥ 
	float MapstartX = 1200.0f;
	float MapEndX = 3500.0f;

	// ���� ��ų Ƚ��
	int StingCount = 0; // �ִ� 2ȸ

	// ���� �ݸ��� �Ÿ�

	float OutRangeDistance = 2000.0f;
	float InRangeDistance = 800.0f;

	// ���� �Ÿ�
	float RushDistance = 645.0f;

	// ���� ��ų ������
	float StingDamage = 10.0f;
	float RushDamage = 10.0f;
	float AuraDamage = 30.0f;


	// ��Ÿ��
	float SkillCoolTime = 0.0f;
	float AuraCoolTime = 1.0f;
	float StimgCoolTime = 1.0f;
	float RushCoolTime = 3.0f;
	
	// ������ ��Ÿ��
	float Floor1CoolTime = 10.0f;
	float Floor2CoolTime = 8.0f;
	float Floor3CoolTime = 14.0f;
	float Floor4CoolTime = 19.0f;
	float Floor5CoolTime = 12.0f;
	float Floor6CoolTime = 7.0f;
	float Floor7CoolTime = 5.0f;

	class UEngineRandom ExplosionRandom1;
	class UEngineRandom ExplosionRandom2;
	class UEngineRandom ExplosionRandom3;
	class UEngineRandom ExplosionRandom4;
	class UEngineRandom ExplosionRandom5;
	class UEngineRandom ExplosionRandom6;
	class UEngineRandom ExplosionRandom7;

	class UEngineRandom SmallAtomRandom1;
	class UEngineRandom SmallAtomRandom2;
	class UEngineRandom SmallAtomRandom3;
	class UEngineRandom SmallAtomRandom4;
	class UEngineRandom SmallAtomRandom5;
	class UEngineRandom SmallAtomRandom6;
	class UEngineRandom SmallAtomRandom7;

	class UEngineRandom SmallAtomLocationRandom1;
	class UEngineRandom SmallAtomLocationRandom2;
	class UEngineRandom SmallAtomLocationRandom3;
	class UEngineRandom SmallAtomLocationRandom4;
	class UEngineRandom SmallAtomLocationRandom5;
	class UEngineRandom SmallAtomLocationRandom6;
	class UEngineRandom SmallAtomLocationRandom7;

	float SmallAtom1CoolTime = 15.0f;
	float SmallAtom2CoolTime = 20.0f;
	float SmallAtom3CoolTime = 12.0f;
	float SmallAtom4CoolTime = 10.0f;
	float SmallAtom5CoolTime = 7.0f;
	float SmallAtom6CoolTime = 16.0f;
	float SmallAtom7CoolTime = 22.0f;

	bool bIsAtom1Init = false;
	bool bIsAtom2Init = false;
	bool bIsAtom3Init = false;
	bool bIsAtom4Init = false;
	bool bIsAtom5Init = false;
	bool bIsAtom6Init = false;
	bool bIsAtom7Init = false;

	float AuraSpeed = 160.0f;
	bool bIsAuraSpawn = false;

};

