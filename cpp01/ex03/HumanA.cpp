#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

void Human_A::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}