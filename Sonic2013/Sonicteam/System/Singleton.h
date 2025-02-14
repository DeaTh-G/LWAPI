#pragma once

namespace csl::fnd
{	
	template<typename T>
	class SingletonPointer
	{
	protected:
		static T** instance;

	public:
		static T** GetPointer()
		{
			return instance;
		}
		
		static T* GetInstance()
		{
			return *instance;
		}

		static T* SwapInstance(T* inst)
		{
			T* pOldInstance = *instance;
			*instance = inst;
			return pOldInstance;
		}

		static void ReplaceInstance(T* inst)
		{
			if (*instance) delete *instance;
			
			*instance = inst;
		}

		static bool IsInitialized()
		{
			return *instance == nullptr;
		}
	};

	template<typename T>
	inline T** SingletonPointer<T>::instance{ nullptr };
	
	template<typename T>
	class Singleton
	{
	public:
		inline static T* instance{};

		[[nodiscard]] static T* GetInstance()
		{
			if constexpr (std::is_base_of<SingletonPointer<T>, T>())
			{
				return SingletonPointer<T>::GetInstance();
			}

			return instance;
		}

		static void ReplaceInstance(T* inst)
		{
			if constexpr (std::is_base_of<SingletonPointer<T>, T>())
			{
				SingletonPointer<T>::ReplaceInstance(inst);
				return;
			}
			
			if (instance) delete instance;
			instance = inst;
		}

		static T* SwapInstance(T* inst)
		{
			if constexpr (std::is_base_of<SingletonPointer<T>, T>())
			{
				return SingletonPointer<T>::SwapInstance(inst);
			}

			T* pInst = instance;
			instance = inst;
			return pInst;
		}

		static bool IsInitialized()
		{
			if constexpr (std::is_base_of<SingletonPointer<T>, T>())
			{
				return SingletonPointer<T>::IsInitialized();
			}
			
			return instance != nullptr;
		}
	};
}

#define DEFINE_SINGLETONPTR(type, ptr) type** csl::fnd::SingletonPointer<type>::instance = reinterpret_cast<type**>(ptr);