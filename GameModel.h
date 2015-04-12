
#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <string>


#include "Level.h"
#include "Setting.h"
#include "Shop.h"

class GameModel
{

private:
    int _width;
    int _height;

    Player * _player;
    Level * _level;
    Shop * _shop;
    Settings * _settings;


public :
// CONSTRUCTOR / DESTRUCTOR
//

	GameModel();

	~GameModel ();


// METHODS

    void nextStep();

    void newGame ();
    
    bool loadGame();

    void saveGame ();

    void play ();

    void nextLevel ();

    void newLevel ();

    void destructLevel();



// ACCESSOR METHODS

    Player* getPlayer() const;
    Level* getLevel() const;
    Shop* getShop() const;
    Settings* getSettings() const;



};

#endif // GAMEMODEL_H
