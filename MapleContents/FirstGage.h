#pragma once

#include <EngineCore/Actor.h>

class AFirstGage :public AActor
{
public:
	// ������ �Ҹ���
	AFirstGage();
	~AFirstGage();

	// delete funcion

	AFirstGage(const AFirstGage& _Other) = delete;
	AFirstGage(AFirstGage&& _Other) noexcept = delete;
	AFirstGage& operator=(const AFirstGage& _Other) = delete;
	AFirstGage& operator=(AFirstGage&& _Other) noexcept = delete;


protected:

private:

};

