#include <iostream>
#include "../headers/myAllocator.h"


constexpr char* myAllocator::allocate(std::size_t n)
{
	if(n > 16) {
		return new char[n];
	} 
	char buffer[n];
	return buffer;
}
	
void myAllocator::deallocate(char* p, std::size_t n)
{
	if(n > 16) {
		delete [] p;
	}
}

