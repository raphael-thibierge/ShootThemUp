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
    _time.Reset();
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

    if (_time.GetElapsedTime() > TIME_INTRODUCTION)
        returnValue = 0;

    sf::Event event;

     while (_window->GetEvent(event))
    {

        switch (event.Type)
        {
        case sf::Event::Closed :
            returnValue = 111;
            break;

        case sf::Event::KeyPressed :
            switch (event.Key.Code)
            {

                case sf::Key::Space:
                    returnValue = 0;
                    break;

                case sf::Key::Escape :
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
    _window->Draw(_spritesList["background"]);
    displayTitle("FARM THEM UP", INTROVIEW_TITLE_X,INTROVIEW_TITLE_Y);
}

bool ViewIntroduction::initSFML()
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

