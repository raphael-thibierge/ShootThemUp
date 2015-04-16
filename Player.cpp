#include "Player.h"


using namespace std;

// Constructors/Destructors
//

Player::Player () : Ship::Ship("player")
{
    cout << "\n=====================" << endl;
    cout << "CONSTRUCTOR PLAYER" << endl;
    initPlayer();
}


Player::~Player ()
{
    cout << "\n=====================" << endl;
    cout << "DESTRUCTOR PLAYER" << endl;
}

//
// Methods
//

void Player::shoot (string bulletType, string direction, list<Bullet*> * bulletList)
{
    bulletList->push_back(new Bullet(_bulletType, direction, _X+_height/2, _Y-5,  "player"));
}

void Player::nextLevel()
{
    _level++;
}

string Player::toString()
{
    string text;
    text = "PLAYER : " ;
    text += Ship::toString();
    text += " monney=" + to_string(_money);
    text += " level=" + to_string(_level);
    text+= " score=" + to_string(_score) ;
    return text;
}


void Player::initPlayer()
{
    _bulletType = "standart";
    _lifeLevel = 300;
    _score = 0;
    _money = 110;
    _speed = 10;
    _level = 1;
    _nbLife = 3;
    _width = 10;
    _height = 10;
    setPosition(25, 100); // valeur provisoire
}

void Player::score(Enemy * enemy, unsigned int difficultyLevel)
{
    if ( enemy->getType() == "standart")
    {
        _score+= 5*enemy->getLevel()*difficultyLevel;
    }


    //gestion de la monnaie ici

}


void Player::activatedShild()
{
    _lifeLevel+=_shild;
    _shild=0;
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



