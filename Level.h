
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
	unsigned int _nbEnnemies;
    Player * _player;
    std::list<Enemy*> _enemiesList ;
    std::list<Bullet*> _bulletsList;
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
    
    // methods with explicit names
    void moveAllBullets();
    
    void moveAllEnemies();
    
    void randomEnemiesShoot();
    
    void runGame();
    
    // activate player's bomb
    void playerUseBomb();
    

// ACCESSOR METHODS
//
    
    std::list<Enemy*> * getEnemies();

    std::list<Bullet*> * getBullet();

    Player * getPlayer()const;


};

#endif // LEVEL_H
