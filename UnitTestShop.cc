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


BOOST_AUTO_TEST_CASE(BuyShoot)
{
    Player p;
    Shop s(&p);

    BOOST_CHECK(s.upgradeBullet(1)==false);
    BOOST_CHECK(s.available("bullet", 1)==true);
    BOOST_CHECK(s.available("bullet", 2)==false);
    BOOST_CHECK(s.available("bullet", 3)==false);
    BOOST_CHECK(s.available("bullet", 4)==false);
    BOOST_CHECK(s.upgradeBullet(1)==false);
    BOOST_CHECK(p.getBulletType()==0);

    p.setMoney(110);
    BOOST_CHECK(s.upgradeBullet(1)==true);
    BOOST_CHECK(p.getMoney()==10);
    BOOST_CHECK(p.getBulletType()==1);
    BOOST_CHECK(s.available("bullet", 2)==true);

    p.setMoney(210);
    BOOST_CHECK(s.upgradeBullet(2)==true);
    BOOST_CHECK(p.getMoney()==10);
    BOOST_CHECK(p.getBulletType()==2);
    BOOST_CHECK(s.available("bullet", 3)==true);

    p.setMoney(360);
    BOOST_CHECK(s.upgradeBullet(3)==true);
    BOOST_CHECK(p.getMoney()==10);
    BOOST_CHECK(p.getBulletType()==3);
    BOOST_CHECK(s.available("bullet", 4)==true);

    p.setMoney(510);
    BOOST_CHECK(s.upgradeBullet(4)==true);
    BOOST_CHECK(p.getMoney()==10);
    BOOST_CHECK(p.getBulletType()==4);

}



BOOST_AUTO_TEST_CASE(BuyShip)
{
    Player p;
    Shop s(&p);

    BOOST_CHECK(s.available("ship", 1)==true);
    BOOST_CHECK(s.available("ship", 2)==false);
    BOOST_CHECK(s.available("ship", 3)==false);
    BOOST_CHECK(s.upgradeShip(1)==false);
    BOOST_CHECK(p.getType()==0);

    p.setMoney(210);
    BOOST_CHECK(s.upgradeShip(1)==true);
    BOOST_CHECK(p.getMoney()==10);
    BOOST_CHECK(p.getType()==1);
    BOOST_CHECK(s.available("ship", 2)==true);

    p.setMoney(510);
    BOOST_CHECK(s.upgradeShip(2)==true);
    BOOST_CHECK(p.getMoney()==10);
    BOOST_CHECK(p.getType()==2);
    BOOST_CHECK(s.available("ship", 3)==true);

    p.setMoney(1010);
    BOOST_CHECK(s.upgradeShip(3)==true);
    BOOST_CHECK(p.getMoney()==10);
    BOOST_CHECK(p.getType()==3);

}

BOOST_AUTO_TEST_CASE(BuyShield)
{
    Player p;
    Shop s(&p);

    BOOST_CHECK(s.available("shield", 1)==true);
    BOOST_CHECK(s.available("shield", 2)==true);
    BOOST_CHECK(s.available("shield", 3)==true);
    BOOST_CHECK(s.upgradeShield(1)==false);
    BOOST_CHECK(s.upgradeShield(2)==false);
    BOOST_CHECK(s.upgradeShield(3)==false);
    BOOST_CHECK(p.getShield()==0);

    p.setMoney(110);
    BOOST_CHECK(s.upgradeShield(1)==true);
    BOOST_CHECK(p.getMoney()==10);
    BOOST_CHECK(p.getShield()==100);
    BOOST_CHECK(s.available("shield", 2)==false);
    BOOST_CHECK(s.available("shield", 3)==false);

    p.setShield(0);
    p.setMoney(310);
    BOOST_CHECK(s.upgradeShield(2)==true);
    BOOST_CHECK(p.getMoney()==10);
    BOOST_CHECK(p.getShield()==200);
    BOOST_CHECK(s.available("shield", 1)==false);
    BOOST_CHECK(s.available("shield", 3)==false);

    p.setShield(0);
    p.setMoney(510);
    BOOST_CHECK(s.upgradeShield(3)==true);
    BOOST_CHECK(p.getMoney()==10);
    BOOST_CHECK(p.getShield()==300);
    BOOST_CHECK(s.available("shield", 1)==false);
    BOOST_CHECK(s.available("shield", 2)==false);

}


BOOST_AUTO_TEST_CASE(BuyBomb)
{
    Player p;
    Shop s(&p);

    BOOST_CHECK(p.getBombNumber()==0);
    BOOST_CHECK(p.getMoney()==0);
    BOOST_CHECK(s.buyBomb()==false);

    p.setMoney(220);
    BOOST_CHECK(s.buyBomb()==true);
    BOOST_CHECK(p.getBombNumber()==1);
    BOOST_CHECK(p.getMoney()==120);
    BOOST_CHECK(s.buyBomb()==true);
    BOOST_CHECK(p.getBombNumber()==2);
    BOOST_CHECK(p.getMoney()==20);

}

BOOST_AUTO_TEST_CASE(BuyLife)
{
    Player p;
    Shop s(&p);

    BOOST_CHECK(p.getNbLife()==0);
    BOOST_CHECK(s.buyLife()==false);

    p.setMoney(260);
    BOOST_CHECK(s.buyLife()==true);
    BOOST_CHECK(p.getNbLife()==1);
    BOOST_CHECK(p.getMoney()==10);

}

