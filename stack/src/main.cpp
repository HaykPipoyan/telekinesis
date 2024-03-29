#include "../headers/stack.h"


int main()
{
	stack<int> c1 = {1, 2, 3, 4, 5};
	stack<int> c2 = {6, 7, 8, 9, 10};

	if(c1 == c2){
		std::cout << "ok";
	}
	std::cout << "No" << std::endl; 
}
