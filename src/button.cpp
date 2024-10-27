#include "../include/classes.h"
#include "../include/globals.h"
#include "../include/raylib.h"
#include "../include/types.h"
#include "iostream"

Button::Button(std::string text, Vector2 position) {
  this->text = text;
  this->font_size = 5;
  this->position = position;
}

void Button::draw() {
  this->text_size = MeasureText(text.c_str(), font_size);
  this->rect = {position.x, position.y, (float)text_size, 9};

  if (hover()) {
    DrawText(text.c_str(), rect.x, rect.y, font_size, WHITE);
  } else {
    DrawText(text.c_str(), rect.x, rect.y, font_size, GRAY);
  }
}

bool Button::hover() {
  Vector2 mouse_world_position =
      GetScreenToWorld2D(GetMousePosition(), main_camera);

  if (CheckCollisionPointRec(mouse_world_position, rect)) {
    return true;
  } else {
    return false;
  }
}

void Button::click(std::function<void()> func) {
  if (hover() && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    func();
  }
}
