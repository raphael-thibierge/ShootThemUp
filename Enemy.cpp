#include "Enemy.h"

using namespace std;

//
// CONSTRUCTOR AND DESTRUCTOR
//

Enemy::Enemy (const unsigned int type, const unsigned int level, const float x, const float y, const float width, const float height, const unsigned int lifeLevel, const float speed, const unsigned int nbLife) : Ship(type), _level(level){

    setPosition(x, y);
    _lifeLevel = lifeLevel;
    _speed = speed;
    _direction =  ENEMIES_DIRECTION;
    _width = width;
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
    if (_type != 10)
        bulletList->push_back(new Bullet(0, _direction, _X+_width/2, _Y+_height, "enemy"));
}

string Enemy::toString(){
    return "ENEMY : " + Ship::toString();
}

//
// ACCESSOR METHODS
//

unsigned int Enemy::getLevel() const{
    return _level;
}

//
// STATIC METHODS
//

Enemy* Enemy::Standard(const unsigned int level){
     return new Enemy(0, level, randomPositionX(), 0, ENEMY_WIDTH[0], ENEMY_HEIGHT[0], ENEMY_LIFE_LEVEL[0], ENEMY_SPEED[0], ENEMY_NB_LIFE );
}

Enemy* Enemy::Kamikaze(const unsigned int level){
     return new Enemy(10, level, randomPositionX(), 0, ENEMY_WIDTH[1], ENEMY_HEIGHT[1], ENEMY_LIFE_LEVEL[1], ENEMY_SPEED[1], ENEMY_NB_LIFE );
}

Enemy* Enemy::Helicopter(const unsigned int level){
     return new Enemy(11, level, randomPositionX(), 0, ENEMY_WIDTH[0], ENEMY_HEIGHT[2], ENEMY_LIFE_LEVEL[2], ENEMY_SPEED[2], ENEMY_NB_LIFE );;
}


int Enemy::randomPositionX(){
    return rand()%(-SCREEN_WIDTH);
}
