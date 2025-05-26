#include "../inc/Zombie.hpp"

int	main(void) {
	int	N = 7;

	std::cout << std::endl;
	Zombie* horde = zombieHorde(N, "Grigoris");
	for (int i = 0; i < N; i++) {
		(&horde[i])->announce();
	}
	for (int i = 0; i < N; i++) {
		(&horde[i])->~Zombie();
	}
	::operator delete(horde);
}
