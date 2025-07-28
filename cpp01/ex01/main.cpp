#include "Zombie.hpp"

int main()
{
	int N = 5;
	std::string zombieName = "Zombie";

	Zombie* Z = Zombie::zombieHorde(N, zombieName);
	for (int i = 0; i < N; i++)
	{
		Z[i].announce();
	}
	delete[] Z;
	return 0;
}
