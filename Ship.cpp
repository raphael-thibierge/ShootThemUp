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

void Ship::setLifeLevel(unsigned int lifeLevel) {
    _lifeLevel = lifeLevel;
}

void Ship::setType(const unsigned int value){
    _type = value;
}


// Other methods
//
