#include "PreCompile.h"
#include "MapleContentsCore.h"

#include <EngineCore/Level.h>
#include <EngineCore/EngineTexture.h>
#include <EngineCore/EngineSprite.h>

#include "TitleGameMode.h"
#include "CerniumPlazaMode.h"
#include "MainHallMode.h"
#include "TheBoundaryOfTheWorld.h"

CreateContentsCoreDefine(UMapleContentsCore);

UMapleContentsCore::UMapleContentsCore()
{

}

UMapleContentsCore::~UMapleContentsCore()
{

}


void UMapleContentsCore::EngineStart(UEngineInitData& _Data)
{

	_Data.WindowPos = { 100, 100 };
	_Data.WindowSize = { 1366, 768 };


	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("MapleResources"))
		{
			MSGASSERT("���ҽ� ������ ã�� ���߽��ϴ�.");
			return;
		}
		Dir.Append("Image");
		std::vector<UEngineFile> ImageFiles = Dir.GetAllFile(true, { ".PNG", ".BMP", ".JPG" });
		for (size_t i = 0; i < ImageFiles.size(); i++)
		{
			std::string FilePath = ImageFiles[i].GetPathToString();
			UEngineTexture::Load(FilePath);
		}
	}

	// �÷��̾�
	UEngineSprite::CreateSpriteToMeta("Idle.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Walk.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Leaf_Tornado.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Rolling.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Jump.png", ".sdata");


	// �����Ͽ� �̹���
#pragma region 
	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("MapleResources"))
		{
			MSGASSERT("���ҽ� ������ ã�� ���߽��ϴ�.");
			return;
		}
		Dir.Append("Image/Cernium");

		UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
	}

	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("MapleResources"))
		{
			MSGASSERT("���ҽ� ������ ã�� ���߽��ϴ�.");
			return;
		}
		Dir.Append("Image");
		Dir.Append("Cernium/Smithy");

		UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
	}

	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("MapleResources"))
		{
			MSGASSERT("���ҽ� ������ ã�� ���߽��ϴ�.");
			return;
		}
		Dir.Append("Image");
		Dir.Append("Cernium/Potion");

		UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
	}

	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("MapleResources"))
		{
			MSGASSERT("���ҽ� ������ ã�� ���߽��ϴ�.");
			return;
		}
		Dir.Append("Image");
		Dir.Append("Cernium/DawnPriest");

		UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
	}

	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("MapleResources"))
		{
			MSGASSERT("���ҽ� ������ ã�� ���߽��ϴ�.");
			return;
		}
		Dir.Append("Image");
		Dir.Append("Cernium/FirePriest");

		UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
	}

	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("MapleResources"))
		{
			MSGASSERT("���ҽ� ������ ã�� ���߽��ϴ�.");
			return;
		}
		Dir.Append("Image");
		Dir.Append("Cernium/Shorn");

		UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
	}

	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("MapleResources"))
		{
			MSGASSERT("���ҽ� ������ ã�� ���߽��ϴ�.");
			return;
		}
		Dir.Append("Image");
		Dir.Append("Cernium/Shirine");

		UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
	}

	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("MapleResources"))
		{
			MSGASSERT("���ҽ� ������ ã�� ���߽��ϴ�.");
			return;
		}
		Dir.Append("Image");
		Dir.Append("Cernium/Hate");

		UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
	}
	
	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("MapleResources"))
		{
			MSGASSERT("���ҽ� ������ ã�� ���߽��ϴ�.");
			return;
		}
		Dir.Append("Image");
		Dir.Append("Cernium/OldMan");

		UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
	}

	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("MapleResources"))
		{
			MSGASSERT("���ҽ� ������ ã�� ���߽��ϴ�.");
			return;
		}
		Dir.Append("Image");
		Dir.Append("Cernium/Joy");

		UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
	}

	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("MapleResources"))
		{
			MSGASSERT("���ҽ� ������ ã�� ���߽��ϴ�.");
			return;
		}
		Dir.Append("Image");
		Dir.Append("Cernium/Manyu");

		UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
	}

	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("MapleResources"))
		{
			MSGASSERT("���ҽ� ������ ã�� ���߽��ϴ�.");
			return;
		}
		Dir.Append("Image");
		Dir.Append("Cernium/Duglas");

		UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
	}


	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("MapleResources"))
		{
			MSGASSERT("���ҽ� ������ ã�� ���߽��ϴ�.");
			return;
		}
		Dir.Append("Image");
		Dir.Append("Cernium/Elbis");

		UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
	}

	UEngineSprite::CreateSpriteToMeta("Flag.png", ".sdata");

