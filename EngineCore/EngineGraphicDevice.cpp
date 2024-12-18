#include "PreCompile.h"
#include "EngineGraphicDevice.h"

UEngineGraphicDevice::UEngineGraphicDevice()
{
}

UEngineGraphicDevice::~UEngineGraphicDevice()
{
    Release();
}

void UEngineGraphicDevice::Release()
{
    if (nullptr != Context)
    {
        Context->Release();
        Context = nullptr;
    }

    if (nullptr != Device)
    {
        Device->Release();
        Device = nullptr;
    }
}

IDXGIAdapter* UEngineGraphicDevice::GetHighPerFormanceAdapter()
{
    IDXGIFactory* Factory = nullptr;
    unsigned __int64 MaxVideoMemory = 0;
    IDXGIAdapter* ResultAdapter = nullptr;

    HRESULT HR = CreateDXGIFactory(__uuidof(IDXGIFactory), reinterpret_cast<void**>(&Factory));

    if (nullptr == Factory)
    {
        MSGASSERT("�׷���ī�� ����� ���丮 ������ �����߽��ϴ�.");
        return nullptr;
    }



    for (int Index = 0;; ++Index)
    {
        IDXGIAdapter* CurAdapter = nullptr;
        Factory->EnumAdapters(Index, &CurAdapter);

        if (nullptr == CurAdapter)
        {
            break;
        }

        DXGI_ADAPTER_DESC Desc;

        CurAdapter->GetDesc(&Desc);

        if (MaxVideoMemory <= Desc.DedicatedVideoMemory)
        {
            MaxVideoMemory = Desc.DedicatedVideoMemory;
            if (nullptr != ResultAdapter)
            {
                ResultAdapter->Release();
            }

            ResultAdapter = CurAdapter;
            continue;
        }

        CurAdapter->Release();
    }

    if (nullptr != Factory)
    {
        Factory->Release();
    }

    if (nullptr == ResultAdapter)
    {
        MSGASSERT("�׷���ī�尡 �޷����� ���� ��ǻ���Դϴ�.");
        return nullptr;
    }

    return ResultAdapter;
}

void UEngineGraphicDevice::CreateDeviceAndContext()
{
    IDXGIAdapter* Adapter = GetHighPerFormanceAdapter();

    int iFlag = 0;

#ifdef _DEBUG
    iFlag = D3D11_CREATE_DEVICE_DEBUG;
#endif
    D3D_FEATURE_LEVEL ResultLevel;

    HRESULT Result = D3D11CreateDevice(
        Adapter,
        D3D_DRIVER_TYPE::D3D_DRIVER_TYPE_UNKNOWN,
        nullptr, // Ư�� �ܰ踦 ���� § �ڵ�� ��ü
        iFlag,
        nullptr, // �������� ���� 11
        0, // ���� ������ ��ó���� ����
        D3D11_SDK_VERSION, // ���� ���̷�Ʈx sdk ����
        &Device,
        &ResultLevel,
        &Context);

    if (nullptr == Device)
    {
        MSGASSERT("�׷��� ����̽� ������ �����߽��ϴ�.");
        return;
    }

    if (nullptr == Context)
    {
        MSGASSERT("�׷��� ���ؽ�Ʈ ������ �����߽��ϴ�.");
        return;
    }

    if (Result != S_OK)
    {
        MSGASSERT("���� �߸���.");
        return;
    }

    if (ResultLevel != D3D_FEATURE_LEVEL_11_0
        && ResultLevel != D3D_FEATURE_LEVEL_11_1)
    {
        MSGASSERT("���̷�Ʈ 11������ �������� �ʴ� �׷���ī�� �Դϴ�.");
        return;
    }

    Result = CoInitializeEx(nullptr, COINIT_MULTITHREADED);

    if (Result != S_OK)
    {
        MSGASSERT("������ ������ ���뿡 ������ ������ϴ�.");
        return;
    }

    Adapter->Release();
}

void UEngineGraphicDevice::CreateBackBuffer(const UEngineWindow& _Window)
{
    FVector Size = _Window.GetWindowSize();

    DXGI_SWAP_CHAIN_DESC ScInfo = { 0 };

    ScInfo.BufferCount = 2;
    ScInfo.BufferDesc.Width = Size.iX();
    ScInfo.BufferDesc.Height = Size.iY();
    ScInfo.OutputWindow = _Window.GetWindowHandle();
    ScInfo.Windowed = true;

    ScInfo.BufferDesc.RefreshRate.Denominator = 1;
    ScInfo.BufferDesc.RefreshRate.Numerator = 60;

    ScInfo.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;

    ScInfo.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
    ScInfo.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

    ScInfo.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT | DXGI_USAGE_SHADER_INPUT;

    ScInfo.SampleDesc.Quality = 0;
    ScInfo.SampleDesc.Count = 1;

    ScInfo.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
    ScInfo.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

}