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
ViewGame::ViewGame() : _backgroundY(0), _cptSprite(0)
{

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
    if (_modele->getPlayer()->getNbLife() == 0 && _modele->getTime() > TIME_YOU_LOOSE_TRANSITION)
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
                        case Key::S :
                            _modele->getPlayer()->activateShild();
                            break;

                        case Key::Escape :
                            _modele->endCurrentGame();
                            returnValue = 0;
                            break;

                        default :
                            break;
                    }
                break;

                case sf::Event::Closed :
                    returnValue = 111;
                    break;

                default:
                    break;
            }
        }

        if (!_modele->getPlayer()->isLosingLife())
        {


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
                if (_modele->getLevel() != nullptr)
                    _modele->getLevel()->playerShoot();
            }
        }
    }

    return returnValue;
}

void ViewGame::showViewTerminal()
{
    if(_modele->getLevel()==nullptr)
    {
        if (_modele->getPlayer()->getNbLife() > 0)
            showTransitionConsole();
        else
            showLoseConsole();
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
        cout << "\t (4)" + _language->getText("shield") << endl;
        cout << "\t (5)" + _language->getText("nothing") << endl;
        cout << "\t (6)" + _language->getText("escape") << endl;
    }
}

void ViewGame::showViewSFML()
{

    if(_modele->getLevel()==nullptr)
    {
        if (_modele->getPlayer()->getNbLife() > 0)
            showTransitionSFML();
        else
            showLoseSFML();
    }

    else if (!_modele->getPlayer()->isLosingLife())
    {
        // BAACKGROUND
        displayScrollingBackground();

        // PLAYER
        _spritesList["player"].SetPosition(_modele->getPlayer()->getX(), _modele->getPlayer()->getY());
        _window->Draw(_spritesList["player"]);

        int cptSprite;
        //ENEMIES
        for (auto enemy : *_modele->getLevel()->getEnemies())
        {
            switch (enemy->getType())
            {
                case 10 :
                    _spritesList["enemy_1"].SetPosition(enemy->getX(), enemy->getY());
                    _window->Draw(_spritesList["enemy_1"]);
                    break;

                case 11 :
                    _spritesList["enemy_2"].SetPosition(enemy->getX(), enemy->getY());
                    _window->Draw(_spritesList["enemy_2"]);
                    break;

                case 12 :
                    _spritesList["enemy_3"].SetPosition(enemy->getX(), enemy->getY());
                    _window->Draw(_spritesList["enemy_3"]);
                    break;

                default:
                    break;
            }
        }

        Boss * boss = _modele->getLevel()->getBoss();
        if (boss != nullptr)
        {
            _spritesList["player"].SetPosition(boss->getX(), boss->getY());
            _window->Draw(_spritesList["player"]);
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

                case 1 :
                    _spritesList["bullet_1"].SetPosition(bullet->getX(), bullet->getY());
                    _window->Draw(_spritesList["bullet_1"]);
                    break;

                case 2 :
                    _spritesList["bullet_1"].SetPosition(bullet->getX(), bullet->getY());
                    _window->Draw(_spritesList["bullet_1"]);
                    break;

                case 3 :
                    _spritesList["bullet_1"].SetPosition(bullet->getX(), bullet->getY());
                    _window->Draw(_spritesList["bullet_1"]);
                    break;

                case 4 :
                    _spritesList["bullet_1"].SetPosition(bullet->getX(), bullet->getY());
                    _window->Draw(_spritesList["bullet_1"]);
                    break;

                case 10 :
                    _spritesList["bullet_1"].SetPosition(bullet->getX(), bullet->getY());
                    _window->Draw(_spritesList["bullet_1"]);
                    break;

                case 11 :
                    _spritesList["bullet_1"].SetPosition(bullet->getX(), bullet->getY());
                    _window->Draw(_spritesList["bullet_1"]);
                    break;

                case 12 :
                    _spritesList["bullet_1"].SetPosition(bullet->getX(), bullet->getY());
                    _window->Draw(_spritesList["bullet_1"]);
                    break;

                default:
                    break;
            }
        }

        // BLASTS
        for (auto blast : *_modele->getLevel()->getBlast())
        {
             cptSprite = _cptSprite % BLAST_NBSPRITES ;
            _spritesList["blast_1"].SetSubRect(sf::IntRect(BLAST_SPRITES_X[cptSprite],BLAST_SPRITES_Y[cptSprite], BLAST_SPRITES_X[cptSprite]+BLAST_SPRITE_WIDTH, BLAST_SPRITES_Y[cptSprite]+BLAST_SPRITE_HEIGHT));
            _spritesList["blast_1"].SetPosition(blast->getX(), blast->getY());
            _window->Draw(_spritesList["blast_1"]);

        }

        // LABEL
        // score
        string score = _language->getText("score") + " : " + to_string( _modele->getPlayer()->getScore() );
        displayText(score, GAMEVIEW_LABEL_SCORE_X, GAMEVIEW_LABEL_SCORE_Y);

        // life level & life number
        string lifeLevel = _language->getText("lifeLevel") + " : " + to_string( _modele->getPlayer()->getLifeLevel()) + " / " + to_string(PLAYER_LIFE_LEVEL);
        displayText(lifeLevel, GAMEVIEW_LABEL_LIFE_X, GAMEVIEW_LABEL_LIFE_Y);

        // display lifes
        for (unsigned int i = 0 ; i < _modele->getPlayer()->getNbLife() ; i ++)
        {
            _spritesList["heart"].SetPosition(GAMEVIEW_HEART_X + GAMEVIEW_HEART_SIZE * i, GAMEVIEW_HEART_Y);
            _window->Draw(_spritesList["heart"]);
        }
        // display bomb
        for (unsigned int i = 0 ; i < _modele->getPlayer()->getBombNumber() ; i++ )
        {
            _spritesList["bomb"].SetPosition(GAMEVIEW_BOMB_X + GAMEVIEW_BOMB_SIZE * i, GAMEVIEW_BOMB_Y);
            _window->Draw(_spritesList["bomb"]);
        }
        _cptSprite++;
    }
    else {
        showLifeTransitionSFML();
    }
}

