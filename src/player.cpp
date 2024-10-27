#include "../include/classes.h"
#include "../include/globals.h"
#include "../include/raylib.h"
#include "../include/types.h"
#include "iostream"

Player::Player(Texture2D texture, u8 speed, Vector2 position) {
  this->texture = texture;
  this->position = position;
  this->speed = speed;
}

void Player::draw() {
  this->render_position = {position.x - (float)texture.width / 2,
                           position.y - (float)texture.height / 2};
  DrawTexture(texture, render_position.x, render_position.y, WHITE);
}

void Player::move() {
  if (!game_paused) {
    if (IsKeyDown(KEY_D)) {
      position.x += speed * GetFrameTime();
    }
    if (IsKeyDown(KEY_A)) {
      position.x -= speed * GetFrameTime();
    }
    if (IsKeyDown(KEY_W)) {
      position.y -= speed * GetFrameTime();
    }
    if (IsKeyDown(KEY_S)) {
      position.y += speed * GetFrameTime();
    }
  }
}

void Player::unload() { UnloadTexture(texture); }
