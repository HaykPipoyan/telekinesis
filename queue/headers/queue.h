#ifndef QUEUE_H
#define QUEUE_H

#include <vector>

template<typename T, typename Container = std::vector<T>>
class queue 
{
public:
	using container_type = Container;
	using value_type = Container::value_type;
	using size_type = Container::size_type;
	using reference = Container::reference;
	using const_reference = Container::const_reference;

public:
	queue();
//	queue(const queue& other);
//	queue(queue&& other);
//	queue(std::initializer_list<value_type> init);
//	~queue();
/*
public:
	void push(const value_type& value);
	void pop();
	reference front();
	size_type size() const;
	void swap(queue<T, Container>& other);
	bool empty() const;
*/
private:
	Container ob;
};

/*
template< class T, class Container >
bool operator==( const queue<T, Container>& lhs,
                 const queue<T, Container>& rhs );
	
template< class T, class Container >
bool operator!=( const queue<T, Container>& lhs,
                 const queue<T, Container>& rhs );
	
template< class T, class Container >
bool operator< ( const queue<T, Container>& lhs,
                 const queue<T, Container>& rhs );
	
template< class T, class Container >
bool operator<=( const queue<T, Container>& lhs,
                 const queue<T, Container>& rhs );
	
template< class T, class Container >
bool operator> ( const queue<T, Container>& lhs,
                 const queue<T, Container>& rhs );
	
template< class T, class Container >
bool operator>=( const queue<T, Container>& lhs,
                 const queue<T, Container>& rhs );
	
template< class T, std::three_way_comparable Container >
std::compare_three_way_result_t<Container>
    operator<=>( const queue<T, Container>& lhs,
                 const queue<T, Container>& rhs );

*/

#include "queue.hpp"

#endif // QUEUE_H
