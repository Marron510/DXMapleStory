#pragma once

#include "Icon.h"

class UIconHighKick : public UIcon
{
public:
	// ������ �Ҹ���
	UIconHighKick();
	~UIconHighKick();

	// delete funcion

	UIconHighKick(const UIconHighKick& _Other) = delete;
	UIconHighKick(UIconHighKick&& _Other) noexcept = delete;
	UIconHighKick& operator=(const UIconHighKick& _Other) = delete;
	UIconHighKick& operator=(UIconHighKick&& _Other) noexcept = delete;

	void Tick(float _DeltaTime) override;

	void Render(UEngineCamera* Camera, float _DeltaTime) override;

protected:

private:

};

