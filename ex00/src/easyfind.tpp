
template <typename T>
void	easyfind(T& cont, int val) {
	auto it = std::find(cont.begin(), cont.end(), val);
	std::cout << "'" << *it << "'" << std::endl;
}