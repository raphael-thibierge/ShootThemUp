#include "Player.h"


using namespace std;

// Constructors/Destructors
//

Player::Player () : Ship::Ship("player")
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

void Player::shoot (string bulletType, string direction, list<Bullet*> * bulletList)
{
    bulletList->push_back(new Bullet(_bulletType, direction, _X+_height/2, _Y-5,  "player"));
}


void Player::initPlayer()
{
    _bulletType = "standart";
    _lifeLevel = LIFE_LEVEL_INITIAL;
    _score = 0;
    _money = 10000;
    _speed = 0;
    _level = 1;
    _shild = 0;
    _nbLife = NB_LIFE_INITIAL;
    _width = WIDTH_PLAYER_DEFAULT;
    _height = HEIGHT_PLAYER_DEFAULT;
    resetPosition();
}

void Player::score(Enemy * enemy, unsigned int difficultyLevel)
{
    if ( enemy->getType() == "standard"){
        _score+= 5*enemy->getLevel()*difficultyLevel;
    }
    else if (enemy->getType() == "kamikaze"){
        _score+= 10*enemy->getLevel()*difficultyLevel;
    }
    else if (enemy->getType() == "helicoptere"){
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


void Player::affectDamage(unsigned int damage){
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
    _lifeLevel = LIFE_LEVEL_INITIAL;
}

void Player::addMoney(){
    _money += float(_score)/10;
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

unsigned int Player::getShild() const
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

string Player::getBulletType() const
{
    return _bulletType;
}



void Player::setNbLife(unsigned int nbLife)
{
    _nbLife=nbLife;
}

void Player::setLevel( unsigned int level)
{
    _level=level;
}

void Player::setShild( unsigned int shild)
{
    _shild=shild;
}

void Player::setBulletType(string bulletType)
{
    _bulletType=bulletType;
}

void Player::setMoney( float money)
{
    _money=money;
}

void Player::setScore(unsigned int score){
    _score=score;
}

// Other methods
//



