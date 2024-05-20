#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include "queue.h"

using namespace g3;

template<typename T, typename Container>
queue<T, Container>::queue() 
	: ob{}
{}

template<typename T, typename Container>
queue<T, Container>::queue(const queue& rhv)
	: ob{rhv.ob}
{}

template<typename T, typename Container>
queue<T, Container>::queue(queue&& rhv)
	: ob{std::move(rhv.ob)}
{
	rhv.ob.clear();
}

template<typename T, typename Container>
queue<T, Container>::queue(std::initializer_list<value_type> init)
	: ob{init}
{}

template<typename T, typename Container>
template <typename InputIt>
queue<T, Container>::queue(InputIt first, InputIt last)
	: ob(first, last)
{}

template<typename T, typename Container>
queue<T, Container>::~queue()
{}

template<typename T, typename Container>
const queue<T, Container>& 
queue<T, Container>::operator=(const queue& rhv)
{
	if(this != & rhv.ob) {
		ob = rhv.ob;
	}
	return *this;
}

template<typename T, typename Container>
const queue<T, Container>& 
queue<T, Container>::operator=(queue&& rhv)
{
	if(this != & rhv.ob) {
		ob = std::move(rhv.ob);
	}
	return *this;
}

template<typename T, typename Container>
typename queue<T, Container>::reference 
queue<T, Container>::front()
{
	if(empty()) {
		throw std::out_of_range("queue underflow");
	}
	return ob.front();
}

template<typename T, typename Container>
typename queue<T, Container>::const_reference 
queue<T, Container>::front() const
{
	if(empty()) {
		throw std::out_of_range("queue underflow");
	}
	return ob.front();
}

template<typename T, typename Container>
typename queue<T, Container>::reference 
queue<T, Container>::back()
{
	if(empty()) {
        throw std::out_of_range("queue underflow");
    }
    return ob.back();
}

template<typename T, typename Container>
typename queue<T, Container>::const_reference 
queue<T, Container>::back() const
{
	if(empty()) {
        throw std::out_of_range("queue underflow");
    }
    return ob.back();
}

template<typename T, typename Container>
bool queue<T, Container>::empty() const
{
	return ob.empty();
}

template<typename T, typename Container>
typename queue<T, Container>::size_type
queue<T, Container>::size() const
{
	return ob.size();
}

template<typename T, typename Container>
void queue<T, Container>::push(const_reference val)
{
	ob.push_back(val);
}

template<typename T, typename Container>
void queue<T, Container>::pop()
{
	if(empty()) {
		throw std::out_of_range("queue underflow on pop");
	}
	ob.pop_back();
}

template <typename T, class Container>
bool queue<T, Container>::operator==(const queue& other)
{
	return  this->ob == other.ob;
} 

template <typename T, class Container>
bool queue<T, Container>::operator!=(const queue& other)
{
	return  this->ob != other.ob;
} 

template <typename T, class Container>
bool queue<T, Container>::operator<(const queue& other)
{
	return  this->ob < other.ob;
} 
	
template <typename T, class Container>
bool queue<T, Container>::operator<=(const queue& other)
{
	return  this->ob <= other.ob;
} 

template <typename T, class Container>
bool queue<T, Container>::operator>(const queue& other)
{
	return  this->ob > other.ob;
} 

template <typename T, class Container>
bool queue<T, Container>::operator>=(const queue& other)
{
	return  this->ob >= other.ob;
} 

#endif // QUEUE_HPP
