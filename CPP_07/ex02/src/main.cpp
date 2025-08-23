#include "../inc/Array.hpp"
#define ARR_SIZE 20

static void	printArray(int* arr) {
	for (unsigned int i = 0; i < ARR_SIZE; i++) {
		std::cout << "'" << arr[i] << "'\t";
		if((i + 1) % 5 == 0)
			std::cout << '\n';
	}
}

int main(int, char**)
{
	std::cout << "\nv================== CONSTRUCTORS ===================v" << std::endl;
	Array<int> numbers(ARR_SIZE);
	int* mirror = new int[ARR_SIZE];
	srand(time(NULL));
	for (int i = 0; i < ARR_SIZE; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	std::cout << "\n\t" << color("NUMBERS", YLW) << ":\n" <<  numbers << std::endl;
	std::cout << "\n\t" << color("MIRROR", YLW) << ":" << std::endl;
	printArray(mirror);
	for (int i = 0; i < ARR_SIZE; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	std::cout << "^===================================================^\n" << std::endl;


	std::cout << "\nv==================== DEEP COPY ====================v" << std::endl;
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
		std::cout << "\n\t" << color("TMP", YLW) << ":\n" <<  tmp << std::endl;
		std::cout << "\n\t" << color("TEST", YLW) << ":\n" <<  test << std::endl;
		tmp[10] = 0;
		test[10] = 1;
		std::cout << color("tmp", YLW) << "[10]: " << tmp[10] << std::endl;
		std::cout << color("test", YLW) << "[10]: " << test[10] << std::endl;
		std::cout << color("numbers", YLW) << "[10]: " << numbers[10] << std::endl;
		std::cout << color("mirror", YLW) << "[10]: " << mirror[10] << std::endl;
	}
	std::cout << "^===================================================^\n" << std::endl;
	

	std::cout << "\nv================== OUT OF BOUNDS ==================v" << std::endl;
	std::cout << "Modifying " << color("numbers", YLW) << "[-2]: ";
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "Modifying " << color("numbers", YLW) << "[ARR_SIZE]: ";
	try
	{
		numbers[ARR_SIZE] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "^===================================================^\n" << std::endl;


	std::cout << "\nv================== MODIFICATIONS ==================v" << std::endl;
	for (int i = 0; i < ARR_SIZE; i++)
	{
		numbers[i] = rand();
	}
	std::cout << "\t" << color("NUMBERS", YLW) << ":\n" <<  numbers << std::endl;
	std::cout << "\n\t" << color("MIRROR", YLW) << ":" << std::endl;
	printArray(mirror);
	std::cout << "^===================================================^\n" << std::endl;
	delete [] mirror;
	return 0;
}