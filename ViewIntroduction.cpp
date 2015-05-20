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
ViewIntroduction::ViewIntroduction(){}

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

    int returnvalue = 0;

    sf::Event event;

     while (_window->GetEvent(event))
    {

        switch (event.Type)
        {
        case sf::Event::Closed :
            returnvalue = 111;
            break;

        default :
            break;
        }
    }

    return returnvalue;
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
}

void ViewIntroduction::initButtons()
{
}

