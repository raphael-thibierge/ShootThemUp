#ifndef CONSTANTE_H_INCLUDED
#define CONSTANTE_H_INCLUDED
#include "iostream"

// ======== PLAYER ============
const int PLAYER_LIFE_LEVEL = 300;
const int PLAYER_NB_LIFE = 3;
const int PLAYER_WIDTH = 201;
const int PLAYER_HEIGHT = 179;
const int PLAYER_SPEED = 8;

// ======== LEVEL ============
const unsigned int LEVEL_DIFFICULTY = 2;
const unsigned int LEVEL_NB_ENEMIES = 20;

// ======== SCREEN ============
const int SCREEN_HEIGHT=1000;
const int SCREEN_WIDTH=780;

// ======== BEST SCORES ============
const int BEST_SCORE_NB = 5;
const std::string BEST_SCORE_FILE = "bestScoreFile.txt";

const int LABEL_BESTSCORES_POSITION_X = 200;
const int LABEL_BESTSCORES_POSITION_Y = 200;
const int LABEL_BESTSCORES_SPACE = 50;
const int LABEL_BESTSCORES_TITLE_POSITION_X = 100;
const int LABEL_BESTSCORES_TITLE_POSITION_Y = 100;
const int BUTTON_BESTSCORES_QUIT_POSITION_X = 200;
const int BUTTON_BESTSCORES_QUIT_POSITION_Y = 800;

// ======== DIRECTIONS ============
const std::string PLAYER_DIRECTION = "NORTH";
const std::string ENEMIES_DIRECTION = "SOUTH";

const int MAX_DIFFICULTY = 3;

// ======== ENEMIES ============
const int ENEMY_WIDTH[3] = { 115, 201, 278 };
const int ENEMY_HEIGHT[3] = { 142, 179, 155 };
const int ENEMY_LIFE_LEVEL[3] = { 50, 50, 100 };
const int ENEMY_SPEED[3] = { 2, 2, 3 };
const int ENEMY_TYPE[3] = {10, 11, 12};
const int ENEMY_NB_LIFE = 1 ;

// ======== BOSS ============
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
const int BULLET_SPEED[5] = { 4, 4, 4, 4, 6};
const int BULLET_PRICE[5] = { 0, 100, 200, 350, 500 };
const int BULLET_WIDTH[5] = { 56, 56, 56, 56, 56};
const int BULLET_HEIGHT[5] = { 20, 20, 20, 20, 20};



// ======== SHIELDS ============
const int SHIELD_PRICE[4] = { 0, 100, 300, 500 };
const int SHIELD_LIFE[4] = { 0, 100, 200, 300 };

// ======== SHIPS ============
const int SHIP_PRICE[4] = { 0, 200, 500, 1000 };

// ======== BOMBS ============
const int BOMB_PRICE = 100;

// ======== LIFES ============
const int LIFE_PRICE = 250;

// ======== IMAGES ============
const std::string IMAGE_BACKGROUD_MAIN_MENU = "./images/espace.jpg";
const std::string IMAGE_BACKGROUD_GAME = "./images/planet.png";
const int IMAGE_BACKGROUD_GAME_SIZE_X = 780;
const int IMAGE_BACKGROUD_GAME_SIZE_Y = 2340;
const int IMAGE_BACKGROUND_SPEED = 1;
const std::string IMAGE_BACKGROUD_BESTSCORES = "./images/espace.jpg";
const std::string IMAGE_BACKGROUD_SHOP = "./images/espace.jpg";
const std::string IMAGE_BACKGROUD_SETTINGS = "./images/espace.jpg";

const std::string IMAGE_BUTTONS = "./images/buttons.png";
const std::string IMAGE_PLAYER_SHIP = "./images/ennemy_1.png";
const std::string IMAGE_ENEMY_SHIP[3] = {"./images/ennemy_0.png" , "./images/ennemy_1.png", "./images/ennemy_2.png" };
const std::string IMAGE_BULLET_0 = "./images/shot.png";

// ======== BUTTONS ============
const int BUTTON_WIDTH = 150;
const int BUTTON_HEIGHT = 80;

const int BUTTON_SPRITE_X = 0;
const int BUTTON_SPRITE_Y = 0;
const int BUTTON_SPRITE_ACTIVE_X = 150;
const int BUTTON_SPRITE_ACTIVE_Y = 0;

const int BUTTON_NEWGAME_POSITION_X = 100;
const int BUTTON_NEWGAME_POSITION_Y = 100;

const int BUTTON_LOADGAME_POSITION_X = 100;
const int BUTTON_LOADGAME_POSITION_Y = 200;

const int BUTTON_SETTINGS_POSITION_X = 100;
const int BUTTON_SETTINGS_POSITION_Y = 300;

const int BUTTON_BESTSCORES_POSITION_X = 100;
const int BUTTON_BESTSCORES_POSITION_Y = 400;

const int BUTTON_QUIT_POSITION_X = 100;
const int BUTTON_QUIT_POSITION_Y = 500;

const int BUTTON_PLAY_POSITION_X = 100;
const int BUTTON_PLAY_POSITION_Y = 100;

const int BUTTON_SHOP_POSITION_X = 100;
const int BUTTON_SHOP_POSITION_Y = 200;

// ======== GAME VIEW ============

const int GAMEVIEW_LABEL_SCORE_X = 10;
const int GAMEVIEW_LABEL_SCORE_Y = 10;
const int GAMEVIEW_LABEL_LIFE_X = 10;
const int GAMEVIEW_LABEL_LIFE_Y = 40;
const int GAMEVIEW_LABEL_BOMB_X = 10;
const int GAMEVIEW_LABEL_BOMB_Y = 70;

#endif // CONSTANTE_H_INCLUDED
