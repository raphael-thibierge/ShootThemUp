//
//  ViewIntroduction.cpp
//  ShmupTerminal
//
//  Created by Raphael Thibierge on 11/04/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "ViewIntroduction.h"

using namespace std;

ViewIntroduction::ViewIntroduction(){}

ViewIntroduction::~ViewIntroduction(){}

int ViewIntroduction::treatEvent(){
    
    showView();
    
    return 0;
}

void ViewIntroduction::showView(){
    cout
    << " ------------------------------------------------------" << endl
    << "  ______   __                                         " << endl
    << " /      \ |  \ " << endl
    << "|  $$$$$$\| $$____   ______ ____   __    __   ______" << endl
    << "| $$___\$$| $$    \ |      \    \ |  \  |  \ /      \ " << endl
    << " \$$    \ | $$$$$$$\| $$$$$$\$$$$\| $$  | $$|  $$$$$$\ " << endl
    << " _\$$$$$$\| $$  | $$| $$ | $$ | $$| $$  | $$| $$  | $$" << endl
    << "|  \__| $$| $$  | $$| $$ | $$ | $$| $$__/ $$| $$__/ $$" << endl
    << " \$$    $$| $$  | $$| $$ | $$ | $$ \$$    $$| $$    $$" << endl
    << "  \$$$$$$ \$$   \$$ \$$  \$$  \$$  \$$$$$$ | $$$$$$$" << endl
    << "                                            | $$" << endl
    << "                                            | $$" << endl
    << "                                             \$$      " << endl
    << " ------------------------------------------------------" << endl;
    
}
