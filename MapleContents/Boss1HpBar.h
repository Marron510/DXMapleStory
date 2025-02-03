#pragma once
#include "Bar.h"

//	Ό³Έν:
class UBoss1HpBar :public UBar
{
public:
	UBoss1HpBar();
	virtual ~UBoss1HpBar();
	UBoss1HpBar(const UBoss1HpBar& _Other) = delete;
	UBoss1HpBar(UBoss1HpBar&& _Other) noexcept = delete;
	UBoss1HpBar& operator=(const UBoss1HpBar& _Other) = delete;
	UBoss1HpBar& operator=(UBoss1HpBar&& _Other) noexcept = delete;

	virtual void Tick(float _DeltaTime) override;


protected:

private:
	bool bIsPlayEffect = false;



};

