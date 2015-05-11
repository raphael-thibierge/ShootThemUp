#ifndef BULLET_H
#define BULLET_H
#include "RectanglePosition.h"
#include <iostream>
#include <string>
#include <vector>


class Bullet : virtual public RectanglePosition
{

private :

    unsigned int _type;
    unsigned int _damage;
    std::string _shooter;
    std::string _direction;
    float _speed;

public:

// Constructeurs destructeurs

	Bullet (const unsigned int type , const std::string direction, const float whith, const float height, const std::string shooter);

    
    Bullet(const unsigned int type);
    
	virtual ~Bullet ();


// Methodes
    
    // move the bullet (depend of its direction and speed)
    void move ();

    void initBullet();

    std::string toString();


// ACCESSORS METHODS

    unsigned int getDamage() const;
    
    std::string getShooter() const;
    
    unsigned int getType() const;

};

#endif // BULLET_H
