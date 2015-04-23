
#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include "Enemy.h"
#include "Player.h"

class Level
{

private:

    unsigned int _level;
	unsigned int * _difficulty;
	unsigned int _nbEnnemy;
    Player * _player;
    std::list<Enemy*> _enemyList ;
    std::list<Bullet*> _bulletList;
    int _enemiesCpt;

public:

    Level (Player * player, unsigned int * difficultyPointer);

	virtual ~Level ();


// METHODS
//
    // generation of enemies
    void generateEnemy();

    // if player win
    bool win ();
    
    // if player loose
    bool loose ();
    
    // verify collision between all level's objects
    void collisionManager();
    
    void moveAllBullets();
    
    void moveAllEnemies();
    
    void randomEnemiesShoot();
    
    void runGame();


// ACCESSOR METHODS
//
    
    std::list<Enemy*> * getEnemies();

    std::list<Bullet*> * getBullet();

    Player * getPlayer()const;


};

#endif // LEVEL_H
