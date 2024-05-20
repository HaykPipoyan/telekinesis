#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <initializer_list>
#include "vector.h"

using namespace g3;

    template <typename T, typename Allocator>
    vector<T, Allocator>::vector()
        : m_size {0}
        , m_capacity {0}
        , m_arr {nullptr}
    {
    }

    template <typename T, typename Allocator>
    vector<T, Allocator>::vector(const vector& rhv)
        : m_size {rhv.m_size}
        , m_capacity {rhv.m_capacity}
        , m_allocator {rhv.m_allocator}
    {
        m_arr = m_allocator.allocate(m_capacity);
        for(int i = 0; i < m_size; ++i) {
            m_allocator.construct(&m_arr[i], rhv.data_[i]);
        }
    }
   
    template <typename T, typename Allocator>
    vector<T, Allocator>::vector(vector&& rhv)
        : m_size {rhv.m_size}
        , m_capacity {rhv.m_capasity}
        , m_arr {rhv.m_arr}
    {
        rhv.m_size = 0;
        rhv.m_capacity = 0;
        rhv.m_arr = nullptr;
    }

    template <typename T, typename Allocator>
    vector<T, Allocator>::vector(std::initializer_list<value_type> init)
        :   m_size {init.size()}
        ,   m_capacity {m_size}
        ,   m_arr {m_allocator.allocate(m_capacity)}
     {
        size_t index = 0;
        for (const auto& elem : init) {
           m_allocator.construct(&m_arr[index++], elem);
        }
    }
    
    template <typename T, typename Allocator>
    vector<T, Allocator>::vector(size_type size, const_reference val)
        : m_size {size}
        , m_capacity {size}
    {
        m_arr = m_allocator.allocate(m_capacity);
        for(int i = 0; i < m_size; ++i) {
            m_allocator.allocate(&m_arr[i], val);
        }
    }
    
    template <typename T, typename Allocator>
    template <typename InputIt>
    vector<T, Allocator>::vector(InputIt first, InputIt last)
        :   m_size {0}
    {
        for(InputIt it = first; first != last; ++ it) {
            ++m_size;
        }
        m_capacity = m_size;
        m_arr = m_allocator.allocate(m_capacity);
        size_type i = 0;
        for(InputIt it = first; it != last; ++it, ++i) {
            m_allocator.construct(&m_arr[i], *it);
        }
    }
    
    template<typename T, typename Allocator>
    vector<T, Allocator>::~vector()
    {
        clear();
    }

    template<typename T, typename Allocator>
    const vector<T, Allocator>& 
    vector<T, Allocator>::operator=(const vector& rhv)
    {
        if(this != &rhv) {
            clear();
            m_size = rhv.m_size;
            m_capacity = rhv.m_capacity;
            this->m_arr = m_allocator.allocate(m_capacity);
            for(size_type i = 0; i < m_size; ++i) {
                m_allocator.construct(&this->m_arr[i], rhv.m_arr[i]);
            }
        }
        return *this;
    }

    template<typename T, typename Allocator>
    const vector<T, Allocator>& 
    vector<T, Allocator>::operator=(vector&& rhv)
    {
        if(this != &rhv) {
            clear();
            m_size = rhv.m_size;
            m_capacity = rhv.m_capacity;
            m_arr = rhv.m_arr;

            rhv.m_size = 0;
            rhv.m_capacity = 0;
            rhv.m_arr = nullptr;
        }
        return *this;
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::allocator_type 
    vector<T, Allocator>::get_allocator()
    {
        return this->m_allocator;
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::reference  
    vector<T, Allocator>::at(size_type pos)
    {
        if(pos >= m_capacity) {
            throw std::out_of_range("not correct position");
        }
        return m_arr[pos];
    }
   
    template<typename T, typename Allocator>
    typename vector<T, Allocator>::const_reference  
    vector<T, Allocator>::at(size_type pos) const
    {
        if(pos >= m_capacity) {
            throw std::out_of_range("not correct position");
        }
        return m_arr[pos];
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::reference 
    vector<T, Allocator>::operator[](size_type pos)
    {
        return m_arr[pos];
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::const_reference 
    vector<T, Allocator>::operator[](size_type pos) const
    {
        return m_arr[pos];
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::reference 
    vector<T, Allocator>::front()
    {
        if(m_size == 0) {
            throw std::out_of_range("vector is empty");
        }
        return m_arr[0];

    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::const_reference 
    vector<T, Allocator>::front() const
    {
        if(m_size == 0) {
            throw std::out_of_range("vector is empty");
        }
        return m_arr[0];

    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::reference 
    vector<T, Allocator>::back()
    {
        if(m_size == 0) {
            throw std::out_of_range("vector is empty");
        }
        return m_arr[m_size - 1];
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::const_reference 
    vector<T, Allocator>::back() const
    {
        if(m_size == 0) {
            throw std::out_of_range("vector is empty");
        }
        return m_arr[m_size - 1];
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::iterator
    vector<T, Allocator>::begin()
    {
        return iterator(m_arr);
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::const_iterator
    vector<T, Allocator>::begin() const
    {
        return const_iterator(m_arr);
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::const_iterator
    vector<T, Allocator>::cbegin() const
    {
        return const_iterator(m_arr);
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::iterator
    vector<T, Allocator>::end()
    {
        return iterator(m_arr + m_size);
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::const_iterator
    vector<T, Allocator>::end() const
    {
        return const_iterator(m_arr + m_size);
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::const_iterator
    vector<T, Allocator>::cend() const
    {
        return const_iterator(m_arr + m_size);
    }
    
    template<typename T, typename Allocator>
    typename vector<T, Allocator>::iterator
    vector<T, Allocator>::rbegin()
    {
        return iterator(m_arr + m_size - 1);
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::const_iterator
    vector<T, Allocator>::rbegin() const
    {
        return const_iterator(m_arr + m_size - 1);
    }
 
    template<typename T, typename Allocator>
    typename vector<T, Allocator>::const_iterator
    vector<T, Allocator>::crbegin() const
    {
        return const_iterator(m_arr + m_size - 1);
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::iterator
    vector<T, Allocator>::rend()
    {
        return iterator(m_arr - 1);
    }
    
    template<typename T, typename Allocator>
    typename vector<T, Allocator>::const_iterator
    vector<T, Allocator>::rend() const
    {
        return const_iterator(m_arr - 1);
    }
 
    template<typename T, typename Allocator>
    typename vector<T, Allocator>::const_iterator
    vector<T, Allocator>::crend() const
    {
        return const_iterator(m_arr - 1);
    }
    
    template<typename T, typename Allocator>
    bool vector<T, Allocator>::empty() const
    {   
        return m_size == 0;
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::size_type 
    vector<T, Allocator>::size() const
    {
        return m_size;
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::size_type 
    vector<T, Allocator>::capacity() const
    {
        return m_size;
    }

    template<typename T, typename Allocator>
    void vector<T, Allocator>::reserve(size_type new_cap)
    {
        if(m_capacity <= new_cap) {
            m_capacity = new_cap;
            T* tmp = m_allocator.allocate(m_capacity);
            for(size_type i = 0; i < m_size; ++i) {
                m_allocator.construct(&tmp[i], m_arr[i]);
            }
            clear();
            m_arr = tmp;
        }
        return;
    }

    template<typename T, typename Allocator>
    void vector<T, Allocator>::clear() noexcept
    {
        for(size_type i = 0; i < m_size; ++i) {
            m_allocator.destroy(&m_arr[i]);
        }
        m_allocator.deallocate(m_arr, m_capacity);
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::iterator 
    vector<T, Allocator>::insert(const_iterator pos, const_reference val)
    {
        size_type index = pos - begin();
        if (index > m_size) {
            throw std::out_of_range("insert position is out of range");
        }
        if (m_size == m_capacity) {
            reserve(m_capacity > 0 ? 2 * m_capacity : 1);
        }
        for (size_type i = m_size; i > index; --i) {
            m_arr[i] = m_arr[i - 1];
        }
        m_arr[index] = val;
        ++m_size;

        return begin() + index;
    }
    

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::iterator 
    vector<T, Allocator>::insert(const_iterator pos, size_type count, const_reference val)
    {
        for(size_type i = 0; i < count; ++i) {
            pos = insert(pos, val);
            ++pos;
        }
        return pos;
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::iterator 
    vector<T, Allocator>::insert(const_iterator pos, std::initializer_list<value_type> init)
    {
        for(T& i : init) {
            pos = insert(pos, i);
            ++pos;
        }
        return pos;
    }

    template<typename T, typename Allocator>
    template <typename InputIt>
    typename vector<T, Allocator>::iterator 
    vector<T, Allocator>::insert(const_iterator pos, InputIt first, InputIt last)
    {
        for( ; first != last; ++first) {
            pos = insert(pos, *first);
            ++pos;
        }
        return pos;
    }
   
    template <typename T, typename Allocator>
    typename vector<T, Allocator>::iterator 
    vector<T, Allocator>::erase(const_iterator pos)
    {
         iterator non_const_pos = begin() + (pos - cbegin());
        if (non_const_pos < begin() || non_const_pos >= end()) {
            throw std::out_of_range("distance is out of bounds or incorrect");
        }
        for (iterator it = non_const_pos; it != end() - 1; ++it) {
            *it = std::move(*(it + 1));
        }
        --m_size;
        m_allocator.destroy(&m_arr[m_size]);
        return non_const_pos;
    }

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::iterator 
    vector<T, Allocator>::erase(const_iterator first, const_iterator last)
    {
        iterator non_const_first = begin() + (first - cbegin());
        iterator non_const_last = begin() + (last - cbegin());
        if (non_const_first < begin() || non_const_first >= end() ||
            non_const_last < begin() || non_const_last > end() ||
            non_const_first > non_const_last) {
            throw std::out_of_range("distance is out of bounds or incorrect");
        }
        size_type num_elements_to_remove = non_const_last - non_const_first;
        iterator it = non_const_first;
        for (; non_const_last != end(); ++non_const_last, ++it) {
            *it = std::move(*non_const_last);
        }
        m_size -= num_elements_to_remove;
        for (iterator destroy_it = end(); destroy_it != end() + num_elements_to_remove; ++destroy_it) {
            m_allocator.destroy(&*destroy_it);
        }
        return non_const_first;
    }
    
    template<typename T, typename Allocator>
    void vector<T, Allocator>::push_back(const_reference val)
    {
        if(m_size == m_capacity) {
            m_capacity *= 2;
            reserve(m_capacity);
        }
        m_allocator.construct(&m_arr[m_size++], val);
    }

    template<typename T, typename Allocator>
    void vector<T, Allocator>::pop_back()
    {
        if(m_size > 0) {
            m_allocator.destroy(&m_arr[m_size - 1]);
            --m_size;
        }
    }

    template<typename T, typename Allocator>
    void vector<T, Allocator>::resize(size_type new_size, const_reference val)
    {
        if(m_size == new_size) {
            return;
        }
        if(m_size > new_size) {
            for(size_type i = m_size - 1; i != new_size - 1; --i) {
                m_allocator.destroy(&m_arr[i]);
                --m_size;
            }
        } else if (m_size < new_size) {
            if(new_size > m_capacity) {
                reserve(new_size);
            }
        for(size_type i = m_size; i < new_size; ++i) {
            m_allocator.construct(&m_arr[i], val);
        }
        m_size = new_size;
        }
    }

    template<typename T, typename Allocator>
    bool vector<T, Allocator>::operator==(const vector& other) const
    {
        std::cout << "==" << std::endl;
        if(m_size == other.size()) {
            for(size_type i = 0; i < m_size; ++i) {
                if(m_arr[i] != other.m_arr[i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
 
    template<typename T, typename Allocator>
    bool vector<T, Allocator>::operator!=(const vector& other) const
    {
        std::cout << "!=" << std::endl;
        return !operator==(other);
    }
 
    template<typename T, typename Allocator>
    bool vector<T, Allocator>::operator<(const vector& other) const
    {
        if(m_size < other.size()) {
            return true;
        } else if(m_size > other.size()) {
            return false;
        }
        for(size_type i = 0; i < m_size; ++i) {
            if(m_arr[i] < other.m_arr[i]) {
                return true;
            } else if (m_arr[i] > other.m_arr[i]) {
                return false;
            }
        }
        return false;
    }

    template<typename T, typename Allocator>
    bool vector<T, Allocator>::operator<=(const vector& other) const
    {
        if(m_size <= other.size()) {
            return true;
        } else if(m_size > other.size()) {
            return false;
        }
        for(size_type i = 0; i < m_size; ++i) {
            if(m_arr[i] <= other.m_arr[i]) {
                return true;
            } else if (m_arr[i] > other.m_arr[i]) {
                return false;
            }
        }
    }

    template<typename T, typename Allocator>
    bool vector<T, Allocator>::operator>(const vector& other) const
    {
        if(m_size > other.size()) {
            return true;
        } else if(m_size < other.size()) {
            return false;
        }
        for(size_type i = 0; i < m_size; ++i) {
            if(m_arr[i] > other.m_arr[i]) {
                return true;
            } else if (m_arr[i] < other.m_arr[i]) {
                return false;
            }
        }
        return false;
    }

    template<typename T, typename Allocator>
    bool vector<T, Allocator>::operator>=(const vector& other) const
    {
        if(m_size >= other.size()) {
            return true;
        } else if(m_size < other.size()) {
            return false;
        }
        for(size_type i = 0; i < m_size; ++i) {
            if(m_arr[i] >= other.m_arr[i]) {
                return true;
            } else if (m_arr[i] < other.m_arr[i]) {
                return false;
            }
        }
    }   

    template <typename T, typename Allocator>
    int vector<T, Allocator>::compare(const vector& other) const
    {
        if (m_size < other.m_size) {
            return -1;
        } else if (m_size > other.m_size) {
            return 1;
        }
        for (size_type i = 0; i < m_size; ++i) {
            if (m_arr[i] < other.m_arr[i]) {
                return -1;
            } else if (m_arr[i] > other.m_arr[i]) {
                return 1;
            }
        }
        return 0;
    }
    
    template <typename T, typename Allocator>
    vector<T, Allocator>::const_iterator::const_iterator(pointer ptr) 
        : ptr{ptr} 
    {}

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::const_iterator 
    vector<T, Allocator>::const_iterator::operator+(size_type n) const
    {
        return const_iterator(ptr + n);
    }    
 
    template <typename T, typename Allocator>
    typename vector<T, Allocator>::const_iterator 
    vector<T, Allocator>::const_iterator::operator-(size_type n) const
    {
        return const_iterator(ptr - n);
    }    
 
    template <typename T, typename Allocator>
    typename vector<T, Allocator>::const_iterator& 
    vector<T, Allocator>::const_iterator::operator++()
    {
        ++ptr;
        return *this;
    }
    
    template <typename T, typename Allocator>
    typename vector<T, Allocator>::const_iterator 
    vector<T, Allocator>::const_iterator::operator++(int)
    {
        const_iterator tmp = *this;
        ++ptr;
        return tmp;
    }

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::const_iterator& 
    vector<T, Allocator>::const_iterator::operator--()
    {
        --ptr;
        return *this;
    }

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::const_iterator 
    vector<T, Allocator>::const_iterator::operator--(int)
    {
        const_iterator tmp = *this;
        --ptr;
        return tmp;
    }

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::const_reference
    vector<T, Allocator>::const_iterator::operator*() const
    {
        return *ptr;
    }

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::const_pointer
    vector<T, Allocator>::const_iterator::operator->() const
    {
        return ptr;
    }

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::const_reference
    vector<T, Allocator>::const_iterator::operator[](size_type pos) const
    {
        return ptr[pos];
    }

    template <typename T, typename Allocator>
    bool vector<T, Allocator>::const_iterator::operator==(const const_iterator& other) const
    {
        return ptr == other.ptr;
    } 

    template <typename T, typename Allocator>
    bool vector<T, Allocator>::const_iterator::operator!=(const const_iterator& other) const
    {
        return ptr != other.ptr;
    }

    template <typename T, typename Allocator>
    bool vector<T, Allocator>::const_iterator::operator<(const const_iterator& other) const
    {
        return ptr < other.ptr;
    }  

    template <typename T, typename Allocator>
    bool vector<T, Allocator>::const_iterator::operator<=(const const_iterator& other) const
    {
        return ptr <= other.ptr;
    }  

    template <typename T, typename Allocator>
    bool vector<T, Allocator>::const_iterator::operator>(const const_iterator& other) const
    {
        return ptr > other.ptr;
    }     

    template <typename T, typename Allocator>
    bool vector<T, Allocator>::const_iterator::operator>=(const const_iterator& other) const
    {
        return ptr >= other.ptr;
    }      

    template <typename T, typename Allocator>
    vector<T, Allocator>::iterator::iterator(pointer ptr) 
        : const_iterator::ptr {ptr} 
    {}

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::iterator 
    vector<T, Allocator>::iterator::operator+(size_type n) const
    {
        return iterator(const_iterator::ptr + n);
    }    

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::iterator 
    vector<T, Allocator>::iterator::operator-(size_type n) const
    {
        return iterator(const_iterator::ptr - n);
    }    

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::iterator& 
    vector<T, Allocator>::iterator::operator++()
    {
        ++const_iterator::ptr;
        return *this;
    }

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::iterator 
    vector<T, Allocator>::iterator::operator++(int)
    {
        iterator tmp = *this;
        ++const_iterator::ptr;
        return tmp;
    }

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::iterator& 
    vector<T, Allocator>::iterator::operator--()
    {
        --const_iterator::ptr;
        return *this;
    }

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::iterator 
    vector<T, Allocator>::iterator::operator--(int)
    {
        iterator tmp = *this;
        --const_iterator::ptr;
        return tmp;
    }

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::reference
    vector<T, Allocator>::iterator::operator*()
    {
        return *const_iterator::ptr;
    }

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::pointer
    vector<T, Allocator>::iterator::operator->() 
    {
        return const_iterator::ptr;
    }

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::reference
    vector<T, Allocator>::iterator::operator[](size_type pos) const
    {
        return const_iterator::ptr[pos];
    }

    template <typename T, typename Allocator>
    vector<T, Allocator>::const_reverse_iterator::const_reverse_iterator(pointer ptr)
    : ptr {ptr}
    {}

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::const_reverse_iterator 
    vector<T, Allocator>::const_reverse_iterator::operator+(size_type n) const
    {
        return const_iterator(ptr - n);
    }    
     
    template <typename T, typename Allocator>
    typename vector<T, Allocator>::const_reverse_iterator 
    vector<T, Allocator>::const_reverse_iterator::operator-(size_type n) const
    {
        return const_iterator(ptr + n);
    }    
    
    template <typename T, typename Allocator>
    typename vector<T, Allocator>::const_reverse_iterator& 
    vector<T, Allocator>::const_reverse_iterator::operator++()
    {
        --ptr;
        return *this;
    }

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::const_reverse_iterator 
    vector<T, Allocator>::const_reverse_iterator::operator++(int)
    {
        const_iterator tmp = *this;
        --ptr;
        return tmp;
    }

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::const_reverse_iterator& 
    vector<T, Allocator>::const_reverse_iterator::operator--()
    {
        ++ptr;
        return *this;
    }

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::const_reverse_iterator 
    vector<T, Allocator>::const_reverse_iterator::operator--(int)
    {
        const_iterator tmp = *this;
        ++ptr;
        return tmp;
    }
  
    template <typename T, typename Allocator>
    typename vector<T, Allocator>::const_reference
    vector<T, Allocator>::const_reverse_iterator::operator*() const
    {
        return *ptr;
    }

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::const_pointer
    vector<T, Allocator>::const_reverse_iterator::operator->() const
    {
        return ptr;
    }

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::const_reference
    vector<T, Allocator>::const_reverse_iterator::operator[](size_type pos) const
    {
        return ptr[pos];
    }

    template <typename T, typename Allocator>
    bool vector<T, Allocator>::const_reverse_iterator::operator==(const const_reverse_iterator& other) const
    {
        return ptr == other.ptr;
    } 

    template <typename T, typename Allocator>
    bool vector<T, Allocator>::const_reverse_iterator::operator!=(const const_reverse_iterator& other) const
    {
        return ptr != other.ptr;
    }

    template <typename T, typename Allocator>
    bool vector<T, Allocator>::const_reverse_iterator::operator<(const const_reverse_iterator& other) const
    {
        return ptr > other.ptr;
    }  

    template <typename T, typename Allocator>
    bool vector<T, Allocator>::const_reverse_iterator::operator<=(const const_reverse_iterator& other) const
    {
        return ptr >= other.ptr;
    }  

    template <typename T, typename Allocator>
    bool vector<T, Allocator>::const_reverse_iterator::operator>(const const_reverse_iterator& other) const
    {
        return ptr < other.ptr;
    }     

    template <typename T, typename Allocator>
    bool vector<T, Allocator>::const_reverse_iterator::operator>=(const const_reverse_iterator& other) const
    {
        return ptr <= other.ptr;
    }     

    template <typename T, typename Allocator>
    vector<T, Allocator>::reverse_iterator::reverse_iterator(pointer ptr)
    : const_reverse_iterator::ptr {ptr}
    {}

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::reverse_iterator 
    vector<T, Allocator>::reverse_iterator::operator+(size_type n) const
    {
        return reverse_iterator(const_reverse_iterator::ptr - n);
    }    

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::reverse_iterator 
    vector<T, Allocator>::reverse_iterator::operator-(size_type n) const
    {
        return reverse_iterator(const_reverse_iterator::ptr - n);
    }   

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::reverse_iterator& 
    vector<T, Allocator>::reverse_iterator::operator++()
    {
        --const_reverse_iterator::ptr;
        return *this;
    }

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::reverse_iterator 
    vector<T, Allocator>::reverse_iterator::operator++(int)
    {
        reverse_iterator tmp = *this;
        ++const_reverse_iterator::ptr;
        return tmp;
    }
    
    template <typename T, typename Allocator>
    typename vector<T, Allocator>::reverse_iterator& 
    vector<T, Allocator>::reverse_iterator::operator--()
    {
        ++const_reverse_iterator::ptr;
        return *this;
    }

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::reverse_iterator 
    vector<T, Allocator>::reverse_iterator::operator--(int)
    {
        reverse_iterator tmp = *this;
        --const_reverse_iterator::ptr;
        return tmp;
    }

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::reference
    vector<T, Allocator>::reverse_iterator::operator*()
    {
        return *const_reverse_iterator::ptr;
    }

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::pointer
    vector<T, Allocator>::reverse_iterator::operator->()
    {
        return const_reverse_iterator::ptr;
    }

    template <typename T, typename Allocator>
    typename vector<T, Allocator>::reference
    vector<T, Allocator>::reverse_iterator::operator[](size_type pos) const
    {
        return *(const_reverse_iterator::ptr - pos - 1);
    }

#endif // VECTOR_HPP


