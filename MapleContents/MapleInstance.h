#pragma once


class MapleInstance
{
public:
	// 持失切 社瑚切
	MapleInstance();
	~MapleInstance();

	// delete funcion

	MapleInstance(const MapleInstance& _Other) = delete;
	MapleInstance(MapleInstance&& _Other) noexcept = delete;
	MapleInstance& operator=(const MapleInstance& _Other) = delete;
	MapleInstance& operator=(MapleInstance&& _Other) noexcept = delete;


protected:

private:

};

