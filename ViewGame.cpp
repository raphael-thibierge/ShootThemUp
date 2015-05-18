//
//  ViewGame.cpp
//  ShmupTerminal
//
//  Created by Raphael Thibierge on 11/04/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "ViewGame.h"

using namespace std;
using namespace sf;

//
// CONSTRUCTOR AND DESTRUCTOR
//
ViewGame::ViewGame()
{

    //background
    _imagesList.insert(make_pair("background", sf::Image()));
    _imagesList["background"].LoadFromFile(IMAGE_BACKGROUD_GAME);

    //player
    _imagesList.insert(make_pair("player", sf::Image()));
    _imagesList["player"].LoadFromFile(IMAGE_PLAYER_SHIP);

    //enemy
    _imagesList.insert(make_pair("enemy_1", sf::Image()));
    _imagesList["enemy_1"].LoadFromFile(IMAGE_ENEMY_0_SHIP);

    //bullet
    _imagesList.insert(make_pair("bullet_1", sf::Image()));
    _imagesList["bullet_1"].LoadFromFile(IMAGE_BULLET_0);


    // backgound
    _spritesList.insert(make_pair("background", sf::Sprite()));
    _spritesList["background"].SetImage(_imagesList["background"]);
    _spritesList["background"].SetSubRect(sf::IntRect(0,0, SCREEN_WIDTH, SCREEN_HEIGHT));
    _spritesList["background"].SetPosition(0,0);

    // player
    _spritesList.insert(make_pair("player", sf::Sprite()));
    _spritesList["player"].SetImage(_imagesList["player"]);
    _spritesList["player"].SetSubRect(sf::IntRect(0,0, PLAYER_WIDTH, PLAYER_HEIGHT));

    // player
    _spritesList.insert(make_pair("enemy_1", sf::Sprite()));
    _spritesList["enemy_1"].SetImage(_imagesList["enemy_1"]);
    _spritesList["enemy_1"].SetSubRect(sf::IntRect(0,0, ENEMY_WIDTH[0], ENEMY_HEIGHT[0]));

    // bullet
    _spritesList.insert(make_pair("bullet_1", sf::Sprite()));
    _spritesList["bullet_1"].SetImage(_imagesList["bullet_1"]);
    _spritesList["bullet_1"].SetSubRect(sf::IntRect(0,0, BULLET_WIDTH[0], ENEMY_HEIGHT[0]));

}

ViewGame::~ViewGame() {}


//
// METHODS
//
int ViewGame::treatEvent()
{
    int returnValue = 1;

    if (_modele->getLevel() != nullptr)
    {

        int reponse;

        do
        {
            cout << "Choix : ";
            cin >> reponse;
        }
        while (reponse<0 || reponse>7);


        switch (reponse)
        {
        case 1:
            int dx, dy;
            cout << _language->getText("moveX") << " : ";
            cin >> dx ;
            cout << _language->getText("moveY") << " : ";
            cin >> dy;
            _modele->getPlayer()->RectanglePosition::move(dx, dy);
            break;

        case 2:
            _modele->getPlayer()->shoot(_modele->getLevel()->getBullet());
            break;

        case 3 :
            _modele->getLevel()->playerUseBomb();

            break;

        case 4 :
            if(_modele->getPlayer()->getShield()!=0)
            {
                _modele->getPlayer()->activateShild();
                cout << _language->getText("activatedShild");
            }
            else
            {
                cout << _language->getText("noShild");
            }

            break;

        case 6 :
            returnValue = 0;
            _modele->endCurrentGame();
            break;

        default:
            break;
        }
    }
    else if (_modele->getPlayer()->getNbLife() == 0)
        returnValue = 0;
    return returnValue;
}












