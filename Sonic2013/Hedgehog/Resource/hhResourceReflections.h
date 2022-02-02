#pragma once

#define LWAPI_STUB_POSTFIX Data
#define LWAPI_MAKE_STUBRES(NAME, PTR) \
	struct CONCAT2(NAME, LWAPI_STUB_POSTFIX) {}; \
	class NAME : public app::fnd::ResCommon<CONCAT2(NAME, LWAPI_STUB_POSTFIX)> \
	{ \
		inline static hh::ut::ResourceTypeInfo* ms_pTypeInfo = reinterpret_cast<hh::ut::ResourceTypeInfo*>(PTR); \
		public: \
		static const hh::ut::ResourceTypeInfo& staticTypeInfo() { return *ms_pTypeInfo; } \
	}; \

namespace app
{
	LWAPI_MAKE_STUBRES(ResPhysicsMesh, ASLR(0x00F62224));
	LWAPI_MAKE_STUBRES(ResUnusedPhysicsMesh, ASLR(0x00F62234));
	LWAPI_MAKE_STUBRES(ResGismoConfig, ASLR(0x00F938E8));
	LWAPI_MAKE_STUBRES(ResScoreTable, ASLR(0x00FB9A0C));
	LWAPI_MAKE_STUBRES(ResSvCol, ASLR(0x00FB772C));
	LWAPI_MAKE_STUBRES(ResSample, ASLR(0x00F6A48C));
	LWAPI_MAKE_STUBRES(ResSurfRideProject, ASLR(0x00F731D0));
	LWAPI_MAKE_STUBRES(ResFxColFile, ASLR(0x00FB6D68));
	LWAPI_MAKE_STUBRES(ResVoxelContainer, ASLR(0x00FB6FE8));
	LWAPI_MAKE_STUBRES(ResCustomData, ASLR(0x00F69960));
	LWAPI_MAKE_STUBRES(ResLuaData, ASLR(0x00F6FC2C));
	LWAPI_MAKE_STUBRES(ResTerrainMap, ASLR(0x00FB76F0));
	LWAPI_MAKE_STUBRES(ResSM4ShaderContainer, ASLR(0x00FB6FAC));
	
	namespace game
	{
		LWAPI_MAKE_STUBRES(ResNameExtra, ASLR(0x00F6AD14));
		LWAPI_MAKE_STUBRES(ResSplinePath2, ASLR(0x00F6F958));
	}
	
	namespace text
	{
		LWAPI_MAKE_STUBRES(ResTTFData, ASLR(0x00F69E38));
		LWAPI_MAKE_STUBRES(ResBFTTFData, ASLR(0x00F69E48));
	}

	namespace dev
	{
		LWAPI_MAKE_STUBRES(ResEventTb, ASLR(0x00F64FD0));
		LWAPI_MAKE_STUBRES(ResEventTag, ASLR(0x00F64F98));
		LWAPI_MAKE_STUBRES(ResEventEvs, ASLR(0x00F64F60));
	}

	namespace res
	{
		LWAPI_MAKE_STUBRES(ResShadowModel, ASLR(0x00FB6F0C));
	}
}

namespace hh::ut
{
	LWAPI_MAKE_STUBRES(ResPacDepend, ASLR(0x00FCEAEC));

	namespace internal
	{
		LWAPI_MAKE_STUBRES(ResPacGeneral, ASLR(0x00FCEAFC));
	}
}

namespace hh::gfx::res
{
	LWAPI_MAKE_STUBRES(ResAnimCameraContainer, ASLR(0x00FCE990));
	LWAPI_MAKE_STUBRES(ResAnimLightContainer, ASLR(0x00FCE948));
	LWAPI_MAKE_STUBRES(ResAnimMaterial, ASLR(0x00FCE900));
	LWAPI_MAKE_STUBRES(ResAnimMorphTarget, ASLR(0x00FCE8C0));
	LWAPI_MAKE_STUBRES(ResAnimSkeleton, ASLR(0x00FCE87C));
	LWAPI_MAKE_STUBRES(ResAnimTexPat, ASLR(0x00FCE83C));
	LWAPI_MAKE_STUBRES(ResAnimTexSrt, ASLR(0x00FCE7FC));
	LWAPI_MAKE_STUBRES(ResAnimVis, ASLR(0x00FCE7BC));
	LWAPI_MAKE_STUBRES(ResFragmentShader, ASLR(0x00FCE600));
	LWAPI_MAKE_STUBRES(ResMaterial, ASLR(0x00FCE780));
	LWAPI_MAKE_STUBRES(ResModel, ASLR(0x00FCE6B4));
	LWAPI_MAKE_STUBRES(ResModelInstanceInfo, ASLR(0x00FCE744));
	LWAPI_MAKE_STUBRES(ResShader, ASLR(0x00FCE610));
	LWAPI_MAKE_STUBRES(ResSkeleton, ASLR(0x00FCE700));
	LWAPI_MAKE_STUBRES(ResTerrainModel, ASLR(0x00FCE6C4));
	LWAPI_MAKE_STUBRES(ResTexture, ASLR(0x00FCE64C));
	LWAPI_MAKE_STUBRES(ResVertexShader, ASLR(0x00FCE5F0));
	LWAPI_MAKE_STUBRES(ResMirageLight, ASLR(0x00FCE550));
	LWAPI_MAKE_STUBRES(ResMirageLightField, ASLR(0x00FCE510));
	LWAPI_MAKE_STUBRES(ResMiragePixelShaderCode, ASLR(0x00FCE4CC));
	LWAPI_MAKE_STUBRES(ResMiragePixelShaderParameter, ASLR(0x00FCE484));
	LWAPI_MAKE_STUBRES(ResMirageTerrainInstanceInfo, ASLR(0x00FCE434));
	LWAPI_MAKE_STUBRES(ResMirageVertexShaderCode, ASLR(0x00FCE3E8));
	LWAPI_MAKE_STUBRES(ResMirageVertexShaderParameter, ASLR(0x00FCE39C));
}

namespace hh::eff::res
{
	LWAPI_MAKE_STUBRES(ResEffect, ASLR(0x00FCDDC8));
}

#undef LWAPI_STUB_POSTFIX
#undef LWAPI_MAKE_STUBRES