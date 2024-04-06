#include "../headers/spreadSheet.h"
#include <iostream>

spreadSheet::spreadSheet()
	: m_row {2}
	, m_col {2}
{
	Allocator();
}

spreadSheet::spreadSheet(int n)
	: m_row {n}
	, m_col {n}
{
		Allocator();
}	

spreadSheet::spreadSheet(int n, int m)
	: m_row {n}
	, m_col {m}
{
	Allocator();
}

spreadSheet::spreadSheet(std::initializer_list<cell> init)
{
	m_col = 5;
	m_row = (init.size() + m_col -1) / m_col;
	Allocator();
	int i = 0; 
	int j = 0;
	for(auto& it : init) {
		m_cell[i][j] = it;
		++j;
		if(m_col == j){
			++i;
			j = 0; 
		}
	}	
}

spreadSheet::spreadSheet(const spreadSheet& other)
	: m_row {other.m_row}
	, m_col {other.m_col}
{
	Allocator();
	for(int i = 0; i < m_row; ++i) {
		for(int j = 0; j < m_col; ++j) {
			m_cell[i][j] = other.m_cell[i][j];
		}
	}
}
spreadSheet::spreadSheet(spreadSheet&& other)
	: m_row {other.m_row}
	, m_col {other.m_col}
	, m_cell {other.m_cell}
{
	other.m_row = 0;
	other.m_col = 0;
	other.m_cell = nullptr;
}

spreadSheet::~spreadSheet()
{
	for(int i = 0; i < m_row; ++i) {
		delete[] m_cell[i];
	}
	delete[] m_cell;
}

spreadSheet& spreadSheet::operator=(const spreadSheet& other)
{
	if(this != &other) {
			m_row = other.m_row;
			m_col = other.m_col;
			for(int i = 0; i < m_row; ++i) {
				for(int j = 0; j < m_col; ++j) {
					m_cell[i][j] = other.m_cell[i][j];
				}
			}
	}
	return *this;
}

spreadSheet& spreadSheet::operator=(spreadSheet&& other)
{
	if(this != &other) {
		m_row = other.m_row;
		m_col = other.m_col;
		m_cell = other.m_cell;
		other.m_row = 0;
		other.m_col = 0;
		other.m_cell = nullptr;
	}
	return *this;
}

void spreadSheet::add_row(int val)
{
	resize(m_row + val, m_col);
}

void spreadSheet::add_col(int val)
{
	resize(m_row, m_col + val);
}

void spreadSheet::resize_row(int val)
{
	resize(val, m_col);
}

void spreadSheet::resize_col(int val)
{
	resize(m_row, val);
}

void spreadSheet::resize(int n, int m)
{
	int tmp_row = (n <= m_row) ? n : m_row;
	int tmp_col = (m <= m_col) ? m : m_col;
	cell** ptr = new cell*[n];
	for(int i = 0; i < n; ++i) {
		ptr[i] = new cell[m];
	}
	
	for(int i = 0; i < tmp_row; ++i) {
		for(int j = 0; j < tmp_col; ++j) {
			ptr[i][j] = m_cell[i][j];
		}
	}
	for(int i = 0; i < m_row; ++i) {
		delete[] m_cell[i];
	}
	delete[] m_cell;
	m_cell = ptr;
	ptr = nullptr;
	m_row = n;
	m_col = m;
}

void spreadSheet::delete_row(int val)
{
	if(val < m_row) {
		resize(m_row - val, m_col);
		return;
	}
	throw std::out_of_range("value > row");
}

void  spreadSheet::delete_col(int val)
{
	if(val < m_col) {
		resize(m_row, m_col - val);
		return;
	}
	throw std::out_of_range("value > row");
}

void spreadSheet::print() 
{
	for(int i = 0; i < m_row; ++i) {
		for(int j = 0; j < m_col; ++j) {
			std::cout << m_cell[i][j] << " ";
		}	 
		std::cout << std::endl;
	}
}

void spreadSheet::insert(int n, int m, cell ob)
{
	if(n >=m_row || m >= m_col || n < 0 || m < 0) {
		throw std::out_of_range("out of range");
	}
	m_cell[n][m] = ob;
}

void spreadSheet::Allocator()
{
	m_cell = new cell*[m_row];
	for(int i = 0; i < m_row; ++i) {
		m_cell[i] = new cell[m_col];
	}
}

void  spreadSheet::copy_from(int n, int m, const spreadSheet& rhv)
{
	this -> resize(n, m);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j) {
			this->m_cell[i][j] = rhv.m_cell[i][j];
		}
	}
}

spreadSheet& spreadSheet::slice(int n, int m)
{
	resize(m_row - n, m_col - m);
	return *this;
}

