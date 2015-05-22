#include "Ship.h"

using namespace std;

// Constructors/Destructors
//

Ship::Ship (const unsigned int type) :_type(type) {
    _time.Reset();
}

Ship::~Ship () {
}

//
// Methods
//

void Ship::shoot (list<Bullet*> * bulletlist){}

void Ship::move (const string direction)
{
    RectanglePosition::move(direction, _speed);
}

string Ship::toString(){
    return " type="+to_string(_type)+" = "+RectanglePosition::toString() + " speed=" + to_string(_speed) + " life=" + to_string(_lifeLevel);
}


bool Ship::collisionPoint(const float x, const float y)
{// return true if the point is in the ship

    if ( x >= _X && x <= _X+_width && y >= _Y && y <= _Y+_height)
        return true;
    return false;
}


bool Ship::collision(Bullet *bullet)
{// return true if there is a collision

    // test collisision with every bullet'corners
    if (collisionPoint(bullet->getX(), bullet->getY()) // up left
        || collisionPoint(bullet->getX(), bullet->getY()+bullet->getHeight()) // down left
        || collisionPoint(bullet->getX()+bullet->getWidht(), bullet->getY()) // up right
        || collisionPoint(bullet->getX() + bullet->getWidht(), bullet->getY() + bullet->getHeight())) // down left
        return true;
    return false;
}


bool Ship::collision(Ship *ship)
{// return true if there is a collision

    // test collisision with every ship'corners
    if (collisionPoint(ship->getX(), ship->getY()) // up left
        || collisionPoint(ship->getX(), ship->getY()+ship->getHeight()) // down left
        || collisionPoint(ship->getX()+ship->getWidht(), ship->getY()) // up right
        || collisionPoint(ship->getX()+ship->getWidht(), ship->getY()+ship->getHeight())) // down right
        return true;
    return false;
}

void Ship::affectDamage(const unsigned int damage){
    if (damage < _lifeLevel)
        _lifeLevel -= damage;
    else {
        looseLife();
    }
}

void Ship::looseLife(){
    _lifeLevel = 0;
    if (_nbLife > 0) {
        _nbLife--;
        resetLifeLevel();

    }
    else
        _nbLife = 0;
}

void Ship::resetLifeLevel(){
    // if this is the player's ship
    if (_type <= 3 )
        _lifeLevel = PLAYER_LIFE_LEVEL;
}
// Accessor methods
//


unsigned int Ship::getLifeLevel() const{
    return _lifeLevel;
}

unsigned int Ship::getNbLife() const{
    return _nbLife;
}

unsigned int Ship::getType() const{
    return _type;
}

float Ship::getSpeed() const{
    return _speed;
}

void Ship::setLifeLevel(unsigned int lifeLevel) {
    _lifeLevel = lifeLevel;
}

void Ship::setType(const unsigned int value){
    _type = value;
}

Blast * Ship::getBlast(){
    return new Blast(_type, _direction, _speed, _X, _Y);
}



// Other methods
//
