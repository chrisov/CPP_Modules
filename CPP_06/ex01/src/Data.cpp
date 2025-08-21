#include "../inc/Data.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

Data::Data() : _type(Type::INT) {
	_data.i = 0;
	std::cout << "Default " << color("Data", YLW) << color( " constructor", GRN) << " called!" << std::endl;
}

Data::Data(const Data& other) : _type(other._type) {
	switch (_type)	{
		case Type::INT:
			_data.i = other._data.i;
			break;
		case Type::DOUBLE:
			_data.d = other._data.d;
			break;
		case Type::FLOAT:
			_data.f = other._data.f;
			break;
	}
}

Data::Data(int i) : _type(Type::INT) {
	_data.i = i;
	std::cout << "Parameterized " << color("Data", YLW) << " int " << color("constructor", GRN) << " called!" << std::endl;
}

Data::Data(double d) : _type(Type::DOUBLE) {
	_data.d = d;
	std::cout << "Parameterized " << color("Data", YLW) << " double " << color("constructor", GRN) << " called!" << std::endl;
}

Data::Data(float f) : _type(Type::FLOAT) {
	_data.f = f;
	std::cout << "Parameterized " << color("Data", YLW) << " float " << color("constructor", GRN) << " called!" << std::endl;
}

Data::~Data() {
	std::cout << color("Data", YLW) << " was " << color("destroyed", RED) << "!" << std::endl;
}

/****************************************************
*					OPERATORS						*
****************************************************/

Data&	Data::operator=(const Data& other) {
	if (this != &other) {
		switch (_type) {
			case Type::INT:
				_data.i = other._data.i;
				break;
			case Type::DOUBLE:
				_data.d = other._data.d;
				break;
			case Type::FLOAT:
				_data.f = other._data.f;
				break;			
		}
	}
	return (*this);
}

/****************************************************
*					FUNCTIONS						*
****************************************************/

Data::Type		Data::getType(void) const {
	return (_type);
}

int	Data::getInt(void) const {
	switch (_type) {
		case Type::INT:
			return (_data.i);
		case Type::DOUBLE:
			return (static_cast<double>(_data.d));
		case Type::FLOAT:
			return (static_cast<double>(_data.f));
	}
	return (-1);
}

double	Data::getDouble(void) const {
	switch (_type) {
		case Type::INT:
			return (static_cast<double>(_data.i));
		case Type::DOUBLE:
			return (_data.d);
		case Type::FLOAT:
			return (static_cast<double>(_data.f));
	}
	return (-1.0);
}

float	Data::getFloat(void) const {
	switch (_type) {
		case Type::INT:
			return (static_cast<double>(_data.i));
		case Type::DOUBLE:
			return (static_cast<double>(_data.d));
		case Type::FLOAT:
			return (_data.f);
	}
	return (-1.0);
}
