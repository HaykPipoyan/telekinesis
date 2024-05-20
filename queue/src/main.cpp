#include "../headers/queue.h"

#include <iostream>

int main()
{
	queue<int>  obj;
	queue<int> ob2 {1, 2, 3, 4, 5};
	queue<int> ob3 = ob2;
	queue<int> ob4 = std::move(ob3);
	obj.push(19);
	ob2.pop();
	ob2.front();
	std::cout << ob2.size() << std::endl;

	std::cout << obj.empty();
	std::cout << "ok" << std::endl;
	if(ob2 == obj) {
		std::cout << "==" << std::endl;
	} else {
		std::cout << "==" << std::endl;
	}
	if(ob2 != obj) {
		std::cout << "!=" << std::endl;
	} else {
		std::cout << "!=" << std::endl;
	}
	if(ob2 <= obj) {
		std::cout << "<=" << std::endl;
	} else {
		std::cout << "<=" << std::endl;
	}
	if(ob2 < obj) {
		std::cout << "<" << std::endl;
	} else {
		std::cout << "<" << std::endl;
	}
	if(ob2 >= obj) {
		std::cout << ">=" << std::endl;
	} else {
		std::cout << ">=" << std::endl;
	}
	if(ob2 > obj) {
		std::cout << ">" << std::endl;
	} else {
		std::cout << ">" << std::endl;
	}
}

