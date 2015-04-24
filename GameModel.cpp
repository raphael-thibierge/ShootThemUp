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

    _height = 500;
    _width = 200;
    _gameLevel = 0;
    _settings = new Settings;
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
    _player = new Player();
    _player->resetPosition();
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


void GameModel::play ()
{
    // game start from the main menu
    newLevel();
    _player->setNbLife(*_settings->getNbLife());
}



void GameModel::newLevel ()
{
    if (_level != nullptr)
        destructLevel();
    _level = new Level(_player, _settings->getDifficulty());
    _gameLevel++;
    _player->resetPosition();
}


void GameModel::destructLevel()
{
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
