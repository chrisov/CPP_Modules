
template <typename cont>
class FordJohnson {

	private:
		cont**	_a;
		cont**	_b;
		cont*	_unused;

	public:
		FordJohnson();
		FordJohnson(const FordJohnson<cont>& other);
		~FordJohnson();

		FordJohnson<cont>&	operator=(const FordJohnson<cont>& other);

		cont	sorting(PmergeMe<cont>& obj);
		void	swapping(PmergeMe<cont>& obj, size_t block_size);
		void	insertion(PmergeMe<cont>& obj, size_t block_size = 1);
		void	setArrayCont(cont& con, size_t block_size);
		void	clearCont(void);
};

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

template <typename cont>
FordJohnson<cont>::FordJohnson() :
	_a(nullptr),
	_b(nullptr),
	_unused(nullptr) {
	std::cout << "Default Ford-Johnson constructor called!" << std::endl;
}

template <typename cont>
FordJohnson<cont>::FordJohnson(const FordJohnson<cont>& other) :
	_a(nullptr), _b(nullptr), _unused(nullptr) {
	if (other._a) {
		size_t a_size = 0;
		while(other._a[a_size] != nullptr)
			a_size++;
		_a = new cont*[a_size + 1];
		for(size_t i = 0; i < a_size; ++i)
			_a[i] = new cont(*other._a[i]);
		_a[a_size] = nullptr;
	}
	if (other._b) {
		size_t b_size = 0;
		while(other._b[b_size] != nullptr)
			b_size++;
		_b = new cont*[b_size + 1];
		for(size_t i = 0; i < b_size; ++i)
			_b[i] = new cont(*other._b[i]);
		_b[b_size] = nullptr;
	}
	if (other._unused != nullptr)
		_unused = new cont(*other._unused);
	std::cout << "Copy Ford-Johnson constructor called!" << std::endl;
}

template <typename cont>
FordJohnson<cont>::~FordJohnson() {
	if (_a) {
		for (size_t i = 0; _a[i] != nullptr; i++)
			delete _a[i];
		delete[] _a;
	}
	if (_b) {
		for (size_t i = 0; _b[i] != nullptr; i++)
			delete _b[i];
		delete[] _b;
	}
	if (_unused != nullptr)
		delete _unused;
	std::cout << utils::color("Ford-Johnson", YLW) << utils::color(" destructor", RED) << " called!" << std::endl;
}

/****************************************************
*					OPERATORS						*
****************************************************/

template <typename cont>
FordJohnson<cont>&	FordJohnson<cont>::operator=(const FordJohnson<cont>& other) {
    if (this != &other) {
        FordJohnson<cont> tmp(other);
        std::swap(_a, tmp._a);
        std::swap(_b, tmp._b);
        std::swap(_unused, tmp._unused);
    }
	return (*this);
}

/****************************************************
*					FUNCTIONS						*
****************************************************/

template <typename cont>
void	FordJohnson<cont>::setArrayCont(cont& con, size_t block_size) {
	size_t num_of_blocks = con.size() / block_size;
	int count_a = 0;
	int count_b = 0;
	
	_a = new cont*[num_of_blocks / 2 + 1];
	_b = new cont*[num_of_blocks - num_of_blocks / 2 + 1];
	std::cout << std::endl;
	for (size_t i = 0; i < con.size(); i += block_size) {
		auto start = std::next(con.begin(), i);
		auto end = std::next(con.begin(), std::min(i + block_size, con.size()));
		if ((size_t)std::distance(start, end) == block_size) {
			if ((i / block_size) % 2 == 0) {
				_b[count_b] = new cont(start, end);
				count_b++;
			}
			else {
				_a[count_a] = new cont(start, end);
				count_a++;
			}
		}
		else
			_unused = new cont(start, end);
	}
	_b[count_b] = nullptr;
	_a[count_a] = nullptr;
	for (int j = 0; _a[j] != nullptr; j++) {
		std::cout << "_a[" << j << "]: [";
		utils::printCont(*_a[j]);
		std::cout << ']' << std::endl;
	}
	for (int j = 0; _b[j] != nullptr; j++) {
		std::cout << "_b[" << j << "]: [";
		utils::printCont(*_b[j]);
		std::cout << ']' << std::endl;
	}
	std::cout << "unused: ";
	if (_unused)
		utils::printCont(*_unused);
	std::cout << std::endl;
}

template <typename cont>
void	FordJohnson<cont>::insertion(PmergeMe<cont>& obj, size_t block_size) {
	cont	main;
	cont	pend;
	cont	unused;

	std::cout << "\nInsertion with a block size of " << block_size << ":\n\t";
	std::cout << obj << std::endl;
	setArrayCont(obj.getCont(), block_size);
	// cont **temp = _a;
	// bool first_time = true;
	// std::cout << "a = ";
	// while (*temp) {
	// 	if (!first_time)
	// 		std::cout << ", ";
	// 	std::cout << "[";
	// 	utils::printCont(**temp);
	// 	std::cout << "]";
	// 	first_time = false;
	// 	temp++;
	// }
	// temp = _b;
	// first_time = true;
	// std::cout << "\nb = ";
	// while (*temp) {
	// 	if (!first_time)
	// 		std::cout << ", ";
	// 	std::cout << "[";
	// 	utils::printCont(**temp);
	// 	std::cout << "]";
	// 	first_time = false;
	// 	temp++;
	// }
	// std::cout << "\nunused: ";
	// utils::printCont(*_unused);
	// std::cout << std::endl;
}

template <typename cont>
void	FordJohnson<cont>::swapping(PmergeMe<cont>& obj, size_t block_size) {
	cont& con = obj.getCont();
	
	if (block_size >= con.size() / 2)
	return ;
	// std::cout << "\nSwapping with a block size of " << block_size << ":\n\t";
	for (size_t i = 0; i + 2 * block_size <= con.size(); i += 2 * block_size) {
		auto first_block_start = std::next(con.begin(), i);
		auto first_block_end = std::next(first_block_start, block_size);
		auto second_block_start = first_block_end;
		auto second_block_end = std::next(second_block_start, block_size);

		if (*std::prev(first_block_end) > *std::prev(second_block_end))
			std::swap_ranges(first_block_start, first_block_end, second_block_start);
    }
	// utils::printCont(obj.getCont());
    swapping(obj, 2 * block_size);
	clearCont();
	insertion(obj, block_size);
}

template <typename cont>
cont	FordJohnson<cont>::sorting(PmergeMe<cont>& obj) {
	std::cout << utils::color("\nBefore", YLW) << ": ";
	std::cout << obj << std::endl;
	swapping(obj, 1);
	return (obj.getCont());
}

template <typename cont>
void	FordJohnson<cont>::clearCont(void) {
    if (_a) {
        for (size_t i = 0; _a[i] != nullptr; ++i)
            delete _a[i];
        delete[] _a;
        _a = nullptr;
    }
    if (_b) {
        for (size_t i = 0; _b[i] != nullptr; ++i)
            delete _b[i];
        delete[] _b;
        _b = nullptr;
    }
    if (_unused != nullptr) {
        delete _unused;
        _unused = nullptr;
    }
}
