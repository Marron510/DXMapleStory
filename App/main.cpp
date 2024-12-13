#include <EngineBase/EngineMath.h>
#include <EngineCore/EngineCore.h>

#pragma comment(lib, "EngineBase.lib")
#pragma comment(lib, "EnginePlatform.lib")
#pragma comment(lib, "EngineCore.lib")

int APIENTRY wWinMain(_In_ HINSTANCE _hInstance,
	_In_opt_ HINSTANCE _hPrevInstance,
	_In_ LPWSTR    _lpCmdLine,
	_In_ int       _nCmdShow)
{
	// 동적 연결을 위한 "EngineContents" dll이름을 넣어줘야 한다.
	UEngineCore::EngineStart(_hInstance, "MapleContents.dll");
	return 0;
}