void ViewGame::showTransitionConsole()
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

void ViewGame::showTransitionSFML()
{
    _window->Draw(_spritesList["nextLevel"]);
}

void ViewGame::showLoseConsole()
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

void ViewGame::showLoseSFML()
{
    _window->Draw(_spritesList["youLoose"]);
}

void ViewGame::showLifeTransitionSFML()
{
    displayTitle(_language->getText("loseLife"), SCREEN_WIDTH / 3, SCREEN_HEIGHT/2);
}

void ViewGame::displayScrollingBackground()
{ // this method display a scrolling background

    // imcrement the Y position of background
    _backgroundY += IMAGE_BACKGROUND_SPEED ;

    // display first background
    _spritesList["background"].SetY(_backgroundY);
    _window->Draw(_spritesList["background"]);

    // if the window need a second image to display normal background
    if (_backgroundY > 0 && _backgroundY < SCREEN_HEIGHT)
    {
        // display a second one
        int positionY = _backgroundY - IMAGE_BACKGROUD_GAME_SIZE_Y +2 ;
        _spritesList["background"].SetY(positionY);
        _window->Draw(_spritesList["background"]);
    }

    // if background image is at the end of the screen
    else if (_backgroundY >= SCREEN_HEIGHT)
    {// go back up of the top of the screen
        _backgroundY -= IMAGE_BACKGROUD_GAME_SIZE_Y;
    }
}

