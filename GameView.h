
#ifndef GAMEVIEW_H
#define GAMEVIEW_H
#include "GameModel.h"
#include "View.h"
#include "viewGame.h"
#include <map>


class ViewController {

protected:
    bool _quit;
    GameModel* _modele;
    std::map<std::string, View*> _allViews;
    View* _view ;
    
    ViewGame _game;
    
public:
    
    ViewController();
    
    ~ViewController();

    bool treatEvent();
    
    void showView();
    
    void quit();
    
    void init(GameModel* modele);
    
private:
    void changeView(std::string view);
    
    
    
    
    
    
    
    
    
};




#endif // GAMEVIEW_H