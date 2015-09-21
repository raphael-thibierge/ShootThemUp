//
//  ViewBestScores.cpp
//  ShmupTerminal
//
//  Created by Raphael Thibierge on 09/05/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.


#include "ViewBestScores.h"
using namespace std;

ViewBestScores::ViewBestScores(){}

ViewBestScores::~ViewBestScores(){}


int ViewBestScores::treatEvent()
{
    return 0;
}

int ViewBestScores::treatEventSFML()
{
    int returnValue  = 1;

    sf::Event event;

    while (_window->pollEvent(event))
    {

        switch (event.type)
        {
        case sf::Event::Closed :
            returnValue = 111;
            break;

        case sf::Event::MouseButtonPressed :
        {
            unsigned int mouseX = event.mouseButton.x ;
            unsigned int mouseY = event.mouseButton.y ;
            
            transformMousePosition(mouseX, mouseY);

            if (mouseOnButton(mouseX, mouseY, BUTTON_BESTSCORES_QUIT_POSITION_X, BUTTON_BESTSCORES_QUIT_POSITION_Y, BUTTON_WIDTH, BUTTON_HEIGHT))
            {
                returnValue = 0;
            }
            break;
        }

        case sf::Event::KeyPressed :
             if (event.key.code == sf::Keyboard::Escape)
             {
                 returnValue = 0;
             }
        default :
            break;
        }
    }

    return returnValue;
}


void ViewBestScores::showViewTerminal(){
    int cpt = 1 ;
    for (auto value : *_modele->getBestScores()){
        cout << cpt << " --> " << value << endl;
        cpt++;
    }
}

void ViewBestScores::showViewSFML()
{
    // draw background
    _window->draw(_spritesList["background"]);

    //
    displayTitle(_language->getText("bestScores"), LABEL_BESTSCORES_TITLE_POSITION_X, LABEL_BESTSCORES_TITLE_POSITION_Y);

    // Y position of each score label
    int positionY = LABEL_BESTSCORES_POSITION_Y ;
    // display all best scores
    for (auto score : *_modele->getBestScores())
    {
        displayText(to_string(score), LABEL_BESTSCORES_POSITION_X, positionY);
        positionY += LABEL_BESTSCORES_SPACE + BUTTON_HEIGHT;
    }

    // display quit button
    displayStandartButton(_language->getText("quit"), BUTTON_BESTSCORES_QUIT_POSITION_X, BUTTON_BESTSCORES_QUIT_POSITION_Y);

}


bool ViewBestScores::initSFML()
{
    
    // background image
    _imagesList.emplace(make_pair("background", sf::Texture()));
    if (!_imagesList["background"].loadFromFile(resourcePath() + IMAGE_BACKGROUD_MAIN_MENU))
        return false;

    // background sprite
    _spritesList.insert(make_pair("background", sf::Sprite()));
    _spritesList["background"].setTexture(_imagesList["background"]);
    _spritesList["background"].setTextureRect(sf::IntRect(0,0, SCREEN_WIDTH, SCREEN_HEIGHT));
    _spritesList["background"].setPosition(0,0);
    
    return true;
}
