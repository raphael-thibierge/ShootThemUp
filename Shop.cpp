#include "Shop.h"
using namespace std;

Shop::Shop(Player* player) : _player(player){
    
    cout << "\n=====================" << endl;
    cout << "CONSTRUCTOR SHOP" << endl;
    
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
    cout << "\n=====================" << endl;
    cout << "DESTRUCTOR SHOP" << endl;
    _player = nullptr;
}


bool Shop::upgradeBullet(string type)
{
    //lvl5->500
    //lvl4->350
    //lvl3->200
    //lvl2->100
    if(_player->getMoney()>=100)
    {
        if(type == "level2" && _player->getBulletType()== "standart")
        {
            _player->setBulletType("level2");
            _player->setMoney(_player->getMoney()-100);
            _store["level2"]=false;
            _store["level3"]=true;
            return true;
        }

    }

    if(_player->getMoney()>=200)
    {
        if(type == "level3" && _player->getBulletType()== "level2")
        {
            _player->setBulletType("level3");
            _player->setMoney(_player->getMoney()-100);
            _store["level3"]=false;
            _store["level4"]=true;
            return true;
        }

    }
    if(_player->getMoney()>=350)
    {
        if(type == "level4" && _player
           ->getBulletType()== "level3")
        {
            _player->setBulletType("level4");
            _player->setMoney(_player->getMoney()-100);
            _store["level4"]=false;
            _store["level5"]=true;
            return true;
        }

    }
    if(_player->getMoney()>=500)
    {
        if(type == "level5" && _player->getBulletType()== "level4")
        {
            _player->setBulletType("level5");
            _player->setMoney(_player->getMoney()-100);
            _store["level5"]=false;
            return true;
        }

    }
    return false;
}


bool Shop::upgradeShip(string type)
{

    if(_player->getMoney()>=200)
    {
        if(type == "ship2" && _player->getLevel()== 1)
        {
            _player->setLevel(2);
            _player->setMoney(_player->getMoney()-200);
            _store["ship2"]=false;
            _store["ship3"]=true;
            return true;
        }
    }

    if(_player->getMoney()>=500)
    {
        if(type == "ship3" && _player->getLevel()== 2)
        {
            _player->setLevel(3);
            _player->setMoney(_player->getMoney()-500);
            _store["ship3"]=false;
            _store["ship4"]=true;
            return true;
        }
    }
    if(_player->getMoney()>=1000)
    {
        if(type == "ship4" && _player->getLevel()== 3)
        {
            _player->setLevel(4);
            _player->setMoney(_player->getMoney()-1000);
            _store["ship4"]=false;
            return true;
        }
    }

    return false;

}


bool Shop::upgradeShild(string type)
{

    if(_player->getMoney()>=200)
    {
        if(type == "shild1" && _player->getShild()!=0)
        {
            _player->setShild(100);
            _player->setMoney(_player->getMoney()-200);
            _store["shild1"]=false;
            _store["shild2"]=false;
            _store["shild3"]=false;
            return true;
        }
    }
    if(_player->getMoney()>=500)
    {
        if(type == "shild2" && _player->getShild()!=0)
        {
            _player->setShild(200);
            _player->setMoney(_player->getMoney()-500);
            _store["shild1"]=false;
            _store["shild2"]=false;
            _store["shild3"]=false;
            return true;
        }
    }
    if(_player->getMoney()>=700)
    {
        if(type == "shild3" && _player->getShild()!=0)
        {
            _player->setShild(300);
            _player->setMoney(_player->getMoney()-700);
            _store["shild1"]=false;
            _store["shild2"]=false;
            _store["shild3"]=false;
            return true;
        }
    }
    return false;
}





