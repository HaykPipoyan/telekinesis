#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

#include <iostream>

template <typename T, typename Allocator = std::allocator<T>>
class forward_list {
public:
    using value_type = T;
	using allocator_type = Allocator;
    using size_type = size_t;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = std::allocator_traits<Allocator>::pointer;
    using const_pointer = std::allocator_traits<Allocator>::const_pointer;

public:
	forward_list();
	explicit forward_list(const Allocator& alloc);
	forward_list(size_type count, const T& value, const Allocator& alloc = Allocator());
	explicit forward_list(size_type count, const Allocator& alloc = Allocator());
	forward_list(const forward_list& other);
	forward_list(const forward_list& other, const Allocator& alloc);
	forward_list(forward_list&& other);
	forward_list(forward_list&& other, const Allocator& alloc);
	forward_list(std::initializer_list<T> init, const Allocator& alloc = Allocator());
	~forward_list();
	
public:
//	forward_list& operator=(const forward_list& other);
/*	forward_list& operator=(forward_list&& other);
	forward_list& operator=( std::initializer_list<value_type> list);
	void assign(size_type count, const reference value);
	reference front();
	const_reference front() const;
	*/
	bool empty() const noexcept;
	/*
	size_type max_size() const noexcept;
	void clear() noexcept; 
*/
	void push_front(const T& value);

/*	void push_front(T&& value);
	void pop_front();
	void resize(size_type count);
	void resize(size_type count, const value_type& value);
	void swap( forward_list& other );
	void merge( forward_list& other );
	void merge( forward_list&& other );
	void remove( const T& value );
	size_type remove( const T& value );
	void reverse() noexcept;
	void unique();
	size_type unique();
	void sort();

*/
	void print();

private:	
	struct Node {
		value_type m_data;
		Node* m_next;
		Node(const value_type& val) 
			: m_data{val}
			, m_next{nullptr}
		{} 
	};
	Node* m_head;
	allocator_type m_allocator;
};

/*
template<typename T, typename Alloc >
bool operator==(const forward_list<T, Alloc>& lhs,
                 const std::forward_list<T, Alloc>& rhs );
template< class T, class Alloc >
bool operator!=( const std::forward_list<T, Alloc>& lhs,
                 const std::forward_list<T, Alloc>& rhs );
template< class T, class Alloc >
bool operator<( const std::forward_list<T, Alloc>& lhs,
                const std::forward_list<T, Alloc>& rhs );
template< class T, class Alloc >
bool operator<=( const std::forward_list<T, Alloc>& lhs,
                 const std::forward_list<T, Alloc>& rhs );
template< class T, class Alloc >
bool operator>( const std::forward_list<T, Alloc>& lhs,
                const std::forward_list<T, Alloc>& rhs );
template< class T, class Alloc >
bool operator>=( const std::forward_list<T, Alloc>& lhs,
                 const std::forward_list<T, Alloc>& rhs );

template< class T, class Alloc >
void swap( std::forward_list<T, Alloc>& lhs,
           std::forward_list<T, Alloc>& rhs );
*/

#include "forward_list.hpp"

#endif // FORWARD_LIST_H
