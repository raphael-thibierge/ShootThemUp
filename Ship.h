
#ifndef SHIP_H
#define SHIP_H
#include "Bullet.h"

#include <list>

// provisoire
class Shiel;



class Ship : virtual public RectanglePosition
{

protected:

    unsigned int _lifeLevel;
    unsigned int _nbLife;
    std::string _type;
    float _speed;
    std::string _direction;



public:

//
// Constructors/Destructors
//

    Ship (std::string type);

	virtual ~Ship ();
//
// Methods
//

    virtual void shoot (std::list<Bullet*> * bulletlist);
    
    // move the ship in a direction (move depend of the speed)
    void move (std::string direction);

    virtual std::string toString();
    
    // test collision whith a point
    bool collisionPoint(float x, float y);
    
    // test collision with a bullet
    bool collision(Bullet *bullet);
    
    // test collision with a ship
    bool collision (Ship *ship);
    

    

//  ACCESSOR METHODS
//

    unsigned  int getLifeLevel() const;

    void setLifeLevel(unsigned int lifeLevel);

    unsigned int getNbLife() const;

    std::string getType() const;


};

#endif // SHIP_H
