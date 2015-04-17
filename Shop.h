#ifndef SHOP_H
#define SHOP_H
#include <string>
#include <map>
#include "Player.h"

class Shop
{
private:
    std::map<std::string, bool> _store;
    Player* _player;
    
public:
// CONSTRUCTOR ABD DESTRUCTOR
//
    Shop(Player* player);
    
    virtual ~Shop();
    
// METHODS
//
    bool upgradeBullet(std::string type);
    
    bool upgradeShip(std::string type);
    
    bool upgradeShild(std::string type);

};

#endif // SHOP_H
