#ifndef STACK_H
#define STACK_H

#include <vector>
#include <initializer_list>

template< typename T, typename Container = std::vector<T>>
class stack {
public:
	using container_type = Container;
	using value_type = Container::value_type;
	using size_type = Container::size_type;
	using reference = Container::reference;
	using const_reference = Container::const_reference;

	stack();
	stack(const stack& other);
	stack(stack&& other);
	stack(std::initializer_list<value_type> init);
	~stack();

	void push(const_reference value);
	void pop();
	reference top();
	size_type size() const;
	void swap(stack<T, Container>& other); 
	bool empty() const;

	friend bool operator==(const stack<T, Container>& lhs,
		                   const stack<T, Container>& rhs );	

	friend bool operator!=(const stack<T, Container>& lhs,
		                   const stack<T, Container>& rhs );	

	friend bool operator<(const stack<T, Container>& lhs,
		                  const stack<T, Container>& rhs );	

	friend bool operator<=(const stack<T, Container>& lhs,
		                   const stack<T, Container>& rhs );	

	friend bool operator>(const stack<T, Container>& lhs,
		                  const stack<T, Container>& rhs );	

	friend bool operator>=(const stack<T, Container>& lhs,
		                   const stack<T, Container>& rhs );	

private:
	Container ob;
};

template<typename T, typename Container = std::vector<T>>
bool operator==(const stack<T, Container>& lhs,
                const stack<T, Container>& rhs );	


template<typename T, typename Container = std::vector<T>>
bool operator!=(const stack<T, Container>& lhs,
                const stack<T, Container>& rhs );


template<typename T, typename Container = std::vector<T>>
bool operator<(const stack<T, Container>& lhs,
               const stack<T, Container>& rhs );
	
template<typename T, typename Container = std::vector<T>>
bool operator<=(const stack<T, Container>& lhs,
                const stack<T, Container>& rhs );

template<typename T, typename Container = std::vector<T>>
bool operator>(const stack<T, Container>& lhs,
               const stack<T, Container>& rhs );
	
template<typename T, typename Container = std::vector<T>>
bool operator>=(const stack<T, Container>& lhs,
                const stack<T, Container>& rhs );


#include "stack.hpp"

#endif // STACK_H
