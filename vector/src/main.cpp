#include "../headers/vector.h"

int main() {
	vector<int> vec;
	vec.push_back(19);
	vec.push_back(94);
//	vec.push_back(100);

	for(int i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << std::endl;	
	}
	vector<int> vec2 = vec;

	if(vec == vec2) {
		std::cout << "havasr en" ;
	}
}

	
