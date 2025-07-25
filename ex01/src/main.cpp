#include "../inc/Serializer.hpp"
#include "../inc/Data.hpp"

int main(void) {
	{
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "\nv===================== INT ===================v" << std::endl;
		Data		d(42);
		uintptr_t	ser = Serializer::serialize(&d);
		Data*		res = Serializer::deserialize(ser);
	
		std::cout << color("Value", YLW) << ": " << d.getInt() << std::endl;
		std::cout << color("Address", YLW) << ": " << &d << std::endl;
		
		std::cout << color("Hash", YLW) << ": " << ser << std::endl;
		std::cout << color("Address", YLW) << ": " << res << std::endl;
		std::cout << color("Value", YLW) << ": " << res->getInt() << std::endl;
		std::cout << "^=============================================^\n" << std::endl;
	}
	{
		std::cout << "\nv=================== DOUBLE ==================v" << std::endl;
		Data		d(42.2);
		uintptr_t	ser = Serializer::serialize(&d);
		Data*		res = Serializer::deserialize(ser);
	
		std::cout << color("Value", YLW) << ": " << d.getDouble() << std::endl;
		std::cout << color("Address", YLW) << ": " << &d << std::endl;
		
		std::cout << color("Hash", YLW) << ": " << ser << std::endl;
		std::cout << color("Address", YLW) << ": " << res << std::endl;
		std::cout << color("Value", YLW) << ": " << res->getDouble() << std::endl;
		std::cout << "^=============================================^\n" << std::endl;
	}
	{
		std::cout << "\nv=================== FLOAT ===================v" << std::endl;
		Data		d(42.4f);
		uintptr_t	ser = Serializer::serialize(&d);
		Data*		res = Serializer::deserialize(ser);
	
		std::cout << color("Value", YLW) << ": " << d.getFloat() << "f" << std::endl;
		std::cout << color("Address", YLW) << ": " << &d << std::endl;
		
		std::cout << color("Hash", YLW) << ": " << ser << std::endl;
		std::cout << color("Address", YLW) << ": " << res << std::endl;
		std::cout << color("Value", YLW) << ": " << res->getFloat() << "f" << std::endl;
		std::cout << "^=============================================^\n" << std::endl;
	}
	std::cout << std::fixed << std::setprecision(0);
	
	return (0);
}
