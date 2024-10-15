#include "player.h"
#include "cstdio"
#include "raylib.h"
#include "stdlib.h"

Player::Player(Vector2 position, int speed) {
  this->position = position;
  this->speed = speed;
  this->current_sprite = 0;
  this->timer = 500;
}

void Player::play_animation(const char *animation, int animation_speed,
                            int animation_size) {
  this->animation = animation;
  this->animation_speed = 1.0f / animation_speed;
  this->animation_size = animation_size;

  timer += GetFrameTime();
  if (timer >= this->animation_speed) {
    char new_animation[32];
    snprintf(new_animation, sizeof(new_animation), "%s%d%s", animation,
             current_sprite, ".png");
    printf("%s\n", new_animation);

    texture = LoadTexture(new_animation);

    this->status();
    if (current_sprite < animation_size - 1) {
      current_sprite += 1;
    } else {
      current_sprite = 0;
    }
    timer = 0;
  }
}

void Player::draw() { DrawTexture(texture, position.x, position.y, WHITE); }

void Player::movement() {
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

void Player::status() {
  printf("\nposition: %f, %f\nanimation_speed: %f\nanimation_size: %d\n",
         position.x, position.y, animation_speed, animation_size);
}

void Player::unload() { UnloadTexture(texture); }