int ViewGame::treatEventSFML()
{
    int returnValue = 1;

    // if player loose, quit the game
    if (_modele->getPlayer()->getNbLife() == 0)
        returnValue = 0;

    else
    {
        Event event;
        while (_window->GetEvent(event))
        {
            switch (event.Type)
            {
                case Event::KeyPressed :
                    switch (event.Key.Code)
                    {
                        case Key::B :
                            _modele->getLevel()->playerUseBomb();
                            break;
                    }


                break;

            }

        }

        const Input & input = _window->GetInput(); // input : const reference

        // MOVEMENT
        // UP
        if (input.IsKeyDown(Key::Up)){
            _modele->getPlayer()->move("NORTH");
        }
        // DOWN
        if (input.IsKeyDown(Key::Down)){
            _modele->getPlayer()->move("SOUTH");
        }
        //LEFT
        if (input.IsKeyDown(Key::Left)){
            _modele->getPlayer()->move("WEST");
        }
        //RIGHT
        if (input.IsKeyDown(Key::Right)){
            _modele->getPlayer()->move("EST");
        }

        // MAIN SHOOT
        if (input.IsKeyDown(Key::Space)){
            _modele->getLevel()->playerShoot();
        }

    }

    return returnValue;
}





void ViewGame::showViewSFML()
{
    // BAACKGROUND
    _window->Draw(_spritesList["background"]);


    if(_modele->getLevel()==nullptr)
    {
        if (_modele->getPlayer()->getNbLife() > 0)
            showTransition();
        else
            showLoose();
    }

    else
    {
        // PLAYER
        if ( _modele->getPlayer() != nullptr )
        {
            _spritesList["player"].SetPosition(_modele->getPlayer()->getX(), _modele->getPlayer()->getY());
            _window->Draw(_spritesList["player"]);
        }

        //ENEMIES
        for (auto enemy : *_modele->getLevel()->getEnemies())
        {
            switch (enemy->getType())
            {
            case 0 :
                _spritesList["enemy_1"].SetPosition(enemy->getX(), enemy->getY());
                _window->Draw(_spritesList["enemy_1"]);
                break;
            }
        }

        // BULLETS
        for (auto bullet : *_modele->getLevel()->getBullet())
        {
            switch (bullet->getType())
            {
            case 0 :
                _spritesList["bullet_1"].SetPosition(bullet->getX(), bullet->getY());
                _window->Draw(_spritesList["bullet_1"]);
                break;
            }
        }

        // LABEL
        // score
        string score = _language->getText("score") + " : " + to_string( _modele->getPlayer()->getScore() );
        displayText(score, GAMEVIEW_LABEL_SCORE_X, GAMEVIEW_LABEL_SCORE_Y);

        // life level & life number
        string life = _language->getText("lifeLevel") + " : " + to_string( _modele->getPlayer()->getLifeLevel()) + " / "
        +  _language->getText("nbLife") + " : " + to_string( _modele->getPlayer()->getNbLife()) ;
        displayText(life, GAMEVIEW_LABEL_LIFE_X, GAMEVIEW_LABEL_LIFE_Y);

        // bomb number
        string bomb = _language->getText("nbBomb") + " : " + to_string( _modele->getPlayer()->getBombNumber()) ;
        displayText(bomb, GAMEVIEW_LABEL_BOMB_X, GAMEVIEW_LABEL_BOMB_Y);






    }

}


void ViewGame::showViewTerminal()
{
    if(_modele->getLevel()==nullptr)
    {
        if (_modele->getPlayer()->getNbLife() > 0)
            showTransition();
        else
            showLoose();
    }
    else
    {
        cout << "\n--------------" << endl;
        cout << "Jeu" << endl;
        cout << endl;
        cout << _modele->getPlayer()->toString() << endl;
        cout << endl;

        if (!_modele->getLevel()->getEnemies()->empty())
            for (auto enemy : *_modele->getLevel()->getEnemies())
                cout << enemy->toString() << endl;
        cout << endl;

        if (!_modele->getLevel()->getBullet()->empty())
            for (auto bullet : *_modele->getLevel()->getBullet())
                cout << bullet->toString() << endl;
        cout << endl;


        cout << "\t (1)" + _language->getText("move") << endl;
        cout << "\t (2)" + _language->getText("shoot") << endl;
        cout << "\t (3)" + _language->getText("bomb") << endl;
        cout << "\t (4)" + _language->getText("shild") << endl;
        cout << "\t (5)" + _language->getText("nothing") << endl;
        cout << "\t (6)" + _language->getText("escape") << endl;
    }
}

