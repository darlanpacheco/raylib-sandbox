#ifndef CLASSES_H
#define CLASSES_H

#include "./raylib.h"
#include "./types.h"
#include "functional"
#include "iostream"

class Player {
public:
  Texture2D texture;
  Rectangle source;
  Vector2 position;
  Vector2 render_position;
  u8 speed;

  Player(Texture2D texture, u8 speed, Vector2 position = Vector2{0, 0});

  void draw();
  void move();
  void unload();
};

class Button {
public:
  std::string text;
  u8 font_size;
  u8 text_size;
  Vector2 position;
  Rectangle rect;

  Button(std::string text, Vector2 position = Vector2{0, 0});

  void draw();
  bool hover();
  void click(std::function<void()> func);
};

class CenteredButton {
public:
  std::string text;
  u8 font_size;
  u8 text_size;
  Vector2 position;
  Rectangle rect;

  CenteredButton(std::string text, Vector2 position = Vector2{0, 0});

  void draw();
  bool hover();
  void click(std::function<void()> func);
};

class Icon {
public:
  Texture2D texture;
  Vector2 position;
  Rectangle rect;

  Icon(Vector2 position = Vector2{0, 0});

  void draw();
  void unload();
};

class Tilemap {
public:
  Texture2D texture;
  Vector2 position;
  std::vector<std::vector<Vector2>> map;
  u8 sprite_size;

  Tilemap(Texture2D texture, std::vector<std::vector<Vector2>> map,
          u8 sprite_size, Vector2 position);

  void draw();
  void unload();
};
#endif
