#include "../inc/iter.hpp"
#include <iomanip>

/****************************************************
*					SUBJECT TESTS					*
****************************************************/

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

/****************************************************
*						MAIN						*
****************************************************/

int main(void) {
	std::cout << "\nv============== SUBJECT TESTS ==============v" << std::endl;
	int tab[] = {0, 1, 2, 3, 4};
	Awesome tab2[5];
	
	iter( tab, 5, print<const int> );
	iter( tab2, 5, print<Awesome> );
	std::cout << "^===========================================^\n" << std::endl;
	
	{
		std::cout << "\nv=================== INT ===================v" << std::endl;		
		int	arr[10];
		for (int i = 0; i < 10; i++)
			arr[i] = i;
		std::cout << " ";
		printArray(arr, "int", "  ");

		::iter(arr, 10, elemIncrement<int>);
		printArray(arr, "int", "  ");

		::iter(arr, 10, elemIncrement<int>);
		printArray(arr, "int", "  ");
		std::cout << "^============================================^\n" << std::endl;
	}
	{
		std::cout << "\nv================== FLOAT ===================v" << std::endl;		
		float	arr[10];
		for (int i = 0; i < 10; i++)
			arr[i] = (float)i;
		printArray(arr, "float", "  ");

		::iter(arr, 10, elemIncrement<float>);
		printArray(arr, "float", "  ");

		::iter(arr, 10, elemIncrement<float>);
		printArray(arr, "float", "  ");
		std::cout << "^============================================^\n" << std::endl;
	}
	{
		std::cout << "\nv=================== CHAR ===================v" << std::endl;		
		char	arr[10];
		for (int i = 0; i < 10; i++)
			arr[i] = i + 'A';
		printArray(arr, "char", "  ");
		
		::iter(arr, 10, elemIncrement<char>);
		printArray(arr, "char", "  ");
		
		::iter(arr, 10, elemIncrement<char>);
		printArray(arr, "char", "  ");
		std::cout << "^============================================^\n" << std::endl;
	}
}