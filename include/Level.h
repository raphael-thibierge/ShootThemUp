
#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include "Enemy.h"
#include "Player.h"

class Level
{

private:
    
    unsigned int _level;
	unsigned int _difficulty;
	unsigned int _nbEnnemy;
    Player * _player;
    std::list<Enemy*> * _enemyList ;
    std::list<Bullet*> * _bulletList;

public:
	
    Level (Player * player);
    
	virtual ~Level ();

    
// Methodes
//
    
    void generate();
    
	/**
	 */
    bool win ();

	/**
	 */
    bool loose ();
    
    
    void collisionManager();
    
    
// ACCESSORS
    
    std::list<Enemy*> * getEnemy() const;
    
    std::list<Bullet*> * getBullet() const;
    
    
    

};

#endif // LEVEL_H
