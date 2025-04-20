#pragma once

#include <cstdlib>
#include <memory>
#include <algorithm>
#include <utility>
#include <stdexcept>
#include <type_traits>
#include "pool_buffer.hpp"

/*
	Behaviour:
	Default constructor and reserve() initialize X elements to default, like vector.
	The acquire() member pulls an object from the pool if it has no parameters
	, and creates a new one if it has parameters or the pool is empty.
	The acquire_new() member creates a new object with the provided parameters (Fresh state).
	The pool is expanded upon element creation.
	Resources are managed in LIFO 

	The acquire member returns a Pool::Object that manages the resource, accesible through -> operator.

	Some other methods that work similarly to the vector class are provided. These are mostly for internal
	usage, but it does no harm to expose them.

	Justification:
	Pool buildt according to a testcase provided beforehand.

	It's required that an object released is the next to be pick by an acquisition.

	It's required that the acquire operator picks a resource if the argument list is empty
	or constructs a new one if arguments are provided. This is akward
	for default constructors. So a new operation is provided acquire_new.

	Because some objects can be constructed with parameters and are expected to be released.
	And the next acquired object have to be the released object. It's inferred that
	objects conserve their state.
*/
template<class TType, class A = std::allocator<TType>>
class Pool
{
	public:
	/* CLASS OBJECT
		Manages the lifetime of an adquired resource outside the pool.

		For Pool's copy/move. It's required for the Pool::Object
		to be released to the new Pool. It stores a reference
		to its current owner.
	*/
	class Object
	{
		public:
		TType * operator->(); // Access resource contained by Object.
		TType & operator*(); // For compatible dereference usage.
		TType & operator[](size_t i); // Idem
	
		Object(Object && rhs);
		Object & operator=(Object && rhs);
		~Object();

		private:
		Pool<TType, A> * _owner;
		TType _object;

		template<typename ... TArgs>
		Object(Pool<TType, A> * owner, TArgs&& ... p_args);
		Object(Pool<TType, A> * owner, TType && object);
		Object(Pool<TType, A> * owner, TType const & object);

		Object(const Object &) = delete;
		Object & operator=(const Object &) = delete;

		friend Pool<TType, A>;
	};

	// Constructors / Destructors
	Pool(size_t size = 0, A a = std::allocator<TType>()); // Default constructor of object
	Pool(size_t size, const TType & ref, A a = std::allocator<TType>()); // Constructed by copying reference
	Pool(const Pool & src); // Copy constructor
	Pool (Pool && src); // Move constructor
	~Pool();

	// Overloads
	Pool & operator=(const Pool & src);
	Pool & operator=(Pool && src); 

	// Methods
	size_t size() const;
	size_t capacity() const;
	void resize(const size_t & numberOfObjectStored);
	void reserve(const size_t & numberOfObjectStored);
	void clean();

	template<typename ... TArgs>
	Pool<TType, A>::Object acquire(TArgs&& ... p_args);

	template<typename ... TArgs>
	Pool<TType, A>::Object acquire_new(TArgs&& ... p_args);

	private:
	pool_buffer<TType, A> _base;
	size_t _shared;

	void release(TType & obj);
	void push_resource(TType & rhs);
	Pool<TType, A>::Object pull_resource();
};

// Initialized size elements with default constructor
template<class TType, class A>
Pool<TType, A>::Pool(size_t size, A a)
:_base{size, a}, _shared(0)
{std::uninitialized_default_construct(_base.start, _base.finish);}

// Initialized size elements with reference value
template<class TType, class A>
Pool<TType, A>::Pool(size_t size, const TType & ref, A a)
:_base{size, a}, _shared(0)
{std::uninitialized_fill(_base.start, _base.finish, ref);}

// Initialized pool with reference (Copy constructor)
template<class TType, class A>
Pool<TType, A>::Pool(const Pool & src)
:_base{src._base.size(), src._base.alloc}, _shared(0)
{
	if (src._shared > 0)
		throw std::logic_error("Tried to copy pool with active resources");
	std::uninitialized_copy(src._base.start, src._base.finish, _base.start);
}

// Initialized by move (Move constructor)
template<class TType, class A>
Pool<TType, A>::Pool(Pool && src)
{
	if (src._shared > 0)
		throw std::logic_error("Tried to move pool with active resources");
	_base = std::move(src._base);
	_shared = 0;
}

// Calls destructor on elements
template<class TType, class A>
Pool<TType, A>::~Pool(){_base.destroy_elements(_base.start);}

// Copy assignment
template<class TType, class A>
Pool<TType, A> & Pool<TType, A>::operator=(const Pool & src)
{
	if (src._shared > 0 || _shared > 0)
		throw std::logic_error("Tried to copy pool with active resources");
	if (this == &src)
		return *this;
	clean();
	reserve(src.size());
	std::uninitialized_copy(src._base.start, src._base.finish, _base.start);
	return *this;
}

