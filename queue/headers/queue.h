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

	queue();
	queue(const queue& other);
	queue(queue&& other);
	queue(std::initializer_list<value_type> init);
	~queue();

	void push(const Container::const_reference value);
	void pop();
	reference front();
	size_type size() const;
	void swap(queue<T, Container>& other);
	bool empty() const;

	template <typename U, class ContainerU>
	friend bool operator==(const queue<U, ContainerU>& lhs,
						   const queue<U, ContainerU>& rhs );

	template <typename U, class ContainerU>
	friend bool operator!=(const queue<U, ContainerU>& lhs,
						   const queue<U, ContainerU>& rhs );

	template <typename U, class ContainerU>
	friend bool operator<(const queue<U, ContainerU>& lhs,
						  const queue<U, ContainerU>& rhs );

	template <typename U, class ContainerU>
	friend bool operator<=(const queue<U, ContainerU>& lhs,
						   const queue<U, ContainerU>& rhs );

	template <typename U, class ContainerU>
	friend bool operator>(const queue<U, ContainerU>& lhs,
						  const queue<U, ContainerU>& rhs );

	template <typename U, class ContainerU>
	friend bool operator>=(const queue<U, ContainerU>& lhs,
						   const queue<U, ContainerU>& rhs );

private:
	Container ob;
};

template <typename U, class ContainerU>
bool operator==(const queue<U, ContainerU>& lhs,
                const queue<U, ContainerU>& rhs );
	
template <typename U, class ContainerU>
bool operator!=(const queue<U, ContainerU>& lhs,
                const queue<U, ContainerU>& rhs );
	
template <typename U, class ContainerU>
bool operator<(const queue<U, ContainerU>& lhs,
               const queue<U, ContainerU>& rhs );
	
template <typename U, class ContainerU>
bool operator<=(const queue<U, ContainerU>& lhs,
                const queue<U, ContainerU>& rhs );
	
template <typename U, class ContainerU>
bool operator>(const queue<U, ContainerU>& lhs,
               const queue<U, ContainerU>& rhs );
	
template <typename U, class ContainerU>
bool operator>=(const queue<U, ContainerU>& lhs,
                const queue<U, ContainerU>& rhs );
	


#include "queue.hpp"

#endif // QUEUE_H
