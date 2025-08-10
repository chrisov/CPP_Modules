
template <typename cont>
class PmergeMe {

	private:
		cont	_cont;
		double	_time;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe(const char *arr[], int size);
		~PmergeMe();

		PmergeMe& operator=(const PmergeMe& other);
		
		static cont	parseArray(const char *arr[], int size);
		static bool	isDuplicateParam(cont& con, int val);

		const cont&	getCont(void) const;
		double		getTime(void) const;
};

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

template <typename cont>
PmergeMe<cont>::PmergeMe() : 
	_cont(),
	_time(0) {
	std::cout << "Default " << utils::color("PmergeMe", YLW) << utils::color(" constructor", GRN) << " called!" << std::endl;
}

template <typename cont>
PmergeMe<cont>::PmergeMe(const PmergeMe& other) :
	_cont(other._cont),
	_time(other._time) {
	std::cout << "Default " << utils::color("PmergeMe", YLW) << utils::color(" constructor", GRN) << " called!" << std::endl;
}

template <typename cont>
PmergeMe<cont>::PmergeMe(const char *arr[], int size) :
	_cont(PmergeMe<cont>::parseArray(arr, size)),
	_time(0) {
	std::cout << "Parameterized " << utils::color("PmergeMe", YLW) << utils::color(" constructor", GRN) << " called!" << std::endl;
}

template <typename cont>
PmergeMe<cont>::~PmergeMe() {
	std::cout << utils::color("PmergeMe ", YLW) << utils::color("destructor", RED) << " called!" << std::endl;
}

/****************************************************
*					OPERATORS						*
****************************************************/

template <typename cont>
PmergeMe<cont>&	PmergeMe<cont>::operator=(const PmergeMe& other) {
	if (this != &other) {
		_cont = other._cont;
		_time = other._time;
	}
	return (*this);
}

template <typename cont>
std::ostream&	operator<<(std::ostream& out, const PmergeMe<cont>& obj) {
	int count = 0;
	const cont& container = obj.getCont();

	for (auto it = container.begin(); it != container.end(); ++it) {
		out << std::setw(7) << *it;
		count++;
		if (count % 7 == 0)
			out << "\n\t";
		else if (std::next(it) != container.end())
			out << " ";
	}
	return (out);
}

/****************************************************
*					FUNCTIONS						*
****************************************************/

template <typename cont>
bool	PmergeMe<cont>::isDuplicateParam(cont& con, int val) {
	for (const auto& i : con)
		if (i == val)
			return (true);
	return (false);
}

template <typename cont>
cont	PmergeMe<cont>::parseArray(const char *arr[], int size) {
	cont	res;
	
	for (int i = 0; i < size; i++) {
		char	**matrix = utils::split(arr[i], ' ');
		int		arrSize = utils::arraySize(matrix);
		for (int i = 0; i < arrSize; i++) {
			int val = std::stoi(matrix[i]);
			if (val < 0) {
				utils::freeCharArray(matrix);
				throw NegativeNumberException();
			}
			if (isDuplicateParam(res, val)) {
				utils::freeCharArray(matrix);
				throw DuplicateNumberException();
			}
			res.push_back(val);
		}
		utils::freeCharArray(matrix);
	}
	if (res.size() == 1)
		throw UnitaryArrayException();
	return (res);
}

template <typename cont>
const cont&	PmergeMe<cont>::getCont(void) const {
	return (_cont);
}

template <typename cont>
double	PmergeMe<cont>::getTime(void) const {
	return (_time);
}
