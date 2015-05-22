//
//  ViewMainMenu.cpp
//  ShmupTerminal
//
//  Created by Raphael Thibierge on 11/04/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "ViewMainMenu.h"



using namespace std;
using namespace sf;

//
// CONSTRUCTOR AND DESTRUCTOR
//
ViewMainMenu::ViewMainMenu()
{
    // background
    _imagesList.insert(make_pair("background", sf::Image()));
    _imagesList["background"].LoadFromFile(IMAGE_BACKGROUD_MAIN_MENU);

    _spritesList.insert(make_pair("background", sf::Sprite()));
    _spritesList["background"].SetImage(_imagesList["background"]);
    _spritesList["background"].SetSubRect(sf::IntRect(0,0, SCREEN_WIDTH, SCREEN_HEIGHT));
    _spritesList["background"].SetPosition(0,0);

}

ViewMainMenu::~ViewMainMenu() {}


//
// METHODS
//




void ViewMainMenu::showViewSFML()
{
    _window->Draw(_spritesList["background"]);

    Event event;
    _window->GetEvent(event);
    int mouseX = event.MouseMove.X;
    int mouseY = event.MouseMove.Y;

    if (_modele->getPlayer() == nullptr)
    {
        displayStandartButton(_language->getText("newGame"), MENUVIEW_BUTTON_POSITION_X, BUTTON_NEWGAME_POSITION_Y);
        displayStandartButton(_language->getText("loadGame"), MENUVIEW_BUTTON_POSITION_X, BUTTON_LOADGAME_POSITION_Y);
        displayStandartButton(_language->getText("settings"), MENUVIEW_BUTTON_POSITION_X, BUTTON_SETTINGS_POSITION_Y);
        displayStandartButton(_language->getText("bestScores"), MENUVIEW_BUTTON_POSITION_X, BUTTON_BESTSCORES_POSITION_Y);
        displayStandartButton(_language->getText("quit"), MENUVIEW_BUTTON_POSITION_X, BUTTON_QUIT_POSITION_Y);
    }
    else
    {
        displayStandartButton(_language->getText("play"), MENUVIEW_BUTTON_POSITION_X, BUTTON_PLAY_POSITION_Y);
        displayStandartButton(_language->getText("shop"), MENUVIEW_BUTTON_POSITION_X, BUTTON_SHOP_POSITION_Y);
        displayStandartButton(_language->getText("settings"), MENUVIEW_BUTTON_POSITION_X, BUTTON_SETTINGS_POSITION_Y);
        displayStandartButton(_language->getText("bestScores"), MENUVIEW_BUTTON_POSITION_X, BUTTON_BESTSCORES_POSITION_Y);
        displayStandartButton(_language->getText("quit"), MENUVIEW_BUTTON_POSITION_X, BUTTON_QUIT_POSITION_Y);
    }

}

int ViewMainMenu::treatEventSFML()
{
    int returnValue = 1; // standart return of Event Treatment

    Event event;
    while (_window->GetEvent(event))
    {
        switch (event.Type)
        {

            case sf::Event::Closed :
                returnValue = 111;
                break;

            case Event::MouseButtonPressed :
            {
                int mouseX = event.MouseButton.X;
                int mouseY = event.MouseButton.Y;

                if (_modele->getPlayer() == nullptr)
                {// if a party isn't load

                    if (mouseOnButton(mouseX, mouseY, MENUVIEW_BUTTON_POSITION_X, BUTTON_NEWGAME_POSITION_Y, BUTTON_WIDTH, BUTTON_HEIGHT))
                    {// button new game
                        _modele->newGame();
                        returnValue = 1;
                    }

                    if (mouseOnButton(mouseX, mouseY, MENUVIEW_BUTTON_POSITION_X, BUTTON_LOADGAME_POSITION_Y, BUTTON_WIDTH, BUTTON_HEIGHT))
                    {// button load game
                        _modele->loadGame();
                        returnValue = 1;
                    }
                }

                else
                {
                    if (mouseOnButton(mouseX, mouseY, MENUVIEW_BUTTON_POSITION_X, BUTTON_PLAY_POSITION_Y, BUTTON_WIDTH, BUTTON_HEIGHT))
                    {// button play
                        _modele->play();
                        returnValue = -2;
                    }

                    if (mouseOnButton(mouseX, mouseY, MENUVIEW_BUTTON_POSITION_X, BUTTON_SHOP_POSITION_Y, BUTTON_WIDTH, BUTTON_HEIGHT))
                    {// button shop
                        returnValue = -3;
                    }
                }

                // COMMUN BUTTON

                if (mouseOnButton(mouseX, mouseY, MENUVIEW_BUTTON_POSITION_X, BUTTON_SETTINGS_POSITION_Y, BUTTON_WIDTH, BUTTON_HEIGHT))
                { // button settings
                    returnValue = -4;
                }

                if (mouseOnButton(mouseX, mouseY, MENUVIEW_BUTTON_POSITION_X, BUTTON_BESTSCORES_POSITION_Y, BUTTON_WIDTH, BUTTON_HEIGHT))
                { // button best scores
                    returnValue = -8;
                }

                if (mouseOnButton(mouseX, mouseY, MENUVIEW_BUTTON_POSITION_X, BUTTON_QUIT_POSITION_Y, BUTTON_WIDTH, BUTTON_HEIGHT))
                { // button best scores
                    returnValue = 0;
                }

            break;
        }

            case sf::Event::KeyPressed :
                if (event.Key.Code == Key::Escape)
                {
                    returnValue = 0;
                }
                break;
            default:
                break;

        }
    }

    return returnValue;

}

