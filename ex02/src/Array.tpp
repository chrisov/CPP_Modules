#pragma once

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

template <typename T>
Array<T>::Array() : _data(nullptr), _size(0) {
	std::cout << "Default templated " << color("array ", YLW) << color("constructor", GRN) << " called!" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int size) : _data(new T[size]), _size(size) {
	std::cout << "Parameterized templated " << color("array ", YLW) << color("constructor", GRN) << " called!" << std::endl;
}

template <typename T>
Array<T>::Array(const Array& other) : _size(other._size){
	other._data = new Array(_size); 
	std::cout << "Copy templated " << color("array ", YLW) << color("constructor", GRN) << " called!" << std::endl;
}

template <typename T>
Array<T>::~Array() {
	delete _data;
	std::cout << "Template " << color("array ", YLW) << color("destructor", RED) << " called!" << std::endl;
}

/****************************************************
*					OPERATORS						*
****************************************************/

template <typename T>
Array<T>&	Array<T>::operator=(const Array& other) {
	if (this != &other) {
		_size = other._size;
		delete _data;
		_data = new T[_size];
		for (unsigned int i = 0; i < _size; i++) {
			_data[i] = other._data[i];
		}
	}
	return (*this);
}

template <typename T>
void*	Array<T>::operator new[](std::size_t size) {
	return (new Array<T>(size));
}

template <typename T>
T&	Array<T>::operator[](unsigned int idx) {
	return (this(idx));
}

template <typename T>
std::ostream&	operator<<(std::ostream& out, const Array<T>& obj) {
	for (unsigned int i = 0; i < obj.size(); i++)
		out << obj[i] << ' ';
	std::cout << std::endl;
	return (out);
}

/****************************************************
*					FUNCTIONS						*
****************************************************/

template <typename T>
unsigned int	Array<T>::size(void) const {
	return (_size);
}

/****************************************************
*					EXCEPTIONS						*
****************************************************/

template <typename T>
const char*	Array<T>::IndexOutOfBounds::what(void) const noexcept {
	return ("Index out of bounds!\n");
}
