#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <iomanip>
#include "Colors.hpp"

class Data {

	public:
		enum class Type { INT, FLOAT, DOUBLE };

		Data();
		Data(const Data& other);
		Data(int i);
		Data(float f);
		Data(double d);
		~Data();

		Data&	operator=(const Data& other);

		Type	getType() const;
		int		getInt() const;
		double	getDouble() const;
		float	getFloat() const;

	private:
		Type		_type;
		union {
			int		i;
			float	f;
			double	d;
		}	_data;
};

#endif