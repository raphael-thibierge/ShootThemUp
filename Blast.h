#ifndef BLAST_H
#define BLAST_H



#include "RectanglePosition.h"


class Blast : virtual public RectanglePosition
{
private:

    unsigned int _type;
    std::string _direction;
    float _speed;
    sf::Clock _time;

public:

    Blast(const unsigned int type, const std::string _direction, const float speed, const float X, const float Y);

    void move();

    // GETTERS AND SETTERS
    unsigned int getType();

    float getTime();
};


#endif // BLAST_H
