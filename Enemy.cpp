#include "Enemy.h"

using namespace std;

//
// CONSTRUCTOR AND DESTRUCTOR
//

Enemy::Enemy (const unsigned int type, const unsigned int level, const float x, const float y, const float width, const float height, const unsigned int lifeLevel, const float speed, const unsigned int nbLife) : Ship(type), _level(level)
{
    _time.Reset();
    setPosition(x, y);
    _lifeLevel = lifeLevel;
    _nbLife = nbLife;
    _speed = speed;
    _direction =  ENEMIES_DIRECTION;
    _width = width;
    cout << _type << " : " << _width << endl;
    _height = height;
}

Enemy::~Enemy () {
    //cout << "\n=====================" << endl;
    //cout << "DESTRUCTOR ENEMY" << endl;
}

//
// METHODS
//
void Enemy::move()
{
    RectanglePosition::move(_direction, _speed);
}

void Enemy::shoot (list<Bullet*> * bulletList)
{
    // if enemy isn't a kamikaze
    if (_time.GetElapsedTime() > TIME_ENEMY_FIRE_RATE && _type != ENEMY_TYPE[1])
    {
        bulletList->push_back(new Bullet(_type, _direction, _X+_width/2, _Y+_height, "enemy"));
        _time.Reset();
        playSound();
    }
}

string Enemy::toString(){
    return "ENEMY : " + Ship::toString();
}

void Enemy::difficultyImpact(const unsigned int difficulty)
{
    _lifeLevel *= difficulty;

}

//
// ACCESSOR METHODS
//

unsigned int Enemy::getLevel() const{
    return _level;
}

std::string Enemy::getDirection() const{
    return _direction;
}

//
// STATIC METHODS
//

Enemy* Enemy::Standard(const unsigned int level){
     return new Enemy(ENEMY_TYPE[0], level, 0, 0, ENEMY_WIDTH[0], ENEMY_HEIGHT[0], ENEMY_LIFE_LEVEL[0], ENEMY_SPEED[0], ENEMY_NB_LIFE );
}

Enemy* Enemy::Kamikaze(const unsigned int level){
     return new Enemy(ENEMY_TYPE[1], level, 0, 0, ENEMY_WIDTH[1], ENEMY_HEIGHT[1], ENEMY_LIFE_LEVEL[1], ENEMY_SPEED[1], ENEMY_NB_LIFE );
}

Enemy* Enemy::Helicopter(const unsigned int level){
     return new Enemy(ENEMY_TYPE[2], level, 0, 0, ENEMY_WIDTH[2], ENEMY_HEIGHT[2], ENEMY_LIFE_LEVEL[2], ENEMY_SPEED[2], ENEMY_NB_LIFE );;
}
