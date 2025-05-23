#pragma once
#include "SceneComponent.h"
#include "EngineSprite.h"
#include "RenderUnit.h"
#include <set>

// 설명 : 어떤 랜더링이든 할수 잇는 구조로 만들겠다.
// 랜더링이란 랜더러만 하는게 아닙니다. 3D
class UCollision : public USceneComponent
{
public:
	// constrcuter destructer
	ENGINEAPI UCollision();
	ENGINEAPI ~UCollision();

	// delete Function
	UCollision(const UCollision& _Other) = delete;
	UCollision(UCollision&& _Other) noexcept = delete;
	UCollision& operator=(const UCollision& _Other) = delete;
	UCollision& operator=(UCollision&& _Other) noexcept = delete;

	ENGINEAPI void SetCollisionProfileName(std::string_view _ProfileName);
	ENGINEAPI void BeginPlay() override;
	ENGINEAPI void DebugRender(UEngineCamera* _Camera, float _DeltaTime);

	std::string GetCollisionProfileName()
	{
		return ProfileName;
	}

	bool IsColliding()
	{
		if (CollisionCheckSet.empty())
		{
			return false;
		}
		else 
		{
			return true;
		}
	}


	void SetRadius(float _Value);

	void Release();

	ENGINEAPI bool CollisionCheck(std::string_view _OtherName, std::vector<UCollision*>& _Vector);

	ENGINEAPI bool CollisionCheck(std::string_view _OtherName, FVector _NextPos, std::vector<UCollision*>& _Vector);

	void SetCollisionType(ECollisionType _Type)
	{
		CollisionType = _Type;
	}

	void CollisionEventCheck(std::shared_ptr<UCollision> _Other);

	ENGINEAPI void SetCollisionEnter(std::function<void(UCollision*, UCollision*)> _Function);
	ENGINEAPI void SetCollisionStay(std::function<void(UCollision*, UCollision*)> _Function);
	ENGINEAPI void SetCollisionEnd(std::function<void(UCollision*, UCollision*)> _Function);

	bool IsEvent()
	{
		return Enter != nullptr || Stay != nullptr || End != nullptr;
	}
	ENGINEAPI void SetColColor(FVector _Color);


private:
	ECollisionType CollisionType = ECollisionType::OBB2D;
	// 내가 충돌한 상대를 기억하는 용도의 set
	std::set<UCollision*> CollisionCheckSet;

	// 나는 Monster 그룹이다.
	std::string ProfileName = "NONE";

	// 최초 충돌
	std::function<void(UCollision*, UCollision*)> Enter;

	// 지속 충돌
	std::function<void(UCollision*, UCollision*)> Stay;

	// 충돌 끝.
	std::function<void(UCollision*, UCollision*)> End;

	FVector Color = FVector::ZERO;

	bool bHasRealColor = false;
	FVector RealColor = FVector::ZERO;
};

