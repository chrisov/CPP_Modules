#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void	elemIncrement(T& elem) {
	elem += 1.5;
}

template <typename T_Arr, typename T_Fnc>
void	iter(T_Arr* arr, unsigned int len, T_Fnc fun) {
	if (fun == nullptr)
		return ;
	for (unsigned int i = 0; i < len; i++)
		fun(arr[i]);
}

void	printArray(void* arr, std::string type, std::string del) {
	if (type == "int") {
		int*	res = (int*)arr;	
		for (int i = 0; i < 10; i++)
			std::cout << res[i] << del;
	}
	else if (type == "char") {
		char*	res = (char*)arr;	
		for (int i = 0; i < 10; i++)
			std::cout << res[i] << del;
	}
	else if (type == "float") {
		float*	res = (float*)arr;	
		for (int i = 0; i < 10; i++) {
			std::cout << std::fixed << std::setprecision(1);
			std::cout << res[i] << del;
		}
	}
	std::cout << std::endl;
}

#endif