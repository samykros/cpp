#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

/*
int main()
{
	// Crear una arma
	Weapon sword("Sword");

	// Crear HumanA con un arma
	Human_A knight_1("Arturo", sword);
	knight_1.attack();  // Arturo ataca con su Espada

	// Crear HumanB inicialmente sin arma
	Human_B knight_2("Percival");
	knight_2.attack();  // Percival intenta atacar pero no tiene arma

	// Asignar una arma a HumanB y atacar
	knight_2.setWeapon(sword);
	knight_2.attack();  // Percival ataca con su Espada

	return 0;
}
*/

int main()
{
	{
		Weapon club = Weapon("crude spiked club");

		Human_A bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");

		Human_B jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}

// . (punto): Se usa para acceder a miembros de un objeto o estructura cuando tienes una instancia de un objeto (no un puntero)
// Por ejemplo, si Z es un objeto de la clase Zombie, accedes a su método con z.announce();.
// -> (flecha): Se utiliza para acceder a miembros de un objeto a través de un puntero.
// Si tienes un puntero a un objeto, como Zombie* Z, entonces accedes a sus miembros usando z->announce();.