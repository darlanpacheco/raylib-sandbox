#include "../include/classes.h"
#include "../include/globals.h"
#include "../include/raylib.h"
#include "../include/types.h"
#include "iostream"

Tilemap::Tilemap(Texture2D texture, std::vector<std::vector<Vector2>> map,
                 u8 sprite_size, Vector2 position) {
  this->texture = texture;
  this->map = map;
  this->sprite_size = sprite_size;
  this->position = position;
}

void Tilemap::draw() {
  if (map.empty() || map[0].empty()) {
    return;
  }

  u8 rows = map.size();
  u8 cols = map[0].size();

  for (u8 i = 0; i < rows; i++) {
    for (u8 j = 0; j < cols; j++) {
      DrawTextureRec(texture,
                     {map[i][j].x * sprite_size, map[i][j].y * sprite_size,
                      (float)sprite_size, (float)sprite_size},
                     {(float)j * sprite_size + position.x,
                      (float)i * sprite_size + position.y},
                     WHITE);
    }
  }
}

void Tilemap::unload() { UnloadTexture(texture); }
