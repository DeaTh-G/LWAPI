#pragma once

namespace app::fnd
{
	class GOCVisualContainer : public GOCVisual
	{
	public:
		struct Description
		{
			size_t m_VisualCount;
		};
		
		csl::ut::InplaceMoveArray<GOCVisual*, 2> m_Visuals{ GetAllocator() };
		
		inline static GOComponentClass* ms_pStaticClass = reinterpret_cast<GOComponentClass*>(ASLR(0x00FD4254));

		static GOComponentClass* staticClass()
		{
			return ms_pStaticClass;
		}
		
		void Setup(const Description& rDesc)
		{
			m_Visuals.reserve(rDesc.m_VisualCount);
		}
		
		void Add(GOCVisual* pVisual)
		{
			pVisual->AddRef();
			m_Visuals.push_back(pVisual);

			unk1 |= pVisual->unk1;
		}

		void Remove(GOCVisual* pVisual)
		{
			auto idx = m_Visuals.find(pVisual);
			if (idx != -1)
				m_Visuals.remove(idx);
			
			if (pVisual)
				pVisual->Release();
		}
	};
}