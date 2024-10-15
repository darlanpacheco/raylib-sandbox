#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

class Player {
public:
  Texture2D texture;

  Vector2 position;
  float timer;
  int speed;

  const char *animation;
  float animation_speed;
  int animation_size;
  int current_sprite;

  Player(Vector2 position, int speed);

  void play_animation(const char *sprite_path, int animation_speed,
                      int animation_size);
  void draw();
  void movement();
  void status();
  void unload();
};

#endif
