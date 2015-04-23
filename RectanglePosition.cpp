#include "RectanglePosition.h"

using namespace std ;

//
// CONSTRUCTOR AND DESTRUCTOR
//

RectanglePosition::RectanglePosition () {
    _X = 0;
    _Y = 0;
    _width = 0;
    _height = 0;
}



RectanglePosition::RectanglePosition(float x, float y, float width, float heigh) : _X(x), _Y(y), _width(width), _height(heigh){

}

RectanglePosition::~RectanglePosition () { }


//
// METHODS
//



void RectanglePosition::move(float dx, float dy){
    _X += dx;
    _Y += dy;
}



void RectanglePosition::move(string direction, float speed){
    // switch doesn't work with string
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

void RectanglePosition::setPosition (float x, float y)
{
    _X = x ;
    _Y = y ;
}

void RectanglePosition::setSize (float widht, float height)
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



