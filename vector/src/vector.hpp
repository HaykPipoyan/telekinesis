//#include "vector.h"

template<typename T>
vector<T>::vector() 
	: m_size{0}
	, m_capacity{0} 
	, m_arr{nullptr}
{}

template<typename T>
vector<T>::vector(size_type size) 
	: m_size{size}
	, m_capacity{2 * size}
	, m_arr{new value_type[m_capacity]}
{}

template<typename T>
vector<T>::vector(size_type size, value_type val) 
	: m_size{size}
	, m_capacity{2 * size}
	, m_arr{new T[m_capacity]}
{
	for(int i = 0; i < m_size; ++i) {
		m_arr[i] = val;
	}
}

template<typename T>
vector<T>::vector(const vector& other) 
	: m_size{other.m_size}
	, m_capacity{other.m_capacity}
	, m_arr{new T[m_capacity]}
{
	for(int i = 0; i < other.m_size; ++i) {
		m_arr[i] = other.m_arr[i];
	}
}

template<typename T>
vector<T>::vector(vector&& rhs) 
	: m_size{rhs.m_size}
	, m_capacity{rhs.m_capacity}
	, m_arr{rhs.m_arr}
{
	rhs.m_size = 0;
	rhs.m_capacity = 0;
	rhs.m_arr = nullptr;

	std::cout << "move" << std::endl;
}

template<typename T>
vector<T>::~vector() 
{
	delete[] m_arr;
}

template<typename T>
const vector<T>& 
vector<T>::operator=(const vector& rhv) {
	if(this != &rhv) {
		this->clear();
		m_size = rhv.m_size;
		m_capacity = rhv.m_capacity;
		m_arr = new value_type[m_capacity];

		for(int i = 0; i < m_size; ++i) {
			m_arr[i] = rhv.m_arr[i];
		}

		std::cout << "copy =" << std::endl;
	}
	return *this;
}

template<typename T>
const vector<T>& 
vector<T>::operator=(vector&& rhv) {
	if(this != &rhv) {
		this->clear();
		m_size = rhv.m_size;
		m_capacity = rhv.m_capacity;
		m_arr = rhv.m_arr;
			
		rhv.m_size = 0;
		rhv.m_capacity = 0;
		rhv.m_arr = nullptr;

		std::cout << "move =" << std::endl;
	}
	return *this;
}

template<typename T>
typename vector<T>::referance 
vector<T>::operator[](size_type pos){
		return *(m_arr + pos);
}

template<typename T>
void vector<T>::clear() {
	m_size = 0;
	m_capacity = 0;
	m_arr = nullptr;

	std::cout << "clear" << std::endl;
}

template<typename T>
void vector<T>::push_back(const_referance value){
	if(m_size < m_capacity){
		m_arr[m_size++] = value;
		return;
	}
	reallocator();
 	m_arr[m_size++] = value;
}

template<typename T>
void vector<T>::reallocator() {
	m_capacity = (m_capacity != 0) ? 2 * m_capacity : 1;
 	pointer tmp = new value_type[m_capacity];
	for(int i = 0; i < m_size; ++i){
		tmp[i] = m_arr[i];
	}
	delete[] m_arr;
	m_arr = tmp;
}

template<typename T>
void vector<T>::pop_back(){
	if(m_size != 0 && m_arr != nullptr) {
		--m_size;
	}
	std::cout << "pop_back" << std::endl;
}

template<typename T>
typename vector<T>::size_type 
vector<T>::size() const {
	return m_size;
}

