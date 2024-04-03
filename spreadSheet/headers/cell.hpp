#ifndef CELL_H
#define CELL_H

#include "cell.h"

cell::cell() 
{}

cell::cell(const std::string& value)
	: m_value {value}
{}

cell::cell(const Cell& other)
	: m_value {other.m_value}
{}

cell::cell(cell&& other)
	: m_value = std::move(other.m_value)
{}

cell& cell::operator=(const cell& other)
{
	if(this != &other) {
		m_value = other.m_value;
	}
	return *this;
}
cell& cell::operator=(cell&& other)
{
	if(this != &other) {
		m_value = std::move(other.m_value);
	}
	return *this;
}

void cell::setStringValue(const std::string& value)
{
	m_value = value;
}
const std::string& cell::getStringvalue() const
{
	return m_value;
}

int cell::getIntValue() const
{
	int value = 0;
	std::stringstream ss << m_value;
	ss >> value;
	if(ss.fail()) {
		throw std::runtime_error("error")
	}
	return value;
}
double cell::getDoubleValue() const
{
	double value = 0.0;
	std::stringstream ss << m_value;
	ss >> value;
	if(ss.fail()) {
		trow std::runtime_error("error");
	}
	return value;
}

cell::operator int()
{
	return this -> getIntValue();
}
cell::operator double()
{
	return this -> getDoubleValue();
}

std::ostream& operator<<(std::ostream& os, const cell& other) 
{
	os << other.m_value;
	return os;
}
std::istream& operator>>(std::istream& is, cell& other) {
        is >> other.m_value;
        return is;
    }

private:
	std::string m_value;
		
};

#endif // CELL_H
