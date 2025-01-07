#pragma once
#include <EngineCore/Actor.h>

enum class ESkillState
{
	WrathOfEnril,
	None,
};

class ASkillManager : public AActor
{
public:
	// 持失切 社瑚切
	ASkillManager();
	~ASkillManager();

	// delete funcion

	ASkillManager(const ASkillManager& _Other) = delete;
	ASkillManager(ASkillManager&& _Other) noexcept = delete;
	ASkillManager& operator=(const ASkillManager& _Other) = delete;
	ASkillManager& operator=(ASkillManager&& _Other) noexcept = delete;

	
	virtual void BeginPlay();
	virtual void Tick(float _DeltaTime);

protected:
	std::shared_ptr<class UTimeEventComponent> TimeEventComponent;
	std::shared_ptr<class USpriteRenderer> SkillRender = nullptr;
private:

};

