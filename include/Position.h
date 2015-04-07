
#ifndef POSITION_H
#define POSITION_H

#include "Constante.h"
#include <string>
#include <vector>
#include <list>
#include <iostream>


/******************************* Abstract Class ****************************
Position does not have any pure virtual methods, but its author
  defined it as an abstract class, so you should not use it directly.
  Inherit from it instead and create only objects from the derived classes
*****************************************************************************/

class Position
{

protected:
    float _X;
    float _Y;

public:

	// Constructors/Destructors
	//

	Position ();

    Position (float x, float y);

	virtual ~Position () =0;


// Methods
//
    void setPosition (float x, float y);

    void move(float dx, float dy);

    void move(std::string direction, float speed);

    std::string toString();

};

#endif // POSITION_H
