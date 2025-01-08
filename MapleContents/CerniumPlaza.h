#pragma once
#include <EngineCore/Actor.h>

class ACerniumPlaza : public AActor
{
public:
	// ������ �Ҹ���
	ACerniumPlaza();
	~ACerniumPlaza();

	// delete funcion

	ACerniumPlaza(const ACerniumPlaza& _Other) = delete;
	ACerniumPlaza(ACerniumPlaza&& _Other) noexcept = delete;
	ACerniumPlaza& operator=(const ACerniumPlaza& _Other) = delete;
	ACerniumPlaza& operator=(ACerniumPlaza&& _Other) noexcept = delete;


	std::shared_ptr<class USpriteRenderer> GetPlaza_BackRender()
	{
		return Plaza_Back;
	}

	std::shared_ptr<class USpriteRenderer> GetPlaza_MidRender()
	{
		return Plaza_Mid;
	}
	
	std::shared_ptr<class USpriteRenderer> GetFlag0Render()
	{
		return Flag0;
	}
	
	std::shared_ptr<class USpriteRenderer> GetFlag1Render()
	{
		return Flag1;
	}
	
	std::shared_ptr<class USpriteRenderer> GetFlag2Render()
	{
		return Flag2;
	}
	
	std::shared_ptr<class USpriteRenderer> GetFlag3Render()
	{
		return Flag3;
	}
	
	std::shared_ptr<class USpriteRenderer> GetFlag4Render()
	{
		return Flag4;
	}

	std::shared_ptr<class USpriteRenderer> GetFlag5Render()
	{
		return Flag5;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	// ����
	std::shared_ptr<class USpriteRenderer> Plaza_Back;
	std::shared_ptr<class USpriteRenderer> Plaza_Mid;
	std::shared_ptr<class USpriteRenderer> Plaza_Front;
	// ���
	std::shared_ptr<class USpriteRenderer> Flag0;
	std::shared_ptr<class USpriteRenderer> Flag1;
	std::shared_ptr<class USpriteRenderer> Flag2;
	std::shared_ptr<class USpriteRenderer> Flag3;
	std::shared_ptr<class USpriteRenderer> Flag4;
	std::shared_ptr<class USpriteRenderer> Flag5;
	
	// ���尣
	std::shared_ptr<class USpriteRenderer> Smithy;

	// ���ǻ���
	std::shared_ptr<class USpriteRenderer> Potion;

	// ���� �ǹ�
	std::shared_ptr<class USpriteRenderer> BuildingLeft_0;
	std::shared_ptr<class USpriteRenderer> BuildingLeft_1;
	std::shared_ptr<class USpriteRenderer> BuildingRight_0;
	std::shared_ptr<class USpriteRenderer> BuildingRight_1;
	
	// Object
	std::shared_ptr<class USpriteRenderer> DawnPriestFlag;
	std::shared_ptr<class USpriteRenderer> FirePriestFlag;
	std::shared_ptr<class USpriteRenderer> Tree_0;
	std::shared_ptr<class USpriteRenderer> Tree_1;
	std::shared_ptr<class USpriteRenderer> FootHold_Left_0;
	std::shared_ptr<class USpriteRenderer> FootHold_Left_1;
	std::shared_ptr<class USpriteRenderer> FootHold_Mid;
	std::shared_ptr<class USpriteRenderer> FootHold_Right;

	std::shared_ptr<class USpriteRenderer> BigTree_Left;
	std::shared_ptr<class USpriteRenderer> BigTree_Right;
	

	


};

