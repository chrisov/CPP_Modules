
#include "../inc/Zombie.hpp"

int	main(void) {
	int	num = 7;

	Zombie* horde = zombieHorde(num, "Grigoris");
	for (int i = 0; i < num; i++) {
		(&horde[i])->announce();
	}
	for (int i = 0; i < num; i++) {
		(&horde[i])->~Zombie();
	}
	::operator delete(horde);
}
