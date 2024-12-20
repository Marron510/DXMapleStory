struct EngineVertex
{
    float4 POSITION : POSITION;
    float4 UV : TEXCOORD;
    float4 COLOR : COLOR;
};


struct VertexShaderOutPut
{
    float4 SVPOSITION : SV_POSITION; 
    float4 UV : TEXCOORD; // 
    float4 COLOR : COLOR;
};

// �������
cbuffer FTransform : register(b0)
{
    float4 Scale;
    float4 Rotation;
    float4 Location;

    float4x4 ScaleMat;
    float4x4 RotationMat;
    float4x4 LocationMat;
    float4x4 World;
    float4x4 View;
    float4x4 Projection;
    float4x4 WVP;
};

VertexShaderOutPut VertexToWorld(EngineVertex _Vertex)
{
    VertexShaderOutPut OutPut;
	// _Vertex 0.5, 0.5
    OutPut.SVPOSITION = mul(_Vertex.POSITION, WVP);
    OutPut.UV = _Vertex.UV;
    OutPut.COLOR = _Vertex.COLOR;
    return OutPut;
}

// �ؽ�ó 1��
Texture2D ImageTexture : register(t0);
// ���÷� 1��
SamplerState ImageSampler : register(s0);


float4 PixelToWorld(VertexShaderOutPut _Vertex) : SV_Target0
{
	
    return ImageTexture.Sample(ImageSampler, _Vertex.UV.xy);
}