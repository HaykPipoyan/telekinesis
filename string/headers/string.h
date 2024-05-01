#ifndef STRING_H
#define STRING_H

#include <initializer_list>

class string { 
public:
	string();
	~string();
	string(const char* str);
	string(std::initializer_list<char> list);
	string(const string& other);	
	string(string&& other) noexcept;
public:
	string& operator=(const string& other);
	string& operator=(string&& other) noexcept;
	string& operator=(const char* str);
	string& operator=(char ch);
	string& operator=(std::initializer_list<char> list);

	string& assign(size_t count, char ch);
	char& at(size_t pos);
	char& operator[](size_t pos);
	const char& operator[](size_t pos) const;
	char& front();
	char& back();
	constexpr const char* data() const noexcept;
	constexpr const char* c_str() const noexcept;
	constexpr bool empty() const noexcept;
	constexpr size_t size() const noexcept;
	constexpr size_t length() const noexcept;
	constexpr size_t max_size() const noexcept;
	constexpr void reserve(size_t new_cap);
	constexpr size_t capacity() const noexcept;
	constexpr void shrink_to_fit();
	constexpr void clear() noexcept;
	constexpr string& insert(size_t index, size_t count, char ch );
	constexpr string& erase(size_t index = 0, size_t count = npos);
	constexpr void push_back(char ch);
	constexpr void pop_back();
	constexpr string& append(size_t count, char ch);
	constexpr string& operator+=(const string& str)
	string& replace(size_t pos, size_t count, const string& str);
	constexpr size_t copy(char* dest, size_t count, size_t pos = 0 ) const;
	constexpr void resize(size_t count);
	constexpr void swap(string& other) noexcept;
	constexpr size_t find(const string& str, size_t pos = 0) const noexcept;
	constexpr size_t rfind(const string& str, size_t pos = npos) const noexcept;
	int compare(const string& str) const noexcept;
	static const size_t npos = -1;
	void print();

	friend string operator+(const char* new_str, const string& str);  

private:
	bool m_Is_on_stack;
    struct dyn_str 
    { 
        size_t m_size;
		size_t m_capasity; 
		char* m_ptr;
    };
    union { 
        char on_stack[16]; 
        dyn_str str; 
    } Str; 
};

string operator+(const char* new_str, const string& str);
std::ostream& operator<<(std::ostream&, const string&);
td::istream& operator>>(std::istream& is, string& str);

#endif // STRING_H
