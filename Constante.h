#ifndef CONSTANTE_H_INCLUDED
#define CONSTANTE_H_INCLUDED
#include "iostream"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

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
const int ENEMY_LIFE_LEVEL[3] = { 100, 100, 100 };
const int ENEMY_SPEED[3] = { 2, 4, 3 };
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
const int BULLET_SPEED[5] = { 8, 4, 4, 4, 6};
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
const std::string IMAGE_NEXT_LEVEL = "./images/nextLevel.png";
const std::string IMAGE_YOU_LOOSE = "./images/youloose.jpg";

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

// ======== SETTINGS VIEW ============

const int SETTINGSVIEW_TITLE_X = (SCREEN_WIDTH - BUTTON_WIDTH) / 2;
const int SETTINGSVIEW_TITLE_Y = 100;
const int SETTINGSVIEW_LANGUAGE_X = 100;
const int SETTINGSVIEW_LANGUAGE_Y = 250;
const int SETTINGSVIEW_NBLIFE_X = SETTINGSVIEW_LANGUAGE_X;
const int SETTINGSVIEW_NBLIFE_Y = 350;
const int SETTINGSVIEW_DIFFICULTY_X = SETTINGSVIEW_LANGUAGE_X;
const int SETTINGSVIEW_DIFFICULTY_Y = 450;

const int SETTINGSVIEW_FRENCH_X = 400;
const int SETTINGSVIEW_FRENCH_Y = SETTINGSVIEW_LANGUAGE_Y;
const int SETTINGSVIEW_ENGLISH_X = SETTINGSVIEW_FRENCH_X + BUTTON_WIDTH + 50;
const int SETTINGSVIEW_ENGLISH_Y = SETTINGSVIEW_LANGUAGE_Y;

const int SETTINGSVIEW_QUIT_X = (SCREEN_WIDTH - BUTTON_WIDTH) / 2;
const int SETTINGSVIEW_QUIT_Y = SCREEN_HEIGHT - 100 ;

const int SETTINGSVIEW_DIFFICULTY_1_X = 400;
const int SETTINGSVIEW_DIFFICULTY_1_Y = SETTINGSVIEW_DIFFICULTY_Y;
const int SETTINGSVIEW_DIFFICULTY_2_X = 550;
const int SETTINGSVIEW_DIFFICULTY_2_Y = SETTINGSVIEW_DIFFICULTY_Y;
const int SETTINGSVIEW_DIFFICULTY_3_X = 700;
const int SETTINGSVIEW_DIFFICULTY_3_Y = SETTINGSVIEW_DIFFICULTY_Y;

// ======== SHOP VIEW ============

const int SHOPSVIEW_TITLE_X = (SCREEN_WIDTH - BUTTON_WIDTH) / 2;
const int SHOPSVIEW_TITLE_Y = 100;

const int SHOPSVIEW_MAINSHOOT_X = 10;
const int SHOPSVIEW_MAINSHOOT_Y = 250;

const int SHOPSVIEW_MAINSHOOT2_X = SHOPSVIEW_MAINSHOOT_X;
const int SHOPSVIEW_MAINSHOOT2_Y = SHOPSVIEW_MAINSHOOT_Y+50;
const int SHOPSVIEW_MAINSHOOT3_X = SHOPSVIEW_MAINSHOOT2_X + BUTTON_WIDTH + 50;
const int SHOPSVIEW_MAINSHOOT3_Y = SHOPSVIEW_MAINSHOOT2_Y;
const int SHOPSVIEW_MAINSHOOT4_X = SHOPSVIEW_MAINSHOOT3_X + BUTTON_WIDTH + 50;
const int SHOPSVIEW_MAINSHOOT4_Y = SHOPSVIEW_MAINSHOOT2_Y;
const int SHOPSVIEW_MAINSHOOT5_X = SHOPSVIEW_MAINSHOOT4_X + BUTTON_WIDTH + 50;
const int SHOPSVIEW_MAINSHOOT5_Y = SHOPSVIEW_MAINSHOOT2_Y;

const int SHOPSVIEW_SHIP_X = 10;
const int SHOPSVIEW_SHIP_Y = SHOPSVIEW_MAINSHOOT2_Y+100;

const int SHOPSVIEW_SHIP2_X = SHOPSVIEW_SHIP_X;
const int SHOPSVIEW_SHIP2_Y = SHOPSVIEW_SHIP_Y+50;
const int SHOPSVIEW_SHIP3_X = SHOPSVIEW_SHIP2_X + BUTTON_WIDTH + 100;
const int SHOPSVIEW_SHIP3_Y = SHOPSVIEW_SHIP2_Y;
const int SHOPSVIEW_SHIP4_X = SHOPSVIEW_SHIP3_X + BUTTON_WIDTH + 100;
const int SHOPSVIEW_SHIP4_Y = SHOPSVIEW_SHIP2_Y;

const int SHOPSVIEW_SHIELD_X = 10;
const int SHOPSVIEW_SHIELD_Y = SHOPSVIEW_SHIP2_Y +100;

const int SHOPSVIEW_SHIELD1_X = SHOPSVIEW_SHIELD_X;
const int SHOPSVIEW_SHIELD1_Y = SHOPSVIEW_SHIELD_Y+50;
const int SHOPSVIEW_SHIELD2_X = SHOPSVIEW_SHIELD1_X + BUTTON_WIDTH + 100;
const int SHOPSVIEW_SHIELD2_Y = SHOPSVIEW_SHIELD1_Y;
const int SHOPSVIEW_SHIELD3_X = SHOPSVIEW_SHIELD2_X + BUTTON_WIDTH + 100;
const int SHOPSVIEW_SHIELD3_Y = SHOPSVIEW_SHIELD1_Y;

const int SHOPSVIEW_BOMB_X = 10;
const int SHOPSVIEW_BOMB_Y = SHOPSVIEW_SHIELD1_Y +110;
const int SHOPSVIEW_BOMBBUY_X = 400;
const int SHOPSVIEW_BOMBBUY_Y = SHOPSVIEW_BOMB_Y;

const int SHOPSVIEW_LIFE_X = 10;
const int SHOPSVIEW_LIFE_Y = SHOPSVIEW_BOMBBUY_Y +100;
const int SHOPSVIEW_LIFEBUY_X = 400;
const int SHOPSVIEW_LIFEBUY_Y = SHOPSVIEW_LIFE_Y;


const int SHOPSVIEW_QUIT_X = (SCREEN_WIDTH - BUTTON_WIDTH) / 2;
const int SHOPSVIEW_QUIT_Y = SCREEN_HEIGHT - 100 ;

// ======== GAME VIEW ============
const float TIME_GAME_TRANSITION = 2.0f ;
const float TIME_YOU_LOOSE_TRANSITION = 3.0f;
const float TIME_PLAYER_FIRE_RATE = 0.2f;
const float TIME_ENEMY_FIRE_RATE = 0.5f;
const float TIME_SPAWN_RATE =  0.4f;


#endif // CONSTANTE_H_INCLUDED
