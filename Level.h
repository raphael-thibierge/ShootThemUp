#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include "Boss.h"
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
    std::list<Blast*> _blastList;
    int _enemiesCpt;

    Boss * _boss;

    sf::Clock _time;
    sf::Clock _lifeTransition;

public:

    Level (unsigned int level, Player * player, unsigned int * difficultyPointer);

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

    void moveAllBlast();

    void randomEnemiesShoot();

    void runGame();

    // activate player's bomb
    void playerUseBomb();

    // player shoot a bullet
    void playerShoot();

// ACCESSOR METHODS
//

    std::list<Enemy*> * getEnemies();

    std::list<Bullet*> * getBullet();

    std::list<Blast*> * getBlast();

    Player * getPlayer()const;

    Boss * getBoss();


};

#endif // LEVEL_H
