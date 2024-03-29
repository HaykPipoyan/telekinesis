#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "../headers/queue.h"

template<typename T, typename Container>
queue<T, Container>::queue()
	:ob{}
{}
/*
template<typename T, typename Container>
queue<T, Container>::queue(const queue& other)
	: ob{other.ob}
{}

template<typename T, typename Container>
queue<T, Container>::queue(queue&& other)
	: ob{std::move(other.ob)}
{
	other.ob.clear();
}

template<typename T, typename Container>
queue<T, Container>::queue(std::initializer_list<value_type> init)
	: ob{init}
{}

template<typename T, typename Container>
queue<T, Container>::~queue()
{}
*/

/*
public:
	void push(const value_type& value);
	void pop();
	reference front();
	size_type size() const;
	void swap(queue<T, Container>& other);
	bool empty() const;
*/
/*
	using container_type = Container;
	using value_type = Container::value_type;
	using size_type = Container::size_type;
	using reference = Container::reference;
	using const_reference = Container::const_reference;
*/

#endif // QUEUE_HPP
