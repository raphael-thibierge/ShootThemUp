#include "Enemy.h"

using namespace std;

//
// CONSTRUCTOR AND DESTRUCTOR
//

Enemy::Enemy (std::string type, unsigned int level, float x, float y, float width, float height, unsigned int lifeLevel, float speed, unsigned int nbLife) : Ship(type), _level(level){

    setPosition(x, y);
    _lifeLevel = lifeLevel;
    _speed = speed;
    _direction =  "SOUTH";
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

void Enemy::shoot (string bulletType, string direction, list<Bullet*> * bulletList)
{
    if (_type != "kamikaze")
        bulletList->push_back(new Bullet("standart", direction, _X+_width/2, _Y+_height, "enemy"));
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

Enemy* Enemy::Standard(unsigned int level){
     return new Enemy("standard", level, randomPositionX(), 0, 10, 10, 25*DIFFICULTY, 5, 1 );
}

Enemy* Enemy::Kamikaze(unsigned int level){
    return new Enemy("kamikaze", level, randomPositionX(), 0, 10,10, 25*DIFFICULTY, 10,1) ;
}

Enemy* Enemy::Helicopter(unsigned int level){
    return new Enemy("helicoptere", level, randomPositionX(), 0, 10,10, 25*DIFFICULTY, 10,1) ;
}


int Enemy::randomPositionX(){
    return rand()%(-SCREEN_WIDTH);
}

