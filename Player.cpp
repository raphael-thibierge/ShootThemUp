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
    bulletList->push_back(new Bullet(_bulletType, direction, _X, _Y,  "player"));
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
    _money = 0;
    _speed = 10;
    _level = 1;
    _nbLife = 3;
    setPosition(20, 100); // valeur provisoire
}

void Player::score(string typeEnemy, unsigned int levelEnemy, unsigned int difficultyLevel)
{
    if ( typeEnemy == "standart")
            _score+= 5*levelEnemy*difficultyLevel;

    //gestion de la monnaie ici

}


// Accessor methods
//

unsigned int Player::getLevel() const
{
    return _level;
}

void Player::setBulletType(string bulletType)
{
    _bulletType=bulletType;
}

// Other methods
//

