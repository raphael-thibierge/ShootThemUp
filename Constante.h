#ifndef CONSTANTE_H_INCLUDED
#define CONSTANTE_H_INCLUDED
#include "iostream"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ResourcePath.hpp"
// ======== PLAYER ============
const int PLAYER_LIFE_LEVEL = 300;
const int PLAYER_NB_LIFE = 3;
const int PLAYER_WIDTH = 89;
const int PLAYER_HEIGHT = 168;
const int PLAYER_SPEED = 10;

// ======== LEVEL ============
const unsigned int LEVEL_DIFFICULTY = 2;
const unsigned int LEVEL_NB_ENEMIES = 20;

// ======== SCREEN ============
const int SCREEN_HEIGHT = 1000;
const int SCREEN_WIDTH = 780;

// ======== BEST SCORES ============
const int BEST_SCORE_NB = 5;
const std::string BEST_SCORE_FILE = resourcePath() + "bestScoreFile.txt";

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
const int ENEMY_WIDTH[3] = { 155, 76, 87 };
const int ENEMY_HEIGHT[3] = { 157, 134, 138 };
const int ENEMY_LIFE_LEVEL[3] = { 50, 100, 200 };
const int ENEMY_SPEED[3] = { 4, 8, 6 };
const int ENEMY_TYPE[3] = {10, 11, 12};
const int ENEMY_NB_LIFE = 1 ;

// ======== BOSS ============
const unsigned int BOSS_TYPE = 25;
const unsigned int BOSS_LEVEL = 1;
const float BOSS_INITIAL_X = SCREEN_WIDTH / 2;
const float BOSS_INITIAL_Y = 50;
const float BOSS_HEIGHT = 135;
const float BOSS_WIDTH = 90;
const unsigned int BOSS_LIFELEVEL = 1000;
const float BOSS_SPEED = 5;
const unsigned int BOSS_NBLIFE = 1;
const unsigned int BOSS_BULLET_TYPE = 3;


// ======== BULLETS ============
const int BULLET_DAMAGE[5] = { 50, 100, 200, 300, 500 };
const int BULLET_SPEED[5] = { 8, 8, 8, 8, 8};
const int BULLET_PRICE[5] = { 0, 100, 200, 350, 500 };
const int BULLET_WIDTH[5] = { 30, 30, 30, 30, 30};
const int BULLET_HEIGHT[5] = { 25, 25, 25, 25, 25};



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
const std::string IMAGE_BACKGROUD_MAIN_MENU = "Vache.jpg";
const std::string IMAGE_BACKGROUD_GAME = "paille.png";
const int IMAGE_BACKGROUD_GAME_SIZE_X = 1000;
const int IMAGE_BACKGROUD_GAME_SIZE_Y = 1000;
const int IMAGE_BACKGROUND_SPEED = 1;
const std::string IMAGE_BACKGROUD_BESTSCORES = "Vache.jpg";
const std::string IMAGE_BACKGROUD_SHOP = "vache.jpg";
const std::string IMAGE_BACKGROUD_SETTINGS = "Vache.jpg";

const std::string IMAGE_BUTTONS = "button.png";
const std::string IMAGE_BUTTONS_ACTIVE = "buttonActive.png";
const std::string IMAGE_PLAYER_SHIP = "perso_principal.png";
const std::string IMAGE_BOSS_SHIP = "tracteur.png";
const std::string IMAGE_ENEMY_SHIP[3] = {"chicken.png" , "mouton.png", "cochon.png" };
const std::string IMAGE_BULLET[3] = {"potato.png", "potato2.png", "potato3.png" };
const std::string IMAGE_NEXT_LEVEL = "nextLevel.png";
const std::string IMAGE_YOU_LOOSE = "youloose.png";
const std::string IMAGE_HEART = "heart.png";
const std::string IMAGE_BOMB = "bomb.png";


// ======== BUTTONS ============
const int BUTTON_WIDTH = 248;
const int BUTTON_HEIGHT = 68;

