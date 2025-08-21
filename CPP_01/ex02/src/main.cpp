#include <iostream>
#define UL "\033[4m"
#define RES "\033[0m"

int	main(void) {
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout <<std::endl << UL << "ADDRESSES:" << RES << std::endl;
	std::cout << "Address of str: " << &str << std::endl;
	std::cout << "Address of strPTR: " << &stringPTR << std::endl;
	std::cout << "Address of strREF: " << &stringREF << std::endl;

	std::cout <<std::endl << UL << "VALUES:" << RES << std::endl;
	std::cout << "Value of str: " << str << std::endl;
	std::cout << "Value of strPTR: " << *stringPTR << std::endl;
	std::cout << "Value of strREF: " << stringREF << std::endl;
}
