//
//  Boss.cpp
//  ShmupTerminal
//
//  Created by Raphael Thibierge on 09/05/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "Boss.h"

//
// CONCSTRUCTOR/DESTRUCTOR
//

Boss::Boss() : Enemy::Enemy (BOSS_TYPE, BOSS_LEVEL, BOSS_INITIAL_X, BOSS_INITIAL_Y, BOSS_WIDTH, BOSS_HEIGHT, BOSS_LIFELEVEL, BOSS_SPEED, BOSS_NBLIFE)
{
    
}


Boss::~Boss() {}



void Boss::move()
{
    
}

