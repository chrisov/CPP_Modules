
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
	if (this != &other) {
		this = &other;
	}
	return (*this);
}

// template <typename T>
// std::ostream&	operator<<(std::ostream& out, const MutantStack<T>& obj) {
// 	for (auto i : obj.c)
// 		out << *i << '\n';
// 	return (out);
// }

/****************************************************
*					ITERATORS						*
****************************************************/

// template <typename T>
// typename MutantStack<T>::iterator MutantStack<T>::begin() {
// 	return (c.begin());
// }

/****************************************************
*					FUNCTIONS						*
****************************************************/

// template <typename T>
// void	MutantStack<T>::push(T elem) {
// 	return (c.push_back());
// }