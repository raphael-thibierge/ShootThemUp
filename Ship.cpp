#include "Ship.h"

using namespace std;

// Constructors/Destructors
//



Ship::Ship (string type) :_type(type) {
}



Ship::~Ship () {
}

//
// Methods
//

void Ship::shoot (std::string bullet, std::string direction, std::list<Bullet*> * bulletlist){}

void Ship::move (string direction)
{
    RectanglePosition::move(direction, _speed);
}

string Ship::toString(){
    return " type="+_type+" = "+RectanglePosition::toString() + " speed=" + to_string(_speed) + " life=" + to_string(_lifeLevel);
}


bool Ship::collisionPoint(float x, float y){
    if ( x >= _X && x <= _X+_width && y >= _Y && y <= _Y+_height)
        return true;
    return false;
}


bool Ship::collision(Bullet *bullet){
    if (collisionPoint(bullet->getX(), bullet->getY()) ||
        collisionPoint(bullet->getX(), bullet->getY()+bullet->getHeight()) ||
        collisionPoint(bullet->getX()+bullet->getWidht(), bullet->getY()) ||
        collisionPoint(bullet->getX() + bullet->getWidht(), bullet->getY() + bullet->getHeight()))
        return true;
    return false;
}

bool Ship::collision(Ship *ship){
    if (collisionPoint(ship->getX(), ship->getY())
        || collisionPoint(ship->getX(), ship->getY()+ship->getHeight())
        || collisionPoint(ship->getX()+ship->getWidht(), ship->getY())
        || collisionPoint(ship->getX()+ship->getWidht(), ship->getY()+ship->getHeight()))
        return true;
    return false;
}


// Accessor methods
//


unsigned int Ship::getLifeLevel() const{
    return _lifeLevel;
}

void Ship::setLifeLevel(unsigned int lifeLevel) {
    _lifeLevel = lifeLevel;
}

unsigned int Ship::getNbLife() const{
    return _nbLife;
}

string Ship::getType() const{
    return _type;
}


// Other methods
//
