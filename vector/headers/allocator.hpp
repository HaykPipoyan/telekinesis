#ifndef ALLOCATOR_HPP
#define ALLOCATOR_HPP

#include "allocator.h"

template <typename T>
pointer allocate(size_type n, const void* hint)
{
	return static_cast<pointer>(::operator new(n * sizeof(T)));
}

template <typename T>
void deallocate(pointer p, size_type n)
{
	::operator delete(p);
}
	pointer address( reference x ) const noexcept;
	size_type max_size() const noexcept;
	void construct( U* p, Args&&... args );
	template< class U >
	void destroy( U* p );


#endif // ALLOCATOR_HPP
