#include "../include/classes.h"
#include "../include/globals.h"
#include "../include/raylib.h"
#include "../include/types.h"
#include "iostream"

Camera2D main_camera;
Vector2 game_size;
Vector2 screen_size;
Scene scene;
bool game_paused;

void init_main_menu();
void update_main_menu();
void unload_main_menu();

void init_main_map();
void update_main_map();
void unload_main_map();

void init_main();
void update_main();
void unload_main();

int main() {
  init_main();
  update_main();
  unload_main();

  return 0;
}

void init_main() {
  screen_size = {1920, 1080};

  game_size = {480, 270};
  scene = Scene::MAIN_MENU;

  InitWindow(screen_size.x, screen_size.y, "darlan's raylib");
  SetTargetFPS(360);
  SetExitKey(0);
  ToggleFullscreen();

  init_main_menu();
  init_main_map();
}

void update_main() {
  while (!WindowShouldClose()) {
    main_camera.zoom = screen_size.y / 270;
    main_camera.offset = {screen_size.x / 2, screen_size.y / 2};

    if (scene == Scene::MAIN_MENU) {
      update_main_menu();
    } else if (scene == Scene::MAIN_MAP) {
      update_main_map();
    }
  }
}

void unload_main() {
  unload_main_menu();
  unload_main_map();
  CloseWindow();
}
