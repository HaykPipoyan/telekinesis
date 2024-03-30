#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

#include "../headers/queue.h"

template<typename T, typename Container>
queue<T, Container>::queue() 
	: ob{}
{}


template<typename T, typename Container>
queue<T, Container>::queue(const queue& other)
	: ob{other.ob}
{
	std::cout << "copy" << std::endl;
}

template<typename T, typename Container>
queue<T, Container>::queue(queue&& other)
	: ob{std::move(other.ob)}
{
	other.ob.clear();
	std::cout << "move" << std::endl;
}

template<typename T, typename Container>
queue<T, Container>::queue(std::initializer_list<value_type> init)
	: ob{init}
{
	std::cout << "init" << std::endl; 
}

template<typename T, typename Container>
queue<T, Container>::~queue()
{
	std::cout << "dtor" << std::endl;
}

template<typename T, typename Container>
void queue<T, Container>::push(Container::const_reference value)
{
	ob.push_back(value);
	std::cout << "push" << std::endl;
}

template<typename T, typename Container>
void queue<T, Container>::pop()
{
	if(empty()) {
		throw std::out_of_range("Stack underflow on pop");
	}
	ob.pop_back();
	std::cout << "pop" << std::endl;
}

template<typename T, typename Container>
queue<T, Container>::reference 
queue<T, Container>::front()
{
	if(empty()) {
		throw std::out_of_range("Stack underflow");
	}
	std::cout << "front" << std::endl;
	return ob.front();
}

template<typename T, typename Container>
Container::size_type
queue<T, Container>::size() const
{
	std::cout << "size" << std::endl;
	return ob.size();
}

template <typename T, typename Container>
void queue<T, Container>::swap(queue<T, Container>& other)
{
	std::cout << "swap" << std::endl;
	ob.swap(other.ob);
}

template<typename T, typename Container>
bool queue<T, Container>::empty() const
{
	std::cout << "empty" << std::endl;
	return ob.empty();
}

template <typename U, class ContainerU>
bool operator==(const queue<U, ContainerU>& lhs,
                const queue<U, ContainerU>& rhs )
{
	std::cout << "operator==" << std::endl;
	return  lhs.ob == rhs.ob;
} 

template <typename U, class ContainerU>
bool operator!=(const queue<U, ContainerU>& lhs,
                const queue<U, ContainerU>& rhs )
{
	std::cout << "operator!=" << std::endl;
	return lhs.ob != rhs.ob;
}
	
template <typename U, class ContainerU>
bool operator<(const queue<U, ContainerU>& lhs,
               const queue<U, ContainerU>& rhs )
{	
	std::cout << "operator<" << std::endl;
	return lhs.ob < rhs.ob;
}
	
template <typename U, class ContainerU>
bool operator<=(const queue<U, ContainerU>& lhs,
                const queue<U, ContainerU>& rhs )
{	
	std::cout << "operator<=" << std::endl;
	return lhs.ob <= rhs.ob;
}
	
template <typename U, class ContainerU>
bool operator>(const queue<U, ContainerU>& lhs,
               const queue<U, ContainerU>& rhs )
{
	std::cout << "operator>" << std::endl;
	return lhs.ob > rhs.ob;
}
	
template <typename U, class ContainerU>
bool operator>=(const queue<U, ContainerU>& lhs,
                const queue<U, ContainerU>& rhs )
{	
	std::cout << "operator>=" << std::endl;
	return lhs.ob >= rhs.ob;
}


#endif // QUEUE_HPP
