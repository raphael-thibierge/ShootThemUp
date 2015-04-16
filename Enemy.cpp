#include "Enemy.h"

using namespace std;

// Constructors/Destructors
//

Enemy::Enemy (string type, float x, float y, unsigned int lifeLevel) : Ship::Ship(type) {
    cout << "\n=====================" << endl;
    cout << "CONSTRUCTOR ENEMY" << endl;

    setPosition(x, y);
    initEnemy();
    
    _lifeLevel = lifeLevel;

}


Enemy::Enemy (std::string type, unsigned int level, float x, float y, float width, float height, unsigned int lifeLevel, float speed, unsigned int nbLife) : Ship(type), _level(level){
    
    setPosition(x, y);
    _lifeLevel = lifeLevel;
    _speed = speed;
    _direction =  "SOUTH";
    _width = width;
    _height = height;
}

Enemy::~Enemy () {
    cout << "\n=====================" << endl;
    cout << "DESTRUCTOR ENEMY" << endl;}

//
// Methods
//
void Enemy::move()
{
    Position::move(_direction, _speed);
}

void Enemy::shoot (string bulletType, string direction, list<Bullet*> * bulletList)
{
    if (_type != "kamikaze")
        bulletList->push_back(new Bullet("standart", direction, _X, _Y, "enemy"));
}

string Enemy::toString(){
    return "ENEMY : " + Ship::toString();
}


// A SUPPRIMER BIENTOT =========
void Enemy::initEnemy(){
    if (_type == "standart")
    {
        _level = 1;
        _lifeLevel = 50;
        _speed = 5;
        _direction = "SOUTH";
        _nbLife = 1;
    }
    _nbLife = 1 ;
}
// ==============================

// ACCESSOR METHODS
//

unsigned int Enemy::getLevel() const{
    return _level;
}

// STATIC METHODS
//

Enemy* Enemy::Standart(unsigned int level){
     return new Enemy("standard", level, randomPositionX(), 0, 10, 10, 25*DIFFICULTY, 5, 1 );
}

Enemy* Enemy::Kamikaze(unsigned int level){
    return new Enemy("kamikaze", level, randomPositionX(), 0, 10,10, 25*DIFFICULTY, 10,1) ;
}

int Enemy::randomPositionX(){
    return rand()%(-SCREEN_WIDTH);
}

