#ifndef BULLET_H
#define BULLET_H
#include "Position.h"
#include <iostream>
#include <string>
#include <vector>


class Bullet : virtual public Position
{

    private :

    std::string _type;
    unsigned int _damage;
    std::string _shooter;
    std::string _direction;
    float _speed;

    public:

// Constructeurs destructeurs

	Bullet (std::string type ,std::string direction,float X, float Y, std::string shooter);

	virtual ~Bullet ();




// Methodes

    void move ();

    std::string toString();


// ACCESSORS METHODS

    float getX() const;

    float getY() const;

    unsigned int getDamage() const;




};

#endif // BULLET_H
