cbuffer mycBuffer : register(b0)
{
    float4x4 mat;
};

struct VS_INPUT
{
    float3 inPos : POSITION;
    float3 inTexCoord : TEXCOORD;
};

struct VS_OUTPUT
{
    float4 outPosisiton : SV_POSITION;
    float3 outTexCoord : TEXCOORD;
};

VS_OUTPUT main(VS_INPUT input)
{
    VS_OUTPUT output;
    output.outPosisiton = mul(float4(input.inPos, 1.0f), mat);
    output.outTexCoord = input.inTexCoord;
    
    return output;
}