int ViewMainMenu::treatEvent()
{
    int returnValue = 1;
    int answer;

    if (_modele->getPlayer() == nullptr)
    {


        do
        {
            cout << _language->getText("choice") << endl;
            cin >> answer;

        }
        while ( answer > 3 && answer < 0 );

        switch (answer)
        {
        case 1:
            _modele->newGame();

            returnValue = 1;
            break;

        case 2:
            if (!_modele->loadGame())
            {
                cout << "Impossible de charger la partie" << endl;
            }
            else
                returnValue = 1;
            break;

        case 3:
            returnValue = -4;
            break;

        case 4:
            returnValue = -8;
            break;

        case 5:
            returnValue = 0;
            showQuit();

        default:
            break;
        }
    }
    else
    {

        do
        {
            cout << _language->getText("choice") << endl;
            cin >> answer;

        }
        while ( answer > 4 && answer < 0 );

        switch (answer)
        {
        case 1:
            _modele->play();
            returnValue = -2;
            break;

        case 2:
            returnValue = -3;
            break;

        case 3:
            returnValue = -4;
            break;

        case 4:
            returnValue = -8;
            break;

        case 5:
            returnValue = 0;
            showQuit();
            break;

        default:
            break;
        }
    }


    return returnValue;
}




void ViewMainMenu::showViewTerminal()
{

    showViewSFML();

    if (_modele->getPlayer() == nullptr)
    {
        cout << "\n------------------" << endl;
        cout << _language->getText("menu") << endl ;
        cout << "\t (1) " + _language->getText("newGame") << endl ;
        cout << "\t (2) " + _language->getText("loadGame") << endl;
        cout << "\t (3) " + _language->getText("settings") << endl ;
        cout << "\t (4) " + _language->getText("bestScores") << endl ;
        cout << "\t (5) " + _language->getText("quit") << endl;
    }

    else
    {

        cout << "\n------------------" << endl;
        cout << _language->getText("menu") << endl ;
        cout << "\t (1) " + _language->getText("play") << endl ;
        cout << "\t (2) " + _language->getText("goShop") << endl;
        cout << "\t (3) " + _language->getText("settings") << endl ;
        cout << "\t (4) " + _language->getText("bestScores") << endl ;
        cout << "\t (5) " + _language->getText("quit") << endl;

    }

}

void ViewMainMenu::showQuit()
{


    cout << "    ________  __    __  ________        ________  __    __  _______" << endl;
    cout << "   |        \\|  \\  |  \\|        \\      |        \\|  \\  |  \\|       \\" << endl;
    cout << "    \\$$$$$$$$| $$  | $$| $$$$$$$$      | $$$$$$$$| $$\\ | $$| $$$$$$$\\" << endl;
    cout << "      | $$   | $$__| $$| $$__          | $$__    | $$$\\| $$| $$  | $$" << endl;
    cout << "      | $$   | $$    $$| $$  \\         | $$  \\   | $$$$\\ $$| $$  | $$" << endl;
    cout << "      | $$   | $$$$$$$$| $$$$$         | $$$$$   | $$\\$$ $$| $$  | $$" << endl;
    cout << "      | $$   | $$  | $$| $$_____       | $$_____ | $$ \\$$$$| $$__/ $$" << endl;
    cout << "      | $$   | $$  | $$| $$     \\      | $$     \\| $$  \\$$$| $$    $$" << endl;
    cout << "       \\$$    \\$$   \\$$ \\$$$$$$$$       \\$$$$$$$$ \\$$   \\$$ \\$$$$$$$" << endl;



}

bool ViewMainMenu::initSFML()
{
    // background image
    _imagesList.insert(make_pair("background", sf::Image()));
    if (!_imagesList["background"].LoadFromFile(IMAGE_BACKGROUD_MAIN_MENU))
        return false;
    // background sprite
    _spritesList.insert(make_pair("background", sf::Sprite()));
    _spritesList["background"].SetImage(_imagesList["background"]);
    _spritesList["background"].SetSubRect(sf::IntRect(0,0, SCREEN_WIDTH, SCREEN_HEIGHT));
    _spritesList["background"].SetPosition(0,0);
    return true;
}
