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
ViewShop::ViewShop() {
// background
    _imagesList.insert(make_pair("background", sf::Image()));
    _imagesList["background"].LoadFromFile(IMAGE_BACKGROUD_MAIN_MENU);

    _spritesList.insert(make_pair("background", sf::Sprite()));
    _spritesList["background"].SetImage(_imagesList["background"]);
    _spritesList["background"].SetSubRect(sf::IntRect(0,0, SCREEN_WIDTH, SCREEN_HEIGHT));
    _spritesList["background"].SetPosition(0,0);

}

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
            // UPGRADE SHOOT
            if (mouseOnButton(mouseX, mouseY, SHOPVIEW_COLUMN_1, SHOPVIEW_LINE_1, BUTTON_WIDTH, BUTTON_HEIGHT))
            {
                _modele->getShop()->upgradeBullet(1);
                returnvalue = 1;
            }
            if (mouseOnButton(mouseX, mouseY, SHOPVIEW_COLUMN_2, SHOPVIEW_LINE_1, BUTTON_WIDTH, BUTTON_HEIGHT))
            {
                _modele->getShop()->upgradeBullet(2);
                returnvalue = 1;
            }
            if (mouseOnButton(mouseX, mouseY, SHOPVIEW_COLUMN_3, SHOPVIEW_LINE_1, BUTTON_WIDTH, BUTTON_HEIGHT))
            {
                _modele->getShop()->upgradeBullet(3);
                returnvalue = 1;
            }
            // UPGRADE SHIP
            if (mouseOnButton(mouseX, mouseY, SHOPVIEW_COLUMN_1, SHOPVIEW_LINE_2, BUTTON_WIDTH, BUTTON_HEIGHT))
            {
                _modele->getShop()->upgradeShip(1);
                returnvalue = 1;
            }
            if (mouseOnButton(mouseX, mouseY, SHOPVIEW_COLUMN_2, SHOPVIEW_LINE_2, BUTTON_WIDTH, BUTTON_HEIGHT))
            {
                _modele->getShop()->upgradeShip(2);
                returnvalue = 1;
            }
            if (mouseOnButton(mouseX, mouseY, SHOPVIEW_COLUMN_3, SHOPVIEW_LINE_2, BUTTON_WIDTH, BUTTON_HEIGHT))
            {
                _modele->getShop()->upgradeShip(3);
                returnvalue = 1;
            }
            // UPGRADE SHIELD
            if (mouseOnButton(mouseX, mouseY, SHOPVIEW_COLUMN_1, SHOPVIEW_LINE_3, BUTTON_WIDTH, BUTTON_HEIGHT))
            {
                _modele->getShop()->upgradeShield(1);
                returnvalue = 1;
            }
            if (mouseOnButton(mouseX, mouseY, SHOPVIEW_COLUMN_2, SHOPVIEW_LINE_3, BUTTON_WIDTH, BUTTON_HEIGHT))
            {
                _modele->getShop()->upgradeShield(2);
                returnvalue = 1;
            }
            if (mouseOnButton(mouseX, mouseY, SHOPVIEW_COLUMN_3, SHOPVIEW_LINE_3, BUTTON_WIDTH, BUTTON_HEIGHT))
            {
                _modele->getShop()->upgradeShield(3);
                returnvalue = 1;
            }
            // LIFE
            if (mouseOnButton(mouseX, mouseY, SHOPVIEW_COLUMN_2, SHOPVIEW_LINE_4, BUTTON_WIDTH, BUTTON_HEIGHT))
            {
                _modele->getShop()->buyBomb();
                returnvalue = 1;
            }
            // BOMB
            if (mouseOnButton(mouseX, mouseY, SHOPVIEW_COLUMN_2, SHOPVIEW_LINE_5, BUTTON_WIDTH, BUTTON_HEIGHT))
            {
                _modele->getShop()->buyLife();
                returnvalue = 1;
            }
            // QUIT
            if (mouseOnButton(mouseX, mouseY, SHOPVIEW_COLUMN_2, SHOPVIEW_LINE_6, BUTTON_WIDTH, BUTTON_HEIGHT))
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

    _window->Draw(_spritesList["background"]);


    displayText(_language->getText("shop"), SHOPVIEW_COLUMN_2, SHOPSVIEW_TITLE_Y);

    displayText(_language->getText("money") + " = " + to_string(_modele->getPlayer()->getMoney()) + " $", SHOPVIEW_COLUMN_1, SHOPSVIEW_MONEY_Y);


    displayText(_language->getText("upgradeMainShoot"), SHOPVIEW_COLUMN_1, SHOPSVIEW_MAINSHOOT_Y);

    if (_modele->getPlayer()->getBulletType() >= 1)
        displayStandartButton(_language->getText("upgradeMainShootlvl2")+ " = " + to_string(BULLET_PRICE[1])+"$", SHOPVIEW_COLUMN_1, SHOPVIEW_LINE_1, true);
    else
        displayStandartButton(_language->getText("upgradeMainShootlvl2")+ " = " + to_string(BULLET_PRICE[1])+"$", SHOPVIEW_COLUMN_1, SHOPVIEW_LINE_1);

    if (_modele->getPlayer()->getBulletType() >= 2)
        displayStandartButton(_language->getText("upgradeMainShootlvl3")+ " = " + to_string(BULLET_PRICE[2])+"$", SHOPVIEW_COLUMN_2, SHOPVIEW_LINE_1, true);
    else
        displayStandartButton(_language->getText("upgradeMainShootlvl3")+ " = " + to_string(BULLET_PRICE[2])+"$", SHOPVIEW_COLUMN_2, SHOPVIEW_LINE_1);

    if (_modele->getPlayer()->getBulletType() >= 3)
        displayStandartButton(_language->getText("upgradeMainShootlvl4")+ " = " + to_string(BULLET_PRICE[3])+"$", SHOPVIEW_COLUMN_3, SHOPVIEW_LINE_1, true);
    else
        displayStandartButton(_language->getText("upgradeMainShootlvl4")+ " = " + to_string(BULLET_PRICE[3])+"$", SHOPVIEW_COLUMN_3, SHOPVIEW_LINE_1);
