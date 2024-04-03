#include "../headers/spreadSheet.h"
#include <iostream>

spreadSheet::spreadSheet()
	: m_row {2}
	, m_col {2}
{
	m_cell = new cell*[m_row];
	for(int i = 0; i < m_row; ++i) {
		m_cell[i] = new cell[m_col];
	}
}

spreadSheet::spreadSheet(int n)
	: m_row {n}
	, m_col {n}
{
	m_cell = new cell*[m_row];
		for(int i = 0; i < m_row; ++i) {
			m_cell[i] = new cell[m_col];
		}
}
spreadSheet::spreadSheet(int n, int m)
	: m_row {n}
	, m_col {m}
{
	m_cell = new cell*[m_row];
		for(int i = 0; i < m_row; ++i) {
			m_cell[i] = new cell[m_col];
		}
}
spreadSheet::spreadSheet(const spreadSheet& other)
	: m_row {other.m_row}
	, m_col {other.m_col}
{
	m_cell = new cell*[m_row];
		for(int i = 0; i < m_row; ++i) {
			m_cell[i] = new cell[m_col];
		}
		for(int i = 0; i < m_row; ++i) {
			for(int j = 0; j < m_col; ++j) {
				m_cell[i][j] = other.m_cell[i][j];
			}
		}
	std::cout << "copy" << std::endl;
}
spreadSheet::spreadSheet(spreadSheet&& other)
	: m_row {other.m_row}
	, m_col {other.m_col}
	, m_cell {other.m_cell}
{
	other.m_row = 0;
	other.m_col = 0;
	other.m_cell = nullptr;
	std::cout << "move" << std::endl;
}

spreadSheet::~spreadSheet()
{
	for(int i = 0; i < m_row; ++i) {
		delete[] m_cell[i];
	}
	delete[] m_cell;
	std::cout << "dtor" << std::endl; 
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
	int tmp = m_row;
	m_row += val;
	cell** ptr = new cell*[m_row];
	for(int i = 0; i < m_row; ++i) {
		ptr[i] = new cell[m_col];
	}
	for(int i = 0; i < tmp; ++i) {
		for(int j = 0; j < m_col; ++j) {
			ptr[i][j] = m_cell[i][j];
		}
	}
	for(int i = 0; i < m_row; ++i) {
		delete[] m_cell[i];
	}
	delete[] m_cell;
	m_cell = ptr;
	ptr = nullptr;
}
/*
void spreadSheet::add_col(int val)
{
	
}

void spreadSheet::resize_row(int val)
{

}
	void resize_col(int val);
	void resize(int n, int m);
	void delete_row(int val);
	void delete_col(int val);
	void copy_from(int n, int m, const spreadSheet& rhv);
	spreadSheet& slice({row}, {col});

*/
