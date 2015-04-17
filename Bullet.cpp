#include "Bullet.h"

using namespace std ;

// Constructors/Destructors
//

Bullet::Bullet (string type , string direction, float X, float Y, string shooter ) : RectanglePosition::RectanglePosition(X,Y, 5, 5), _type(type) ,_direction(direction), _shooter(shooter)
{
    // cout << "\n=====================" << endl;
    //cout << "CONSTRUCTOR BULLET" << endl;

    initBullet();

}

Bullet::~Bullet ()
{
    //cout << "\n=====================" << endl;
    //cout << "DESTRUCTOR BULLET" << endl;
}

//
// Methods
//


void Bullet::move ()
{
    RectanglePosition::move(_direction, _speed);
}



void Bullet::initBullet(){

    if (_direction == "NORTH")
        _Y -= _height;
    if (_direction == "SOUTH")
        _Y += _height;

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
        if(_type == "level4")
        {
            _damage = 150;
            _speed = 10;
        }
        if(_type == "level5")
        {
            _damage = 200;
            _speed = 10;
        }

    }

    if(_shooter=="enemy")
    {
        _damage=50;
        _speed=10;
    }


}

string Bullet::toString()
{
    string text = "BULLET : " + _type;
    text += " Shooter=" + _shooter + " ";
    text += RectanglePosition::toString();
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

unsigned int Bullet::getDamage() const
{
    return _damage;
}

// Other methods
//

