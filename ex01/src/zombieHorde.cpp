
#include "../inc/Zombie.hpp"
#include <string>

Zombie*	zombieHorde(int N, std::string name) {
	void* memory = ::operator new(N * sizeof(Zombie));
	Zombie* horde = static_cast<Zombie*>(memory);

	for (int i = 0; i < N; i++) {
		new (&horde[i]) Zombie(name);
	}
	return (horde);
}