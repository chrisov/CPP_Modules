#include "../inc/whatever.hpp"

int main( void ) {
	{
		int a = 2;
		int b = 3;
	
		std::cout << "\nv===================== INT =======================v" << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::cout << "^=================================================^\n" << std::endl;
	}
	{
		char a = 'a';
		char b = 'b';

		std::cout << "\nv===================== CHAR ======================v" << std::endl;
		std::cout << "a = '" << a << "', b = '" << b << "'" << std::endl;
		::swap(a, b);
		std::cout << "a = '" << a << "', b = '" << b << "'" << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::cout << "^=================================================^\n" << std::endl;
	}
	{
		std::string a = "chaine1";
		std::string b = "chaine2";

		std::cout << "\nv==================== STRING =====================v" << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		::swap(a, b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::cout << "^=================================================^\n" << std::endl;
	}
	return 0;
}