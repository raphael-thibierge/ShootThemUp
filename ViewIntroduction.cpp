//
//  ViewIntroduction.cpp
//  ShmupTerminal
//
//  Created by Raphael Thibierge on 11/04/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "ViewIntroduction.h"

using namespace std;

//
// CONSTRUCTOR AND DESTRUCTOR
//
ViewIntroduction::ViewIntroduction()
{
    _time.restart();
}

ViewIntroduction::~ViewIntroduction(){}


//
// METHODS
//
int ViewIntroduction::treatEvent(){

    showViewTerminal();

    return 0;
}

int ViewIntroduction::treatEventSFML()
 {
    showViewSFML();

    int returnValue = 1;

    if (_time.getElapsedTime().asSeconds() > TIME_INTRODUCTION)
        returnValue = 0;

    sf::Event event;

     while (_window->pollEvent(event))
    {

        switch (event.type)
        {
        case sf::Event::Closed :
            returnValue = 111;
            break;

        case sf::Event::KeyPressed :
            switch (event.key.code)
            {

                case sf::Keyboard::Space:
                    returnValue = 0;
                    break;

                case sf::Keyboard::Escape :
                    returnValue = 0;
                    break;
                default :
                    break;
        }
            break;

        default :
            break;
        }
    }

    return returnValue;
 }

void ViewIntroduction::showViewTerminal(){
cout<<endl;
cout<<" ______    __                             __ "<<endl;
cout<<"/      \\  |  \\                           |  \\        "<<endl;
cout<<"|  $$$$$$\\| $$____    ______    ______  _| $$_     "   <<endl;
cout<<"| $$___\\$$| $$    \\  /      \\  /      \\|   $$ \\    " <<endl;
cout<<" \\$$    \\ | $$$$$$$\\|  $$$$$$\\|  $$$$$$\\\\$$$$$$    " <<endl;
cout<<" _\\$$$$$$\\| $$  | $$| $$  | $$| $$  | $$ | $$ __   " <<endl;
cout<<"|  \\__| $$| $$  | $$| $$__/ $$| $$__/ $$ | $$|  \\  "  <<endl;
cout<<" \\$$    $$| $$  | $$ \\$$    $$ \\$$    $$  \\$$  $$    " <<endl;
cout<<"  \\$$$$$$  \\$$   \\$$  \\$$$$$$   \\$$$$$$    \\$$$$    "  <<endl;
cout<<"  _________  __                                            "  <<endl;
cout<<"  |        \\|  \\                                    "   <<endl;
cout<<"   \\$$$$$$$$| $$____    ______   ______ ____       "   <<endl;
cout<<"     | $$   | $$    \\  /      \\ |      \\    \\     "  <<endl;
cout<<"     | $$   | $$$$$$$\\|  $$$$$$\\| $$$$$$\\$$$$\\   "  <<endl;
cout<<"     | $$   | $$  | $$| $$    $$| $$ | $$ | $$  "   <<endl;
cout<<"     | $$   | $$  | $$| $$$$$$$$| $$ | $$ | $$ "   <<endl;
cout<<"     | $$   | $$  | $$ \\$$     \\| $$ | $$ | $$"   <<endl;
cout<<"      \\$$    \\$$   \\$$  \\$$$$$$$ \\$$  \\$$  \\$$"  <<endl;
cout<<"                 __    __                             "<<endl;
cout<<"                |  \\  |  \\             "   <<endl;
cout<<"                | $$  | $$  ______    "  <<endl;
cout<<"                | $$  | $$ /      \\  "  <<endl;
cout<<"                | $$  | $$|  $$$$$$\\"   <<endl;
cout<<"                | $$  | $$| $$  | $$"      <<endl;
cout<<"                | $$__/ $$| $$__/ $$"   <<endl;
cout<<"                 \\$$    $$| $$    $$"     <<endl;
cout<<"                  \\$$$$$$ | $$$$$$$"      <<endl;
cout<<"                          | $$"            <<endl;
cout<<"                          | $$"           <<endl;
cout<<"                           \\$$"   <<endl;

}


void ViewIntroduction::showViewSFML()
{
    _window->draw(_spritesList["background"]);
    displayTitle("FARM THEM UP", INTROVIEW_TITLE_X,INTROVIEW_TITLE_Y);
}

bool ViewIntroduction::initSFML()
{
        // background image
    _imagesList.insert(make_pair("background", sf::Texture()));
    if (!_imagesList["background"].loadFromFile(resourcePath() + IMAGE_BACKGROUD_MAIN_MENU))
        return false;
    // background sprite
    _spritesList.insert(make_pair("background", sf::Sprite()));
    _spritesList["background"].setTexture(_imagesList["background"]);
    _spritesList["background"].setTextureRect(sf::IntRect(0,0, SCREEN_WIDTH, SCREEN_HEIGHT));
    _spritesList["background"].setPosition(0,0);
    
         return true;
}

