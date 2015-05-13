#ifndef CONSTANTE_H_INCLUDED
#define CONSTANTE_H_INCLUDED
#include "iostream"

// ======== PLAYER ============
const int PLAYER_LIFE_LEVEL = 300;
const int PLAYER_NB_LIFE = 3;
const int PLAYER_WIDTH = 10;
const int PLAYER_HEIGHT = 10;
const int PLAYER_SPEED = 5;

// ======== LEVEL ============
const unsigned int LEVEL_DIFFICULTY = 2;
const unsigned int LEVEL_NB_ENEMIES = 50;

// ======== SCREEN ============
const int SCREEN_HEIGHT=100;
const int SCREEN_WIDTH=50;

// ======== BEST SCORES ============
const int BEST_SCORE_NB = 5;
const std::string BEST_SCORE_FILE = "BestScoreFile.txt";

// ======== DIRECTIONS ============
const std::string PLAYER_DIRECTION = "NORTH";
const std::string ENEMIES_DIRECTION = "SOUTH";

const int MAX_DIFFICULTY = 3;

// ======== ENEMIES ============
const int ENEMY_WIDTH[3] = { 10, 10, 10 };
const int ENEMY_HEIGHT[3] = { 10, 10, 10 };
const int ENEMY_LIFE_LEVEL[3] = { 50, 50, 100 };
const int ENEMY_SPEED[3] = { 5, 15, 10 };
const int ENEMY_NB_LIFE = 1 ;



// ======== BOSS ============
//    Enemy (const unsigned int type, const unsigned int level, const float x, const float y, const float width, const float height, const unsigned int lifeLevel, const float speed, const unsigned int nbLife);


const unsigned int BOSS_TYPE = 20;
const unsigned int BOSS_LEVEL = 1;
const float BOSS_INITIAL_X = SCREEN_WIDTH / 2;
const float BOSS_INITIAL_Y = 50;
const float BOSS_HEIGHT = 50;
const float BOSS_WIDTH = 50;
const unsigned int BOSS_LIFELEVEL = 300;
const float BOSS_SPEED = 5;
const unsigned int BOSS_NBLIFE = 1;

// ======== BULLETS ============

const int BULLET_DAMAGE[5] = { 50, 100, 100, 150, 500 };
const int BULLET_SPEED[5] = { 5, 5, 10, 10, 15};
const int BULLET_PRICE[5] = { 0, 100, 200, 350, 500 };


// ======== SHIELDS ============
const int SHIELD_PRICE[4] = { 0, 100, 300, 500 };
const int SHIELD_LIFE[4] = { 0, 100, 200, 300 };

// ======== SHIPS ============
const int SHIP_PRICE[4] = { 0, 200, 500, 1000 };

// ======== BOMBS ============
const int BOMB_PRICE = 100;
// ======== LIFES ============
const int LIFE_PRICE = 250;

#endif // CONSTANTE_H_INCLUDED
