#include "../include/classes.h"
#include "../include/globals.h"
#include "../include/raylib.h"
#include "../include/types.h"
#include "iterator"

bool menu_opened;
bool options_menu_opened;
Color semi_transparent_black;
CenteredButton *initial_buttons_list[3];
CenteredButton *options_buttons_list[1];
Icon *icons_list[1];
Vector2 player_position;

void initial_menu() {
  initial_buttons_list[0]->position = {player_position.x,
                                       player_position.y + -24};
  initial_buttons_list[1]->position = {player_position.x,
                                       player_position.y + 0};
  initial_buttons_list[2]->position = {player_position.x,
                                       player_position.y + 24};

  initial_buttons_list[0]->click([]() { menu_opened = false; });
  initial_buttons_list[1]->click([]() { options_menu_opened = true; });
  initial_buttons_list[2]->click([]() {
    menu_opened = false;
    scene = Scene::MAIN_MENU;
  });

  for (u8 i = 0; i < std::size(initial_buttons_list); i++) {
    initial_buttons_list[i]->draw();
  }
}

void options_menu() {
  options_buttons_list[0]->position = {player_position.x,
                                       player_position.y + 24};
  icons_list[0]->position = {options_buttons_list[0]->rect.x,
                             options_buttons_list[0]->rect.y};

  options_buttons_list[0]->click([]() { options_menu_opened = false; });

  for (u8 i = 0; i < std::size(options_buttons_list); i++) {
    options_buttons_list[i]->draw();
    icons_list[0]->draw();
  }
}

void init_game_menu() {
  menu_opened = false;
  semi_transparent_black = {0, 0, 0, 125};

  initial_buttons_list[0] = new CenteredButton("RESUME");
  initial_buttons_list[1] = new CenteredButton("OPTIONS");
  initial_buttons_list[2] = new CenteredButton("BACK TO MENU");
  options_buttons_list[0] = new CenteredButton("BACK");
  icons_list[0] = new Icon();

  icons_list[0]->texture = LoadTexture("assets/fullscreen_icon.png");
}

void update_game_menu() {
  player_position = player->position;

  if (IsKeyPressed(KEY_ESCAPE) && !menu_opened) {
    menu_opened = true;
  } else if (IsKeyPressed(KEY_ESCAPE) && menu_opened) {
    menu_opened = false;
    options_menu_opened = false;
  }

  if (menu_opened) {
    game_paused = true;
    DrawRectangle(player_position.x - screen_size.x / 2,
                  player_position.y - screen_size.y / 2, screen_size.x,
                  screen_size.y, semi_transparent_black);
    if (options_menu_opened) {
      options_menu();
    } else {
      initial_menu();
    }
  } else {
    game_paused = false;
  }
}
