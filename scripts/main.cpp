#include "raylib.h"

void main_menu();
void main_map();

int scene = 0;

int main() {
  InitWindow(480, 270, "Raylib");
  SetWindowState(FLAG_WINDOW_RESIZABLE);
  SetTargetFPS(75);

  if (scene == 0) {
    main_menu();
  } else if (scene == 1) {
    main_map();
  }

  return 0;
}
