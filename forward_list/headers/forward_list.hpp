#ifndef FORWARD_LIST_HPP
#define FORWARD_LIST_HPP

#include "forward_list.h"
#include <iostream>
#include <initializer_list>


template <typename T, typename Allocator>
forward_list<T, Allocator>::forward_list() 
	: m_head {nullptr}
	, m_allocator {}
{}

template <typename T, typename Allocator>
forward_list<T, Allocator>::forward_list(const Allocator& alloc)
	: m_head {nullptr}
	, m_allocator(alloc)
{}

template <typename T, typename Allocator>
forward_list<T, Allocator>::forward_list(size_type count, const T& value, const Allocator& alloc = Allocator())
    : m_head(nullptr), m_allocator(alloc) 
{
    Node* current = nullptr;
    for (size_type i = 0; i < count; ++i) {
        Node* newNode = m_allocator.allocate(1); 
        std::allocator_traits<Allocator>::construct(m_allocator, &newNode->m_data, value); 
        newNode->m_next = nullptr; 

        if (!m_head) { 
            m_head = newNode;
            current = m_head;
        } else { 
            current->m_next = newNode;
            current = newNode;
        }
    }
}

template <typename T, typename Allocator>
forward_list<T, Allocator>::forward_list(size_type count, const Allocator& alloc = Allocator())
	: m_head(nullptr)
	, m_allocator(alloc) 
{
    Node* current = nullptr;
    for (size_type i = 0; i < count; ++i) {
        Node* newNode = m_allocator.allocate(1); 
        std::allocator_traits<Allocator>::construct(m_allocator, &newNode->m_data); 

        newNode->m_next = nullptr; 

        if (!m_head) { 
            m_head = newNode;
            current = m_head;
        } else { 
            current->m_next = newNode;
            current = newNode;
        }
    }
}

template <typename T, typename Allocator>
forward_list<T, Allocator>::forward_list(const forward_list& other)
	: m_head(nullptr)
	, m_allocator(other.m_allocator) 
{
    Node* current = nullptr;
    Node* otherCurrent = other.m_head;

    while (otherCurrent) {
        Node* newNode = m_allocator.allocate(1); 
        std::allocator_traits<Allocator>::construct(m_allocator, &newNode->m_data, otherCurrent->m_data); 

        newNode->m_next = nullptr; 

        if (!m_head) { 
            m_head = newNode;
            current = m_head;
        } else { 
            current->m_next = newNode;
            current = newNode;
        }

        otherCurrent = otherCurrent->m_next; 
    }
}



// 	forward_list(const forward_list& other, const Allocator& alloc);
// 	forward_list(forward_list&& other);
// 	forward_list(forward_list&& other, const Allocator& alloc);
// 	forward_list(std::initializer_list<T> init,
//               const Allocator& alloc = Allocator());
// 	~forward_list();


// template<typename T>
// forward_list<T>::forward_list(size_type count, value_type val)
//     : m_head(nullptr) 
// {
//     myAllocator alloc;
//     Node* nodes = alloc.allocate(count); 
//     for (size_type i = 0; i < count; ++i) {
//         new(&nodes[i]) Node(val); 
//         if (!m_head) {
//             m_head = &nodes[i];
//         } else {
//             nodes[i].m_next = m_head;
//             m_head = &nodes[i];
//         }
//     }
// }


// template<typename T>
// forward_list<T>::forward_list(value_type val)
// 	: m_head {nullptr}
// {
// 	push_front(val);
// }

// template<typename T>
// forward_list<T>::forward_list(std::initializer_list<value_type> list)
//     : m_head{nullptr}
// {
//     for (const_reference value : list) {
//         push_front(value);
//     }
// }

// template<typename T>
// forward_list<T>::forward_list(const forward_list& other)
// 	: m_head{nullptr}
// {
// 	if(other.empty()) {
// 		return;
// 	}
// 	Node* tmp = other.m_head;
//     while (tmp != nullptr) {
//         push_front(tmp->m_data);
//         tmp = tmp->m_next;
// 	}
// }

// template<typename T>
// forward_list<T>::forward_list(forward_list&& other)
// 	: m_head{other.m_head}
// {
// 	other.m_head();
// }
// template<typename T>
// forward_list<T>::~forward_list() 
// {
//     myAllocator alloc;
//     Node* current = m_head;
//     while (current != nullptr) {
//         Node* next = current->m_next;
//         current->~Node(); 
//         current = next;
//     }
//     alloc.deallocate(m_head); 
// }

/*
template<typename T>
forward_list& forward_list<T>::operator=(const forward_list& other)
{
	
}


	forward_list& operator=(forward_list&& other);
	forward_list& operator=(std::initializer_list<value_type> list);
	void assign(size_type count, const reference value);
	reference front();
	const_reference front() const;
	*/
template<typename T>
bool forward_list<T>::empty() const noexcept
{
	return m_head == nullptr;
}
	/*
	size_type max_size() const noexcept;
	void clear() noexcept;
*/
template<typename T>
void forward_list<T>::push_front(const T& value)
{
	Node* new_node = new Node(value);
	if(!m_head) {
		m_head = new_node;
	} else {
		new_node->m_next = m_head;
		m_head = new_node;
	}
}

/*
	void push_front(T&& value);
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
template<typename T>
void forward_list<T>::print()
{
	Node* tmp = m_head;
	while(tmp) {
		std::cout << tmp->m_data << " ";
		tmp = tmp->m_next;
	}
	std::cout << std::endl;
}
template<typename T>
forward_list<T>::Node* forward_list<T>::myAllocator::allocate(std::size_t n) {
    Node* new_nodes = new Node[n];
    return new_nodes;
}
template<typename T>
void forward_list<T>::myAllocator::deallocate(void* ptr)
{
	delete ptr;
}


#endif // FORWARD_LIST_HPP
