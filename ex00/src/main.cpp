#include "../inc/easyfind.hpp"

int main(void) {
	{
		std::cout << "\nv==================== VECTOR =====================v" << std::endl;
		std::vector<int> cont = {10, 5, 15, 20, 5, 30, 31};
		
		easyfind(cont, 5);
		easyfind(cont, 11);
		std::cout << "^=================================================^\n" << std::endl;
	}
	{
		std::cout << "\nv===================== ARRAY =====================v" << std::endl;
		std::array<int, 7> cont = {10, 5, 15, 20, 5, 30, 31};
		
		easyfind(cont, 5);
		easyfind(cont, 11);
		std::cout << "^=================================================^\n" << std::endl;
	}
	{
		std::cout << "\nv===================== DEQUE =====================v" << std::endl;
		std::deque<int> cont = {10, 5, 15, 20, 5, 30, 31};
		
		easyfind(cont, 5);
		easyfind(cont, 11);
		std::cout << "^=================================================^\n" << std::endl;
	}
	{
		std::cout << "\nv===================== LIST =====================v" << std::endl;
		std::list<int> cont = {10, 5, 15, 20, 5, 30, 31};
		
		easyfind(cont, 5);
		easyfind(cont, 11);
		std::cout << "^=================================================^\n" << std::endl;
	}
	{
		std::cout << "\nv================= FORWARD LIST ==================v" << std::endl;
		std::forward_list<int> cont = {10, 5, 15, 20, 5, 30, 31};
		
		easyfind(cont, 5);
		easyfind(cont, 11);
		std::cout << "^=================================================^\n" << std::endl;
	}
}