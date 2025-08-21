
template <typename cont>
class FordJohnson {

	private:
		cont**	_a;
		cont**	_b;
		cont*	_unused;
		int		_comparisons;

	public:
		FordJohnson();
		FordJohnson(const FordJohnson<cont>& other);
		~FordJohnson();

		FordJohnson<cont>&	operator=(const FordJohnson<cont>& other);

		cont	sorting(PmergeMe<cont>& obj);
		void	swapping(PmergeMe<cont>& obj, size_t block_size);
		void	insertion(PmergeMe<cont>& obj, size_t block_size = 1);
		void	Jacobsthal(cont& main, cont**& pend, size_t block_size);
		void	setArrayCont(cont& con, size_t block_size);
		void	clearCont(void);
		int		getComparisons(void) const;
};

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

template <typename cont>
FordJohnson<cont>::FordJohnson() :
	_a(nullptr),
	_b(nullptr),
	_unused(nullptr),
	_comparisons(0) {}

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
	_comparisons = other._comparisons;
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
        std::swap(_comparisons, tmp._comparisons);
    }
	return (*this);
}

/****************************************************
*					STATIC FUNCTIONS				*
****************************************************/

/**
 * @brief Searches for the upper limit given the b_i and returns 
 * its index in the main chain.
 * 
 * @note Upper limit for any b_i is the equivalent a_i.
 */
template <typename cont>
static size_t	upperBoundIdx(cont& main, cont**& a, size_t b_idx) {
	if (a[b_idx - 1] == nullptr)
		return (main.size() - 1);
	int val = *std::max_element(a[b_idx - 1]->begin(), a[b_idx - 1]->end());
	size_t i = -1;
	while (main[++i] != val)
		continue ;
	return (i);
}

/**
 * @brief Set the pend chain equal to the b's
 */
template <typename cont>
static void	setPend(cont**& b, cont**& pend) {
	pend = nullptr;
	if (b == nullptr)
		return ;
	size_t size = 0;
	while (b[size] != nullptr)
		size++;
	if (size <= 1)
		return ;
	pend = new cont*[size];
	for (size_t i = 0; i < size - 1; ++i)
		pend[i] = new cont(*b[i + 1]);
	pend[size - 1] = nullptr;
}

/**
 * @brief Set the main chain equal to b1 + a's.
 */
template <typename cont>
static void	setMain(cont**& a, cont& b, cont& main) {
	cont**	temp = a;
	main.insert(main.end(), b.begin(), b.end());
	while (*temp != nullptr) {
		main.insert(main.end(), (*temp)->begin(), (*temp)->end());
		temp++;
	}
}

/****************************************************
*					FUNCTIONS						*
****************************************************/

template <typename cont>
void	FordJohnson<cont>::Jacobsthal(cont& main, cont**& pend, size_t block_size) {
	size_t	pend_size = 0;
	size_t	J_prev = 1;
	size_t	J_curr = 3;
	size_t	J_next;

	if (pend == nullptr)
		return ;
	while (pend[pend_size] != nullptr)
		pend_size++;
	while (J_prev <= pend_size) {
		for (size_t j = J_curr; j > J_prev; j--) {
			if (j - 2 < pend_size) {
				size_t upper_bound_idx = upperBoundIdx(main, _a, j);
				size_t i = block_size - 1;
				int max_pend = *std::max_element(pend[j - 2]->begin(), pend[j - 2]->end());
				
				// std::cout << "\ninsert: ";
				// utils::printCont(*pend[j - 2]);
				// std::cout << std::endl;
				// std::cout << "bounds: [main[" << i << "], main[" << upper_bound_idx <<"] = [" << main[i] << ", " << main[upper_bound_idx] << "]" << std::endl;
				
				while (i < upper_bound_idx) {
					_comparisons++;
					if (main[i] > max_pend)
						break ;
					i += block_size;
				}
				// std::cout << "i: " << i << std::endl;
				// std::cout << "size: " << main.size() << std::endl;
				// std::cout << "comparisons + " << (i - block_size + 1) / block_size << std::endl;
				// std::cout << "_comparisons + " << (i - block_size + 1) / block_size << " = " << _comparisons << std::endl;
				if (i == main.size() - 1 && max_pend > main[i])
					main.insert(main.begin() + i + 1, pend[j - 2]->begin(), pend[j - 2]->end());
				else
					main.insert(main.begin() + i + 1 - block_size, pend[j - 2]->begin(), pend[j - 2]->end());

				// std::cout << "\n\t ";
				// utils::printCont(main);
				// std::cout << std::endl;
			}
		}
		J_next = J_curr + 2 * J_prev;
        J_prev = J_curr;
        J_curr = J_next;
	}
}