const int MENUVIEW_BUTTON_POSITION_X = (SCREEN_WIDTH - BUTTON_WIDTH )/ 2;
const int BUTTON_NEWGAME_POSITION_Y = 200;
const int BUTTON_LOADGAME_POSITION_Y = 300;
const int BUTTON_SETTINGS_POSITION_Y = 400;
const int BUTTON_BESTSCORES_POSITION_Y = 500;
const int BUTTON_QUIT_POSITION_Y = 600;
const int BUTTON_PLAY_POSITION_Y = 200;
const int BUTTON_SHOP_POSITION_Y = 300;

const int BUTTON_SPRITE_X = 0;
const int BUTTON_SPRITE_Y = 0;
const int BUTTON_SPRITE_ACTIVE_X = 150;
const int BUTTON_SPRITE_ACTIVE_Y = 0;

const int TEXT_SIZE = 22;


// ======== GAME VIEW ============
const int GAMEVIEW_HEART_SIZE = 48;
const int GAMEVIEW_HEART_X = 10;
const int GAMEVIEW_HEART_Y = 10;
const int GAMEVIEW_BOMB_SIZE = 48;
const int GAMEVIEW_BOMB_X = 10;
const int GAMEVIEW_BOMB_Y = 70;


const int GAMEVIEW_LABEL_SCORE_X = SCREEN_WIDTH - 200;
const int GAMEVIEW_LABEL_SCORE_Y = 10;
const int GAMEVIEW_LABEL_LIFE_X = 10;
const int GAMEVIEW_LABEL_LIFE_Y = GAMEVIEW_HEART_Y + GAMEVIEW_HEART_SIZE + 60 ;
const int GAMEVIEW_LABEL_BOMB_X = 10;
const int GAMEVIEW_LABEL_BOMB_Y = 70;

// ======== SETTINGS VIEW ============

const int SETTINGSVIEW_TEXT_COLONNE_X = 10;

const int SETTINGSVIEW_TITLE_X = (SCREEN_WIDTH - BUTTON_WIDTH) / 2;
const int SETTINGSVIEW_TITLE_Y = 100;
const int SETTINGSVIEW_LANGUAGE_Y = 250;
const int SETTINGSVIEW_NBLIFE_Y = 350;
const int SETTINGSVIEW_DIFFICULTY_Y = 450;

const int SETTINGSVIEW_FRENCH_X = 250;
const int SETTINGSVIEW_FRENCH_Y = SETTINGSVIEW_LANGUAGE_Y;
const int SETTINGSVIEW_ENGLISH_X = SETTINGSVIEW_FRENCH_X + BUTTON_WIDTH + 10;
const int SETTINGSVIEW_ENGLISH_Y = SETTINGSVIEW_LANGUAGE_Y;

const int SETTINGSVIEW_QUIT_X = (SCREEN_WIDTH - BUTTON_WIDTH) / 2;
const int SETTINGSVIEW_QUIT_Y = SCREEN_HEIGHT - 100 ;

const int SETTINGSVIEW_DIFFICULTY_1_X = 350;
const int SETTINGSVIEW_DIFFICULTY_1_Y = SETTINGSVIEW_DIFFICULTY_Y;
const int SETTINGSVIEW_DIFFICULTY_2_X = SETTINGSVIEW_DIFFICULTY_1_X + 80;
const int SETTINGSVIEW_DIFFICULTY_2_Y = SETTINGSVIEW_DIFFICULTY_Y;
const int SETTINGSVIEW_DIFFICULTY_3_X = SETTINGSVIEW_DIFFICULTY_2_X + 80;
const int SETTINGSVIEW_DIFFICULTY_3_Y = SETTINGSVIEW_DIFFICULTY_Y;