//    displayStandartButton(_language->getText("upgradeMainShootlvl5"), SHOPSVIEW_MAINSHOOT5_X, SHOPSVIEW_MAINSHOOT5_Y);

    displayText(_language->getText("upgradeShip"), SHOPVIEW_COLUMN_1, SHOPSVIEW_SHIP_Y);

    if (_modele->getPlayer()->getType() >= 1 )
        displayStandartButton(_language->getText("upgradeShiplvl2")+ " = " + to_string(SHIP_PRICE[1])+"$", SHOPVIEW_COLUMN_1, SHOPVIEW_LINE_2, true);
    else
        displayStandartButton(_language->getText("upgradeShiplvl2")+ " = " + to_string(SHIP_PRICE[1])+"$", SHOPVIEW_COLUMN_1, SHOPVIEW_LINE_2);

    if (_modele->getPlayer()->getType() >= 2 )
        displayStandartButton(_language->getText("upgradeShiplvl3")+ " = " + to_string(SHIP_PRICE[2])+"$", SHOPVIEW_COLUMN_2, SHOPVIEW_LINE_2, true);
    else
        displayStandartButton(_language->getText("upgradeShiplvl3")+ " = " + to_string(SHIP_PRICE[2])+"$", SHOPVIEW_COLUMN_2, SHOPVIEW_LINE_2);

    if (_modele->getPlayer()->getType() >= 3 )
        displayStandartButton(_language->getText("upgradeShiplvl4")+ " = " + to_string(SHIP_PRICE[3])+"$", SHOPVIEW_COLUMN_3, SHOPVIEW_LINE_2, true);
    else
        displayStandartButton(_language->getText("upgradeShiplvl4")+ " = " + to_string(SHIP_PRICE[3])+"$", SHOPVIEW_COLUMN_3, SHOPVIEW_LINE_2);

    displayText(_language->getText("upgradeShield"), SHOPVIEW_COLUMN_1, SHOPSVIEW_SHIELD_Y);

    if (_modele->getPlayer()->getShield() != SHIELD_LIFE[0])
        displayStandartButton(_language->getText("upgradeShieldlvl1")+ " = " + to_string(SHIELD_PRICE[1])+"$", SHOPVIEW_COLUMN_1, SHOPVIEW_LINE_3, true);
    else
        displayStandartButton(_language->getText("upgradeShieldlvl1")+ " = " + to_string(SHIELD_PRICE[1])+"$", SHOPVIEW_COLUMN_1, SHOPVIEW_LINE_3);

    if (_modele->getPlayer()->getShield() != SHIELD_LIFE[0])
        displayStandartButton(_language->getText("upgradeShieldlvl2")+ " = " + to_string(SHIELD_PRICE[2])+"$", SHOPVIEW_COLUMN_2, SHOPVIEW_LINE_3, true);
    else
        displayStandartButton(_language->getText("upgradeShieldlvl2")+ " = " + to_string(SHIELD_PRICE[2])+"$", SHOPVIEW_COLUMN_2, SHOPVIEW_LINE_3);

    if (_modele->getPlayer()->getShield() != SHIELD_LIFE[0])
        displayStandartButton(_language->getText("upgradeShieldlvl3")+ " = " + to_string(SHIELD_PRICE[3])+"$", SHOPVIEW_COLUMN_3, SHOPVIEW_LINE_3, true);
    else
        displayStandartButton(_language->getText("upgradeShieldlvl3")+ " = " + to_string(SHIELD_PRICE[3])+"$", SHOPVIEW_COLUMN_3, SHOPVIEW_LINE_3);

    displayText(_language->getText("buyBomb"), SHOPVIEW_COLUMN_1, SHOPSVIEW_BOMB_Y);
    displayStandartButton(to_string(BOMB_PRICE)+"$", SHOPVIEW_COLUMN_2, SHOPVIEW_LINE_4);

    displayText(_language->getText("buyLife"), SHOPVIEW_COLUMN_1, SHOPSVIEW_LIFE_Y);
    displayStandartButton(to_string(LIFE_PRICE)+"$", SHOPVIEW_COLUMN_2, SHOPVIEW_LINE_5);

    displayStandartButton(_language->getText("quit"), SHOPVIEW_COLUMN_2, SHOPVIEW_LINE_6);
}


void ViewShop::initButtons()
{
}
