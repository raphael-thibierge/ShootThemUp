//
//  ViewShop.cpp
//  ShmupTerminal
//
//  Created by Raphael Thibierge on 11/04/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "ViewShop.h"

using namespace std;

//
// CONSTRUCTOR AND DESTRUCTOR
//
ViewShop::ViewShop() {}

ViewShop::~ViewShop() {}


//
// METHODS
//

int ViewShop::treatEvent()
{
    int returnValue = 1;
    int answer;
    do
    {
        cout << _language->getText("choice") << endl;
        cin >> answer;

    }
    while ( answer < 4 || (answer > 6 && answer < 11) || (answer > 14 && answer < 20) || (answer > 23 && answer < 30 ) || answer > 33);

    bool purchase = false ;
    switch (answer)
    {
        case 4:
            purchase = _modele->getShop()->buyBomb();
            break;

        case 5:
            purchase = _modele->getShop()->buyLife();
            break;

        case 6:
            returnValue = 0;
            break;

        case 11:
            purchase = _modele->getShop()->upgradeBullet(1);
            break;

        case 12:
            purchase = _modele->getShop()->upgradeBullet(2);
            break;

        case 13:
            purchase = _modele->getShop()->upgradeBullet(3);
            break;

        case 14:
            purchase = _modele->getShop()->upgradeBullet(4);
            break;

        case 21:
            purchase = _modele->getShop()->upgradeShip(1);
            break;

        case 22:
            purchase = _modele->getShop()->upgradeShip(2);
            break;

        case 23:
            purchase = _modele->getShop()->upgradeShip(3);
            break;

        case 31:
            purchase = _modele->getShop()->upgradeShield(1);
            break;

        case 32:
            purchase = _modele->getShop()->upgradeShield(2);
            break;

        case 33:
            purchase = _modele->getShop()->upgradeShield(3);
            break;

        default:
            break;
    }

    if (purchase)
        cout << _language->getText("purchaseRight") << endl;

    else if (returnValue != 0)
        cout << _language->getText("purchaseWrong");


    return returnValue;
}


int ViewShop::treatEventSFML()
{
       int returnvalue = 1;

    sf::Event event;

     while (_window->GetEvent(event))
    {

        switch (event.Type)
        {
        case sf::Event::Closed :
            returnvalue = 111;
            break;

        case sf::Event::MouseButtonPressed :
        {


            int mouseX = event.MouseButton.X ;
            int mouseY = event.MouseButton.Y ;

            // a compléter
            break;
        }
        default :
            break;
        }
    }

    return returnvalue;
}

void ViewShop::showViewTerminal()
{
    cout << "\n---------------------- \n " << _language->getText("shop") << endl;
    cout << _language->getText("money") << " " << _modele->getPlayer()->getMoney() << "$"<< endl;
    cout << _language->getText("shootLevel") << " " << (_modele->getPlayer()->getBulletType() + 1 )<< endl;
    cout << _language->getText("shipLevel") << " " << (_modele->getPlayer()->getType() + 1) << endl;

    cout << _language->getText("shieldLevel") << " " << (_modele->getPlayer()->getShield()) << endl;


    if(_modele->getPlayer()->getShield()!=0){
        cout<< _language->getText("alreadyShield")<< endl<< endl;
    }
    else{
        cout<< _language->getText("noShield")<< endl<< endl;
    }


    cout << "\t (1) " << _language->getText("upgradeMainShoot") << endl;
    cout << "\t \t (11) " << _language->getText("upgradeMainShootlvl2") << "  " << BULLET_PRICE[1] <<"$"<< endl;
    cout << "\t \t (12) " << _language->getText("upgradeMainShootlvl3") << "  " << BULLET_PRICE[2] <<"$"<< endl;

    cout << "\t \t (13) " << _language->getText("upgradeMainShootlvl4") << "  " << BULLET_PRICE[3] <<"$"<< endl;

    cout << "\t \t (14) " << _language->getText("upgradeMainShootlvl5") << "  " << BULLET_PRICE[4] <<"$"<< endl;

    cout << "\t (2) " << _language->getText("upgradeShip") << endl;
    cout << "\t \t (21) " << _language->getText("upgradeShiplvl2") << " : " << SHIP_PRICE[1] <<"$"<< endl;

    cout << "\t \t (22) " << _language->getText("upgradeShiplvl3") << " : " << SHIP_PRICE[2] <<"$"<< endl;
    cout << "\t \t (23) " << _language->getText("upgradeShiplvl4") << " : " << SHIP_PRICE[3] <<"$"<< endl;
    cout << "\t (3) " << _language->getText("upgradeShield") << endl;
    cout << "\t \t (31) " << _language->getText("upgradeShieldlvl1") << " : " << SHIELD_PRICE[0] <<"$"<< endl;
    cout << "\t \t (32) " << _language->getText("upgradeShieldlvl2") << " : " << SHIELD_PRICE[1] <<"$"<< endl;
    cout << "\t \t (33) " << _language->getText("upgradeShieldlvl3") << " : " << SHIELD_PRICE[2] <<"$"<< endl;
    cout << "\t (4) " << _language->getText("buyBomb") << " : " << BOMB_PRICE << "$" << endl;
    cout << "\t (5) " << _language->getText("buyLife") << " : " << LIFE_PRICE << "$" << endl;
    cout << "\t (6) " + _language->getText("quit") << endl;
}


void ViewShop::showViewSFML()
{
}


void ViewShop::initButtons()
{
}
