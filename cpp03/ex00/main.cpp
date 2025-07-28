#include "ClapTrap.hpp"

int main()
{
    ClapTrap bot("Bender");

    bot.attack("Target A");
    bot.takeDamage(3);
    bot.beRepaired(5);
    bot.attack("Target B");
    bot.takeDamage(20);
    bot.beRepaired(2); // Esto ya no debería funcionar si HP es 0
}
