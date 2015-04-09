#include "Shop.h"
using namespace std;

Shop::Shop()
{
    //ctor
}

Shop::~Shop()
{
    //dtor
}


bool Shop::upgradeBullet(string type, Player * player)
{
    if(player->getMoney()<=500)
    {
        if (type == "level5" && player->getBulletType()!=type)
        {
            player->setBulletType(type);
            player->setMoney(player->getMoney()-500);
            return true;
        }
        if (type == "level4" && player->getBulletType()!=type)
        {
            player->setBulletType(type);
            player->setMoney(player->getMoney()-350);
            return true;
        }
        if (type == "level3" && player->getBulletType()!=type)
        {
            player->setBulletType(type);
            player->setMoney(player->getMoney()-200);
            return true;
        }
        if (type == "level2" && player->getBulletType()!=type)
        {
            player->setBulletType(type);
            player->setMoney(player->getMoney()-100);
            return true;
        }
    }

    if(player->getMoney()<=350)
    {
        if (type == "level4" && player->getBulletType()!=type)
        {
            player->setBulletType(type);
            player->setMoney(player->getMoney()-350);
            return true;
        }
        if (type == "level3" && player->getBulletType()!=type)
        {
            player->setBulletType(type);
            player->setMoney(player->getMoney()-200);
            return true;
        }
        if (type == "level2" && player->getBulletType()!=type)
        {
            player->setBulletType(type);
            player->setMoney(player->getMoney()-100);
            return true;
        }
    }

    if(player->getMoney()<=200)
    {
        if (type == "level3" && player->getBulletType()!=type)
        {
            player->setBulletType(type);
            player->setMoney(player->getMoney()-200);
            return true;
        }
        if (type == "level2" && player->getBulletType()!=type)
        {
            player->setBulletType(type);
            player->setMoney(player->getMoney()-100);
            return true;
        }
    }
    if(player->getMoney()<=100)
    {
        if (type == "level2" && player->getBulletType()!=type)
        {
            player->setBulletType(type);
            player->setMoney(player->getMoney()-100);
            return true;
        }
    }
    return false;
}


bool Shop::upgradeShip(string type, Player * player)
{
    if(player->getMoney()<=1000)
    {
        if (type == "ship4" && player->getLevel()!=4)
        {
            player->setLevel(4);
            player->setMoney(player->getMoney()-1000);
            return true;
        }
        if (type == "ship3" && player->getLevel()!=3)
        {
            player->setLevel(3);
            player->setMoney(player->getMoney()-500);
            return true;
        }
        if (type == "ship2" && player->getLevel()!=2)
        {
            player->setLevel(2);
            player->setMoney(player->getMoney()-200);
            return true;
        }
    }
    if(player->getMoney()<=500)
    {
        if (type == "ship3" && player->getLevel()!=3)
        {
            player->setLevel(3);
            player->setMoney(player->getMoney()-500);
            return true;
        }
        if (type == "ship2" && player->getLevel()!=2)
        {
            player->setLevel(2);
            player->setMoney(player->getMoney()-200);
            return true;
        }
    }
    if(player->getMoney()<=200)
    {
        if (type == "ship2" && player->getLevel()!=2)
        {
            player->setLevel(2);
            player->setMoney(player->getMoney()-200);
            return true;
        }
    }
    return false;

}


bool Shop::upgradeShild(string type, Player * player)
{
    if(player->getMoney()<=500)
    {
        if (type == "shild3" && player->getShild()!=0)
        {
            player->setLevel(300);
            player->setMoney(player->getMoney()-500);
            return true;
        }
        if (type == "shild2" && player->getShild()!=0)
        {
            player->setLevel(200);
            player->setMoney(player->getMoney()-300);
            return true;
        }
        if (type == "shild1" && player->getShild()!=0)
        {
            player->setLevel(100);
            player->setMoney(player->getMoney()-200);
            return true;
        }
    }
    if(player->getMoney()<=300)
    {
        if (type == "shild2" && player->getShild()!=0)
        {
            player->setLevel(200);
            player->setMoney(player->getMoney()-300);
            return true;
        }
        if (type == "shild1" && player->getShild()!=0)
        {
            player->setLevel(100);
            player->setMoney(player->getMoney()-200);
            return true;
        }
    }
    if(player->getMoney()<=200)
    {
        if (type == "shild1" && player->getShild()!=0)
        {
            player->setLevel(100);
            player->setMoney(player->getMoney()-200);
            return true;
        }
    }
    return false;
}





