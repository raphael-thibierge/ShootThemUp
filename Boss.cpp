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
    if (_Y < 200 ){
        RectanglePosition::move("SOUTH", _speed);
    }
    else{
        if (_direction == "SOUTH")
        {
            _direction = "WEST";

        }
        if (_direction == "WEST"){
            if (_X > 0)
                RectanglePosition::move("WEST", _speed);
            else
                _direction = "EST";
        }
        if (_direction == "EST"){
            if (_X < SCREEN_WIDTH - _width)
                RectanglePosition::move("EST", _speed);
            else
                _direction = "WEST";
        }
    }
}

