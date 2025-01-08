#include "PreCompile.h"
#include "Renderer.h"
#include <EngineBase/EngineString.h>
#include <EngineCore/EngineCamera.h>
#include <EngineCore/EngineTexture.h>
#include <EngineCore/Mesh.h>
#include "EngineVertex.h"
#include "EngineBlend.h"

URenderer::URenderer()
{
}

URenderer::~URenderer()
{

}


void URenderer::SetOrder(int _Order)
{
	if (0 != GetOrder() && _Order == GetOrder())
	{
		return;
	}
	int PrevOrder = GetOrder();
	UObject::SetOrder(_Order);
	ULevel* Level = GetActor()->GetWorld();

	std::shared_ptr<URenderer> RendererPtr = GetThis<URenderer>();
	Level->ChangeRenderGroup(0, PrevOrder, RendererPtr);
}


ENGINEAPI void URenderer::BeginPlay()
{
	USceneComponent::BeginPlay();
	SetOrder(GetOrder());
}

URenderUnit& URenderer::GetRenderUnit(UINT _Index)
{
	return Units[_Index];
}

void URenderer::SetMesh(std::string_view _Name, UINT _Index /*= 0*/)
{
	URenderUnit& Unit = GetRenderUnit(_Index);
	Unit.SetMesh(_Name);
}

void URenderer::SetMaterial(std::string_view _Name, UINT _Index /*= 0*/)
{
	URenderUnit& Unit = GetRenderUnit(_Index);
	Unit.SetMaterial(_Name);
}

void URenderer::RenderTransUpdate(UEngineCamera* _Camera)
{
	// 쉽게 말하면 트랜스폼 
	// 트랜스폼은 랜더러가 가지고 있습니다.
	FTransform& CameraTrans = _Camera->GetTransformRef();
	FTransform& RendererTrans = GetTransformRef();
	//	// 랜더러는 월드 뷰 프로젝트를 다 세팅받았고
	RendererTrans.View = CameraTrans.View;
	RendererTrans.Projection = CameraTrans.Projection;
	RendererTrans.WVP = RendererTrans.World * RendererTrans.View * RendererTrans.Projection;
}

void URenderer::Render(UEngineCamera* _Camera, float _DeltaTime)
{
	this->RenderTransUpdate(_Camera);

	{
		FTransform& CameraTrans = _Camera->GetTransformRef();
		FTransform& RendererTrans = GetTransformRef();
		RendererTrans.View = CameraTrans.View;
		RendererTrans.Projection = CameraTrans.Projection;
		RendererTrans.WVP = RendererTrans.World * RendererTrans.View * RendererTrans.Projection;


		for (size_t i = 0; i < Units.size(); i++)
		{
			Units[i].Render(_Camera, _DeltaTime);
		}
	}
}
URenderUnit& URenderer::CreateRenderUnit()
{

	URenderUnit& NewUnit = Units.emplace_back();
	NewUnit.ParentRenderer = this;
	return NewUnit;
}