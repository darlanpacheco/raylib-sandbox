#include "../include/classes.h"
#include "../include/globals.h"
#include "../include/raylib.h"
#include "../include/types.h"
#include "iostream"

Player *player;
Tilemap *tilemap;
Vector2 sprite_size;

void init_game_menu();
void update_game_menu();
void unload_game_menu();

void init_main_map() {
  player = new Player(LoadTexture("assets/player.png"), 50);
  tilemap = new Tilemap(LoadTexture("assets/tilemap.png"),
                        {{{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
                         {{0, 0}, {0, 1}, {1, 1}, {2, 1}, {0, 0}},
                         {{0, 0}, {0, 2}, {1, 2}, {2, 2}, {0, 0}},
                         {{0, 0}, {0, 3}, {1, 3}, {2, 3}, {0, 0}},
                         {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}}},
                        16, {0, 0});

  init_game_menu();
}

void update_main_map() {
  main_camera.target = player->position;

  BeginDrawing();
  {
    BeginMode2D(main_camera);
    {
      ClearBackground(BLACK);
      tilemap->draw();
      player->draw();
      player->move();
      update_game_menu();
    }
    EndMode2D();
  }
  EndDrawing();
}

void unload_main_map() {
  player->unload();
  tilemap->unload();
}
