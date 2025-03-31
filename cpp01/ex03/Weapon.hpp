#ifndef WAR_HPP
#define WAR_HPP

#include <string>
#include <iostream>

class Weapon
{
	private:
		std::string type;  // Variable privada para almacenar el nombre del zombie.

	public:
		//~Weapon();
		Weapon(const std::string& initType) : type(initType) {}

		const std::string& getType();
		void setType(const std::string& type);  // Función pública para cambiar el nombre del zombie.
};

#endif
