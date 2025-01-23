#pragma once

enum class ECharacterState
{
	Idle,
	Prone,
	Hit,
	Walk,
	IdleJump,
	WalkJump,
	UpJump,
	WalkUpJump,
	DoubleJump,
	LeafTornado,
	LegendarySpear,
	WrathOfEnril,
	Air,
	Death
};

enum class ESerenState
{
	Idle,
	Walk,
	Rush,
	Sting,
	SwordAura,
	SmallLaser,
	Die,
	None
};
class AEventCharacter
{
public:
	// ������ �Ҹ���
	AEventCharacter();
	~AEventCharacter();

	// delete funcion

	AEventCharacter(const AEventCharacter& _Other) = delete;
	AEventCharacter(AEventCharacter&& _Other) noexcept = delete;
	AEventCharacter& operator=(const AEventCharacter& _Other) = delete;
	AEventCharacter& operator=(AEventCharacter&& _Other) noexcept = delete;


protected:

private:

};

