#include "../inc/EasyFind.hpp"

int main(void) {
	{
		std::cout << "\nv==================== VECTOR =====================v" << std::endl;
		std::vector<int> cont = {10, 5, 15, 20, 5, 30, 31};

		printArray(cont);
		easyFind(cont, 5);
		easyFind(cont, 11);
		std::cout << "^=================================================^\n" << std::endl;
	}
	{
		std::cout << "\nv===================== ARRAY =====================v" << std::endl;
		std::array<int, 7> cont = {10, 5, 75, 20, -5, 100, 31};
		
		printArray(cont);
		easyFind(cont, -5);
		easyFind(cont, 11);
		std::cout << "^=================================================^\n" << std::endl;
	}
	{
		std::cout << "\nv===================== DEQUE =====================v" << std::endl;
		std::deque<int> cont = {10, 5, 15, 20, 5, 30, 31};
		
		printArray(cont);
		easyFind(cont, 5);
		easyFind(cont, 11);
		std::cout << "^=================================================^\n" << std::endl;
	}
	{
		std::cout << "\nv===================== LIST =====================v" << std::endl;
		std::list<int> cont = {10, 51, 15, 20, 52, 312, 313};
		
		printArray(cont);
		easyFind(cont, 52);
		easyFind(cont, 11);
		std::cout << "^=================================================^\n" << std::endl;
	}
	{
		std::cout << "\nv================= FORWARD LIST ==================v" << std::endl;
		std::forward_list<int> cont = {10, -10, 15, -20, 31};
		
		printArray(cont);
		easyFind(cont, 31);
		easyFind(cont, 11);
		std::cout << "^=================================================^\n" << std::endl;
	}
}