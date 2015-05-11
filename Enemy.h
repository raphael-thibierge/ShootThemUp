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
    Enemy (const unsigned int type, const unsigned int level, const float x, const float y, const float width, const float height, const unsigned int lifeLevel, const float speed, const unsigned int nbLife);
    
	virtual ~Enemy ();

// METHODS

    void move ();

    void shoot (std::list<Bullet*> * bulletList) override;

    unsigned int getLevel() const;

    std::string toString();


// STATIC METHODS

public:
    
    static Enemy* Standard(const unsigned int level);
    
    static Enemy* Kamikaze(const unsigned int level);
    
    static Enemy* Helicopter(const unsigned int level);
    
private:

        static int randomPositionX();

};
#endif // ENEMY_H
