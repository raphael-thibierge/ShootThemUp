//
//  View.h
//  ShmupTerminal
//
//  Created by Raphael Thibierge on 09/04/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#ifndef __ShmupTerminal__View__
#define __ShmupTerminal__View__

#include <stdio.h>
#include "GameModel.h"



class View
{
protected:

    GameModel* _modele;
    Language* _language;

    // SFML Window
    sf::RenderWindow * _window;

    std::map<std::string, sf::Sprite> _spritesList;
    std::map<std::string, sf::Texture> _imagesList;

    unsigned int cptBlastSprite;

// CONSTRUCTOR AND DESTRUCTOR
//
public :

    View();

    virtual ~View();

// METHODS
//
    // CONSOLE VERSION

    virtual int treatEvent() =0;

    virtual void showViewTerminal() =0 ;


    // SFML VERSION

    virtual int treatEventSFML() =0;

    virtual void showViewSFML() =0;

    void displayStandartButton( const std::string text, const float positionX, const float positionY, const bool active = false);

    void displayText( const std::string text, const float positionX, const float positionY);

    void displayTitle( const std::string text, const float positionX, const float positionY);

    bool mouseOnButton(const int mouseX, const int mouseY, const int buttonX, const int buttonY, const int buttonWidth, const int buttonHeight);

    bool init(GameModel* modele, sf::RenderWindow * window);

    virtual bool initSFML() =0;

    bool initButtons();
    
    
    const bool initSprite(const std::string name, const std::string image, const unsigned int nbSprites, const unsigned int spriteWitdh, const unsigned int spriteHeight);
    


};


#endif /* defined(__ShmupTerminal__View__) */
