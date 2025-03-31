#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class Human_A
{
	private:
		std::string name;
		Weapon& weapon; // & referencia no tiene flexibilidad, Human_A simpre tendra weapon

	public:
		//~Weapon(); // destructores no necesarios pq es memoria no dinamica ?
		Human_A(const std::string& name, Weapon& weapon) : name(name), weapon(weapon) {};
		void attack();
};

#endif
