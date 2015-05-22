#include "Bullet.h"

using namespace std ;

// Constructors/Destructors
//

Bullet::Bullet (const unsigned int type , const string direction, const float X, const float Y, const string shooter ) : RectanglePosition::RectanglePosition(X,Y, 0, 0), _type(type) ,_direction(direction), _shooter(shooter)
{
    initBullet();
}

Bullet::Bullet(const unsigned int type) : _type(type)
{
    initBullet();
}

Bullet::~Bullet () {
    cout << __FUNCTION__ << endl ;
}


//
// Methods
//
void Bullet::move ()
{
    RectanglePosition::move(_direction, _speed);
}


void Bullet::initBullet(){


    _damage = BULLET_DAMAGE[_type%10];
    _speed = BULLET_SPEED[_type%10];
    _width = BULLET_WIDTH[_type%10];
    _height = BULLET_HEIGHT[_type%10];

    if (_direction == "NORTH")
        _Y -= _height;
    _X -= _width / 2;
}

string Bullet::toString()
{
    string text = "BULLET : " ;
    text += " Shooter=" + _shooter + " ";
    text += RectanglePosition::toString();
    text += " speed=";
    text += to_string(_speed);
    text += " direction=" + _direction ;
    text += " damage=" + to_string(_damage);
    text += " bullet type=" + to_string(_type);
    text += " shooter=" + _shooter;
    return text;
}

// Accessor methods
//

unsigned int Bullet::getDamage() const
{
    return _damage;
}

string Bullet::getShooter() const
{
    return _shooter;
}

unsigned int Bullet::getType() const
{
    return _type;
}
// Other methods
//

