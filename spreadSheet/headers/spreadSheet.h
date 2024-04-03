#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include "cell.h"

class spreadSheet {
public:
	spreadSheet();
	spreadSheet(int n);
	spreadSheet(int n, int m);
	spreadSheet(const spreadSheet& other);
	spreadSheet(spreadSheet&& other);
	~spreadSheet();

	spreadSheet& operator=(const spreadSheet& other);
	spreadSheet& operator=(spreadSheet&& other);

	void add_row(int val);
/*	void add_col(int val);
	void resize_row(int val);
	void resize_col(int val);
	void resize(int n, int m);
	void delete_row(int val);
	void delete_col(int val);
	void copy_from(int n, int m, const spreadSheet& rhv);
	spreadSheet& slice({row}, {col});
*/
private:
	cell** m_cell;
	int m_row;
	int m_col;
};

//std::ostream& operator<<(std::ostream&, const spreadSheet& c);

#endif // SPREADSHEET_H
