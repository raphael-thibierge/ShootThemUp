#include "Level.h"

// Constructors/Destructors
//

using namespace std;

Level::Level (Player * player, unsigned int * difficultyPointer) : _player(player), _difficulty(difficultyPointer)
{
    cout << "\n=====================" << endl;
    cout << "CONSTRUCTOR LEVEL" << endl;

    _nbEnnemy = 1;
    _level = _player->getLevel();

    generate();

}

Level::~Level ()
{
    cout << "\n=====================" << endl;
    cout << "DESTRUCTOR LEVEL" << endl;

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
// Methods
//

void Level::generate()
{
    // creation of a enemy
    for (int i=0; i<NB_ENNEMY_LEVEL; i++)
    {
        unsigned int lifeLevel = 25*DIFFICULTY;
        float x = (i%5)*10;
        float y = -i*10;
        _enemyList.push_back(new Enemy("standart", x, y, lifeLevel));

    }
    // need to generate shuffle initial position for ennemy

}

bool Level::win ()
{

    if (_enemyList.begin() == _enemyList.end())
    {
        cout << "\nVICTOIRE DE LA MANCHE" << endl;
        float money=_player->getScore()/20;
        _player->setMoney(_player->getMoney()+money);
        return true;
    }

    return false ;
}

bool Level::loose ()
{
    if (_player->getLifeLevel()<=0 and _player->getNbLife()==0 )
    {
        cout << "\nDEFAITE" << endl;
        return true;
    }
    return false;
}

void Level::collisionManager()
{

    list<Enemy*> enemiesDestroyed ;
    list<Bullet*> bulletsDestroyed ;


    // collision between the player and the bullets
    for (auto bullet : _bulletList)
        if (_player->collision(bullet))
            bulletsDestroyed.push_back(bullet);


    // collision between the player and the enemies
    for (auto enemy : _enemyList)
    {
        if (_player->collision(enemy))
        {
            //score et vie à gérer
            enemiesDestroyed.push_back(enemy);
            cout << "Joueur touché -par un enemi -> doit mourir" << endl;
        }
    }


    // collision between 2 enemy


    // collision between an enemy and a bullet

    for (auto enemy : _enemyList){
        for (auto bullet : _bulletList){
            if (enemy->collision(bullet)){
                _player->score(enemy , *_difficulty);
                enemiesDestroyed.push_back(enemy);
                bulletsDestroyed.push_back(bullet);
            }
        }
    }

    //collision with the border
    for (auto enemy : _enemyList){
        if(enemy->getY() > SCREEN_HEIGHT){
            enemiesDestroyed.push_back(enemy);
        }
    }

    for (auto bullet : _bulletList){
        if(bullet->getY() < 0){
            bulletsDestroyed.push_back(bullet);
        }
        if(bullet->getY() > SCREEN_HEIGHT){
            bulletsDestroyed.push_back(bullet);
        }
    }


    for (auto enemy : enemiesDestroyed){
        cout << enemy->toString() << endl;
        _enemyList.remove(enemy);
        delete enemy;
    }

    for (auto bullet : bulletsDestroyed){
        _bulletList.remove(bullet);
        delete bullet;
    }


}

// Accessor methods
//
list<Enemy*> * Level::getEnemy()
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


// ne vas surement pas servir
void Level::setDifficulty(unsigned int difficulty)
{
     *_difficulty=difficulty;
}


// Other methods
//

