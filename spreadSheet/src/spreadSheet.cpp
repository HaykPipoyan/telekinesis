#include "../headers/spreadSheet.h"
#include <iostream>

SpreadSheet::SpreadSheet()
	: m_row {0}
	, m_col {0}
	, board {nullptr}
{}

SpreadSheet::SpreadSheet(const SpreadSheet& rhv)
	: m_row {rhv.m_row}
	, m_col {rhv.m_col}
{
	Allocator();
	for(size_t i = 0; i < m_row; ++i) {
		for(size_t j = 0; j < m_col; ++j) {
			board[i][j] = rhv.board[i][j];
		}
	}
}

SpreadSheet::SpreadSheet(SpreadSheet&& rhv)
	: m_row {rhv.m_row}
	, m_col {rhv.m_col}
	, board {rhv.board}
{
	rhv.m_row = 0;
	rhv.m_col = 0;
	rhv.board = nullptr;
}

SpreadSheet::SpreadSheet(size_t size)
	: m_row {size}
	, m_col {size}
{
	Allocator();
}	

SpreadSheet::SpreadSheet(size_t row, size_t col)
	: m_row {row}
	, m_col {col}
{
	Allocator();
}

SpreadSheet::~SpreadSheet()
{
	clear();
}

const SpreadSheet& SpreadSheet::operator=(const SpreadSheet& rhv)
{
	if(this != &rhv) {
		clear();
		m_row = rhv.m_row;
		m_col = rhv.m_col;
		Allocator();
		for(int i = 0; i < m_row; ++i) {
			for(int j = 0; j < m_col; ++j) {
				board[i][j] = rhv.board[i][j];
			}
		}
	}
	return *this;
}

const SpreadSheet& SpreadSheet::operator=(SpreadSheet&& rhv)
{
	if(this != &rhv) {
		clear();
		m_row = rhv.m_row;
		m_col = rhv.m_col;
		board = rhv.board;
		rhv.m_row = 0;
		rhv.m_col = 0;
		rhv.board = nullptr;
	}
	return *this;
}

void SpreadSheet::clear() noexcept
 {
	if (board) {
        for (size_t i = 0; i < m_row; ++i) {
            delete[] board[i];
        }
        delete[] board;
        board = nullptr;
    }
 }

 void SpreadSheet::Allocator()
{
	board = new Cell*[m_row];
	for(size_t i = 0; i < m_row; ++i) {
		board[i] = new Cell[m_col];
	}
}

SpreadSheet::Column SpreadSheet::operator[](size_t pos)
{
	if (pos >= m_row) {
        throw std::out_of_range("Row index out of range");
    }
    return Column(board[pos]);
}
    
const SpreadSheet::Column SpreadSheet::operator[](size_t pos) const
{
	if (pos >= m_row) {
        throw std::out_of_range("Row index out of range");
    }
    return Column(board[pos]);
}

size_t SpreadSheet::row() const
{
	return m_row;
}
size_t SpreadSheet::col() const
{
	return m_col;
}

void SpreadSheet::mirrorH()
{
	for (size_t i = 0; i < m_row; ++i) {
        for (size_t j = 0; j < m_col / 2; ++j) {
            std::swap(board[i][j], board[i][m_col - j - 1]);
        }
    }
}

void SpreadSheet::mirrorV()
{
	for (size_t i = 0; i < m_row / 2; ++i) {
        std::swap(board[i], board[m_row - i - 1]);
    }
}

void SpreadSheet::mirrorD()
{
	if (m_row != m_col) {
        throw std::logic_error("MirrorD requires a square matrix");
    }
    for (size_t i = 0; i < m_row; ++i) {
        for (size_t j = i + 1; j < m_col; ++j) {
            std::swap(board[i][j], board[j][i]);
        }
    }
}

void SpreadSheet::mirrorSD()
{
	if (m_row != m_col) {
        throw std::logic_error("MirrorSD requires a square matrix");
    }
    for (size_t i = 0; i < m_row; ++i) {
        for (size_t j = 0; j < m_col - i - 1; ++j) {
            std::swap(board[i][j], board[m_col - j - 1][m_row - i - 1]);
        }
    }
}

void SpreadSheet::rotate(int cnt)
{
	cnt = (cnt % 4 + 4) % 4; 
    for (int k = 0; k < cnt; ++k) {
        size_t new_rows = m_col; 
        size_t new_cols = m_row; 
        Cell** new_board = new Cell*[new_rows];
        for (size_t i = 0; i < new_rows; ++i) {
            new_board[i] = new Cell[new_cols];
        }
        for (size_t i = 0; i < m_row; ++i) {
            for (size_t j = 0; j < m_col; ++j) {
                new_board[j][m_row - 1 - i] = board[i][j];
            }
        }
        clear();
        m_row = new_rows;
        m_col = new_cols;
        board = new_board;
    }
}

