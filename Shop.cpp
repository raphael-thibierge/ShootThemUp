#include "Shop.h"
using namespace std;

//
// CONSTRUCTOR ABD DESTRUCTOR
//

Shop::Shop(Player* player) : _player(player){

    // Bullets and ship class are used to display information in view
    _bullets.push_back(new Bullet(0));
    _bullets.push_back(new Bullet(1));
    _bullets.push_back(new Bullet(2));
    _bullets.push_back(new Bullet(3));
    _bullets.push_back(new Bullet(4));
    _ships.push_back(new Ship(0));
    _ships.push_back(new Ship(1));
    _ships.push_back(new Ship(2));
    _ships.push_back(new Ship(3));
}

Shop::~Shop()
{
    _player = nullptr;
}


//
// METHODS
//
bool Shop::available(const string product, const int level){
    // level 0 of an object is alway available
    // if the player have the previous level of bullet
    // he can buy this one
    if ( product == "bullet"){
        if (_bullets[level-1]->getType() == _player->getBulletType())
            return true;
    }
    // same for shield
    else if (product == "shield"){
        if (_player->getShield() == level-1)
            return true;
    }
    // same for ship
    else if (product == "ship"){
        if (_ships[level-1]->getType() == _player->getType())
            return true;
    }
    return false;
}


bool Shop::upgradeBullet(const int level){
    
    // if the bullet's level is available and the player has enough money
    if ( available("bullet", level) && _player->getMoney() >= BULLET_PRICE[level]){
        // he buys it and he gets it
        _player->pay(BULLET_PRICE[level]);
        _player->setBulletType(level);
        return true;
    }
    return false;
}

bool Shop::upgradeShip(const int level){
    
    // if the ship's level is available and the player has enough money
    if (available("ship", level) && _player->getMoney() >= SHIP_PRICE[level]){
        // he buys it and he gets it
        _player->pay(SHIP_PRICE[level]);
        _player->setType(level);
        return true;
    }
    return false;
}

bool Shop::upgradeShield(const int level){
    
    // if the shield's level is available and the player has enough money
    if (available("shield", level) && _player->getMoney() >= SHIELD_PRICE[level]){
        // he buys it and he gets it
        _player->pay(SHIELD_PRICE[level]);
        _player->setShield(level);
        
        return true;
    }
    return false;
}

bool Shop::buyBomb(){
    //return true if player bought a bomb, else return false
    
    // if player has enough money
    if (_player->getMoney() > BOMB_PRICE){
        // he pays and gets a bomb
        _player->pay(BOMB_PRICE);
        _player->addBomb();
        return true;
    }
    return false;
}

bool Shop::buyLife(){
    //return true if player bought a life, else return false
    
    //if player has enough money
    if (_player->getMoney() > LIFE_PRICE){
        // he pays and gets a life
        _player->pay(LIFE_PRICE);
        _player->addLife(1);
        return true;
    }
    return false;
}


