#pragma once

#include <stdexcept>

template <typename TType>
class Singleton 
{
	public:
	static TType * instance();

	Singleton() = delete;
	~Singleton() = delete;
	Singleton(const Singleton & src) = delete;
	Singleton(Singleton && src) = delete;
	Singleton & operator=(const Singleton & rhs) = delete;
	Singleton & operator=(Singleton && rhs) = delete;


	template<typename ... TArgs> 
	static void instantiate(TArgs && ... args);

	private:
	static TType * _instance;

	friend TType;
};

template <typename TType>
TType * Singleton<TType>::_instance = nullptr;

template <typename TType>
TType * Singleton<TType>::instance()
{
	if (!_instance)
		throw std::runtime_error("Singleton not instantiated");
	return _instance;
}

template <typename TType>
template<typename ... TArgs> 
void Singleton<TType>::instantiate(TArgs && ... args)
{
	if (_instance)
		throw std::runtime_error("Singleton already instantiated");
	
	static TType instance(std::forward<TArgs>(args)...);
	_instance = &instance;
}