#pragma endregion
	// ���� �� �̹���
	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("MapleResources"))
		{
			MSGASSERT("���ҽ� ������ ã�� ���߽��ϴ�.");
			return;
		}
		Dir.Append("Image");
		Dir.Append("Phase1/MainHall");

		UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
	}

	// ���� �� �̹���
	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("MapleResources"))
		{
			MSGASSERT("���ҽ� ������ ã�� ���߽��ϴ�.");
			return;
		}
		Dir.Append("Image");
		Dir.Append("Phase2");
		Dir.Append("Phase2_MapImage/01_NoonImage");

		UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
	}

	// ���� �� �̹���
	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("MapleResources"))
		{
			MSGASSERT("���ҽ� ������ ã�� ���߽��ϴ�.");
			return;
		}
		Dir.Append("Image");
		Dir.Append("Phase2");
		Dir.Append("Phase2_MapImage/02_SunSetImage");

		UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
	}

	// ���� �� �̹���
	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("MapleResources"))
		{
			MSGASSERT("���ҽ� ������ ã�� ���߽��ϴ�.");
			return;
		}
		Dir.Append("Image");
		Dir.Append("Phase2");
		Dir.Append("Phase2_MapImage/03_MidnightImage");

		UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
	}

	// ���� �� �̹���
	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("MapleResources"))
		{
			MSGASSERT("���ҽ� ������ ã�� ���߽��ϴ�.");
			return;
		}
		Dir.Append("Image");
		Dir.Append("Phase2");
		Dir.Append("Phase2_MapImage/04_DawnImage");

		UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
	}


	// ���� �̹���

	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("MapleResources"))
		{
			MSGASSERT("���ҽ� ������ ã�� ���߽��ϴ�.");
			return;
		}
		Dir.Append("Image");
		Dir.Append("Phase2");
		Dir.Append("01_SerenNoon/NoonSerenStand");

		UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
	}

	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("MapleResources"))
		{
			MSGASSERT("���ҽ� ������ ã�� ���߽��ϴ�.");
			return;
		}
		Dir.Append("Image");
		Dir.Append("Phase2");
		Dir.Append("01_SerenNoon/NoonSerenRush");

		UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
	}

	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("MapleResources"))
		{
			MSGASSERT("���ҽ� ������ ã�� ���߽��ϴ�.");
			return;
		}
		Dir.Append("Image");
		Dir.Append("Phase2");
		Dir.Append("01_SerenNoon/NoonSerenSting");

		UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
	}

	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("MapleResources"))
		{
			MSGASSERT("���ҽ� ������ ã�� ���߽��ϴ�.");
			return;
		}
		Dir.Append("Image");
		Dir.Append("Phase2");
		Dir.Append("01_SerenNoon/NoonSerenEightLaser");

		UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
	}

	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("MapleResources"))
		{
			MSGASSERT("���ҽ� ������ ã�� ���߽��ϴ�.");
			return;
		}
		Dir.Append("Image");
		Dir.Append("Phase2");
		Dir.Append("01_SerenNoon/NoonSerenStunLaser");

		UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
	}

	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("MapleResources"))
		{
			MSGASSERT("���ҽ� ������ ã�� ���߽��ϴ�.");
			return;
		}
		Dir.Append("Image");
		Dir.Append("Phase2");
		Dir.Append("01_SerenNoon/NoonSerenHit");

		UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
	}

	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("MapleResources"))
		{
			MSGASSERT("���ҽ� ������ ã�� ���߽��ϴ�.");
			return;
		}
		Dir.Append("Image");
		Dir.Append("Phase2");
		Dir.Append("01_SerenNoon/NoonSerenDie");

		UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
	}





	// ���ΰ� APawn ��� �ޱ�
	UEngineCore::CreateLevel<ATitleGameMode, APawn>("Title");
	UEngineCore::CreateLevel<ACerniumPlazaMode, APawn>("Plaza");
	UEngineCore::CreateLevel<AMainHallMode, APawn>("MainHall");
	UEngineCore::CreateLevel<ATheBoundaryOfTheWorld, APawn>("TheBoundaryOfTheWorld");

	UEngineCore::OpenLevel("TheBoundaryOfTheWorld");
}

void UMapleContentsCore::EngineTick(float _DeltaTime)
{
	IContentsCore::EngineTick(_DeltaTime);
}

void UMapleContentsCore::EngineEnd()
{
	IContentsCore::EngineEnd();
}
