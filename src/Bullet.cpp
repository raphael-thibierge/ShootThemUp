#include "Bullet.h"

using namespace std ;

// Constructors/Destructors
//

Bullet::Bullet (string type , string direction, float X, float Y,string shooter ) : Position::Position(X,Y), _type(type) ,_direction(direction), _shooter(shooter)
{
    cout << "\n=====================" << endl;
    cout << "CONSTRUCTOR BULLET" << endl;

    if(_shooter=="player")
    {
        if(_type == "standart")
        {
            _damage = 50;
            _speed = 5;
        }
        if(_type == "level2")
        {
            _damage = 100;
            _speed = 5;
        }
        if(_type == "level3")
        {
            _damage = 100;
            _speed = 10;
        }

    }


}

Bullet::~Bullet ()
{
    cout << "\n=====================" << endl;
    cout << "DESTRUCTOR BULLET" << endl;
}

//
// Methods
//


void Bullet::move ()
{
    Position::move(_direction, _speed);
}

string Bullet::toString()
{
    string text = "BULLET : " + _type;
    text += " Shooter=" + _shooter + " ";
    text += Position::toString();
    text += " speed=";
    text += to_string(_speed);
    text += " direction=" + _direction ;
    text += " damage=" + to_string(_damage);
    text += " bullet type=" + _type;
    text += " shooter=" + _shooter;
    return text;
}

// Accessor methods
//

float Bullet::getX() const
{
    return  _X;
}

float Bullet::getY() const
{
    return _Y;
}


unsigned int Bullet::getDamage() const
{
    return _damage;
}

// Other methods
//

