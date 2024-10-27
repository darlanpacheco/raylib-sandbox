#ifndef GLOBALS_H
#define GLOBALS_H

#include "./classes.h"
#include "./raylib.h"
#include "./types.h"
#include "functional"
#include "iostream"

enum Scene { MAIN_MENU, MAIN_MAP };

extern Player *player;
extern Camera2D main_camera;

extern Vector2 game_size;
extern Vector2 screen_size;
extern u16 resolution_height;
extern u16 resolution_height_list[5];
extern Vector2 aspect_ratio;
extern Vector2 aspect_ratio_list[3];

extern Scene scene;
extern bool game_paused;

#endif
