#include "PreCompile.h"
#include "Renderer.h"

URenderer::URenderer()
{
}

URenderer::~URenderer()
{
}

void URenderer::SetOrder(int _Order)
{
	int PrevOrder = GetOrder();
	UObject::SetOrder(_Order);
	ULevel* Level = GetActor()->GetWorld();
	
	std::shared_ptr<URenderer> RendererPtr = GetThis<URenderer>();
	Level->ChangeRenderGroup(PrevOrder, RendererPtr);
}

ENGINEAPI void URenderer::BeginPlay()
{
	SetOrder(0);
}

void URenderer::Render(float _DeltaTime)
{
	
	InputAssembler1Setting();
	// 랜더링 파이프라인

}

void URenderer::InputAssembler1Init()
{
	// 버텍스 버퍼를 그래픽카드에게 만들어 달라고 요청
	// 여기는 이미 ram
	// CPU
	std::vector<EngineVertex> Vertexs;
	Vertexs.resize(6);

	Vertexs[0] = EngineVertex{ FVector(-0.5f, 0.5f, -0.5f), {} };
	Vertexs[1] = EngineVertex{ FVector(0.5f, 0.5f, -0.5f), {} };
	Vertexs[2] = EngineVertex{ FVector(-0.5f, -0.5f, -0.5f), {} };
	Vertexs[3] = EngineVertex{ FVector(0.5f, 0.5f, -0.5f), {} };
	Vertexs[4] = EngineVertex{ FVector(0.5f, -0.5f, -0.5f), {} };
	Vertexs[5] = EngineVertex{ FVector(-0.5f, -0.5f, -0.5f), {} };


	D3D11_BUFFER_DESC BufferInfo = { 0 };

	BufferInfo.ByteWidth = sizeof(EngineVertex) * Vertexs.size();
	// 용도는 버텍스 버퍼
	BufferInfo.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	// CPU에서 수정 가능?
	BufferInfo.CPUAccessFlags = 0;
	
	BufferInfo.Usage = D3D11_USAGE_DEFAULT;


	// 초기값
	D3D11_SUBRESOURCE_DATA Data;
	Data.pSysMem = &Vertexs[0];

	// GPU에 xxx 크기의 버퍼 만들어줘
	if (S_OK != UEngineCore::Device.GetDevice()->CreateBuffer(&BufferInfo, &Data, &VertexBuffer))
	{
		MSGASSERT("버텍스 버퍼 생성에 실패했습니다.");
		return;
	}

	// 
}

void URenderer::InputAssembler1Setting()
{
	UINT VertexSize = sizeof(EngineVertex);
	UINT Offset = 0;

	UEngineCore::Device.GetContext()->IASetVertexBuffers(0, 1, &VertexBuffer, &VertexSize, &Offset);

}