void SpreadSheet::removeRow(size_t row)
{
	if (row >= m_row) {
        throw std::out_of_range("Row index out of range");
    }

    Cell** new_board = new Cell*[m_row - 1];
    for (size_t i = 0, k = 0; i < m_row; ++i) {
        if (i != row) {
            new_board[k++] = board[i];
        }
    }

    delete[] board[row];
    delete[] board;

    --m_row;
    board = new_board;
}

void SpreadSheet::removeRows(std::initializer_list<size_t> rows)
{
	for (auto row : rows) {
        removeRow(row);
    }
}

void SpreadSheet::removeCol(size_t col)
{
	if (col >= m_col) {
        throw std::out_of_range("Column index out of range");
    }

    for (size_t i = 0; i < m_row; ++i) {
        for (size_t j = col; j < m_col - 1; ++j) {
            board[i][j] = board[i][j + 1];
        }
    }

    for (size_t i = 0; i < m_row; ++i) {
        Cell* temp = board[i];
        board[i] = new Cell[m_col - 1];
        for (size_t j = 0; j < m_col - 1; ++j) {
            board[i][j] = temp[j];
        }
        delete[] temp;
    }

    --m_col;
}

void SpreadSheet::removeCols(std::initializer_list<size_t> cols)
{
	for (auto col : cols) {
        removeCol(col);
    }
}

void SpreadSheet::resizeRow(size_t r)
{
	if (r == m_row) {
        return;
    }
    if (r < m_row) {
        for (size_t i = r; i < m_row; ++i) {
            delete[] board[i];
        }
        m_row = r;
        Cell** new_board = new Cell*[m_row];
        for (size_t i = 0; i < m_row; ++i) {
            new_board[i] = board[i];
        }
        delete[] board;
        board = new_board;
    } else {
        Cell** new_board = new Cell*[r];
        for (size_t i = 0; i < m_row; ++i) {
            new_board[i] = board[i];
        }
        for (size_t i = m_row; i < r; ++i) {
            new_board[i] = new Cell[m_col];
        }
        delete[] board;
        board = new_board;
        m_row = r;
    }
}

void SpreadSheet::resizeCol(size_t c)
{
	if (c == m_col) {
        return; 
    }
    if (c < m_col) {
        for (size_t i = 0; i < m_row; ++i) {
            Cell* new_row = new Cell[c];
            for (size_t j = 0; j < c; ++j) {
                new_row[j] = board[i][j];
            }
            delete[] board[i];
            board[i] = new_row;
        }
        m_col = c;
    } else {
        for (size_t i = 0; i < m_row; ++i) {
            Cell* new_row = new Cell[c];
            for (size_t j = 0; j < m_col; ++j) {
                new_row[j] = board[i][j];
            }
            for (size_t j = m_col; j < c; ++j) {
                new_row[j] = Cell(); 
            }
            delete[] board[i];
            board[i] = new_row;
        }
        m_col = c;
    }
}

void SpreadSheet::resize(size_t r, size_t c)
{
	size_t tmp_row = (r <= m_row) ? r : m_row;
	size_t tmp_col = (c <= m_col) ? c : m_col;
	Cell** ptr = new Cell*[r];
	for(size_t i = 0; i < r; ++i) {
		ptr[i] = new Cell[c];
	}
	
	for(size_t i = 0; i < tmp_row; ++i) {
		for(size_t j = 0; j < tmp_col; ++j) {
			ptr[i][j] = board[i][j];
		}
	}
	for(size_t i = 0; i < m_row; ++i) {
		delete[] board[i];
	}
	delete[] board;
	board = ptr;
	ptr = nullptr;
	m_row = r;
	m_col = c;
}

SpreadSheet SpreadSheet::slice(std::initializer_list<size_t> rows, std::initializer_list<size_t> cols)
{
	SpreadSheet sliced(rows.size(), cols.size());
    size_t i = 0;
    for (auto row : rows) {
        size_t j = 0;
        for (auto col : cols) {
            sliced.board[i][j] = board[row][col];
            ++j;
        }
        ++i;
    }
    return sliced;
}       

SpreadSheet::Column::Column (Cell* col)
	: col {col}
{}

Cell& SpreadSheet::Column::operator[](size_t pos) {
    return col[pos];
}
const Cell& SpreadSheet::Column::operator[](size_t pos) const {
    return col[pos];
}

bool operator==(const SpreadSheet& lhv, const SpreadSheet& rhv) {
    if (lhv.m_row != rhv.m_row || lhv.m_col != rhv.m_col) {
        return false;
    }

    for (size_t i = 0; i < lhv.m_row; ++i) {
        for (size_t j = 0; j < lhv.m_col; ++j) {
            if (lhv.board[i][j] != rhv.board[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool operator!=(const SpreadSheet& lhv, const SpreadSheet& rhv) {
    return !(lhv == rhv);
}

std::ostream& operator<<(std::ostream& out, const SpreadSheet& ob) {
    for (size_t i = 0; i < ob.m_row; ++i) {
        for (size_t j = 0; j < ob.m_col; ++j) {
            out << std::setw(10) << ob.board[i][j] << " ";
        }
        out << std::endl;
    }
    return out;
}


