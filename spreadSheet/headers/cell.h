#ifndef CELL_H
#define CELL_H

#include <sstream>
#include <string>
#include <iostream>

class cell {
public:
	cell();
	cell(const std::string& value);
	cell(const Cell& other);
	cell(cell&& other);
	~cell() = default;

	cell& operator=(const cell& other);
	cell& operator=(cell&& other);

	void setStringValue(const std::string& value);
	const std::string& getStringvalue() const;

	int getIntValue() const;
	double getDoubleValue() const;

	operator int();
	operator double();

	std::ostream& operator<<(std::ostream& os, const Cell& cell);
	std::istream& operator>>(std::istream& is, Cell& cell);

private:
	std::string m_value;
		
};

#include "cell.hpp"

#endif // CELL_H
