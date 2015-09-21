//
//  View.cpp
//  ShmupTerminal
//
//  Created by Raphael Thibierge on 09/04/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "View.h"

using namespace std;
//
// CONSTRUCTOR AND DESTRUCTOR
//
View::View(){}

View::~View(){
    _modele = nullptr;
    _language = nullptr;
    _window = nullptr;

}


//
// METHODS
//


bool View::init(GameModel* modele, sf::RenderWindow * window)
{
    _modele = modele;
    _language = _modele->getSettings()->getLanguage();
    _window = window ;
    if (!initButtons())
        return false;
    if (!initSFML())
        return false;
    return true;
}

void View::displayStandartButton(const std::string text, const float positionX, const float positionY, bool active)
{
    if (active)
    {
        _spritesList["standartButton_active"].setPosition(positionX, positionY);
        _window->draw(_spritesList["standartButton_active"]);
    }

    else
    {
        _spritesList["standartButton"].setPosition(positionX, positionY);
        _window->draw(_spritesList["standartButton"]);
    }
    //_window->Draw(_spritesList["standartButton"]);

    displayText(text, positionX + 40, positionY+(BUTTON_HEIGHT - TEXT_SIZE)/2 - 5);

}


void View::displayText(const std::string text,const float positionX,const float positionY)
{
    sf::Font font;
    font.loadFromFile(resourcePath() + "sansation.ttf");
    sf::Text textDisplayed(text, font);
    textDisplayed.setCharacterSize(TEXT_SIZE);
    textDisplayed.setPosition(positionX, positionY);
    textDisplayed.setStyle(sf::Text::Bold);
    textDisplayed.setColor(sf::Color::White);
    _window->draw(textDisplayed);
}


void View::displayTitle( const std::string text, const float positionX, const float positionY)
{
    displayText(text, positionX, positionY);
}



bool View::mouseOnButton
(const int mouseX, const int mouseY, const int buttonX, const int buttonY, const int buttonWidth, const int buttonHeight)
{ // return true if the mouse is on the button

    if (mouseX >= buttonX &&
        mouseX <= buttonX + buttonWidth &&
        mouseY >= buttonY &&
        mouseY <= buttonY + buttonHeight )
        return true;
    return false;
}

bool View::initButtons()
{
    
    // STANDART BUTTON
        //buttons's image
    _imagesList.insert(make_pair("standartButtons", sf::Texture()));
    if (!_imagesList["standartButtons"].loadFromFile(resourcePath() + IMAGE_BUTTONS))
        return false;

    _imagesList.insert(make_pair("standartButtonsActive", sf::Texture()));
    if (!_imagesList["standartButtonsActive"].loadFromFile(resourcePath() + IMAGE_BUTTONS_ACTIVE))
        return false;

    // standart button
    _spritesList.insert(make_pair("standartButton", sf::Sprite()));
    _spritesList["standartButton"].setTexture(_imagesList["standartButtons"]);
    _spritesList["standartButton"].setTextureRect(sf::IntRect(0, 0, BUTTON_WIDTH + BUTTON_SPRITE_X , BUTTON_HEIGHT + BUTTON_SPRITE_Y));

    // standart active button
    _spritesList.insert(make_pair("standartButton_active", sf::Sprite()));
    _spritesList["standartButton_active"].setTexture(_imagesList["standartButtonsActive"]);
    _spritesList["standartButton_active"].setTextureRect(sf::IntRect(0, 0, BUTTON_WIDTH + BUTTON_SPRITE_ACTIVE_X , BUTTON_HEIGHT + BUTTON_SPRITE_ACTIVE_Y));
     
    return true;
}

const bool View::initSprite(std:: string name, const std::string image, const unsigned int nbSprites, const unsigned int spriteWitdh, const unsigned int spriteHeight)
{
    // player
    _imagesList.insert(make_pair(name, sf::Texture()));
    if (!_imagesList[name].loadFromFile( resourcePath() + image))
        return false;
    
    string nameSprite = name;
    for ( unsigned int spriteNumber = 0 ; spriteNumber < nbSprites ; spriteNumber++ )
    {
        if (nbSprites > 1)
            nameSprite = name + to_string(spriteNumber);
        else
            nameSprite = name;
        
        _spritesList.insert(make_pair(nameSprite, sf::Sprite()));
        _spritesList[nameSprite].setTexture(_imagesList[name]);
        _spritesList[nameSprite].setTextureRect(sf::IntRect(spriteNumber*spriteWitdh,0, spriteWitdh, spriteHeight));
    }
    return true;
}



