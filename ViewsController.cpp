//
//  ViewsController.cpp
//  ShmupTerminal
//
//  Created by Raphael Thibierge on 11/04/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "ViewsController.h"


using namespace std;

ViewsController::ViewsController() {
    _allViews.emplace(make_pair("Game", &_game));
    _allViews.emplace(make_pair("Shop", ))
    
}

ViewsController::~ViewsController(){
    _view = nullptr;
    
}

bool ViewsController::treatEvent(){
    switch (_view->treatEvent()) {
        case 1:
            // cas ou tout c'est bien déroulé
            break;
            
        case 0:
            //quit();
            break;
            
        case -1:
            _view = _allViews["MainMenu"];
            break;
            
        case -2:
            _view = _allViews["Game"];
            break;
            
        case -3:
            _view = _allViews["Shop"];
            break;
            
        case -4:
            _view = _allViews["Settings"];
            break;
            
        case -5:
            _view = _allViews["BestScores"];
            break;
            
        case -6:
            _view = _allViews["Introduction"];
            break;
        case -7:
            _view = _allViews["Quit"];
            break;
            
        default:
            break;
    }
    
    
    return !_quit;
}

void ViewsController::showView(){
    _view->showView();
}

void ViewsController::changeView(string view){
    _view = _allViews[view];
}

void ViewsController::quit(){
    cout << "QUIT" << endl;
    _quit = true;
}

void ViewsController::init(GameModel *modele){
    _modele = modele;
    
    _game.setModele(_modele);
    
    _view = _allViews["Game"];
    
}
