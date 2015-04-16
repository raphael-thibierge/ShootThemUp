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
    Position::move(direction, _speed);
}

string Ship::toString(){
    return " type="+_type+" = "+Position::toString() + " speed=" + to_string(_speed) + " life=" + to_string(_lifeLevel);
}

bool Ship::collision(Bullet *bullet){
    // A REFAIRE JE M'EN OCCUPE
    bool returnValue = false;
    
    return returnValue;
}

bool Ship::collision(Ship *ship){
    // PAREIL
    bool returnValue = false;
    
    return returnValue;
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
