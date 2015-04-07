//
//  main.cpp
//  ShmupTerminal
//
//  Created by Raphael Thibierge on 19/03/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include <iostream>
#include "GameView.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    GameModel * model = new GameModel;
    GameView * vueTerminal = new GameView;
    
    vueTerminal->setModel(model);
    
    vueTerminal->showIntroduction();
    vueTerminal->showGame();
    delete model;
    model = nullptr;
    delete vueTerminal;
    
    return 0;
}