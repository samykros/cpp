#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

// Funciones dentro de Zombie es porque utilizan atributos priv, cuando utilizan publicos tmb puedes querer ponerlos dentro entiendo
class Zombie
{
	private:
		std::string name;  // Variable privada para almacenar el nombre del zombie.

	public:
		Zombie(std::string name);  // Constructor que inicializa un zombie con un nombre.
		~Zombie();  // Destructor que se llama cuando un objeto zombie se destruye.

		void setName(const std::string& newName);  // Función pública para cambiar el nombre del zombie.
		void announce();  // Función para que el zombie se anuncie.
};

// Pero los que no utilizan atributos van fuera
Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
