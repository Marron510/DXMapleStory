#pragma once


struct FPlayerStatus
{
	std::string Name = "";

	int Level = 1;

	bool bIsFillable = true;
	bool IsFillable()
	{
		return bIsFillable;
	}
	void SetFillable(bool _Value)
	{
		bIsFillable = _Value;
	}
	void SetFillTrue()
	{
		bIsFillable = true;
	}
	void SetFillFalse()
	{
		bIsFillable = false;
	}


	float MaxHp = 55000;
	float PrevHp = 55000;
	float CurHp = 55000;
	bool bIsHpChange = false;
	float CurHpPercent = 1.0f;
	float PrevHpPercent = 1.0f;

	void FillMaxHp()
	{
		if (!bIsFillable) { return; }
		PrevHp = CurHp;
		PrevHpPercent = CurHp / MaxHp;
		CurHp = MaxHp;
		CurHpPercent = CurHp / MaxHp;
		bIsHpChange = true;
	}

	float MaxMp = 20000;
	float PrevMp = 20000;
	float CurMp = 20000;
	bool bIsMpChange = false;
	float CurMpPercent = 1.0f;
	float PrevMpPercent = 1.0f;

	void FillMaxMp()
	{
		if (!bIsFillable) { return; }
		PrevMp = CurMp;
		PrevMpPercent = CurMp / MaxMp;
		CurMp = MaxMp;
		CurMpPercent = CurMp / MaxMp;
		bIsMpChange = true;
	}

	void FillMaxHpMp()
	{
		FillMaxHp();
		FillMaxMp();
	}

	void UseMp(float _Mp)
	{
		PrevMp = CurMp;
		PrevMpPercent = CurMp / MaxMp;
		CurMp -= _Mp;
		if (CurMp < 0.0f)
		{
			CurMp = 0.0f;
		}
		CurMpPercent = CurMp / MaxMp;
		bIsMpChange = true;
	}

	void TakeDamage(float _Damage)
	{
		PrevHp = CurHp;
		PrevHpPercent = CurHp / MaxHp;
		CurHp -= _Damage;
		if (CurHp < 0.0f)
		{
			CurHp = 0.0f;
		}
		CurHpPercent = CurHp / MaxHp;
		bIsHpChange = true;
	}
};