void ViewGame::showTransition()
{


    cout << " __    __                        __            __                                     __ "<<endl;
    cout << "|  \\  |  \\                      |  \\          |  \\                                   |  \\"<<endl;
    cout << "| $$\\ | $$  ______   __    __  _| $$_         | $$       ______  __     __   ______  | $$"<<endl;
    cout << "| $$$\\| $$ /      \\ |  \\  /  \\|   $$ \\        | $$      /      \\|  \\   /  \\ /      \\ | $$"<<endl;
    cout << "| $$$$\\ $$|  $$$$$$\\ \\$$\\/  $$ \\$$$$$$        | $$     |  $$$$$$\\\\$$\\ /  $$|  $$$$$$\\| $$"<<endl;
    cout << "| $$\\$$ $$| $$    $$  >$$  $$   | $$ __       | $$     | $$    $$ \\$$\\  $$ | $$    $$| $$"<<endl;
    cout << "| $$ \\$$$$| $$$$$$$$ /  $$$$\\   | $$|  \\      | $$_____| $$$$$$$$  \\$$ $$  | $$$$$$$$| $$"<<endl;
    cout << "| $$  \\$$$ \\$$     \\|  $$ \\$$\\   \\$$  $$      | $$     \\ $$     \\   \\$$$    \\$$     \\| $$"<<endl;
    cout << " \\$$   \\$$  \\$$$$$$$ \\$$   \\$$    \\$$$$        \\$$$$$$$$ \\$$$$$$$    \\$      \\$$$$$$$ \\$$"<<endl;

    cout << endl << endl << _language->getText("score") << " : " << _modele->getPlayer()->getScore() << endl;
    cout << _language->getText("money") << " : " << _modele->getPlayer()->getMoney() << endl;
}

void ViewGame::showLoose()
{


    cout << "     __      __   ______   __    __        __        ______    ______    ______   ________        __" << endl;
    cout << "    |  \\    /  \\ /      \\ |  \\  |  \\      |  \\      /      \\  /      \\  /      \\ |        \\      |  \\" << endl;
    cout << "     \\$$\\  /  $$|  $$$$$$\\| $$  | $$      | $$     |  $$$$$$\\|  $$$$$$\\|  $$$$$$\\| $$$$$$$$      | $$" << endl;
    cout << "      \\$$\\/  $$ | $$  | $$| $$  | $$      | $$     | $$  | $$| $$  | $$| $$___\\$$| $$__          | $$" << endl;
    cout << "       \\$$  $$  | $$  | $$| $$  | $$      | $$     | $$  | $$| $$  | $$ \\$$    \\ | $$  \\         | $$" << endl;
    cout << "        \\$$$$   | $$  | $$| $$  | $$      | $$     | $$  | $$| $$  | $$ _\\$$$$$$\\| $$$$$          \\$$" << endl;
    cout << "        | $$    | $$__/ $$| $$__/ $$      | $$_____| $$__/ $$| $$__/ $$|  \\__| $$| $$_____        __" << endl;
    cout << "        | $$     \\$$    $$ \\$$    $$      | $$      \\$$    $$ \\$$    $$ \\$$    $$| $$     \\      |  \\" << endl;
    cout << "         \\$$      \\$$$$$$   \\$$$$$$        \\$$$$$$$$ \\$$$$$$   \\$$$$$$   \\$$$$$$  \\$$$$$$$$       \\$$" << endl;



}


void ViewGame::initButtons()
{
}
