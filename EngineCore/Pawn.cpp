#include "PreCompile.h"
#include "Pawn.h"

#include <EnginePlatform/EngineInput.h>

APawn::APawn()
{
}

APawn::~APawn()
{
}

void APawn::BeginPlay()
{
	AActor::BeginPlay();
}

void APawn::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

}

