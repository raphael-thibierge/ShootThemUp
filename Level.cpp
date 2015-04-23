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
            _player->affectDamage(bullet->getDamage());
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

void Level::moveAllBullets(){
    for (auto bullet : _bulletList)
        bullet->move();
}

void Level::moveAllEnemies(){
    for (auto enemy : _enemyList)
        enemy->move();
}


void Level::randomEnemiesShoot(){
    int random= rand()%(-2);
    if(random==1)
    {
        // shuffle shoot for all enemies
        for (auto enemy : _enemyList)
        {
            random = rand()%(-3);
            if(random==2)
                enemy->shoot("standart", "SOUTH", &_bulletList);
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



