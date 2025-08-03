
/****************************************************
*					CONSTRUCTORS					*
****************************************************/

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {
	std::cout << "Default " << color("MutantStack", YLW) << color(" constructor", GRN) << " called!" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : std::stack<T>(other) {
	std::cout << "Copy " << color("MutantStack", YLW) << color(" constructor", GRN) << " called!" << std::endl;
}

template <typename T>
MutantStack<T>::~MutantStack() {
	std::cout << color("MutantStack", YLW) << color(" destructor", RED) << " called!" << std::endl;
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
typename MutantStack<T>::iterator	MutantStack<T>::begin() {
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end() {
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin() const {
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end() const {
	return (this->c.end());
}

/****************************************************
*					FUNCTIONS						*
****************************************************/

template <typename T>
std::deque<T>	MutantStack<T>::getC(void) const {
	return (this->c);
}