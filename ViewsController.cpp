//
//  ViewsController.cpp
//  ShmupTerminal
//
//  Created by Raphael Thibierge on 11/04/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "ViewsController.h"


using namespace std;

//
// CONSTRUCTOR AND DESTRUCTOR
//
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
    for (auto view : _allViews) {
        //the gameview is not in the queue
        if (view.first != "Game")
            delete view.second;
        view.second=nullptr;
    }
}


//
// METHODS
//
bool ViewsController::treatEvent(){
    //return true if the player doesn't quit the game
    
    // switch between the different views
    
    // return of the treatment in active view
    switch (_view->treatEvent()) {
        
        case 1:// every things is ok
            break;
            
        case 0: // quit active view
            // if it's the main menu --> player want to quit
            if (dynamic_cast<ViewMainMenu*>(_view) != nullptr){
                quit();
            }
            
            else { // active view become the main menu
                _view = _allViews["MainMenu"];
            }
            break;
    
            // change of view
            //
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
    //show active view
    _view->showView();
}

void ViewsController::changeView(string view){
    // change active view
    _view = _allViews[view];
}

void ViewsController::quit(){
    // qui the game
    _quit = true;
}

void ViewsController::init(GameModel *modele){
    //initisilisation of the controller and views
    _modele = modele;
    _quit = false;
    for (auto view : _allViews) {
        view.second->setView(_modele);
    }
    
    // at beginning of the program, it's the introduction view
    _view = _allViews["Introduction"];

}