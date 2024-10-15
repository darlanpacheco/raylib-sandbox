#include "static_texture.h"
#include "cstdio"
#include "raylib.h"
#include "stdio.h"
#include "stdlib.h"

StaticTexture::StaticTexture(const char *sprite, const char *sprite_hover) {
  this->sprite = sprite;
  this->sprite_hover = sprite_hover;
  this->rect = {0, 0, 0, 0};
  this->texture = LoadTexture(sprite);
}

void StaticTexture::draw(Vector2 position) {
  this->rect = {position.x, position.y, (float)texture.width,
                (float)texture.height};
  Rectangle source = {0, 0, 64, 16};
  if (CheckCollisionPointRec(GetMousePosition(), rect)) {
    source = {64, 0, 64, 16};
  }
  DrawTextureRec(texture, source, position, WHITE);
}

void StaticTexture::unload() { UnloadTexture(texture); }
