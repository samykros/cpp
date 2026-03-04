#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

// Nivel	    ¿Quién puede acceder?	            Ejemplo
// private	    Solo la clase donde se declaró	    👀 Solo yo
// protected	La clase y sus hijas (subclases)	👪 Yo y mis hijos
// public	    Cualquiera puede acceder	        🌍 Todo el mundo
class ClapTrap
{
    // explicacion arriba
    protected:
        std::string name;
        int hit_points; // vida
        int energy_points;
        int attack_damage;

    public:
        ClapTrap(std::string const& name);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif