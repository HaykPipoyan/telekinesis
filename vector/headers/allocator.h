#ifndef ALLOCATOR_H
#define ALLOCATOR_H

template<typename t>
class allocator {
public:
	using value_type = T;
	using pointer = T*;
	using const_pointer = const T*;
	using reference = T&;
	using const_reference = const T&;
	using size_type = std::size_t;
	
public:
	constexpr allocator() noexcept = default;
	constexpr allocator(const allocator& other) noexcept = default;
	constexpr ~allocator() = default;
public:
	pointer allocate(std::size_t n, const void* hint);
	void deallocate(T* p, std::size_t n);
	pointer address( reference x ) const noexcept;
	size_type max_size() const noexcept;
	void construct( U* p, Args&&... args );
	template< class U >
	void destroy( U* p );
};

/*
template< class T1, class T2 >
constexpr bool
    operator==( const allocator<T1>& lhs, const allocator<T2>& rhs ) noexcept;

template< class T1, class T2 >
bool operator!=( const allocator<T1>& lhs, const allocator<T2>& rhs ) noexcept;
*/

#include "allocator.hpp"

#endif // ALLOCATOR_H
