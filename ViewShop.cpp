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

            if (mouseOnButton(mouseX, mouseY, SHOPSVIEW_MAINSHOOT2_X, SHOPSVIEW_MAINSHOOT2_Y, BUTTON_WIDTH, BUTTON_HEIGHT))
            {
                returnvalue = 1;
            }
            if (mouseOnButton(mouseX, mouseY, SHOPSVIEW_MAINSHOOT3_X, SHOPSVIEW_MAINSHOOT3_Y, BUTTON_WIDTH, BUTTON_HEIGHT))
            {
                returnvalue = 1;
            }
            if (mouseOnButton(mouseX, mouseY, SHOPSVIEW_MAINSHOOT4_X, SHOPSVIEW_MAINSHOOT4_Y, BUTTON_WIDTH, BUTTON_HEIGHT))
            {
                returnvalue = 1;
            }
            if (mouseOnButton(mouseX, mouseY, SHOPSVIEW_MAINSHOOT5_X, SHOPSVIEW_MAINSHOOT5_Y, BUTTON_WIDTH, BUTTON_HEIGHT))
            {
                returnvalue = 1;
            }
            if (mouseOnButton(mouseX, mouseY, SHOPSVIEW_MAINSHOOT2_X, SHOPSVIEW_MAINSHOOT2_X, BUTTON_WIDTH, BUTTON_HEIGHT))
            {
                returnvalue = 0;
            }

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


    if(_modele->getPlayer()->getShield()!=0)
    {
        cout<< _language->getText("alreadyShield")<< endl<< endl;
    }
    else
    {
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
    displayText(_language->getText("shop"), SHOPSVIEW_TITLE_X, SHOPSVIEW_TITLE_Y);

    displayText(_language->getText("upgradeMainShoot"), SHOPSVIEW_MAINSHOOT_X, SHOPSVIEW_MAINSHOOT_Y);
    displayStandartButton(_language->getText("upgradeMainShootlvl2"), SHOPSVIEW_MAINSHOOT2_X, SHOPSVIEW_MAINSHOOT2_Y);
    displayStandartButton(_language->getText("upgradeMainShootlvl3"), SHOPSVIEW_MAINSHOOT3_X, SHOPSVIEW_MAINSHOOT3_Y);
    displayStandartButton(_language->getText("upgradeMainShootlvl4"), SHOPSVIEW_MAINSHOOT4_X, SHOPSVIEW_MAINSHOOT4_Y);
    displayStandartButton(_language->getText("upgradeMainShootlvl5"), SHOPSVIEW_MAINSHOOT5_X, SHOPSVIEW_MAINSHOOT5_Y);

    displayText(_language->getText("upgradeShip"), SHOPSVIEW_SHIP_X, SHOPSVIEW_SHIP_Y);
    displayStandartButton(_language->getText("upgradeShiplvl2"), SHOPSVIEW_SHIP2_X, SHOPSVIEW_SHIP2_Y);
    displayStandartButton(_language->getText("upgradeShiplvl3"), SHOPSVIEW_SHIP3_X, SHOPSVIEW_SHIP3_Y);
    displayStandartButton(_language->getText("upgradeShiplvl4"), SHOPSVIEW_SHIP4_X, SHOPSVIEW_SHIP4_Y);

    displayText(_language->getText("upgradeShield"), SHOPSVIEW_SHIELD_X, SHOPSVIEW_SHIELD_Y);
    displayStandartButton(_language->getText("upgradeShieldlvl1"), SHOPSVIEW_SHIELD1_X, SHOPSVIEW_SHIELD1_Y);
    displayStandartButton(_language->getText("upgradeShieldlvl2"), SHOPSVIEW_SHIELD2_X, SHOPSVIEW_SHIELD2_Y);
    displayStandartButton(_language->getText("upgradeShieldlvl3"), SHOPSVIEW_SHIELD3_X, SHOPSVIEW_SHIELD3_Y);

    displayText(_language->getText("buyBomb"), SHOPSVIEW_BOMB_X, SHOPSVIEW_BOMB_Y);
    displayStandartButton(to_string(BOMB_PRICE), SHOPSVIEW_BOMBBUY_X, SHOPSVIEW_BOMBBUY_Y);

    displayText(_language->getText("buyLife"), SHOPSVIEW_LIFE_X, SHOPSVIEW_LIFE_Y);
    displayStandartButton(to_string(LIFE_PRICE), SHOPSVIEW_LIFEBUY_X, SHOPSVIEW_LIFEBUY_Y);

    displayStandartButton(_language->getText("quit"), SHOPSVIEW_QUIT_X, SHOPSVIEW_QUIT_Y);
}


void ViewShop::initButtons()
{
}