const int SETTINGSVIEW_NBLIFE_1_X = 350;
const int SETTINGSVIEW_NBLIFE_1_Y = SETTINGSVIEW_NBLIFE_Y;
const int SETTINGSVIEW_NBLIFE_2_X = SETTINGSVIEW_NBLIFE_1_X + 80;
const int SETTINGSVIEW_NBLIFE_2_Y = SETTINGSVIEW_NBLIFE_Y;
const int SETTINGSVIEW_NBLIFE_3_X = SETTINGSVIEW_NBLIFE_2_X + 80;
const int SETTINGSVIEW_NBLIFE_3_Y = SETTINGSVIEW_NBLIFE_Y;


// ======== SHOP VIEW ============

const int SHOPSVIEW_TITLE_X = (SCREEN_WIDTH - BUTTON_WIDTH) / 2;
const int SHOPSVIEW_TITLE_Y = 100;


const int SHOPVIEW_COLUMN_1 = 10;
const int SHOPVIEW_COLUMN_2 = SCREEN_WIDTH / 3 + 3;
const int SHOPVIEW_COLUMN_3 = 2*SCREEN_WIDTH/3 + 3;
const int SHOPVIEW_LINE_1 = 350;
const int SHOPVIEW_LINE_2 = 450;
const int SHOPVIEW_LINE_3 = 550;
const int SHOPVIEW_LINE_4 = 650;
const int SHOPVIEW_LINE_5 = 750;
const int SHOPVIEW_LINE_6 = SCREEN_HEIGHT - 100 ;


const int SHOPSVIEW_MAINSHOOT_Y = SHOPVIEW_LINE_1 - TEXT_SIZE - 5;
const int SHOPSVIEW_SHIP_Y = SHOPVIEW_LINE_2 - TEXT_SIZE - 5;
const int SHOPSVIEW_SHIELD_Y = SHOPVIEW_LINE_3 - TEXT_SIZE - 5;
const int SHOPSVIEW_BOMB_Y =  SHOPVIEW_LINE_4 + BUTTON_HEIGHT /2 - 10;
const int SHOPSVIEW_LIFE_Y =  SHOPVIEW_LINE_5 + BUTTON_HEIGHT /2 - 10;
const int SHOPSVIEW_MONEY_Y = SHOPSVIEW_TITLE_Y+80;


// ======== INTRODUCTION VIEW ============
const int INTROVIEW_TITLE_X = SCREEN_WIDTH/3;
const int INTROVIEW_TITLE_Y = SCREEN_HEIGHT/2;


// ======== GAME VIEW ============
const float TIME_GAME_TRANSITION = 2.0f ;
const float TIME_YOU_LOOSE_TRANSITION = 2.0f;
const float TIME_PLAYER_FIRE_RATE = 0.2f;
const float TIME_ENEMY_FIRE_RATE = 0.8f;
const float TIME_SPAWN_RATE =  0.4f;
const float TIME_INTRODUCTION = 2.0f;
const float TIME_BOSS_FIRE_RATE = 1.0f;
const float TIME_LIFE_TRANSITION = 2.0f;

// ======== BLAST ============
const float BLAST_DURATION = 0.2f;
const std::string IMAGE_BLAST[1] = { "explosion.png" };
const int BLAST_IMAGE_WIDTH = 200;
const int BLAST_IMAGE_HEIGHT = 600;
const int BLAST_SPRITE_WIDTH = 200;
const int BLAST_SPRITE_HEIGHT = 200;
const int BLAST_NBSPRITES = 3;
const int BLAST_SPRITES_X[3] = { 0, 200, 400 };
const int BLAST_SPRITES_Y[3] = { 0, 0, 0 };

// ======== SOUND ============
const std::string GAME_MUSIC = resourcePath() + "vavrek.com_journeys_end_1.0_inst.ogg";
const std::string SOUND_SHOT =  resourcePath() + "sf_laser_14.ogg";
const std::string SOUND_BLAST =  resourcePath() + "sf_canon_01.ogg";
#endif // CONSTANTE_H_INCLUDED
