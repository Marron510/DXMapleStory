#include "PreCompile.h"
#include "SkillManager.h"

#include <EngineCore/SpriteRenderer.h>

ASkillManager::ASkillManager()
{
	
	SkillRender = CreateDefaultSubObject<USpriteRenderer>();
	RootComponent = SkillRender;
}

ASkillManager::~ASkillManager()
{

}

void ASkillManager::BeginPlay()
{
	AActor::BeginPlay();
}

void ASkillManager::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

