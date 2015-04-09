#ifndef SHOP_H
#define SHOP_H
#include <string>

#include "Player.h"

class Shop
{
    public:
        Shop();
        virtual ~Shop();
        bool upgradeBullet(std::string type, Player * player);
        bool upgradeShip(std::string type, Player * player);
        bool upgradeShild(std::string type, Player * player);
    protected:
    private:
};

#endif // SHOP_H
