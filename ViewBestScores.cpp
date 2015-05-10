//
//  ViewBestScores.cpp
//  ShmupTerminal
//
//  Created by Raphael Thibierge on 09/05/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "ViewBestScores.h"
using namespace std;

ViewBestScores::ViewBestScores(){}

ViewBestScores::~ViewBestScores(){}


int ViewBestScores::treatEvent()
{
    return 0;
}

void ViewBestScores::showView(){
    int cpt = 1 ;
    for (auto value : *_modele->getBestScores()){
        cout << cpt << " --> " << value << endl;
        cpt++;
    }
}