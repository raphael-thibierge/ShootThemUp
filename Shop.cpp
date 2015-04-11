#include "Shop.h"
using namespace std;

Shop::Shop()
{
    _store["level2"]=true;
    _store["level3"]=false;
    _store["level4"]=false;
    _store["level5"]=false;
    _store["ship2"]=true;
    _store["ship3"]=false;
    _store["ship4"]=false;
    _store["shild1"]=true;
    _store["shild2"]=true;
    _store["shild3"]=true;
}

Shop::~Shop()
{
    //dtor
}


bool Shop::upgradeBullet(string type, Player * player)
{
    //lvl5->500
    //lvl4->350
    //lvl3->200
    //lvl2->100
    if(player->getMoney()>=100)
    {
        if(type == "level2" && player->getBulletType()== "standart")
        {
            player->setBulletType("level2");
            player->setMoney(player->getMoney()-100);
            _store["level2"]=false;
            _store["level3"]=true;
            return true;
        }

    }

    if(player->getMoney()>=200)
    {
        if(type == "level3" && player->getBulletType()== "level2")
        {
            player->setBulletType("level3");
            player->setMoney(player->getMoney()-100);
            _store["level3"]=false;
            _store["level4"]=true;
            return true;
        }

    }
    if(player->getMoney()>=350)
    {
        if(type == "level4" && player->getBulletType()== "level3")
        {
            player->setBulletType("level4");
            player->setMoney(player->getMoney()-100);
            _store["level4"]=false;
            _store["level5"]=true;
            return true;
        }

    }
    if(player->getMoney()>=500)
    {
        if(type == "level5" && player->getBulletType()== "level4")
        {
            player->setBulletType("level5");
            player->setMoney(player->getMoney()-100);
            _store["level5"]=false;
            return true;
        }

    }
    return false;
}


bool Shop::upgradeShip(string type, Player * player)
{

    if(player->getMoney()>=200)
    {
        if(type == "ship2" && player->getLevel()== 1)
        {
            player->setLevel(2);
            player->setMoney(player->getMoney()-200);
            return true;
            _store["ship2"]=false;
            _store["ship3"]=true;
            return true;
        }
    }

    if(player->getMoney()>=500)
    {
        if(type == "ship3" && player->getLevel()== 2)
        {
            player->setLevel(3);
            player->setMoney(player->getMoney()-500);
            return true;
            _store["ship3"]=false;
            _store["ship4"]=true;
            return true;
        }
    }
    if(player->getMoney()>=1000)
    {
        if(type == "ship4" && player->getLevel()== 3)
        {
            player->setLevel(4);
            player->setMoney(player->getMoney()-1000);
            return true;
            _store["ship4"]=false;
            return true;
        }
    }

    return false;

}


bool Shop::upgradeShild(string type, Player * player)
{

    if(player->getMoney()>=200)
    {
        if(type == "shild1" && player->getShild()!=0)
        {
            player->setShild(100);
            player->setMoney(player->getMoney()-200);
            return true;
            _store["shild1"]=false;
            _store["shild2"]=false;
            _store["shild3"]=false;
            return true;
        }
    }
    if(player->getMoney()>=500)
    {
        if(type == "shild2" && player->getShild()!=0)
        {
            player->setShild(200);
            player->setMoney(player->getMoney()-500);
            return true;
            _store["shild1"]=false;
            _store["shild2"]=false;
            _store["shild3"]=false;
            return true;
        }
    }
    if(player->getMoney()>=700)
    {
        if(type == "shild3" && player->getShild()!=0)
        {
            player->setShild(300);
            player->setMoney(player->getMoney()-700);
            return true;
            _store["shild1"]=false;
            _store["shild2"]=false;
            _store["shild3"]=false;
            return true;
        }
    }
    return false;
}





