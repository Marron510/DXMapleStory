#pragma once

#include <d3d11_4.h> // directx 11 ����4�� ���
#include <d3dcompiler.h> 
#include <EnginePlatform/EngineWindow.h>

// ���̺귯����
#pragma comment(lib, "d3d11")
#pragma comment(lib, "d3dcompiler") 
#pragma comment(lib, "dxguid")

#pragma comment(lib, "DXGI") 

class UEngineGraphicDevice
{
public:
	// constrcuter destructer
	ENGINEAPI UEngineGraphicDevice();
	ENGINEAPI ~UEngineGraphicDevice();

	// delete Function
	UEngineGraphicDevice(const UEngineGraphicDevice& _Other) = delete;
	UEngineGraphicDevice(UEngineGraphicDevice&& _Other) noexcept = delete;
	UEngineGraphicDevice& operator=(const UEngineGraphicDevice& _Other) = delete;
	UEngineGraphicDevice& operator=(UEngineGraphicDevice&& _Other) noexcept = delete;

	void CreateDeviceAndContext();

	void CreateBackBuffer(const UEngineWindow& _Window);

	IDXGIAdapter* GetHighPerFormanceAdapter();

	void Release();

protected:

private:

	// �޸� �ε��ض� ����
	ID3D11Device* Device = nullptr;

	// ������ �׷��� ����
	ID3D11DeviceContext* Context = nullptr;

	IDXGISwapChain* SwapChain = nullptr;
};

