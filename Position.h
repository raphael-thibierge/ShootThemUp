
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
    float _X;
    float _Y;
    float _width;
    float _height;

public:

	// Constructors/Destructors
	//

	RectanglePosition ();

    RectanglePosition (float x, float y);
    
    RectanglePosition(float x, float y, float width, float heigh);

	virtual ~RectanglePosition () =0;


// Methods
//
    void setPosition (float x, float y);

    void move(float dx, float dy);

    void move(std::string direction, float speed);

    std::string toString();
    
//ACCESSOR METHODS
    float getX() const;
    
    float getY() const;
    
    float getWidht() const;
    
    float getHeight() const;

};

#endif // POSITION_H
