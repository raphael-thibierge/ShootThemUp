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
    _enemiesCpt = 0;

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

void Level::generateEnemy()
{
    // creation of enemies

    //every 3 level, enemies are stronger
    int level = _level/3 + 1;

    // if we can create one more enemy
    if (_enemiesCpt < NB_ENNEMY_LEVEL){

        // 1/2 chance to create an enemy
        int random = rand()%(-2);
        if(random==1){
            // random choise of an enemy's type
            int randomType = rand()%(-3);
            switch (randomType) {
                case 0:
                    _enemyList.push_back(Enemy::Standard(level));
                    break;

                case 1 :
                    if (_level%3 >= 1)
                        _enemyList.push_back(Enemy::Kamikaze(level));
                    else
                        _enemyList.push_back(Enemy::Standard(level));
                    break;

                case 2 :
                    if (_level%3 == 2)
                        _enemyList.push_back(Enemy::Helicopter(level));
                    else
                        _enemyList.push_back(Enemy::Standard(level));
                    break;

                default:
                    break;
            }
            _enemiesCpt++;
        }
    }
}



bool Level::win ()
{// check if player win
    if (_enemyList.size() == 0 && _enemiesCpt == NB_ENNEMY_LEVEL){
        _player->addMoney();
        return true;
    }


    return false;
}

bool Level::loose ()
{
    if (_player->getLifeLevel()==0 and _player->getNbLife()==0 )
    {
        _player->addMoney();
        return true;
    }
    return false;
}

void Level::collisionManager()
{

    // list to destruct enemies and bullets
    list<Enemy*> enemiesKilled ;
    list<Bullet*> bulletsDestroyed ;


    // collision between player and all bullets
    for (auto bullet : _bulletList)
    {
        if (_player->collision(bullet))
        {
            _player->affectDamage(bullet->getDamage());
            bulletsDestroyed.push_back(bullet);
        }
    }


    // collision between player and all enemies
    for (auto enemy : _enemyList)
    {
        if (_player->collision(enemy))
        {
            enemiesKilled.push_back(enemy);
            _player->looseLife();
        }
    }


    // collision between 2 enemies
    // NOT DONE
    

    // collision between all enemies and all bullets
    for (auto enemy : _enemyList)
    {
        for (auto bullet : _bulletList)
        {
            if (enemy->collision(bullet))
            {
                _player->score(enemy , *_difficulty);
                
                // if player is the shooter
                if (bullet->getShooter() == "player")
                    _player->score(enemy , *_difficulty);
                enemiesKilled.push_back(enemy);
                bulletsDestroyed.push_back(bullet);
            }
        }
    }

    //collision with the border
    // for all enemies
    for (auto enemy : _enemyList)
    {
        if(enemy->getY() > SCREEN_HEIGHT)
        {
            enemiesKilled.push_back(enemy);
        }
    }
    // for all bullets
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
    enemiesKilled.unique();
    bulletsDestroyed.unique();

    // destruction of enemies
    for (auto enemy : enemiesKilled)
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
    
    // clear enemyKilled list
    enemiesKilled.clear();
    
    // clear bulletDestroy list
    bulletsDestroyed.clear();
    
}

void Level::moveAllBullets(){
    for (auto bullet : _bulletList)
        bullet->move();
}

void Level::moveAllEnemies(){
    for (auto enemy : _enemyList)
        enemy->move();
}


void Level::randomEnemiesShoot(){
    
    // for each step, there is 1/2 chance that enemies shoot
    int random= rand()%(-2);
    if(random==1)
    {
        // shuffle shoot for all enemies
        for (auto enemy : _enemyList)
        {
            // each enemy has 1/3 chance to shoot
            random = rand()%(-3);
            if(random==2)
                enemy->shoot(&_bulletList);
        }
    }

}

void Level::runGame(){

    // generate enemies
    generateEnemy();

    // random shoot of enemies
    randomEnemiesShoot();

    // bullet's move
    moveAllBullets();

    // checking for collision
    collisionManager();

    // then enemies'move
    moveAllEnemies();

    // checking a second time for collision
    collisionManager();

}

void Level::playerUseBomb(){
    // this method try to activate the player bomb
    _player->useBomb(_enemyList, *_difficulty);
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



