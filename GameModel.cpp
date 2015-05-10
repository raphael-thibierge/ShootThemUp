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

    
    // loading best scores
    loadBestScore();

    
    
}

GameModel::~GameModel()
{
    //cout << "\n=====================" << endl;
    //cout << "DESTRUCTION DE GAMEMODEL" << endl;
    
    // save best scores
    saveBestScores();
    
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
            if (_level->loose()){
                tryAddBestScore(_player->getScore());
                endCurrentGame();
            }
            
            // if the player win, he plays the next level
            else if (_level->win())
                destructLevel();
        }
    }
}

void GameModel::newGame ()
{ // crate and prepare a new game
    _player = new Player();
    _player->resetPosition();
    _player->setScore(0);
    _shop = new Shop(_player);
}

bool GameModel::loadGame ()
{
    // chargement d'une partie depuis un fichier
    
    fstream gameFile;
    gameFile.open("GameFile.txt", ios::in);
    string line;
    
    _player = new Player;
    _shop = new Shop(_player);
    
    // SETTINGS
    // difficulty
    getline(gameFile, line);
    unsigned int value = atoi(&line[0]);
    _settings->setDifficulty(value);
    
    //nbLifeInitial
    getline(gameFile, line);
    _settings->setNbLife(atoi(&line[0]));
    
    //_langauge
    getline(gameFile, line);
    _settings->getLanguage()->change(line);
    
    //PLAYER
    //_bulletType
    getline(gameFile, line);
    _player->setBulletType(atoi(&line[0]));
    
    // _money
    getline(gameFile, line);
    _player->setMoney(atoi(&line[0]));
    
    // _level
    getline(gameFile, line);
    _player->setLevel(atoi(&line[0]));
    
    // shield
    getline(gameFile, line);
    _player->setShield(atoi(&line[0]));
    
    // _bombNumber
    getline(gameFile, line);
    _player->setBombNumber(atoi(&line[0]));
    
    gameFile.close();
    return true;
}

void GameModel::saveGame ()
{ // save settings and player's attributes
   
    fstream gameFile;
    
    
    // open or create gamefile
    gameFile.open("GameFile.txt", ios::out);

    // SETTINGS
    // _difficulty
    gameFile << *_settings->getDifficulty() << "\n";
    
    // _nbLifeInitial
    gameFile << *_settings->getNbLife() << "\n";

    //_language
    gameFile << _settings->getLanguage()->getLanguage() << "\n";
    
    // PLAYER
    //_bulletType
    gameFile << _player->getBulletType() << "\n";
    
    //_money
    gameFile << _player->getMoney() << "\n";
    
    //_level
    gameFile << _player->getLevel() << "\n";
    
    //_shild
    gameFile << _player->getShield() << "\n";
    
    //_bombNumber
    gameFile << _player->getBombNumber() << "\n";

}

void GameModel::loadBestScore()
{
    fstream scoreFile(BEST_SCORE_FILE, ios::in);
    // cpt used to know if best scores's number is less than const BEST_SCORE_NB
    int cpt = 0;
    if (scoreFile)
    {
        string scoreLine ;
        
        // load all score values from the file in _bestScores vector
        while (getline(scoreFile, scoreLine)) {
            _bestScores.push_back(atoi(&scoreLine[0]));
            cpt++;
        }
        scoreFile.close();
    }
    
    _bestScores.resize(BEST_SCORE_NB);
    // if there is less best score than BEST_SCORE_NB
    while (cpt < BEST_SCORE_NB) {
        // rest of vector is init with 0
        _bestScores[cpt]=0;
        cpt++;
    }
    
    
}

void GameModel::saveBestScores()
{ // save values from _bestScores in a file
    
    fstream scoreFile ;
    // open or create a best score file
    scoreFile.open(BEST_SCORE_FILE, ios::out);
    
    // save all score values
    for (auto score : _bestScores){
        scoreFile << score << "\n";
    }
    
    scoreFile.close();
}

bool GameModel::tryAddBestScore(const unsigned int score){
    // return true if the score is a best score
    
    // to know if score is a best score
    bool best = false ;
    
    int cpt = 0;
    
    // for all values in _bestScores vector
    while (!best && cpt < _bestScores.size())
    {
        // if score is bigger or equal than value
        best = score >= _bestScores[cpt]  ;
        
        if (!best)
            cpt++;
        
        // if it is, and different of value, score is insert in vector
        // without ducplicate value
        else if (_bestScores[cpt] != score) {
            _bestScores.insert(_bestScores.begin()+cpt, score);
        }
    }

    _bestScores.resize(BEST_SCORE_NB);
    
    return best;
}


void GameModel::play ()
{
    // game start from the main menu
    newLevel();
    // set the initilal life number before to begin the game
    _player->addLife(*_settings->getNbLife());
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
    _player->setNbLife(0);
    _player->setScore(0);    
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

vector<unsigned int> * GameModel::getBestScores()
{
    return &_bestScores;
}