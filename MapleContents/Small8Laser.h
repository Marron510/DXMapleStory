#pragma once

#include <EngineCore/Actor.h> 


class Small8Laser : public AActor
{
public:
	// 持失切 社瑚切
	Small8Laser();
	~Small8Laser();

	// delete funcion

	Small8Laser(const Small8Laser& _Other) = delete;
	Small8Laser(Small8Laser&& _Other) noexcept = delete;
	Small8Laser& operator=(const Small8Laser& _Other) = delete;
	Small8Laser& operator=(Small8Laser&& _Other) noexcept = delete;


protected:

private:

};

