#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T_Arr, typename T_Fnc>
void	iter(T_Arr* arr, unsigned int len, T_Fnc fun) {
	for (unsigned int i = 0; i < len; i++)
		fun(arr[i]);
}

#endif