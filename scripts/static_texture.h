#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

class StaticTexture {
public:
  Texture2D texture;
  Vector2 position;
  Rectangle rect;
  const char *sprite;
  const char *sprite_hover;

  StaticTexture(const char *sprite, const char *sprite_hover);

  void draw(Vector2 position);
  void unload();
};

#endif
