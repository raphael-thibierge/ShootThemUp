#ifndef SHOP_H
#define SHOP_H
#include <string>
#include <map>
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
        std::map<std::string, bool> _store;
};

#endif // SHOP_H
