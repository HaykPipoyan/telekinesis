#ifndef STACK_HPP
#define STACK_HPP

#include "stack.h"
#include <iostream>
#include <vector>

template<typename T, typename Container>
stack<T, Container>::stack() 
	: ob{} 
{
	std::cout << "ctor" << std::endl;
}

template<typename T, typename Container>
stack<T, Container>::stack(const stack& other) 
	: ob{other.ob}
{}

template<typename T, typename Container>
stack<T, Container>::stack(stack&& other)
	: ob{std::move(other.ob)}
{
	other.ob.clear();
}

template<typename T, typename Container>
stack<T, Container>::stack(std::initializer_list<value_type> init)
	: ob{init}
{
	std::cout << "init" << std::endl;
}

template<typename T, typename Container>
stack<T, Container>::~stack() 
{}

template <typename T, typename Container>
void stack<T, Container>::push(const_reference value) 
{
	ob.push_back(value);
}

template <typename T, typename Container>
void stack<T, Container>::pop()
{
	if(empty()) {
		throw std::out_of_range("Stack underflow on pop");
	}
	ob.pop_back();
}

template <typename T, typename Container>
stack<T, Container>::reference 
	stack<T, Container>::top()
{
	if(empty()) {
		throw std::out_of_range("Stack underflow on top");
	}
	return ob.back();
}

template <typename T, typename Container>
stack<T, Container>::size_type 
	stack<T, Container>::size() const
{
	return ob.size();
}

template <typename T, typename Container>
void stack<T, Container>::swap(stack<T, Container>& other)
{
	ob.swap(other.ob);
}

template <typename T, typename Container>
bool stack<T, Container>::empty() const
{
	return ob.empty();
}

template<typename U, typename ContainerU>
bool operator==(const stack<U, ContainerU>& lhs,
                const stack<U, ContainerU>& rhs ) 
{
	std::cout << "operator==";
	return lhs.ob == rhs.ob;
}


template<typename U, typename ContainerU>
bool operator!=(const stack<U, ContainerU>& lhs,
                const stack<U, ContainerU>& rhs )
{
	return lhs.ob != rhs.ob;
}
	
template<typename U, typename ContainerU>
bool operator<=(const stack<U, ContainerU>& lhs,
                const stack<U, ContainerU>& rhs )
{
	return lhs.ob <= rhs.ob;
}

template<typename U, typename ContainerU>
bool operator<(const stack<U, ContainerU>& lhs,
               const stack<U, ContainerU>& rhs )
{
	return lhs.ob < rhs.ob;
}

template<typename U, typename ContainerU>
bool operator>(const stack<U, ContainerU>& lhs,
               const stack<U, ContainerU>& rhs )
{
	return lhs.ob > rhs.ob;
}
	
template<typename U, typename ContainerU>
bool operator>=(const stack<U, ContainerU>& lhs,
                const stack<U, ContainerU>& rhs )
{
	return lhs.ob >= rhs.ob;
}



#endif // STACK_HPP
