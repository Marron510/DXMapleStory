#pragma once


class MapleInstance
{
public:
	// ������ �Ҹ���
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

