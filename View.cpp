//
//  View.cpp
//  ShmupTerminal
//
//  Created by Raphael Thibierge on 09/04/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "View.h"

View::View(){}

View::~View(){
    _modele = nullptr;
}

void View::showView(){}


void View::setView(GameModel *modele){
    _modele = modele;
    _language = _modele->getSettings()->getLanguage();
}
