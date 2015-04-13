#include "Position.h"

using namespace std ;

// Constructors/Destructors
//  

Position::Position () {
    _X = 0;
    _Y = 0;
    _width = 0;
    _height = 0;
}

Position::Position (float x, float y){
    setPosition(x,y);
}

Position::Position(float x, float y, float width, float heigh) : _X(x), _Y(y), _width(width), _height(heigh){
    
}

Position::~Position () { }


//  
// Methods
//

void Position::setPosition (float x, float y)
{
    _X = x ;
    _Y = y ;
}

void Position::move(float dx, float dy){
    _X += dx;
    _Y += dy;
}



void Position::move(string direction, float speed){
    // switch doesn't work with string
    if (direction == "NORTH")
        Position::move(0, -speed);
    else if (direction == "SOUTH")
        Position::move(0, speed);
    else if (direction == "WEST")
        Position::move(-speed, 0);
    else if (direction == "EST")
        Position::move(speed, 0);
}

string Position::toString(){
    return "Position X=" + to_string(_X) + " Y=" + to_string(_Y);
}



// ACCESSOR METHODS
//  

float Position::getX() const {
    return _X;
}

float Position::getY() const {
    return _Y;
}

float Position::getWidht() const {
    return _width;
}

float Position::getHeight() const {
    return _height;
}

// Other methods
//  



