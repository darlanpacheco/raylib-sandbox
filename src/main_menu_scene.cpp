#include "../include/classes.h"
#include "../include/globals.h"
#include "../include/raylib.h"
#include "../include/types.h"
#include "iostream"

Button *main_menu_buttons[3];
Texture2D background_texture;

void init_main_menu() {
  main_menu_buttons[0] = new Button("PLAY", {-game_size.x / 2 + 16, 24});
  main_menu_buttons[1] = new Button("OPTIONS", {-game_size.x / 2 + 16, 48});
  main_menu_buttons[2] = new Button("QUIT", {-game_size.x / 2 + 16, 72});

  background_texture = LoadTexture("assets/background.png");
}

void update_main_menu() {
  main_camera.target = {0, 0};

  main_menu_buttons[0]->click([]() { scene = Scene::MAIN_MAP; });
  main_menu_buttons[2]->click([]() { CloseWindow(); });

  BeginDrawing();
  {
    BeginMode2D(main_camera);
    {
      ClearBackground(BLACK);
      DrawTexture(background_texture, -game_size.x / 2, -game_size.y / 2,
                  WHITE);
      for (u8 i = 0; i < std::size(main_menu_buttons); i++) {
        main_menu_buttons[i]->draw();
      }
    }
    EndMode2D();
  }
  EndDrawing();
}

void unload_main_menu() { UnloadTexture(background_texture); }
