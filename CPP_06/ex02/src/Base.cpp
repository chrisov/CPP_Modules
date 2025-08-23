#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

/****************************************************
*					CONSTRUCTORS				 	*
****************************************************/

Base::~Base() {
	std::cout << color("Base", YLW) << color(" destructor ", RED) << "called!" << std::endl;
};


/****************************************************
*					FUNCTIONS						*
****************************************************/

Base*	generate(void) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(1,3);

	int		rand = dist(gen);

	switch (rand) {
		case 1:
			std::cout << color("Instantiated", GRN) << " an " << color("A", YLW) << " object!" << std::endl;
			return (new A());
		case 2:
			std::cout << color("Instantiated", GRN) << " a " << color("B", YLW) << " object!" << std::endl;
			return (new B());
		case 3:
			std::cout << color("Instantiated", GRN) << " a " << color("C", YLW) << " object!" << std::endl;
			return (new C());
		default:
			return (nullptr);
	}
}

void	identify(Base* p) {
	std::cout << "Object is of type: ";
	if (dynamic_cast<A*>(p))
		std::cout << color("A", YLW) << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << color("B", YLW) << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << color("C", YLW) << std::endl;
	else
		std::cout << color("Unknown", RED) << std::endl;
}

void identify(Base& obj) {
	std::cout << "Object is of type: ";
	try {
		static_cast<void>(dynamic_cast<A&>(obj));
		std::cout << color("A", YLW) << std::endl;
	} catch (const std::bad_cast&) {
		try {
			static_cast<void>(dynamic_cast<B&>(obj));
			std::cout << color("B", YLW) << std::endl;
		} catch (const std::bad_cast&) {
			try {
				static_cast<void>(dynamic_cast<C&>(obj));
				std::cout << color("C", YLW) << std::endl;
			} catch (const std::bad_cast&) {
				std::cout << color("Unkown", RED) << std::endl;
			}
		}
	}
}
