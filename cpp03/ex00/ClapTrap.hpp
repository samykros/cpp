#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

// ClapTrap es un "robot" de un juego
class ClapTrap
{
    private:
        std::string name;
        // inicializar aqui funciona en C++11 en adelante
        // C++98 no permite, por eso poner int hit_points = 10;
        // es incorrecto y hay que hacerlo desde el constructor
        // en C++11 o más moderno, usar initializer list (inicializar
        // en constructor) es más eficiente que hacer eso
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