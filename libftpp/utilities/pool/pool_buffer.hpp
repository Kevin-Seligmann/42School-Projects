#pragma once

#include <memory>

/* CLASS POOL_BUFFER:
	This is a resource handler contiguous memory.
*/
template<class TType, class A = std::allocator<TType>>
struct pool_buffer
{
	A alloc;
	TType * start;
	TType * finish;
	TType * end;

	pool_buffer(size_t size, A a);
	pool_buffer(size_t size, size_t initialized, A a);
	~pool_buffer();
	pool_buffer(pool_buffer && rhs);
	pool_buffer & operator=(pool_buffer && rhs);
	pool_buffer(const pool_buffer &) = delete;
	pool_buffer & operator=(const pool_buffer &) = delete;
	size_t size() const;
	size_t capacity() const;
	void destroy_elements(TType * from);
};

template<class TType, class A>
pool_buffer<TType, A>::pool_buffer(size_t size, A a) :alloc(a)
,start{alloc.allocate(size)} ,finish{start + size} ,end{start + size}{}

template<class TType, class A>
pool_buffer<TType, A>::pool_buffer(size_t size, size_t initialized, A a) :alloc(a)
,start{alloc.allocate(size)} ,finish{start + initialized} ,end{start + size}{}

template<class TType, class A>
pool_buffer<TType, A>::~pool_buffer()
{alloc.deallocate(start, end - start);}

template<class TType, class A>
pool_buffer<TType, A>::pool_buffer(pool_buffer && rhs):alloc(rhs.alloc)
,start{rhs.start} ,finish{rhs.finish} ,end{rhs.end}
{
	rhs.start = nullptr;
	rhs.finish = nullptr;
	rhs.end = nullptr;
}

template<class TType, class A>
size_t pool_buffer<TType, A>::size() const {return finish - start;}

template<class TType, class A>
size_t pool_buffer<TType, A>::capacity() const {return end - start;}

template<class TType, class A>
pool_buffer<TType, A> & pool_buffer<TType, A>::operator=(pool_buffer && rhs)
{
	alloc = rhs.alloc;
	start = rhs.start;
	finish = rhs.finish;
	end = rhs.end;

	rhs.start = nullptr;
	rhs.finish = nullptr;
	rhs.end = nullptr;
	return *this;
}

template<class TType, class A>
void pool_buffer<TType, A>::destroy_elements(TType * from)
{
	for (TType * obj = from; obj < finish; obj ++)
		obj->~TType();
	finish = from;
}
