#include "GameModel.h"

using namespace std;

//
// CONSTRUCTOR AND DESTRUCTOR
//

GameModel::GameModel()
{
    //cout << "\n=====================" << endl;
    //cout << "CONSTRUCTOR GAMEMODEL" << endl;

    srand (time(NULL));
    
    // unused
   // _height = SCREEN_HEIGHT;
   // _width = SCREEN_WIDTH;
    
    // always init
    _gameLevel = 0;
    _settings = new Settings;
    
    // not init, because player can choose to load an old game
    _player = nullptr;
    _level = nullptr;

    
}

GameModel::~GameModel()
{
    //cout << "\n=====================" << endl;
    //cout << "DESTRUCTION DE GAMEMODEL" << endl;

    destructLevel();
    delete _player;
    delete _shop;
    delete _level;
    delete _settings;
}


//
// Methods
//

void GameModel::nextStep()
{
    // if a game is loaded
    if (_player != nullptr){

        // if there isn't any level and level upper than 0
        // --> there isn't any game loaded
        if(_level==nullptr && _gameLevel>0)
        {
            // creation of the next level
            newLevel();
        }

        // if there is a level
        // --> the player is playing
        if ( _level != nullptr)
        {
            // game constinue
            _level->runGame();

            // if the player loose, it's the end of the current game
            if (_level->loose())
                endCurrentGame();

            // if the player win, he plays the next level
            else if (_level->win())
                destructLevel();
        }
    }
}

void GameModel::newGame ()
{
    // Player choose to play a new game
    _player = new Player();
    _shop = new Shop(_player);
}



bool GameModel::loadGame ()
{
    // chargement d'une partie depuis un fichier
    return false;
}




void GameModel::saveGame ()
{
    // sauvegarde de l'ensemble de la partie.
    // a réaliser plus tard
}


void GameModel::saveBestScores()
{
    // open file
    ifstream file("bestScores.txt", ios::in);
    
}


void GameModel::play ()
{
    // game start from the main menu
    newLevel();
    // set the initilal life number before to begin the game
    _player->setNbLife(*_settings->getNbLife());
}



void GameModel::newLevel ()
{
    // destruction of level (even if there is no one)
    destructLevel();
    _level = new Level(_player, _settings->getDifficulty());
    // increment the level number
    _gameLevel++;
    // player's initial position
    _player->resetPosition();
}


void GameModel::destructLevel()
{
    // return null level
    if (_level != nullptr){
        delete _level;
        _level = nullptr;
    }
}

void GameModel::endCurrentGame(){
    destructLevel();
}


//
// ACCESSOR METHODS
//

Player* GameModel::getPlayer()
{
    return _player ;
}

Level* GameModel::getLevel()
{
    return _level;
}

Shop* GameModel::getShop()
{
    return _shop;
}

Settings* GameModel::getSettings()
{
    return _settings;
}
