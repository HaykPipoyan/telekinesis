#include "../headers/cell.h"


cell::cell(const std::string& value)
	: m_value {value}
{}

cell::cell(const char* value)
	: m_value {value}
{}

cell::cell(const char value)
	: m_value {value}
{}

cell::cell(int value)
	: m_value {std::to_string(value)}
{}

cell::cell(double value)
	: m_value {std::to_string(value)}
{}

cell::cell(const cell& other)
	: m_value {other.m_value}
{}

cell::cell(cell&& other)
{
	m_value = std::move(other.m_value);
}

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

cell& cell::operator=(const std::string& value)
{
	m_value = value;
	return *this;
}

cell& cell::operator=(int value)
{
	m_value = std::to_string(value);
	return *this;
}

cell& cell::operator=(double value)
{
	m_value = std::to_string(value);
	return *this;
}

cell::operator int()
{
	return std::stoi(m_value);
}

cell::operator double()
{
	return std::stod(m_value);
}

cell::operator std::string() const
{
	return m_value;
}

std::ostream& operator<<(std::ostream& os, const cell& other) {
	os << other.operator std::string();
    return os;
}

std::istream& operator>>(std::istream& is, cell& other) {
    std::string value;
    is >> value;
    other = value;
    return is;
}



