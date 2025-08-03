
/****************************************************
*					CONSTRUCTORS					*
****************************************************/

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {
	std::cout << "Default constructor called!" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : std::stack<T>(other) {
	std::cout << "Copy constructor called!" << std::endl;
}

template <typename T>
MutantStack<T>::~MutantStack() {
	std::cout << "Default destructor called!" << std::endl;
}

/****************************************************
*					OPERATORS						*
****************************************************/

template <typename T>
MutantStack<T>&	MutantStack<T>::operator=(const MutantStack& other) {
	if (this != &other)
		this = &other;
	return (*this);
}

template <typename T>
std::ostream&	operator<<(std::ostream& out, const MutantStack<T>& obj) {
	for (const auto& elem : obj.getC())
		out << "'" << elem << "'\n";
	return (out);
}

/****************************************************
*					ITERATORS						*
****************************************************/

template <typename T>
typename std::deque<T>::iterator	MutantStack<T>::begin() {
	return (this->c.begin());
}

/****************************************************
*					FUNCTIONS						*
****************************************************/

template <typename T>
std::deque<T>	MutantStack<T>::getC(void) const {
	return (this->c);
}