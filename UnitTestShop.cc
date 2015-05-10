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

    BOOST_CHECK(p.getBulletType() == "standart");
    BOOST_CHECK(s.upgradeBullet("level2")==false);

    p.setMoney(110);
    BOOST_CHECK(s.upgradeBullet("level3")==false);
    BOOST_CHECK(s.upgradeBullet("level2")==true);
    BOOST_CHECK(p.getMoney() == 10);
    BOOST_CHECK(p.getBulletType() == "level2");
    BOOST_CHECK(s.upgradeBullet("level3")==false);
    BOOST_CHECK(s.upgradeBullet("level2")==false);

    p.setMoney(210);
    BOOST_CHECK(s.upgradeBullet("level4")==false);
    BOOST_CHECK(s.upgradeBullet("level3")==true);
    BOOST_CHECK(p.getMoney() == 10);
    BOOST_CHECK(p.getBulletType() == "level3");
    BOOST_CHECK(s.upgradeBullet("level4")==false);
    BOOST_CHECK(s.upgradeBullet("level3")==false);

    p.setMoney(360);
    BOOST_CHECK(s.upgradeBullet("level5")==false);
    BOOST_CHECK(s.upgradeBullet("level4")==true);
    BOOST_CHECK(p.getMoney() == 10);
    BOOST_CHECK(p.getBulletType() == "level4");
    BOOST_CHECK(s.upgradeBullet("level5")==false);
    BOOST_CHECK(s.upgradeBullet("level4")==false);

    p.setMoney(510);
    BOOST_CHECK(s.upgradeBullet("level5")==true);
    BOOST_CHECK(p.getMoney() == 10);
    BOOST_CHECK(p.getBulletType() == "level5");
    BOOST_CHECK(s.upgradeBullet("level5")==false);


}

BOOST_AUTO_TEST_CASE(BuyShip)
{
    Player p;
    Shop s(&p);

    BOOST_CHECK(s.upgradeShip("ship2")==false);
    BOOST_CHECK(p.getLevel()==1);

    p.setMoney(220);
    BOOST_CHECK(s.upgradeShip("ship3")==false);
    BOOST_CHECK(s.upgradeShip("ship2")==true);
    BOOST_CHECK(p.getMoney() == 20);
    BOOST_CHECK(p.getLevel() == 2);
    BOOST_CHECK(p.getLifeLevel() == 500);
    BOOST_CHECK(s.upgradeShip("ship3")==false);
    BOOST_CHECK(s.upgradeShip("ship2")==false);

    p.setMoney(520);
    BOOST_CHECK(s.upgradeShip("ship4")==false);
    BOOST_CHECK(s.upgradeShip("ship3")==true);
    BOOST_CHECK(p.getMoney() == 20);
    BOOST_CHECK(p.getLevel() == 3);
    BOOST_CHECK(p.getLifeLevel() == 700);
    BOOST_CHECK(s.upgradeShip("ship3")==false);
    BOOST_CHECK(s.upgradeShip("ship2")==false);

    p.setMoney(1020);
    BOOST_CHECK(s.upgradeShip("ship4")==true);
    BOOST_CHECK(p.getMoney() == 20);
    BOOST_CHECK(p.getLevel() == 4);
    BOOST_CHECK(p.getLifeLevel() == 900);
    BOOST_CHECK(s.upgradeShip("ship4")==false);

}


BOOST_AUTO_TEST_CASE(BuyShild)
{
    Player p;
    Shop s(&p);

    BOOST_CHECK(s.upgradeShild("shild1")==false);
    BOOST_CHECK(s.upgradeShild("shild2")==false);
    BOOST_CHECK(s.upgradeShild("shild3")==false);

    p.setMoney(125);
    BOOST_CHECK(s.upgradeShild("shild2")==false);
    BOOST_CHECK(s.upgradeShild("shild3")==false);
    BOOST_CHECK(s.upgradeShild("shild1")==true);
    BOOST_CHECK(p.getMoney() == 25);
    BOOST_CHECK(p.getShild() == 100);
    BOOST_CHECK(s.upgradeShild("shild1")==false);
    BOOST_CHECK(s.upgradeShild("shild2")==false);
    BOOST_CHECK(s.upgradeShild("shild3")==false);
    s.shidlDisponible();
    p.setShild(0);

    p.setMoney(325);
    BOOST_CHECK(s.upgradeShild("shild3")==false);
    BOOST_CHECK(s.upgradeShild("shild2")==true);
    BOOST_CHECK(s.upgradeShild("shild1")==false);
    BOOST_CHECK(p.getMoney() == 25);
    BOOST_CHECK(p.getShild() == 200);
    BOOST_CHECK(s.upgradeShild("shild1")==false);
    BOOST_CHECK(s.upgradeShild("shild2")==false);
    BOOST_CHECK(s.upgradeShild("shild3")==false);
    s.shidlDisponible();
    p.setShild(0);


    p.setMoney(525);
    BOOST_CHECK(s.upgradeShild("shild3")==true);
    BOOST_CHECK(s.upgradeShild("shild2")==false);
    BOOST_CHECK(s.upgradeShild("shild1")==false);
    BOOST_CHECK(p.getMoney() == 25);
    BOOST_CHECK(p.getShild() == 300);
    BOOST_CHECK(s.upgradeShild("shild1")==false);
    BOOST_CHECK(s.upgradeShild("shild2")==false);
    BOOST_CHECK(s.upgradeShild("shild3")==false);
    s.shidlDisponible();
    p.setShild(0);





}








