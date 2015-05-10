#ifndef SHOP_H
#define SHOP_H
#include <string>
#include <map>
#include "Player.h"


class Shop
{
private:
    Player * _player;
    std::vector<Bullet *> _bullets;
    std::vector<Ship *> _ships;

public:
// CONSTRUCTOR ABD DESTRUCTOR
//
    Shop(Player* player);

    virtual ~Shop();

// METHODS
//
    // return if player can buy the product
    bool available(const std::string product, const int level);
    
    // upgrade the bullet if it's possible
    bool upgradeBullet(const int level);
    
    // same for ship
    bool upgradeShip(const int level);
    
    // same for shild
    bool upgradeShield(const int level);
    
    bool buyBomb();
    
    bool buyLife();
    

};

#endif // SHOP_H
