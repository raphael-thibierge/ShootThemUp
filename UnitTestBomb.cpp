#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE test

#include <boost/test/unit_test.hpp>

#include "Bullet.h"
#include "Constante.h"
#include "Enemy.h"
#include "GameModel.h"
#include "Language.h"
#include "Level.h"
#include "Player.h"
#include "RectanglePosition.h"
#include "Setting.h"
#include "Ship.h"
#include "Shop.h"


BOOST_AUTO_TEST_CASE(TestBomb)
{

    Player p;
    unsigned int difficulty = 2;
    Level l(&p , &difficulty);
    p.setBombNumber(2);
    BOOST_CHECK(p.getBombNumber()==2);
    l.getEnemies()->push_back(Enemy::Standard(1));
    BOOST_CHECK(l.getEnemies()->size()==1);
    l.playerUseBomb();
    BOOST_CHECK(l.getEnemies()->size()==0);
    BOOST_CHECK(p.getBombNumber()==1);


    l.getEnemies()->push_back(Enemy::Standard(1));
    l.getEnemies()->push_back(Enemy::Helicopter(1));
    l.getEnemies()->push_back(Enemy::Kamikaze(1));
    BOOST_CHECK(l.getEnemies()->size()==3);
    l.playerUseBomb();
    BOOST_CHECK(l.getEnemies()->size()==0);
    BOOST_CHECK(p.getBombNumber()==0);
}
