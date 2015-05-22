//
//  Boss.h
//  ShmupTerminal
//
//  Created by Raphael Thibierge on 09/05/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#ifndef __ShmupTerminal__Boss__
#define __ShmupTerminal__Boss__

#include <stdio.h>
#include "Enemy.h"

class Boss : public Enemy
{


// CONCSTRUCTOR/DESTRUCTOR
//
public:

    Boss();

    virtual ~Boss();


// METHODS
//
public:

    void move();

    void shoot(std::list<Bullet*> &bulletList);



};







#endif /* defined(__ShmupTerminal__Boss__) */
