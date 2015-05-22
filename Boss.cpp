//
//  Boss.cpp
//  ShmupTerminal
//
//  Created by Raphael Thibierge on 09/05/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "Boss.h"
using namespace std;
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
            if (_X > 100)
                RectanglePosition::move("WEST", _speed);
            else
                _direction = "EST";
        }
        if (_direction == "EST"){
            if (_X < SCREEN_WIDTH - _width - 100)
                RectanglePosition::move("EST", _speed);
            else
                _direction = "WEST";
        }
    }
}

void Boss::shoot(list<Bullet*> &bulletList)
{
    if (_time.GetElapsedTime() > TIME_BOSS_FIRE_RATE)
    {
        bulletList.push_back(new Bullet(BOSS_BULLET_TYPE, "SOUTH", _X+_width/2, _Y+_height , "boss" ));
        bulletList.push_back(new Bullet(BOSS_BULLET_TYPE, "SOUTH-EST",  _X+_width/2, _Y+_height, "boss" ));
        bulletList.push_back(new Bullet(BOSS_BULLET_TYPE, "SOUTH-WEST",  _X+_width/2, _Y+_height, "boss" ));
        _time.Reset();
    }
}
