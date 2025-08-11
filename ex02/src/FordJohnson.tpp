
template <typename cont>
class FordJohnson {

	private:
		// cont	_main;
		// cont	_pend;
		// cont	_unused;
		cont*	_a;
		cont*	_b;

	public:
		FordJohnson();
		// FordJohnson(cont con);
		FordJohnson(const FordJohnson<cont>& other);
		~FordJohnson();

		FordJohnson<cont>&	operator=(const FordJohnson<cont>& other);

		cont		sorting(PmergeMe<cont>& obj);
};

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

template <typename cont>
FordJohnson<cont>::FordJohnson() :
	_a(nullptr),
	_b(nullptr) {
	std::cout << "Default Ford-Johnson constructor called!" << std::endl;
}

// template <typename cont>
// FordJohnson<cont>::FordJohnson(cont con) :
// 	_main(con),
// 	_pend(),
// 	_unused(),
// 	_a(nullptr),
// 	_b(nullptr) {
// 	std::cout << "Parameterized Ford-Johnson constructor called!" << std::endl;
// }

template <typename cont>
FordJohnson<cont>::FordJohnson(const FordJohnson<cont>& other) :
	// _main(other._main),
	// _pend(other._pend),
	// _unused(other._unused),
	_a(other._a),
	_b(other._b) {
	std::cout << "Copy Ford-Johnson constructor called!" << std::endl;
}

template <typename cont>
FordJohnson<cont>::~FordJohnson() {
	if (_a)
		delete _a;
	if (_b)
		delete _b;
	std::cout << "Default destructor called!" << std::endl;
}

/****************************************************
*					OPERATORS						*
****************************************************/

template <typename cont>
FordJohnson<cont>&	FordJohnson<cont>::operator=(const FordJohnson<cont>& other) {
	if (this != &other) {
		// _main = other._main;
		// _pend = other._pend;
		// _unused = other.unused;
		if (_a)
			delete _a;
			_a = new cont(other._a);
		if (_b)
			delete _b;
			_b = new cont(other._b);
	}
	return (*this);
}

/****************************************************
*					FUNCTIONS						*
****************************************************/

template <typename cont>
cont	FordJohnson<cont>::sorting(PmergeMe<cont>& obj) {
	std::cout << obj << std::endl;
}
