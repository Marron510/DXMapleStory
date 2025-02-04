#pragma once

#include "Icon.h"

class UIconCharge : public UIcon
{
public:
	// ������ �Ҹ���
	UIconCharge();
	~UIconCharge();

	// delete funcion

	UIconCharge(const UIconCharge& _Other) = delete;
	UIconCharge(UIconCharge&& _Other) noexcept = delete;
	UIconCharge& operator=(const UIconCharge& _Other) = delete;
	UIconCharge& operator=(UIconCharge&& _Other) noexcept = delete;

	void Tick(float _DeltaTime) override;

	void Render(UEngineCamera* Camera, float _DeltaTime) override;

protected:

private:

};

