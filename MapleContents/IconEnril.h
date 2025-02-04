#pragma once

#include "Icon.h"

class UIconEnril : public UIcon
{
public:
	// ������ �Ҹ���
	UIconEnril();
	~UIconEnril();

	// delete funcion

	UIconEnril(const UIconEnril& _Other) = delete;
	UIconEnril(UIconEnril&& _Other) noexcept = delete;
	UIconEnril& operator=(const UIconEnril& _Other) = delete;
	UIconEnril& operator=(UIconEnril&& _Other) noexcept = delete;

	void Tick(float _DeltaTime) override;

	void Render(UEngineCamera* Camera, float _DeltaTime) override;

protected:

private:

};

