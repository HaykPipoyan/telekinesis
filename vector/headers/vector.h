#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

template<typename T>
class vector {
public:
	using value_type = T;
	using size_type = size_t;
	using referance = value_type&;
	using const_referance = const value_type&;
	using pointer = value_type*;
	using const_pointer = const value_type*;

public:
	vector();
	vector(size_type size);
	vector(size_type size, value_type val);
	vector(const vector& other);
	vector(vector&& other);
	~vector();

public:
	const vector& operator=(const vector& rhv);
	const vector& operator=(vector&& rhv);
	referance operator[](size_type pos);

	void clear();
	void push_back(const_referance value);
	void pop_back();
	size_type size() const;

private:
	void reallocator();

private:
	size_type m_size;
	size_type m_capacity;
	pointer m_arr;
};

#include "../src/vector.hpp"

#endif // VECTOR_H
