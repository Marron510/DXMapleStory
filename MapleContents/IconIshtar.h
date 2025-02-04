#pragma once

#include "Icon.h"

class UIconIshtar : public UIcon
{
public:
	// ������ �Ҹ���
	UIconIshtar();
	~UIconIshtar();

	// delete funcion

	UIconIshtar(const UIconIshtar& _Other) = delete;
	UIconIshtar(UIconIshtar&& _Other) noexcept = delete;
	UIconIshtar& operator=(const UIconIshtar& _Other) = delete;
	UIconIshtar& operator=(UIconIshtar&& _Other) noexcept = delete;


	void Tick(float _DeltaTime) override;

	void Render(UEngineCamera* Camera, float _DeltaTime) override;
protected:

private:

};

