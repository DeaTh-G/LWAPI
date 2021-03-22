#pragma once

namespace app::animation
{
	class CharactorAnimation;
	class AnimationClip;
	class AnimationSimple;
	class AnimationComplex;
	class ExternalAnimation;
	
	class AnimationNodeManager
	{
	protected:
		csl::ut::StringMap<AnimationClip*> m_Animations;
		AnimSkeletonBlender m_Blender{ nullptr };
		csl::ut::ObjectMoveArray<AnimationSimple> m_SimpleAnimations;
		csl::ut::ObjectMoveArray<AnimationComplex> m_ComplexAnimations;
		CharactorAnimation* m_pOwner{};
		csl::fnd::IAllocator* m_pAllocator{};
		csl::ut::ObjectMoveArray<ut::RefPtr<ExternalAnimation>> m_ExternalAnimations;
		
	public:
		AnimationNodeManager(csl::fnd::IAllocator& rAlloc) : m_Animations(&rAlloc), m_SimpleAnimations(&rAlloc),
			m_ComplexAnimations(&rAlloc), m_ExternalAnimations(&rAlloc)
		{
			m_pAllocator = &rAlloc;
		}

		AnimationClip* GetAnimationClip(const char* pName) const
		{
			const auto result = m_Animations.find(pName);
			if (result == m_Animations.end())
				return nullptr;

			return result;
		}
	};
}