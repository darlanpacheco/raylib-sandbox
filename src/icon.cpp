#include "../include/classes.h"
#include "../include/globals.h"
#include "../include/raylib.h"
#include "../include/types.h"
#include "iostream"

Icon::Icon(Vector2 position) { this->position = position; }

void Icon::draw() { DrawTexture(texture, position.x - 16, position.y, WHITE); }
