#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class Human_B
{
	private:
		std::string name;
		Weapon* weapon; // * permite flexibilidad, weapon se puede cambiar y Human_B puede no estar armado

	public:
		//~Weapon();
		Human_B(const std::string& name) : name(name) {};
		void setWeapon(Weapon& weapon);
		void attack();
};

// to do
// entender mejor constructors

#endif

