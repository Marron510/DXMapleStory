#include "PreCompile.h"
#include "WrathOfEnril.h"


AWrathOfEnril::AWrathOfEnril()
{

}

AWrathOfEnril::~AWrathOfEnril()
{

}

void AWrathOfEnril::BeginPlay()
{
	ASkillManager::BeginPlay();
}

void AWrathOfEnril::Tick(float _DeltaTime)
{
	ASkillManager::Tick(_DeltaTime);
}
