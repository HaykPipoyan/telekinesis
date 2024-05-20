#include "../headers/vector.h"
using namespace g3;

int main() {
	vector<int> vec{1, 2, 3, 4};
	vector<int> vec2{2, 3, 4, 5};

	// vec.push_back(8);
	// for (size_t i = 0; i < vec.size(); i++)
	// {
	// 	std::cout<< vec[i] << std::endl;
	// }
	// vec.resize(6, 12);
	// for (size_t i = 0; i < vec.size(); i++)
	// {
	// 	std::cout<< vec[i] << std::endl;
	// }
	// std::cout << vec.size() << std::endl;
	if(vec != vec2) {
		std::cout << "Yes" << std::endl;
	}
	std::cout << "No" << std::endl;
}

	
