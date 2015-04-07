#include "Enemy.h"

using namespace std;

// Constructors/Destructors
//

Enemy::Enemy (string type, float x, float y, unsigned int lifeLevel) : Ship::Ship(type) {
    cout << "\n=====================" << endl;
    cout << "CONSTRUCTOR ENEMY" << endl;

    setPosition(x, y);
    initEnemy();

    _lifeLevel = lifeLevel;
    cout << toString() << endl ;

}

Enemy::~Enemy () {
    cout << "\n=====================" << endl;
    cout << "DESTRUCTOR ENEMY" << endl;}

//
// Methods
//
void Enemy::move()
{
    Position::move(_direction, _speed);
}

void Enemy::shoot (string bulletType, string direction, list<Bullet*> * bulletList)
{
    bulletList->push_back(new Bullet("standart", direction, _X, _Y, "enemy"));
}

string Enemy::toString(){
    return "ENEMY : " + Ship::toString();
}

void Enemy::initEnemy(){
    if (_type == "standart")
    {
        _level = 1;
        _lifeLevel = 50;
        _speed = 5;
        _direction = "SOUTH";
        _nbLife = 1;
    }
    _nbLife = 1 ;
}

// Accessor methods
//


unsigned int Enemy::getLevel() const{
    return _level;
}

// Other methods
//

