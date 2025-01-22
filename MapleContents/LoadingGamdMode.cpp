#include "PreCompile.h"
#include "LoadingGamdMode.h"

#include <EngineCore/GameMode.h>
#include <EngineCore/CameraActor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineGUIWindow.h>
#include <EngineCore/EngineGUI.h>
#include <EngineCore/imgui.h>
#include <EngineCore/EngineCamera.h>
#include <EngineCore/EngineCore.h>

#include "TitleGameMode.h"
#include "CerniumPlazaMode.h"
#include "MainHallMode.h"
#include "TheBoundaryOfTheWorld.h"

#include "TitleHUD.h"
#include "CerniumHUD.h"
#include "SerenHUD.h"

#include "Player.h"
#include "MapleInstance.h"


ALoadingGamdMode::ALoadingGamdMode()
{

}

ALoadingGamdMode::~ALoadingGamdMode()
{

}

void ALoadingGamdMode::Tick(float _DeltaTime)
{
	// 부모 호출
	AActor::Tick(_DeltaTime);

	if (true == ThreadLoadingInit)
	{
		if (0 == LoadingCount)
		{
			ThreadLoadingEnd = true;
		}


		if (true == ThreadLoadingEnd)
		{

			// 플레이어
			UEngineSprite::CreateSpriteToMeta("Idle.png", ".sdata");
			UEngineSprite::CreateSpriteToMeta("Walk.png", ".sdata");
			UEngineSprite::CreateSpriteToMeta("Hit.png", ".sdata");
			UEngineSprite::CreateSpriteToMeta("LeafTornado.png", ".sdata");
			UEngineSprite::CreateSpriteToMeta("Rolling.png", ".sdata");
			UEngineSprite::CreateSpriteToMeta("StrikeDualShot.png", ".sdata");
			UEngineSprite::CreateSpriteToMeta("Jump.png", ".sdata");
			UEngineSprite::CreateSpriteToMeta("Charge.png", ".sdata");
			UEngineSprite::CreateSpriteToMeta("Wrath.png", ".sdata");
			UEngineSprite::CreateSpriteToMeta("Unicorn.png", ".sdata");
			UEngineSprite::CreateSpriteToMeta("LegendarySpear.png", ".sdata");
			UEngineSprite::CreateSpriteToMeta("Prone.png", ".sdata");

			//플레이어 스킬

			{
				UEngineDirectory Dir;
				if (false == Dir.MoveParentToDirectory("MapleResources"))
				{
					MSGASSERT("리소스 폴더를 찾지 못했습니다.");
					return;
				}
				Dir.Append("Image");
				Dir.Append("Skill/WrathOfEnril");

				UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
			}

			{
				UEngineDirectory Dir;
				if (false == Dir.MoveParentToDirectory("MapleResources"))
				{
					MSGASSERT("리소스 폴더를 찾지 못했습니다.");
					return;
				}
				Dir.Append("Image");
				Dir.Append("Skill/LeafTornadoUp");

				UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
			}


			{
				UEngineDirectory Dir;
				if (false == Dir.MoveParentToDirectory("MapleResources"))
				{
					MSGASSERT("리소스 폴더를 찾지 못했습니다.");
					return;
				}
				Dir.Append("Image");
				Dir.Append("Skill/LeafTornadoDown");

				UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
			}

			{
				UEngineDirectory Dir;
				if (false == Dir.MoveParentToDirectory("MapleResources"))
				{
					MSGASSERT("리소스 폴더를 찾지 못했습니다.");
					return;
				}
				Dir.Append("Image");
				Dir.Append("Skill/RollingMoonSult");

				UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
			}

			{
				UEngineDirectory Dir;
				if (false == Dir.MoveParentToDirectory("MapleResources"))
				{
					MSGASSERT("리소스 폴더를 찾지 못했습니다.");
					return;
				}
				Dir.Append("Image");
				Dir.Append("Skill/StrikeDualShot");

				UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
			}

			{
				UEngineDirectory Dir;
				if (false == Dir.MoveParentToDirectory("MapleResources"))
				{
					MSGASSERT("리소스 폴더를 찾지 못했습니다.");
					return;
				}
				Dir.Append("Image");
				Dir.Append("Skill/StrikeDualShot_Back");

				UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
			}

			{
				UEngineDirectory Dir;
				if (false == Dir.MoveParentToDirectory("MapleResources"))
				{
					MSGASSERT("리소스 폴더를 찾지 못했습니다.");
					return;
				}
				Dir.Append("Image");
				Dir.Append("Skill/ChargeDrive");

				UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
			}

			{
				UEngineDirectory Dir;
				if (false == Dir.MoveParentToDirectory("MapleResources"))
				{
					MSGASSERT("리소스 폴더를 찾지 못했습니다.");
					return;
				}
				Dir.Append("Image");
				Dir.Append("Skill/HighKick");

				UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
			}

			{
				UEngineDirectory Dir;
				if (false == Dir.MoveParentToDirectory("MapleResources"))
				{
					MSGASSERT("리소스 폴더를 찾지 못했습니다.");
					return;
				}
				Dir.Append("Image");
				Dir.Append("Skill/UnicornSpike");

				UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
			}

			{
				UEngineDirectory Dir;
				if (false == Dir.MoveParentToDirectory("MapleResources"))
				{
					MSGASSERT("리소스 폴더를 찾지 못했습니다.");
					return;
				}
				Dir.Append("Image");
				Dir.Append("Skill/LegendarySpearFront");

				UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
			}

			{
				UEngineDirectory Dir;
				if (false == Dir.MoveParentToDirectory("MapleResources"))
				{
					MSGASSERT("리소스 폴더를 찾지 못했습니다.");
					return;
				}
				Dir.Append("Image");
				Dir.Append("Skill/LegendarySpearMid");

				UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
			}

			{
				UEngineDirectory Dir;
				if (false == Dir.MoveParentToDirectory("MapleResources"))
				{
					MSGASSERT("리소스 폴더를 찾지 못했습니다.");
					return;
				}
				Dir.Append("Image");
				Dir.Append("Skill/RoyalKnightsStart");

				UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
			}

			{
				UEngineDirectory Dir;
				if (false == Dir.MoveParentToDirectory("MapleResources"))
				{
					MSGASSERT("리소스 폴더를 찾지 못했습니다.");
					return;
				}
				Dir.Append("Image");
				Dir.Append("Skill/RoyalKnightsLoop");

				UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
			}

			{
				UEngineDirectory Dir;
				if (false == Dir.MoveParentToDirectory("MapleResources"))
				{
					MSGASSERT("리소스 폴더를 찾지 못했습니다.");
					return;
				}
				Dir.Append("Image");
				Dir.Append("Skill/RoyalKnightsEnd");

				UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
			}

			// 세르니움 이미지
#pragma region 
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
				Dir.Append("Image");
				Dir.Append("Cernium/Smithy");

				UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
			}

			{
				UEngineDirectory Dir;
				if (false == Dir.MoveParentToDirectory("MapleResources"))
				{
					MSGASSERT("리소스 폴더를 찾지 못했습니다.");
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
					MSGASSERT("리소스 폴더를 찾지 못했습니다.");
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
					MSGASSERT("리소스 폴더를 찾지 못했습니다.");
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
					MSGASSERT("리소스 폴더를 찾지 못했습니다.");
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
					MSGASSERT("리소스 폴더를 찾지 못했습니다.");
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
					MSGASSERT("리소스 폴더를 찾지 못했습니다.");
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
					MSGASSERT("리소스 폴더를 찾지 못했습니다.");
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
					MSGASSERT("리소스 폴더를 찾지 못했습니다.");
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
					MSGASSERT("리소스 폴더를 찾지 못했습니다.");
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
					MSGASSERT("리소스 폴더를 찾지 못했습니다.");
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
					MSGASSERT("리소스 폴더를 찾지 못했습니다.");
					return;
				}
				Dir.Append("Image");
				Dir.Append("Cernium/Elbis");

				UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
			}

			UEngineSprite::CreateSpriteToMeta("Flag.png", ".sdata");


#pragma endregion

				// 보스 맵 이미지
			#pragma region
				{
					UEngineDirectory Dir;
					if (false == Dir.MoveParentToDirectory("MapleResources"))
					{
						MSGASSERT("리소스 폴더를 찾지 못했습니다.");
						return;
					}
					Dir.Append("Image");
					Dir.Append("Phase1/MainHall");
			
					UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
				}
			
				// 정오 맵 이미지
				{
					UEngineDirectory Dir;
					if (false == Dir.MoveParentToDirectory("MapleResources"))
					{
						MSGASSERT("리소스 폴더를 찾지 못했습니다.");
						return;
					}
					Dir.Append("Image");
					Dir.Append("Phase2");
					Dir.Append("Phase2_MapImage/01_NoonImage");
			
					UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
				}
			
				// 석양 맵 이미지
				{
					UEngineDirectory Dir;
					if (false == Dir.MoveParentToDirectory("MapleResources"))
					{
						MSGASSERT("리소스 폴더를 찾지 못했습니다.");
						return;
					}
					Dir.Append("Image");
					Dir.Append("Phase2");
					Dir.Append("Phase2_MapImage/02_SunSetImage");
			
					UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
				}
			
				// 자정 맵 이미지
				{
					UEngineDirectory Dir;
					if (false == Dir.MoveParentToDirectory("MapleResources"))
					{
						MSGASSERT("리소스 폴더를 찾지 못했습니다.");
						return;
					}
					Dir.Append("Image");
					Dir.Append("Phase2");
					Dir.Append("Phase2_MapImage/03_MidnightImage");
			
					UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
				}
			
				// 여명 맵 이미지
				{
					UEngineDirectory Dir;
					if (false == Dir.MoveParentToDirectory("MapleResources"))
					{
						MSGASSERT("리소스 폴더를 찾지 못했습니다.");
						return;
					}
					Dir.Append("Image");
					Dir.Append("Phase2");
					Dir.Append("Phase2_MapImage/04_DawnImage");
			
					UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
				}
			
			// 세렌 이미지
			// 세렌 정오
#pragma region
			{
				UEngineDirectory Dir;
				if (false == Dir.MoveParentToDirectory("MapleResources"))
				{
					MSGASSERT("리소스 폴더를 찾지 못했습니다.");
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
					MSGASSERT("리소스 폴더를 찾지 못했습니다.");
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
					MSGASSERT("리소스 폴더를 찾지 못했습니다.");
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
					MSGASSERT("리소스 폴더를 찾지 못했습니다.");
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
					MSGASSERT("리소스 폴더를 찾지 못했습니다.");
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
					MSGASSERT("리소스 폴더를 찾지 못했습니다.");
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
					MSGASSERT("리소스 폴더를 찾지 못했습니다.");
					return;
				}
				Dir.Append("Image");
				Dir.Append("Phase2");
				Dir.Append("01_SerenNoon/NoonSerenDie");

				UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
			}

			#pragma endregion

	



		#pragma endregion

			// 세렌 석양
			{
				UEngineDirectory Dir;
				if (false == Dir.MoveParentToDirectory("MapleResources"))
				{
					MSGASSERT("리소스 폴더를 찾지 못했습니다.");
					return;
				}
				Dir.Append("Image");
				Dir.Append("Phase2");
				Dir.Append("02_SerenSunSet/SunSetSerenFirstAttack");

				UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
			}

			{
				UEngineDirectory Dir;
				if (false == Dir.MoveParentToDirectory("MapleResources"))
				{
					MSGASSERT("리소스 폴더를 찾지 못했습니다.");
					return;
				}
				Dir.Append("Image");
				Dir.Append("Phase2");
				Dir.Append("02_SerenSunSet/SunSetSerenSecondAttack");

				UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
			}

			{
				UEngineDirectory Dir;
				if (false == Dir.MoveParentToDirectory("MapleResources"))
				{
					MSGASSERT("리소스 폴더를 찾지 못했습니다.");
					return;
				}
				Dir.Append("Image");
				Dir.Append("Phase2");
				Dir.Append("02_SerenSunSet/SunSetSerenThirdAttack");

				UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
			}

			{
				UEngineDirectory Dir;
				if (false == Dir.MoveParentToDirectory("MapleResources"))
				{
					MSGASSERT("리소스 폴더를 찾지 못했습니다.");
					return;
				}
				Dir.Append("Image");
				Dir.Append("Phase2");
				Dir.Append("02_SerenSunSet/SunSetSerenDie");

				UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
			}

			{
				UEngineDirectory Dir;
				if (false == Dir.MoveParentToDirectory("MapleResources"))
				{
					MSGASSERT("리소스 폴더를 찾지 못했습니다.");
					return;
				}
				Dir.Append("Image");
				Dir.Append("Phase1");
				Dir.Append("Phase1_Skill/Phase1_SwordAura_Ball");

				UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
			}

			{
				UEngineDirectory Dir;
				if (false == Dir.MoveParentToDirectory("MapleResources"))
				{
					MSGASSERT("리소스 폴더를 찾지 못했습니다.");
					return;
				}
				Dir.Append("Image");
				Dir.Append("Phase1");
				Dir.Append("Phase1_Seren/Phase1_Stand");

				UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
			}

			{
				UEngineDirectory Dir;
				if (false == Dir.MoveParentToDirectory("MapleResources"))
				{
					MSGASSERT("리소스 폴더를 찾지 못했습니다.");
					return;
				}
				Dir.Append("Image");
				Dir.Append("Phase1");
				Dir.Append("Phase1_Seren/Phase1_Sting");

				UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
			}

			{
				UEngineDirectory Dir;
				if (false == Dir.MoveParentToDirectory("MapleResources"))
				{
					MSGASSERT("리소스 폴더를 찾지 못했습니다.");
					return;
				}
				Dir.Append("Image");
				Dir.Append("Phase1");
				Dir.Append("Phase1_Seren/Phase1_Rush");

				UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
			}

			{
				UEngineDirectory Dir;
				if (false == Dir.MoveParentToDirectory("MapleResources"))
				{
					MSGASSERT("리소스 폴더를 찾지 못했습니다.");
					return;
				}
				Dir.Append("Image");
				Dir.Append("Phase1");
				Dir.Append("Phase1_Seren/Phase1_SwordAura");

				UEngineSprite::CreateSpriteToFolder(Dir.GetPathToString());
			}

			// 이미지를 변환 
			UEngineCore::CreateLevel<ATitleGameMode, APawn, ATitleHUD>("Title");
			UEngineCore::CreateLevel<ACerniumPlazaMode, APlayer, ACerniumHUD>("Plaza");
			UEngineCore::CreateLevel<AMainHallMode, APlayer, ASerenHUD>("MainHall");
			UEngineCore::CreateLevel<ATheBoundaryOfTheWorld, APlayer, ASerenHUD>("TheBoundaryOfTheWorld");
			
			UEngineCore::OpenLevel("MainHall");
		}

	}
}

void ALoadingGamdMode::LevelChangeStart()
{
	UEngineGUI::AllWindowOff();

	if (false == ThreadLoadingEnd)
	{


		Thread.Start("Loading", [this]()
			{
				{
					UEngineDirectory Dir;
					if (false == Dir.MoveParentToDirectory("MapleResources"))
					{
						MSGASSERT("리소스 폴더를 찾지 못했습니다.");
						return;
					}
					Dir.Append("Image");

					std::vector<UEngineFile> ImageFiles = Dir.GetAllFile(true, { ".PNG", ".BMP", ".JPG" });

					LoadingCount = ImageFiles.size();

					for (size_t i = 0; i < ImageFiles.size(); i++)
					{
						std::string FilePath = ImageFiles[i].GetPathToString();

						UEngineCore::GetThreadPool().WorkQueue([this, FilePath]()
							{
								UEngineTexture::ThreadSafeLoad(FilePath);
								--(this->LoadingCount);
							});
					}
				}
				ThreadLoadingInit = true;
			});
	}
}
