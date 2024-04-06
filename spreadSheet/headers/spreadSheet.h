#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include <initializer_list>

#include "cell.h"

class spreadSheet {
public:
	spreadSheet();
	spreadSheet(int n);
	spreadSheet(int n, int m);
 	spreadSheet(std::initializer_list<cell> init); 
	spreadSheet(const spreadSheet& other);
	spreadSheet(spreadSheet&& other);
	~spreadSheet();

	spreadSheet& operator=(const spreadSheet& other);
	spreadSheet& operator=(spreadSheet&& other);

	void add_row(int val);
	void add_col(int val);
	void resize_row(int val);
	void resize_col(int val);
	void resize(int n, int m);
	void delete_row(int val);
	void delete_col(int val);
	void print();
	void insert(int n, int m, cell ob);
	void copy_from(int n, int m, const spreadSheet& rhv);
	spreadSheet& slice(int n, int m);

private:
	void Allocator();
	cell** m_cell;
	int m_row;
	int m_col;
};



#endif // SPREADSHEET_H
