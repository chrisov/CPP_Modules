
template <typename cont>
class PmergeMe {

	private:
		cont	*_con;
		double	_time;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe(const char *arr[], int size);
		~PmergeMe();

		PmergeMe& operator=(const PmergeMe& other);
		
		static cont	parseArray(const char *arr[], int size);
		static bool	isDuplicateParam(cont& con, int val);

		const cont&		getCont(void) const;
		cont&			getCont(void);
		void			setCont(cont con);
		double			getTime(void) const;
};

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

template <typename cont>
PmergeMe<cont>::PmergeMe() : 
	_con(nullptr),
	_time(0) {}

template <typename cont>
PmergeMe<cont>::PmergeMe(const PmergeMe& other) :
	_con(new cont(*other._con)),
	_time(other._time) {}

template <typename cont>
PmergeMe<cont>::PmergeMe(const char *arr[], int size) :
	_con(new cont(PmergeMe<cont>::parseArray(arr, size))),
	_time(0) {}

template <typename cont>
PmergeMe<cont>::~PmergeMe() {
	if (_con != nullptr)
		delete _con;
}

/****************************************************
*					OPERATORS						*
****************************************************/

template <typename cont>
PmergeMe<cont>&	PmergeMe<cont>::operator=(const PmergeMe& other) {
	if (this != &other) {
		if (_con != nullptr)
			delete _con;
		_con = new cont(*other._con);
		_time = other._time;
	}
	return (*this);
}

template <typename cont>
std::ostream&	operator<<(std::ostream& out, const PmergeMe<cont>& obj) {
	int			count = 0;
	const cont& container = obj.getCont();

	for (auto it = container.begin(); it != container.end(); ++it) {
		out << std::setw(7) << *it;
		count++;
		if (count % 10 == 0) {
			out << "\n";
			if (std::next(it) != container.end())
				std::cout << '\t';
		}
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
		for (int j = 0; j < arrSize; j++) {
			int val = std::stoi(matrix[j]);
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
void	PmergeMe<cont>::setCont(cont con) {
	if (_con != nullptr)
		delete _con;
	_con = new cont(con);
}

template <typename cont>
const cont&	PmergeMe<cont>::getCont(void) const {
	return (*_con);
}

template <typename cont>
cont&	PmergeMe<cont>::getCont(void) {
	return (*_con);
}

template <typename cont>
double	PmergeMe<cont>::getTime(void) const {
	return (_time);
}
