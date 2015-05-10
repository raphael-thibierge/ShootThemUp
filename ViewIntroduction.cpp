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

    showView();

    return 0;
}

void ViewIntroduction::showView(){
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
