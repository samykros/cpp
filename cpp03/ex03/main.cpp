#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap bot("monster");

    bot.attack("enemy");
    bot.takeDamage(50);
    bot.beRepaired(30);
    bot.whoAmI();

    return 0;
}
