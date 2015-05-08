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
    _allViews.emplace(make_pair("Introduction", new ViewIntroduction()));
    _allViews.emplace(make_pair("MainMenu", new ViewMainMenu));
    _allViews.emplace(make_pair("Game", &_game));
    _allViews.emplace(make_pair("Shop", new ViewShop()));
    _allViews.emplace((make_pair("Settings", new ViewSettings)));
    _quit = false;
    
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
            if (dynamic_cast<ViewMainMenu*>(_view) != nullptr){
                quit();
            }
            
            else {
                _view = _allViews["MainMenu"];
            }
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
    _quit = true;
}

void ViewsController::init(GameModel *modele){
    _modele = modele;
    _quit = false;
    for (auto view : _allViews) {
        view.second->setView(_modele);
    }
    
    _view = _allViews["Introduction"];

}