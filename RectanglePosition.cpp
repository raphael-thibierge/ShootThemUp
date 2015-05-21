#include "RectanglePosition.h"

using namespace std ;

//
// CONSTRUCTOR AND DESTRUCTOR
//

RectanglePosition::RectanglePosition () {
    _X, _Y,_width, _height = 0;
}



RectanglePosition::RectanglePosition(const float x, const float y, const float width, const float heigh) : _X(x), _Y(y), _width(width), _height(heigh)
{

}

RectanglePosition::~RectanglePosition () {}


//
// METHODS
//



void RectanglePosition::move(const float dx, const float dy){
    _X += dx;
    _Y += dy;

    if (_X < 0)
        _X = 0;
    else if (_X > SCREEN_WIDTH-_width)
        _X = SCREEN_WIDTH - _width;

}



void RectanglePosition::move(const string direction, const float speed)
{
    // switch doesn't work with string
    // origin of map is the left top corner
    if (direction == "NORTH")
        move(0, -speed);
    else if (direction == "SOUTH")
        move(0, speed);
    else if (direction == "WEST")
        move(-speed, 0);
    else if (direction == "EST")
        move(speed, 0);
}

string RectanglePosition::toString(){
    string text = "Position X=" + to_string(_X);
    text += " Y=" + to_string(_Y) ;
    text += " Width=" + to_string(_width);
    text += " Height" + to_string(_height);
    return text;
}


//
// ACCESSOR METHODS
//

void RectanglePosition::setPosition (const float x, const  float y)
{
    _X = x ;
    _Y = y ;
}

void RectanglePosition::setSize (const float widht, const float height)
{
    _width = widht;
    _height = height;
}

float RectanglePosition::getX() const {
    return _X;
}

float RectanglePosition::getY() const {
    return _Y;
}

float RectanglePosition::getWidht() const {
    return _width;
}

float RectanglePosition::getHeight() const {
    return _height;
}

// Other methods
//



