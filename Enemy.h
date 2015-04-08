
#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include <vector>

#include "Ship.h"


class Enemy : virtual public Ship
{

    private :
    unsigned int _level;
    std::string _direction;

public:

	// Constructors/Destructors
	//

    Enemy (std::string type, float x, float y, unsigned int lifeLevel);

	virtual ~Enemy ();

    void move ();

    void shoot (std::string bulletType, std::string direction, std::list<Bullet*> * bulletList) override;

    unsigned int getLevel() const;


    std::string toString();

    private :

    void initEnemy();



};

#endif // ENEMY_H
