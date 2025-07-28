#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
	private:
		std::string name;  // Variable privada para almacenar el nombre del zombie.

	public:
		~Zombie();  // Destructor que se llama cuando un objeto zombie se destruye.
		Zombie(); // Constructor por defecto, antes tenia cosas

		void setName(const std::string& newName);  // Función pública para cambiar el nombre del zombie.
		void announce();  // Función para que el zombie se anuncie.
		static Zombie* zombieHorde(int N, std::string name);
};

#endif
