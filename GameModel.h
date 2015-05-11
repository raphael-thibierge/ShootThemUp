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
    // best scores
    std::vector<unsigned int> _bestScores;
    
    // levelnumber of the current level played
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
    
    // load from file the best scores
    void loadBestScore();
    
    // save the current best scores
    void saveBestScores();

    // check if score is a best score, and save it if it is one
    bool tryAddBestScore(const unsigned int score);
    
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
    std::vector<unsigned int>* getBestScores();



};

#endif // GAMEMODEL_H
