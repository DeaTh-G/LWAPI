#pragma once

namespace app::game
{
	class SvSplineGravityEffect : GravityEffect
	{
	public:
		DEFINE_RTTI_PTR(ASLR(0x00F6C130));

		INSERT_PADDING(28);
		float Distance{};
		INSERT_PADDING(8);

		float GetDistanceOnPath() const
		{
			return Distance;
		}
		
		const csl::ut::detail::RuntimeTypeInfo* GetRuntimeTypeInfo() const override
		{
			return GetRuntimeTypeInfoStatic();
		}
	};
}