// Move assignment
template<class TType, class A>
Pool<TType, A> & Pool<TType, A>::operator=(Pool && src)
{
	if (src._shared > 0 || _shared > 0)
		throw std::logic_error("Tried to move pool with active resources");
	clean();
	std::swap(*this, src);
	return *this;
}

template<class TType, class A>
void Pool<TType, A>::clean(){resize(0);}

template<class TType, class A>
void Pool<TType, A>::resize(const size_t & numberOfObjectStored)
{
	reserve(numberOfObjectStored);
	if (numberOfObjectStored > _base.size())
		std::uninitialized_default_construct(_base.finish, _base.start + numberOfObjectStored);
	else
		_base.destroy_elements(_base.start + numberOfObjectStored);
	_base.finish = _base.start + numberOfObjectStored;
}

template<class TType, class A>
void Pool<TType, A>::reserve(const size_t & numberOfObjectStored)
{
	if (numberOfObjectStored <= _base.capacity())
		return ;
	size_t og_size = size();
	pool_buffer<TType, A> new_base{numberOfObjectStored, A()};
	if constexpr (std::is_move_constructible_v<TType>)
	{
		std::uninitialized_move(_base.start, _base.finish, new_base.start);
	}
	else if constexpr (std::is_copy_constructible_v<TType>)
	{
		std::uninitialized_copy(_base.start, _base.finish, new_base.start);
		_base.destroy_elements(_base.start);
	}
	else
		static_assert(std::is_copy_constructible_v<TType> || std::is_move_constructible_v<TType>,
					"Type must be copy-constructible or move-constructible");
	new_base.finish = new_base.start + og_size;
	std::swap(_base, new_base);
}

template<class TType, class A>
size_t Pool<TType, A>::size() const {return _base.size();}

template<class TType, class A>
size_t Pool<TType, A>::capacity() const {return _base.capacity();}

template<class TType, class A>
template<typename ... TArgs>
typename Pool<TType, A>::Object Pool<TType, A>::acquire(TArgs&& ... p_args)
{
	if (sizeof...(TArgs) != 0 || size() == 0) // Create new resource
		return acquire_new(std::forward<TArgs>(p_args)...);
	return pull_resource();
}

template<class TType, class A>
template<typename ... TArgs>
typename Pool<TType, A>::Object Pool<TType, A>::acquire_new(TArgs&& ... p_args)
{
	_shared ++;
	return Object(this, std::forward<TArgs>(p_args)...);
}

template<class TType, class A>
void Pool<TType, A>::push_resource(TType & src)
{
	if (size() == capacity())
		reserve(std::max(static_cast<size_t>(8), size() * 2));
	new (_base.finish) TType(src);
	_base.finish ++;
}

template<class TType, class A>
typename Pool<TType, A>::Object Pool<TType, A>::pull_resource()
{
	Object obj(this, TType{*(_base.finish - 1)});
	_shared ++;
	_base.finish --;
	_base.finish->~TType();
	return obj;
}

template<typename TType, typename A>
void Pool<TType, A>::release(TType & obj)
{
	push_resource(obj);
	_shared --;
}

// Pool::Object
// Constructor
template<typename TType, typename A>
Pool<TType, A>::Object::Object(Pool<TType, A> * owner, TType && object)
:_owner(owner), _object(object){}

template<typename TType, typename A>
Pool<TType, A>::Object::Object(Pool<TType, A> * owner, const TType & object)
:_owner(owner), _object(object){}

template<typename TType, typename A>
template<typename ... TArgs>
Pool<TType, A>::Object::Object(Pool<TType, A> * owner, TArgs&& ... p_args)
:_owner(owner), _object(std::forward<TArgs>(p_args)...){}

// Move constructor
template<typename TType, typename A>
Pool<TType, A>::Object::Object(Object && src)
:_owner(src._owner), _object(src._object)
{
	src._owner = nullptr;
}

// Move assignment
template<typename TType, typename A>
typename Pool<TType, A>::Object & Pool<TType, A>::Object::operator=(Object && rhs)
{
	if (this != &rhs)
	{
		_owner->release(_object);
		_owner = rhs._owner;
		_object = rhs._object;
		rhs._owner = nullptr;
	}
	return *this;
}

// Destructor
template<typename TType, typename A>
Pool<TType, A>::Object::~Object()
{
	if (this->_owner)
		_owner->release(_object);
}

// Dereference
template<typename TType, typename A>
TType * Pool<TType, A>::Object::operator->()
{return &_object;}

template<typename TType, typename A>
TType & Pool<TType, A>::Object::operator*()
{return _object;}

template<typename TType, typename A>
TType & Pool<TType, A>::Object::operator[](size_t i)
{return *((&_object) + i);}
