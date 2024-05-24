#include "../headers/cell.h"

std::ostream& operator<<(std::ostream& out, const std::vector<int>& ob) {
	out << "[";
    for (size_t i = 0; i < ob.size(); ++i) {
        out << ob[i];
        if (i != ob.size() - 1) {
            out << ", ";
        }
    }
    out << "]";
    return out;
}

std::istream& operator>>(std::istream& in, std::vector<int>& ob) 
{
	int value;
    while (in >> value) {
        ob.push_back(value);
    }
    return in;
}

Cell::Cell()
	: m_val {}
{}

Cell::Cell(const Cell& rhv)
	:m_val {rhv.m_val}
{}

Cell::Cell(Cell&& rhv)
	: m_val (std::move(rhv.m_val))
{
	rhv.m_val = std::string();
}

Cell::Cell(int val)
	: m_val(std::to_string(val))
{}

Cell::Cell(double val)
	: m_val {std::to_string(val)}
{}

Cell::Cell(char val)
	: m_val {std::string(1, val)}
{}

Cell::Cell(bool val)
	: m_val {val ? "true" : "false"}
{}

Cell::Cell(std::string val)
	: m_val {val}
{}

Cell::Cell(const std::vector<int>& val)
{
	std::ostringstream oss;
    for (size_t i = 0; i < val.size(); ++i) {
        oss << val[i];
        if (i != val.size() - 1) {
            oss << " ";
        }
    }
    m_val = oss.str();
}
const Cell& Cell::operator=(const Cell& rhv)
{
	if(this != &rhv) {
		m_val = rhv.m_val;
	}
	return *this;
}
   
const Cell& Cell::operator=(Cell&& rhv)
{
	if(this != &rhv) {
		m_val = std::move(rhv.m_val);
	}
	return *this;
}
 
const Cell& Cell::operator=(int rhv)
{
	m_val = std::to_string(rhv);
	return *this;
}

const Cell& Cell::operator=(double rhv)
{
	m_val = std::to_string(rhv);
	return *this;
} 

const Cell& Cell::operator=(char rhv)
{
	m_val = std::string(1, rhv);
	return *this;
} 

const Cell& Cell::operator=(bool rhv)
{
	m_val = rhv ? "true" : "false";
	return *this;
} 
    
const Cell& Cell::operator=(std::string rhv)
{
	m_val = rhv;
	return *this;
}
    
const Cell& Cell::operator=(const std::vector<int>& rhv)
{
	std::ostringstream oss;
    for (size_t i = 0; i < rhv.size(); ++i) {
        oss << rhv[i];
        if (i != rhv.size() - 1) {
            oss << " ";
        }
    }
    m_val = oss.str();
    return *this;
}



Cell::operator int() const
{
	return std::stoi(m_val);
} 
    
Cell::operator double() const
{
	return std::stod(m_val);
} 
    
Cell::operator char() const
{
	return m_val.empty() ? ' ' : m_val[0];
} 
    
Cell::operator bool() const
{
	return (m_val == "true" || m_val == "1");
}
    
Cell::operator std::string() const
{
	return m_val;
}
    
Cell::operator std::vector<int>() const
{
	std::vector<int> result;
    std::istringstream iss(m_val);
    int num;
    while (iss >> num) {
        result.push_back(num);
    }
    return result;
} 

std::string Cell::getValue() const 
{
    return m_val;
}

void Cell::setValue(const std::string& value)
{
    m_val = value;
}

bool operator==(const Cell& lhv, const Cell& rhv)
{
	return lhv.getValue() == rhv.getValue();
}

bool operator!=(const Cell& lhv, const Cell& rhv)
{
	return !(lhv == rhv);
}

std::ostream& operator<<(std::ostream& out, const Cell& ob)
{
	out << ob.getValue();
	return out;
}

std::istream& operator>>(std::istream& in, Cell& ob)
{
	std::string value;
    in >> value;
    ob.setValue(value);
    return in;
}



