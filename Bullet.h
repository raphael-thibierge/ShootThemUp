#ifndef BULLET_H
#define BULLET_H
#include "RectanglePosition.h"
#include <iostream>
#include <string>
#include <vector>


class Bullet : virtual public RectanglePosition
{


private :

    std::string _type;
    unsigned int _damage;
    std::string _shooter;
    std::string _direction;
    float _speed;

public:

// Constructeurs destructeurs

	Bullet (std::string type ,std::string direction, float whith, float height, std::string shooter);

	virtual ~Bullet ();


// Methodes
    
    // move the bullet (depend of its direction and speed)
    void move ();

    void initBullet();

    std::string toString();


// ACCESSORS METHODS

    unsigned int getDamage() const;
    
    std::string getShooter() const;

};

#endif // BULLET_H
