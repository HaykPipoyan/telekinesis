#ifndef CELL_H
#define CELL_H

#include <string>
#include <iostream>

class cell {
public:
	cell() = default;
	cell(const std::string& value);
	cell(int value);
	cell(double value);
	cell(const cell& other);
	cell(cell&& other);
	~cell() = default;

	cell& operator=(const cell& other);
	cell& operator=(cell&& other);

	cell& operator=(const std::string& value);
	cell& operator=(int value);
	cell& operator=(double value);

	operator int();
	operator double();
	operator std::string() const;


private:
	std::string m_value;
		
};

std::ostream& operator<<(std::ostream& os, const cell& other);
std::istream& operator>>(std::istream& is, cell& other);



#endif // CELL_H
