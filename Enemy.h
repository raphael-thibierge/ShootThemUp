
#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include <vector>

#include "Ship.h"


class Enemy : virtual public Ship
{

private :

    unsigned int _level;


// CONSTRUCTORS/DESTRUCTORS
//
public:
    
   // Enemy (std::string type, float x, float y, unsigned int lifeLevel);

    Enemy (std::string type, unsigned int level, float x, float y, float width, float height, unsigned int lifeLevel, float speed, unsigned int nbLife);
    
	virtual ~Enemy ();

// METHODS

    void move ();

    void shoot (std::list<Bullet*> * bulletList) override;

    unsigned int getLevel() const;

    std::string toString();


// STATIC METHODS

public:
    
    static Enemy* Standard(unsigned int level);
    
    static Enemy* Kamikaze(unsigned int level);
    
    static Enemy* Helicopter(unsigned int level);
    
private:

        static int randomPositionX();

};
#endif // ENEMY_H
