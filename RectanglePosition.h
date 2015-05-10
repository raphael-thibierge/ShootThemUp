
#ifndef POSITION_H
#define POSITION_H

#include "Constante.h"
#include <string>
#include <vector>
#include <list>
#include <iostream>




class RectanglePosition
{

protected:
    // position
    float _X;
    float _Y;
    //size
    float _width;
    float _height;



// CONSTRUCTOR AND DESTRUCTOR
//
public:
	RectanglePosition ();

    RectanglePosition(const float x, const float y, const float width, const float heigh);

	virtual ~RectanglePosition () =0;


// METHODS
//
public:
    
    // move with values
    void move(const float dx, const float dy);
    
    // move in a direction, depend of speed
    void move(const std::string direction, const float speed);

    std::string toString();

//ACCESSOR METHODS
//
    void setPosition (const float x, const float y);
    
    void setSize (const float widht, const float height);
    
    float getX() const;

    float getY() const;

    float getWidht() const;

    float getHeight() const;

};

#endif // POSITION_H
