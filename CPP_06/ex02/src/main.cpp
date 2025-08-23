#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

int main(void) {
	{
		std::cout << "\nv=============== HOW IT WORKS ================v" << std::endl;
		Base*	example = new B();

		if (dynamic_cast<A*>(example))
			std::cout << "This is an A object!" << std::endl;
		if (dynamic_cast<B*>(example))
			std::cout << "This is a B object!" << std::endl;
		if (dynamic_cast<C*>(example))
			std::cout << "This is a C object!" << std::endl;
		delete example;
		std::cout << "^=============================================^\n" << std::endl;
	}
	{
		std::cout << "\nv================ RANDOM GEN =================v" << std::endl;
		Base*	b;
	
		b = generate();
		identify(b);
		identify(&*b);
		delete b;
		std::cout << "^=============================================^\n" << std::endl;
	}
	return (0);
}
