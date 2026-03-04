#include "ScavTrap.hpp"

int main()
{
    ScavTrap bot("R2D2");

    bot.attack("intruder");
    bot.takeDamage(30);
    bot.beRepaired(10);
    bot.guardGate();
}