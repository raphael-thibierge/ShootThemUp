
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

    RectanglePosition(float x, float y, float width, float heigh);

	virtual ~RectanglePosition () =0;


// METHODS
//
public:
    
    // move with values
    void move(float dx, float dy);
    
    // move in a direction, depend of speed
    void move(std::string direction, float speed);

    std::string toString();

//ACCESSOR METHODS
//
    void setPosition (float x, float y);
    
    void setSize (float widht, float height);
    
    float getX() const;

    float getY() const;

    float getWidht() const;

    float getHeight() const;

};

#endif // POSITION_H
