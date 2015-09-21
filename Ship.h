#ifndef SHIP_H
#define SHIP_H
#include "Bullet.h"
#include "Blast.h"

#include <list>

// provisoire
class Shiel;



class Ship : virtual public RectanglePosition
{

protected:

    unsigned int _lifeLevel;
    unsigned int _nbLife;
    unsigned int _type;
    float _speed;
    std::string _direction;
    sf::Clock _time;
    bool _loosingLife;

    // shoot sound
    sf::SoundBuffer _soundBuffer;
    sf::Sound _sound;

public:

//
// Constructors/Destructors
//

    Ship (const unsigned int type);

	virtual ~Ship ();
//
// Methods
//

    virtual void shoot (std::list<Bullet*> * bulletlist);

    // move the ship in a direction (move depend of the speed)
    void move (const std::string direction);

    virtual std::string toString();

    // test collision whith a point
    bool collisionPoint(const float x,const  float y);

    // test collision with a bullet
    bool collision(Bullet *bullet);

    // test collision with a ship
    bool collision (Ship *ship);

    void affectDamage(const unsigned int damage);

    void looseLife();

    void resetLifeLevel();

    // to know if we are in the transition
    bool isLosingLife();

    void playSound();


//  ACCESSOR METHODS
//

    unsigned  int getLifeLevel() const;

    unsigned int getNbLife() const;

    unsigned int getType() const;

    void setLifeLevel(const unsigned int lifeLevel);

    void setType(const unsigned int value);

    float getSpeed() const;

    float getTime() const;

    Blast * getBlast();

};

#endif // SHIP_H
