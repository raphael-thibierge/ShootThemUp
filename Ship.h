
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



public:

//
// Constructors/Destructors
//

    Ship (std::string type);

	virtual ~Ship ();
//
// Methods
//

    virtual void shoot (std::string bullet, std::string direction, std::list<Bullet*> * bulletlist);

    void move (std::string direction);

    virtual std::string toString();

    bool collision(Bullet *bullet);

    bool collision (Ship *ship);
    
    bool collisionPoint(float x, float y);
    

//  ACCESSOR METHODS
//

    unsigned  int getLifeLevel() const;

    void setLifeLevel(unsigned int lifeLevel);

    unsigned int getNbLife() const;

    std::string getType() const;


};

#endif // SHIP_H
