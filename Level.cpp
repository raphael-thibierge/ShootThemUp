#include "Level.h"

//
// CONSTRUCTOR  AND DESTRUCTOR
//

using namespace std;

Level::Level (Player * player, unsigned int * difficultyPointer) : _player(player), _difficulty(difficultyPointer)
{
    //cout << "\n=====================" << endl;
    //cout << "CONSTRUCTOR LEVEL" << endl;

    _nbEnnemies = LEVEL_NB_ENEMIES;
    _level = _player->getLevel();
    _enemiesCpt = 0;

}

Level::~Level ()
{
    //cout << "\n=====================" << endl;
    //cout << "DESTRUCTOR LEVEL" << endl;

    for(auto enemy : _enemiesList)
        delete enemy;
    _enemiesList.clear();

    for(auto bullet : _bulletsList)
        delete bullet;
    _bulletsList.clear();

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
    if (_enemiesCpt < _nbEnnemies){

        // 1/2 chance to create an enemy
        int random = rand()%(4);
        if(random == 1){
            // random choise of an enemy's type
            int randomType = rand()%(-3);
            switch (randomType) {
                case 0:
                    _enemiesList.push_back(Enemy::Standard(level));
                    break;

                case 1 :
                    if (_level%3 >= 1)
                   _enemiesList.push_back(Enemy::Kamikaze(level));
                    else
                        _enemiesList.push_back(Enemy::Standard(level));
                    break;

                case 2 :
                    if (_level%3 == 2)
                        _enemiesList.push_back(Enemy::Helicopter(level));
                    else
                        _enemiesList.push_back(Enemy::Standard(level));
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
    if (_enemiesList.size() == 0 && _enemiesCpt == _nbEnnemies){
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
    for (auto bullet : _bulletsList)
    {
        if (_player->collision(bullet))
        {
            _player->affectDamage(bullet->getDamage());
            bulletsDestroyed.push_back(bullet);
            cout << "player loose life" << _player->getLifeLevel() << endl;
        }
    }


    // collision between player and all enemies
    for (auto enemy : _enemiesList)
    {
        if (_player->collision(enemy))
        {
            enemiesKilled.push_back(enemy);
            cout << "player loose a life" << _player->getNbLife()  << endl;
            _player->looseLife();
        }
    }


    // collision between 2 enemies
    // NOT DONE


    // collision between all enemies and all bullets
    for (auto enemy : _enemiesList)
    {
        for (auto bullet : _bulletsList)
        {
            if (enemy->collision(bullet))
            {
                // if player is the shooter
                if (bullet->getShooter() == "player")
                {
                    _player->score(enemy , *_difficulty);
                }

                cout << "Enemy and bullet destroyed" << endl;

                enemiesKilled.push_back(enemy);
                bulletsDestroyed.push_back(bullet);
                cout << enemiesKilled.size() << " " << bulletsDestroyed.size() << endl ;
            }
        }
    }

    //collision with the border
    // for all enemies
    for (auto enemy : _enemiesList)
    {
        if(enemy->getY() >= SCREEN_HEIGHT)
        {
            enemiesKilled.push_back(enemy);
            cout << "enemy out of screen" << endl;
        }
    }

    // for all bullets
    for (auto bullet : _bulletsList)
    {
        if(bullet->getY() < 0){
            bulletsDestroyed.push_back(bullet);
        }
        if(bullet->getY() > SCREEN_HEIGHT){
            bulletsDestroyed.push_back(bullet);
            cout << "bullet out of screen" << endl;
        }
    }

    // remove duplicate enemies and bullets
    //enemiesKilled.unique();
    //bulletsDestroyed.unique();

    // destruction of enemies
    cout << "a " << endl ;
    int cpt = 0;

    for (auto enemy : enemiesKilled)
    {
        _enemiesList.remove(enemy);
        cpt++;
        cout << cpt << endl;
        //delete enemy;
    }
    cout << "b" << endl << endl;

    cout << "c " << endl;
    cpt = 0;
    // destruction of bullets

    for (auto bullet : bulletsDestroyed)
    {
        cpt++;
        cout << cpt << endl;
        _bulletsList.remove(bullet);
        //delete bullet;
    }

    cout << "d" << endl << endl;

    // clear enemyKilled list
    enemiesKilled.clear();

    // clear bulletDestroy list
    bulletsDestroyed.clear();

}

void Level::moveAllBullets(){
    for (auto bullet : _bulletsList)
        bullet->move();
}

void Level::moveAllEnemies(){
    for (auto enemy : _enemiesList)
        enemy->move();
}


void Level::randomEnemiesShoot(){

    // for each step, there is 1/2 chance that enemies shoot
    int random= rand()%(10);
    if (random==1)
    {
        // shuffle shoot for all enemies
        for (auto enemy : _enemiesList)
        {
            // each enemy has 1/3 chance to shoot
            random = rand()%(10);
            if (random == 1)
                enemy->shoot(&_bulletsList);
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
    _player->useBomb(_enemiesList, *_difficulty);
}

void Level::playerShoot(){
    //this method make the player shoot
    _player->shoot(&_bulletsList);
}





//
// ACCESSOR METHODS
//

list<Enemy*> * Level::getEnemies()
{
    return &_enemiesList;
}

list<Bullet*> * Level::getBullet()
{
    return &_bulletsList;
}

Player * Level::getPlayer()const
{
    return _player;
}
