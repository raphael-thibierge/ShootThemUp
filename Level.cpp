#include "Level.h"

//
// CONSTRUCTOR  AND DESTRUCTOR
//

using namespace std;

Level::Level (Player * player, unsigned int * difficultyPointer) : _player(player), _difficulty(difficultyPointer)
{
    //cout << "\n=====================" << endl;
    //cout << "CONSTRUCTOR LEVEL" << endl;

    _nbEnnemy = 1;
    _level = _player->getLevel();

    generate();

}

Level::~Level ()
{
    //cout << "\n=====================" << endl;
    //cout << "DESTRUCTOR LEVEL" << endl;

    for(auto enemy : _enemyList)
        delete enemy;
    _enemyList.erase(_enemyList.begin(), _enemyList.end());

    for(auto bullet : _bulletList)
        delete bullet;
    _bulletList.erase(_bulletList.begin(), _bulletList.end());

    _player = nullptr;
    _difficulty = nullptr;

}


//
// METHODS
//

void Level::generate()
{
    // creation of enemies
    for (int i=0; i<NB_ENNEMY_LEVEL; i++)
    {
        _enemyList.push_back(Enemy::Standard(1));

    }
}

bool Level::win ()
{
    if (_enemyList.size() == 0){
        float money=_player->getScore()/20;
        _player->setMoney(_player->getMoney()+money);
        _player->nextLevel();
        
        return true;
    }

    return false ;
}

bool Level::loose ()
{
    if (_player->getLifeLevel()==0 and _player->getNbLife()==0 )
    {
        return true;
    }
    return false;
}

void Level::collisionManager()
{
    // list to destruct enemies and bullets
    list<Enemy*> enemiesDestroyed ;
    list<Bullet*> bulletsDestroyed ;


    // collision between player and bullets
    for (auto bullet : _bulletList)
        if (_player->collision(bullet))
        {
            _player->setLifeLevel(_player->getLifeLevel()-bullet->getDamage());
            if(_player->getLifeLevel()==0)
            {
                _player->setNbLife(_player->getNbLife()-1);
            }
            bulletsDestroyed.push_back(bullet);
        }



    // collision between player and enemies
    for (auto enemy : _enemyList)
    {
        if (_player->collision(enemy))
        {
            enemiesDestroyed.push_back(enemy);
            _player->looseLife();
        }
    }


    // collision between 2 enemy
    // NOT DONE

    // collision between enemies and bullets
    for (auto enemy : _enemyList)
    {
        for (auto bullet : _bulletList)
        {
            if (enemy->collision(bullet))
            {
                _player->score(enemy , *_difficulty);
                enemiesDestroyed.push_back(enemy);
                bulletsDestroyed.push_back(bullet);
            }
        }
    }

    //collision with the border
    for (auto enemy : _enemyList)
    {
        if(enemy->getY() > SCREEN_HEIGHT)
        {
            enemiesDestroyed.push_back(enemy);
        }
    }

    for (auto bullet : _bulletList)
    {
        if(bullet->getY() < 0){
            bulletsDestroyed.push_back(bullet);
        }
        if(bullet->getY() > SCREEN_HEIGHT){
            bulletsDestroyed.push_back(bullet);
        }
    }
    
    // remove duplicate enemies and bullets
    enemiesDestroyed.unique();
    bulletsDestroyed.unique();

    // destruction of enemies
    for (auto enemy : enemiesDestroyed)
    {
        _enemyList.remove(enemy);
        delete enemy;
    }

    // destruction of bullets
    for (auto bullet : bulletsDestroyed)
    {
        _bulletList.remove(bullet);
        delete bullet;
    }

}

//
// ACCESSOR METHODS
//

list<Enemy*> * Level::getEnemies()
{
    return &_enemyList;
}

list<Bullet*> * Level::getBullet()
{
    return &_bulletList;
}

Player * Level::getPlayer()const
{
    return _player;
}