/**
 * @brief Set the a's and the b's as the min and max of each pair of blocks.
 */
template <typename cont>
void	FordJohnson<cont>::setArrayCont(cont& con, size_t block_size) {
	size_t num_of_blocks = con.size() / block_size;
	int count_a = 0;
	int count_b = 0;
	
	_a = new cont*[num_of_blocks / 2 + 1];
	_b = new cont*[num_of_blocks - num_of_blocks / 2 + 1];
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
}

/**
 * @note change the signature from taking the whole PmergeMe obj as param to only its cont
 */
template <typename cont>
void	FordJohnson<cont>::insertion(PmergeMe<cont>& obj, size_t block_size) {
	cont	main;
	cont**	pend;

	// std::cout << utils::color("\nInsertion with a block size of ", YLW) << block_size << ":\n\t" << obj << std::endl;
	clearCont();
	setArrayCont(obj.getCont(), block_size);
	setMain(_a, *_b[0], main);
	setPend(_b, pend);
	

	// std::cout << "_a: [";
	// for (int j = 0; _a[j] != nullptr; j++) {
	// 	std::cout << '[';
	// 	utils::printCont(*_a[j]);
	// 	std::cout << ']';
	// 	if (_a[j + 1] != nullptr)
	// 		std::cout << ", ";
	// 	else
	// 		std::cout << ']' << std::endl;
	// }
	// std::cout << "_b: [";
	// for (int j = 0; _b[j] != nullptr; j++) {
	// 	std::cout << '[';
	// 	utils::printCont(*_b[j]);
	// 	std::cout << ']';
	// 	if (_b[j + 1] != nullptr)
	// 		std::cout << ", ";
	// 	else
	// 		std::cout << ']' << std::endl;
	// }
	// std::cout << "\nmain:\t";
	// utils::printCont(main);
	// std::cout << std::endl;
	// std::cout << "pend:\t[";
	// if (pend != nullptr) {
	// 	for (int j = 0; pend[j] != nullptr; j++) {
	// 		std::cout << '[';
	// 		utils::printCont(*pend[j]);
	// 		std::cout << ']';
	// 		if (pend[j + 1] != nullptr)
	// 			std::cout << ", ";
	// 		else
	// 			std::cout << ']' << std::endl;
	// 	}	
	// }
	// else
	// 	std::cout << "]" << std::endl; 
	// std::cout << "unused: ";
	// if (_unused)
	// 	utils::printCont(*_unused);
	// else
	// 	std::cout << "'null'";
	// std::cout << std::endl << std::endl;
	

	Jacobsthal(main, pend, block_size);
	if (_unused != nullptr)
		main.insert(main.end(), _unused->begin(), _unused->end());
	obj.setCont(main);
	if (pend != nullptr) {
		for (int i = 0; pend[i] != nullptr; i++)
			delete pend[i];
		delete[] pend;
	}
}

/**
 * @brief Swapping elements of the pair
 * 
 * @param block_size how many numbers each element is comprised of.
 */
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
	insertion(obj, block_size);
}

template <typename cont>
cont	FordJohnson<cont>::sorting(PmergeMe<cont>& obj) {
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

template <typename cont>
int	FordJohnson<cont>::getComparisons(void) const {
	return (_comparisons);
}