bool ViewGame::initSFML()
{
    // =======================================================
    //                       LOADING IMAGES
    // =======================================================
    //background
    _imagesList.insert(make_pair("background", sf::Image()));
    if (!_imagesList["background"].LoadFromFile(IMAGE_BACKGROUD_GAME))
        return false;

    //player
    _imagesList.insert(make_pair("player", sf::Image()));
    if (!_imagesList["player"].LoadFromFile(IMAGE_PLAYER_SHIP))
        return false;

    //enemies
    _imagesList.insert(make_pair("enemy_1", sf::Image()));
    if (!_imagesList["enemy_1"].LoadFromFile(IMAGE_ENEMY_SHIP[0]))
        return false;

    _imagesList.insert(make_pair("enemy_2", sf::Image()));
    if (!_imagesList["enemy_2"].LoadFromFile(IMAGE_ENEMY_SHIP[1]))
        return false;

    _imagesList.insert(make_pair("enemy_3", sf::Image()));
    if (!_imagesList["enemy_3"].LoadFromFile(IMAGE_ENEMY_SHIP[2]))
        return false;

    //bullets
    _imagesList.insert(make_pair("bullet_1", sf::Image()));
    if (!_imagesList["bullet_1"].LoadFromFile(IMAGE_BULLET_0))
        return false;

    // nextLevel
    _imagesList.insert(make_pair("nextLevel", sf::Image()));
    if (!_imagesList["nextLevel"].LoadFromFile(IMAGE_NEXT_LEVEL))
        return false;

    // youLoose
    _imagesList.insert(make_pair("youLoose", sf::Image()));
    if (!_imagesList["youLoose"].LoadFromFile(IMAGE_YOU_LOOSE))
        return false;

    // heart ( life )
    _imagesList.insert(make_pair("heart", sf::Image()));
    if (!_imagesList["heart"].LoadFromFile(IMAGE_HEART))
        return false;

    // bomb
    _imagesList.insert(make_pair("bomb", sf::Image()));
    if (!_imagesList["bomb"].LoadFromFile(IMAGE_BOMB))
        return false;

    //blast
    _imagesList.insert(make_pair("blast_1", sf::Image()));
    if (!_imagesList["blast_1"].LoadFromFile(IMAGE_BLAST[0]))
        return false;


    // =======================================================
    //                       INIT SPRITE
    // =======================================================
    // backgound
    _spritesList.insert(make_pair("background", sf::Sprite()));
    _spritesList["background"].SetImage(_imagesList["background"]);
    _spritesList["background"].SetSubRect(sf::IntRect(0,0, IMAGE_BACKGROUD_GAME_SIZE_X, IMAGE_BACKGROUD_GAME_SIZE_Y));
    _spritesList["background"].SetPosition(0,0);
    // player
    _spritesList.insert(make_pair("player", sf::Sprite()));
    _spritesList["player"].SetImage(_imagesList["player"]);
    _spritesList["player"].SetSubRect(sf::IntRect(0,0, PLAYER_WIDTH, PLAYER_HEIGHT));
    // enemy
    _spritesList.insert(make_pair("enemy_1", sf::Sprite()));
    _spritesList["enemy_1"].SetImage(_imagesList["enemy_1"]);
    _spritesList["enemy_1"].SetSubRect(sf::IntRect(0,0, ENEMY_WIDTH[0], ENEMY_HEIGHT[0]));
    _spritesList.insert(make_pair("enemy_2", sf::Sprite()));
    _spritesList["enemy_2"].SetImage(_imagesList["enemy_2"]);
    _spritesList["enemy_2"].SetSubRect(sf::IntRect(0,0, ENEMY_WIDTH[1], ENEMY_HEIGHT[1]));
    _spritesList.insert(make_pair("enemy_3", sf::Sprite()));
    _spritesList["enemy_3"].SetImage(_imagesList["enemy_3"]);
    _spritesList["enemy_3"].SetSubRect(sf::IntRect(0,0, ENEMY_WIDTH[2], ENEMY_HEIGHT[2]));
    // bullet
    _spritesList.insert(make_pair("bullet_1", sf::Sprite()));
    _spritesList["bullet_1"].SetImage(_imagesList["bullet_1"]);
    _spritesList["bullet_1"].SetSubRect(sf::IntRect(0,0, BULLET_WIDTH[0], BULLET_HEIGHT[0]));
    // nextLevel
    _spritesList.insert(make_pair("nextLevel", sf::Sprite()));
    _spritesList["nextLevel"].SetImage(_imagesList["nextLevel"]);
    _spritesList["nextLevel"].SetSubRect(sf::IntRect(0,0, SCREEN_WIDTH, SCREEN_HEIGHT));
    // youLoose
    _spritesList.insert(make_pair("youLoose", sf::Sprite()));
    _spritesList["youLoose"].SetImage(_imagesList["youLoose"]);
    _spritesList["youLoose"].SetSubRect(sf::IntRect(0,0, SCREEN_WIDTH, SCREEN_HEIGHT));
    // heart
    _spritesList.insert(make_pair("heart", sf::Sprite()));
    _spritesList["heart"].SetImage(_imagesList["heart"]);
    _spritesList["heart"].SetSubRect(sf::IntRect(0,0, GAMEVIEW_HEART_SIZE, GAMEVIEW_HEART_SIZE));
    // bomb
    _spritesList.insert(make_pair("bomb", sf::Sprite()));
    _spritesList["bomb"].SetImage(_imagesList["bomb"]);
    _spritesList["bomb"].SetSubRect(sf::IntRect(0,0, GAMEVIEW_BOMB_SIZE, GAMEVIEW_BOMB_SIZE));
    // blast 1
    _spritesList.insert(make_pair("blast_1", sf::Sprite()));
    _spritesList["blast_1"].SetImage(_imagesList["blast_1"]);
    return true;
}
