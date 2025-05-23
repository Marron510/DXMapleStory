#pragma once
#include "EngineShaderResources.h"
#include "Mesh.h"
#include "EngineMaterial.h"
#include "EngineEnums.h"


class URenderUnit
{
public:
	// constrcuter destructer
	ENGINEAPI URenderUnit();
	ENGINEAPI ~URenderUnit();

	UTransformObject* TransformObject = nullptr;

	class URenderer* ParentRenderer = nullptr;

	// 매쉬(육체) 
	std::shared_ptr<UMesh> Mesh;
	// 머티리얼(피부)
	std::shared_ptr<UEngineMaterial> Material;

	Microsoft::WRL::ComPtr<ID3D11InputLayout> InputLayOut;

	ENGINEAPI void SetMesh(std::string_view _Name);
	ENGINEAPI void SetMaterial(std::string_view _Name);

	//void SetInputAssembler1();
	//void SetInputAssembler1();

	ENGINEAPI virtual void Render(class UEngineCamera* _Camera, float _DeltaTime);

	ENGINEAPI void MaterialResourcesCheck();

	template<typename Data>
	ENGINEAPI void ConstantBufferLinkData(std::string_view _Name, Data& _Data)
	{
		ConstantBufferLinkData(_Name, reinterpret_cast<void*>(&_Data));
	}

	ENGINEAPI void ConstantBufferLinkData(std::string_view Name, void* _Data);

	ENGINEAPI void SetTexture(std::string_view _Name, std::string_view _ResName);
	ENGINEAPI void SetTexture(std::string_view _Name, std::shared_ptr<UEngineTexture> _Texture);
	ENGINEAPI void SetSampler(std::string_view Name, std::string_view _ResName);


	ENGINEAPI void SetTexture(std::string_view _Name, UEngineTexture* _Texture);

	ENGINEAPI void Reset();

	std::map<EShaderType, UEngineShaderResources> Resources;

private:
	void InputLayOutCreate();
};

