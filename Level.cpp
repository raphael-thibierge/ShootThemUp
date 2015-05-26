#include "Level.h"

//
// CONSTRUCTOR  AND DESTRUCTOR
//

using namespace std;

Level::Level (unsigned int level, Player * player, unsigned int * difficultyPointer) : _player(player), _difficulty(difficultyPointer)
{
    _nbEnnemies = LEVEL_NB_ENEMIES;
    _level = level;
    _time.Reset();
    _lifeTransition.Reset();
    _enemiesCpt = 0;
    _player->resetLifeLevel();
    _boss = nullptr;
}

Level::~Level ()
{
    for(auto enemy : _enemiesList)
    {
        if (enemy != nullptr)
            delete enemy;
        enemy = nullptr;
    }
    _enemiesList.clear();

    for(auto bullet : _bulletsList)
    {
        if (bullet != nullptr)
            delete bullet;
        bullet = nullptr;
    }
    _bulletsList.clear();

    for (auto blast : _blastList)
    {
        if (blast != nullptr)
            delete blast;
        blast = nullptr;
    }

    if (_boss != nullptr)
        delete _boss;
    _boss = nullptr;

    _player = nullptr;
    _difficulty = nullptr;
}


//
// METHODS
//
void Level::generateEnemy()
{// creation of enemies
    //every 3 level, enemies are stronger
    int level = _level/3 + 1;

    // if we can create one more enemy
    if (_enemiesCpt < _nbEnnemies && _time.GetElapsedTime() > TIME_SPAWN_RATE )
    {
        _time.Reset();
        // 1/2 chance to create an enemy
        int random = rand()%(2);
        if(random == 1){
            // random choise of an enemy's type
            int randomType = rand()%((_level%3)+1);
            Enemy * enemy = nullptr;
            switch (randomType) {
                case 0:
                    enemy = Enemy::Standard(level);
                    break;

                case 1 :
                    enemy = Enemy::Kamikaze(level);
                    break;

                case 2 :
                    enemy = Enemy::Helicopter(level);
                    break;

                default:
                    break;
            }
            // place the enemy on the screen
            int enemyWidth = enemy->getWidht();

            // difficulty impact on enemy
            enemy->difficultyImpact(*_difficulty);


            enemy->setPosition(rand()%(SCREEN_WIDTH-enemyWidth), 0);
            _enemiesList.push_back(enemy);
            enemy = nullptr;

            _enemiesCpt++;
        }
    }
    if (_enemiesCpt == _nbEnnemies && _level % 3 == 2){
        _boss = new Boss();
        _enemiesCpt++;

    }
}

bool Level::win ()
{// check if player win
    if (_enemiesList.size() == 0 && _enemiesCpt >= _nbEnnemies && _boss == nullptr){
        _player->addMoney();
        return true;
    }
    return false;
}

bool Level::loose ()
{
    if (_player->getNbLife()==0 )
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
    list<Blast*> blastDestroyed;

    // collision between player and all bullets
    for (auto bullet : _bulletsList)
    {
        if (_player->collision(bullet))
        {
            _player->affectDamage(bullet->getDamage());
            bulletsDestroyed.push_back(bullet);
        }
    }

    // collision between player and all enemies
    for (auto enemy : _enemiesList)
    {
        if (_player->collision(enemy))
        {
            enemiesKilled.push_back(enemy);
            _blastList.push_back(enemy->getBlast());
            _player->affectDamage(enemy->getLifeLevel());
        }
    }


    // collision between 2 enemies
    // NOT DONE


    // collision between all enemies and all bullets
    for (auto enemy : _enemiesList)
    {
        for (auto bullet : _bulletsList)
        {
            if (enemy->collision(bullet)){
                _player->score(enemy , *_difficulty);

                // if player is the shooter
                if (bullet->getShooter() == "player"){
                    _player->score(enemy , *_difficulty);
                }

                enemy->affectDamage(bullet->getDamage());
                if (enemy->getNbLife() == 0 )
                {
                    enemiesKilled.push_back(enemy);
                    _blastList.push_back(enemy->getBlast());
                }
                bulletsDestroyed.push_back(bullet);
            }
        }
    }

    // collision between boss and bullets
    if (_boss != nullptr)
    {
        for (auto bullet : _bulletsList)
        {
            if (_boss->collision(bullet))
            {
                _boss->affectDamage(bullet->getDamage());
                if (_boss->getLifeLevel() == 0){
                    enemiesKilled.push_back(_boss);
                    _player->score(_boss , *_difficulty);
                }
                bulletsDestroyed.push_back(bullet);
            }
            if (_player->collision(_boss))
            {
                _player->affectDamage(_boss->getLifeLevel());
            }
        }
    }


    //destroy ended blast
    for (auto blast : _blastList)
    {
        if (blast->getTime() >= BLAST_DURATION)
        {
            blastDestroyed.push_back(blast);
        }
    }


    //collision with the border
    // for all enemies
    for (auto enemy : _enemiesList)
    {
        if(enemy->getY() >= SCREEN_HEIGHT){
            enemiesKilled.push_back(enemy);
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
        }
    }



    // remove duplicate enemies and bullets
    enemiesKilled.unique();
    bulletsDestroyed.unique();
    blastDestroyed.unique();

    // destruction of enemies
    for (auto enemy : enemiesKilled){
        _enemiesList.remove(enemy);
        if (enemy->getType() == BOSS_TYPE)
        {
            enemy = nullptr;
            delete _boss;
            _boss = nullptr;
        }
        if (enemy != nullptr)
            delete enemy;
        enemy = nullptr;
    }

    // destruction of bullets
    for (auto bullet : bulletsDestroyed){
        _bulletsList.remove(bullet);
       // if (bullet != nullptr)
         //   delete bullet;
        bullet = nullptr;
    }

    for (auto blast : blastDestroyed){
        _blastList.remove(blast);
        if (blast != nullptr)
            delete blast;
        blast = nullptr;
    }
    // clear enemyKilled and bulletDestroy lists
    enemiesKilled.clear();
    bulletsDestroyed.clear();
    blastDestroyed.clear();

}

void Level::moveAllBullets(){
    for (auto bullet : _bulletsList)
        bullet->move();
}

void Level::moveAllEnemies(){
    for (auto enemy : _enemiesList)
        enemy->move();

    if (_boss != nullptr)
        _boss->move();
}

void Level::moveAllBlast(){
    for (auto blast : _blastList)
        blast->move();
}

void Level::randomEnemiesShoot()
{// for each step, there is 1/2 chance that enemies shoot

        // shuffle shoot for all enemies
        for (auto enemy : _enemiesList)
        {
            // each enemy has 1/3 chance to shoot
            int random = rand()%(10);
            if (random == 1)
                enemy->shoot(&_bulletsList);
        }

        if (_boss != nullptr)
        {
            _boss->shoot(_bulletsList);
        }
}

void Level::runGame(){

    if (!_player->isLosingLife())
    {
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

        // blasts'move
        moveAllBlast();

        // checking a second time for collision
        collisionManager();
    }
}

void Level::playerUseBomb(){
    // this method try to activate the player bomb
        _player->useBomb(_enemiesList, _blastList, *_difficulty);
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

list<Blast*> * Level::getBlast()
{
    return &_blastList;
}

Player * Level::getPlayer()const
{
    return _player;
}

Boss * Level::getBoss()
{
    return _boss;
}
