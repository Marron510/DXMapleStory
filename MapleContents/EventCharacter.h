#pragma once

enum class ECharacterState
{
	Idle,
	Prone,
	Walk,
	IdleJump,
	WalkJump,
	UpJump,
	WalkUpJump,
	DoubleJump,
	Air,
	Death
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

