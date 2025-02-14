#pragma once

namespace csl::fnd
{
	template<typename TLock = Mutex>
	class PoolHeapTemplate : public PoolHeapBase
	{
	public:
		TLock m_Lock{};

		PoolHeapTemplate()
		{
			
		}

		void* Alloc(size_t in_size, size_t in_alignment) override
		{
			m_Lock.Lock();
			void* pMemory = PoolHeapBase::Alloc(in_size, in_alignment);
			m_Lock.Unlock();

			return pMemory;
		}

		void* AllocBottom(size_t in_size, size_t in_alignment) override
		{
			m_Lock.Lock();
			void* pMemory = PoolHeapBase::AllocBottom(in_size, in_alignment);
			m_Lock.Unlock();

			return pMemory;
		}

		void Free(void* in_pMemory) override
		{
			m_Lock.Lock();
			PoolHeapBase::Free(in_pMemory);
			m_Lock.Unlock();
		}
	};
}