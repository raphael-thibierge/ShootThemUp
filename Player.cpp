#include "Player.h"


using namespace std;

// Constructors/Destructors
//

Player::Player () : Ship::Ship(0)
{
    //cout << "\n=====================" << endl;
    //cout << "CONSTRUCTOR PLAYER" << endl;
    initPlayer();
}


Player::~Player ()
{
    //cout << "\n=====================" << endl;
    //cout << "DESTRUCTOR PLAYER" << endl;
}

//
// Methods
//


void Player::shoot (list<Bullet*> * bulletList)
{
    if (_time.GetElapsedTime() >= TIME_PLAYER_FIRE_RATE )
    {
        bulletList->push_back(new Bullet(_bulletType, _direction, _X+_width/2, _Y,  "player"));
        _time.Reset();
    }
}


void Player::initPlayer()
{
    _bulletType = 0;
    _lifeLevel = PLAYER_LIFE_LEVEL;
    _nbLife = 0;
    _width = PLAYER_WIDTH;
    _height = PLAYER_HEIGHT;
    _bombNumber = 10 ; // provisoire, sinon 0
    _direction = PLAYER_DIRECTION;
    _score = 0;
    _money = 0;
    _speed = PLAYER_SPEED;
    _shild = SHIELD_LIFE[0];
    _level = 0;

    // standart position of player
    resetPosition();
}


void Player::useBomb(list<Enemy*> & enemyList, const int difficulty)
{ // destruct all enemies on the screen


    if (_bombNumber > 0){
        _bombNumber-- ;
        // list of enemies wich are destroyed by the bomb
        list<Enemy*> enemiesKilled;

        // founding enemies
        cout << "====================================" << endl;
        for (auto enemy : enemyList){
            // if he is on screen
            if (enemy->getX() >= 0 && enemy->getX() <= SCREEN_WIDTH &&
                enemy->getY() >= 0 && enemy->getY() <= SCREEN_HEIGHT){

                //the enemy is put on the enemiesKilled list
                enemiesKilled.push_back(enemy);

                // update score
                score(enemy, difficulty);
            }
        }

        // destruction of killed enemies
        for (auto enemy : enemiesKilled){
            // delete enemy from enemyList
            enemyList.remove(enemy);
            // destruct enemy
            delete enemy;
        }

        // clear
        enemiesKilled.clear();
    }
}


void Player::nextLevel()
{
    _level++;
}

void Player::score(Enemy * enemy, const unsigned int difficultyLevel)
{ // return player's score updated
    // score for standart enemies
    if ( enemy->getType() == 0){
        _score+= 5*enemy->getLevel()*difficultyLevel;
    }

    //Score for kamikaze enemies
    else if (enemy->getType() == 10){
        _score+= 10*enemy->getLevel()*difficultyLevel;
    }

    //Score for helicoptere enemies
    else if (enemy->getType() == 11){
        _score+= 15*enemy->getLevel()*difficultyLevel;
    }
}


void Player::activateShild()
{
    _lifeLevel+=_shild;
    _shild=0;
}

void Player::looseLife(){
    _lifeLevel = 0;
    if (_nbLife > 0) {
        _nbLife--;
        resetLifeLevel();
    }
}


void Player::affectDamage(const unsigned int damage){
    if (damage < _lifeLevel)
        _lifeLevel -= damage;
    else {
        looseLife();
    }
}


void Player::resetPosition(){
    setPosition((SCREEN_WIDTH-_width)/2, SCREEN_HEIGHT-_height);
}

void Player::resetLifeLevel(){
    _lifeLevel = PLAYER_LIFE_LEVEL;
}

void Player::addMoney(){
    _money += float(_score)/10;
}

void Player::addBomb(){
    _bombNumber++;
}

void Player::addLife(const unsigned int number){
    _nbLife += number;
}

void Player::pay(float value){
    _money -= value;
}


string Player::toString()
{
    string text;
    text = "PLAYER : " ;
    text += Ship::toString();
    text += " monney=" + to_string(_money);
    text += " level=" + to_string(_level);
    text+= " score=" + to_string(_score) ;
    text+= " Nb life= " + to_string(_nbLife);
    return text;
}



// Accessor methods
//

unsigned int Player::getLevel() const
{
    return _level;
}

unsigned int Player::getShield() const
{
    return _shild;
}

float Player::getMoney() const
{
    return _money;
}

unsigned int Player::getScore() const
{
    return _score;
}

unsigned int Player::getBulletType() const
{
    return _bulletType;
}

unsigned int Player::getBombNumber() const
{
    return _bombNumber;
}



void Player::setNbLife( const unsigned int nbLife)
{
    _nbLife=nbLife;
}

void Player::setLevel( const unsigned int level)
{
    _level=level;
}

void Player::setShield( const unsigned int shild)
{
    _shild=shild;
}

void Player::setBulletType(const unsigned int bulletType)
{
    _bulletType=bulletType;
}

void Player::setMoney( const float money)
{
    _money=money;
}

void Player::setScore( const unsigned int score){
    _score=score;
}

void Player::setBombNumber( const unsigned int value)
{
    _bombNumber = value;
}

// Other methods
//



