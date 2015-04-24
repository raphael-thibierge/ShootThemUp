
#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <string>
#include <time.h>

#include "Level.h"
#include "Setting.h"
#include "Shop.h"
#include "Language.h"

class GameModel
{

private:
    // screen resolution
    int _width;
    int _height;
    //--

    int _gameLevel;
    Player* _player;
    Level* _level;
    Shop* _shop;

    Settings* _settings;

public :
// CONSTRUCTOR AND DESTRUCTOR
//

	GameModel();

	~GameModel ();


// METHODS
//

    // heart of the programme
    void nextStep();

    // create a new game, player start from 0
    void newGame ();

    // load a game from a file to resume an old game
    bool loadGame();

    // save the current game
    void saveGame ();

    // play the game
    void play ();

    // create a new level
    void newLevel ();

    // destruct the current level
    void destructLevel();

    // manage the end of the current game
    void endCurrentGame();



// ACCESSOR METHODS
//

    Player* getPlayer();
    Level* getLevel();
    Shop* getShop();
    Settings* getSettings();



};

#endif // GAMEMODEL_H
