#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Hello

#include <boost/test/unit_test.hpp>


#include "Constante.h"

#include "Player.h"
#include "Ship.h"
#include "Position.h"
#include "Level.h"
#include "GameModel.h""
#include "Setting.h"
#include "Langage.h"
#include "Shop.h"
#include "Enemy.h"
#include "Bomb.h"
#include "Bullet.h"

#include "Player.cpp"
#include "Ship.cpp"
#include "Position.cpp"
#include "Level.cpp"
#include "GameModel.cpp""
#include "Setting.cpp"
#include "Langage.cpp"
#include "Shop.cpp"
#include "Enemy.cpp"
#include "Bomb.cpp"
#include "Bullet.cpp"





BOOST_AUTO_TEST_CASE(PlayerAndEnemyShoot)
{
    Player p;
    unsigned int difficulte = 2;
    Level level(&p, &difficulte);

    p.shoot("standart", "NORTH", level.getBullet());
    level.getEnemy()->clear();
    level.getEnemy()->push_back( Enemy::Standart(1) );

    for (auto e : *level.getEnemy())
        e->shoot("standart", "SOUTH", level.getBullet());

    BOOST_CHECK(level.getBullet()->size() == 2 );
    BOOST_CHECK(level.getEnemy()->size() == 1 );
}


BOOST_AUTO_TEST_CASE(CollisionWithAPoint){

    Player p;
    p.RectanglePosition::setPosition(0,0);

    p.RectanglePosition::setSize(10,10);

    BOOST_CHECK(p.Ship::collisionPoint(0,0) == true );
    BOOST_CHECK(p.Ship::collisionPoint(0,10) == true );
    BOOST_CHECK(p.Ship::collisionPoint(10,0) == true );
    BOOST_CHECK(p.Ship::collisionPoint(10,10) == true );
    BOOST_CHECK(p.Ship::collisionPoint(-1,0) == false );
    BOOST_CHECK(p.Ship::collisionPoint(11,0) == false );
    BOOST_CHECK(p.Ship::collisionPoint(0,11) == false );
    BOOST_CHECK(p.Ship::collisionPoint(0,-1) == false );

}


BOOST_AUTO_TEST_CASE(CollisionWithBullet){

    Player p;
    p.RectanglePosition::setPosition(10,10);
    p.RectanglePosition::setSize(10,10);
    Bullet b ("standart" , "SOUTH", 5, 5, "enemy");
    b.RectanglePosition::setSize(5,5);

    BOOST_CHECK(p.Ship::collision(&b) == true );

    b.RectanglePosition::setPosition(4,4);
    BOOST_CHECK(p.Ship::collision(&b) == false );

    b.RectanglePosition::setPosition(20,20);
    BOOST_CHECK(p.Ship::collision(&b) == true );

    b.RectanglePosition::setPosition(21,20);
    BOOST_CHECK(p.Ship::collision(&b) == false );

}

BOOST_AUTO_TEST_CASE(CollisionWithEnemy){

    Player p;
    p.RectanglePosition::setPosition(10,10);
    p.RectanglePosition::setSize(10,10);
    Enemy* e = Enemy::Standart(1);
    e->RectanglePosition::setPosition(5, 5);
    e->RectanglePosition::setSize(5,5);

    BOOST_CHECK(p.Ship::collision(e) == true );

    e->RectanglePosition::setPosition(4,4);
    BOOST_CHECK(p.Ship::collision(e) == false );

    e->RectanglePosition::setPosition(20,20);
    BOOST_CHECK(p.Ship::collision(e) == true );

    e->RectanglePosition::setPosition(21,20);
    BOOST_CHECK(p.Ship::collision(e) == false );

}












BOOST_AUTO_TEST_CASE(CollisionManagement)
{
    Player p;
    unsigned int difficulte = 2;
    Level level(&p, &difficulte);

    p.shoot("standart", "NORTH", level.getBullet());
    level.getEnemy()->clear();
    level.getEnemy()->push_back( Enemy::Standart(1) );

    for (auto e : *level.getEnemy())
        e->shoot("standart", "SOUTH", level.getBullet());

    p.RectanglePosition::move(0.0, -10.0);

    level.collisionManager();
    BOOST_CHECK(level.getBullet()->size() == 1 );
    BOOST_CHECK(level.getEnemy()->size() == 1 );

    for (auto e : *level.getEnemy())
        e->RectanglePosition::move(0.0, 10.0);
        level.collisionManager();
    BOOST_CHECK(level.getBullet()->size() == 0 );
    BOOST_CHECK(level.getEnemy()->size() == 0 );

    level.getEnemy()->push_back( Enemy::Standart(1) );
    for (auto e : *level.getEnemy())
        e->RectanglePosition::setPosition(p.getX()+1, p.getY()+1);
        level.collisionManager();
    BOOST_CHECK(level.getBullet()->size() == 0 );
    BOOST_CHECK(level.getEnemy()->size() == 0 );

    BOOST_CHECK(p.Ship::getLifeLevel() == 0 );
    BOOST_CHECK(p.Ship::getNbLife() == NB_LIFE_PLAYER-1);

}








