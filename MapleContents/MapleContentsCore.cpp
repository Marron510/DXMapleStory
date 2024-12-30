#include "PreCompile.h"
#include "MapleContentsCore.h"

#include <EngineCore/Level.h>
#include <EngineCore/EngineTexture.h>
#include <EngineCore/EngineSprite.h>

#include "TitleGameMode.h"
#include "CerniumPlazaMode.h"

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
			MSGASSERT("리소스 폴더를 찾지 못했습니다.");
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

	UEngineSprite::CreateSpriteToMeta("Idle.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Walk.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Leaf_Tornado.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Rolling.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Jump.png", ".sdata");
	
	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("MapleResources"))
		{
			MSGASSERT("리소스 폴더를 찾지 못했습니다.");
			return;
		}
		Dir.Append("Image/Cernium");

		UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
	}

	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("MapleResources"))
		{
			MSGASSERT("리소스 폴더를 찾지 못했습니다.");
			return;
		}
		Dir.Append("Image/Smithy");

		UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
	}

	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("MapleResources"))
		{
			MSGASSERT("리소스 폴더를 찾지 못했습니다.");
			return;
		}
		Dir.Append("Image/Potion");

		UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
	}

	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("MapleResources"))
		{
			MSGASSERT("리소스 폴더를 찾지 못했습니다.");
			return;
		}
		Dir.Append("Image/DawnPriest");

		UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
	}


	// 주인공 APawn 상속 받기
	UEngineCore::CreateLevel<ATitleGameMode, APawn>("Title");
	UEngineCore::CreateLevel<ACerniumPlazaMode, APawn>("Plaza");
	UEngineCore::OpenLevel("Plaza");
}

void UMapleContentsCore::EngineTick(float _DeltaTime)
{
	IContentsCore::EngineTick(_DeltaTime);
}

void UMapleContentsCore::EngineEnd()
{
	IContentsCore::EngineEnd();
}