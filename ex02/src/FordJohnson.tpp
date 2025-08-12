
template <typename cont>
class FordJohnson {

	private:
		cont*	_a;
		cont*	_b;

	public:
		FordJohnson();
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

template <typename cont>
FordJohnson<cont>::FordJohnson(const FordJohnson<cont>& other) :
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
static void	swapping(cont& con, size_t block_size = 1) {
    if (block_size >= con.size() / 2)
        return ;
    std::cout << "\nSwapping with a block size of " << block_size << ":\n";
for (size_t i = 0; i + 2 * block_size <= con.size(); i += 2 * block_size) {
		auto first_block_start = std::next(con.begin(), i);
		auto first_block_end = std::next(first_block_start, block_size);
		auto second_block_start = first_block_end;
		auto second_block_end = std::next(second_block_start, block_size);

		
		if (*std::prev(first_block_end) > *std::prev(second_block_end)) {
			// auto it = first_block_start;
			// auto end = first_block_end;
			// std::cout << "Before f: [";
			// while (it != end) {
			// 	std::cout << *it;
			// 	if (std::next(it) != end)
			// 		std::cout << ", ";
			// 	it++;
			// }
			// std::cout << "], [";
			// it = second_block_start;
			// end = second_block_end;
			// while (it != end) {
			// 	std::cout << *it;
			// 	if (std::next(it) != end)
			// 		std::cout << ", ";
			// 	it++;
			// }
			// std::cout << "]" << std::endl;

			std::swap_ranges(first_block_start, first_block_end, second_block_start);
			
			// it = first_block_start;
			// end = first_block_end;
			// std::cout << "After f: [";
			// while (it != end) {
			// 	std::cout << *it;
			// 	if (std::next(it) != end)
			// 		std::cout << ", ";
			// 	it++;
			// }
			// std::cout << "], [";
			// it = second_block_start;
			// end = second_block_end;
			// while (it != end) {
			// 	std::cout << *it;
			// 	if (std::next(it) != end)
			// 		std::cout << ", ";
			// 	it++;
			// }
			std::cout << "]\n" << std::endl;
		}
    }
	std::cout << '\t';
	utils::printCont(con);
    swapping(con, block_size * 2);
}

template <typename cont>
cont	FordJohnson<cont>::sorting(PmergeMe<cont>& obj) {
	cont	main;
	cont	pend;
	cont	unused;

	swapping(obj.getCont());
	return (main);
}
