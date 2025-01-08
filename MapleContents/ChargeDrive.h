#pragma once
class ChargeDrive
{
public:
	// 持失切 社瑚切
	ChargeDrive();
	~ChargeDrive();

	// delete funcion

	ChargeDrive(const ChargeDrive& _Other) = delete;
	ChargeDrive(ChargeDrive&& _Other) noexcept = delete;
	ChargeDrive& operator=(const ChargeDrive& _Other) = delete;
	ChargeDrive& operator=(ChargeDrive&& _Other) noexcept = delete;


protected:

private:

};

