#include "raylib.h"

Camera2D main_camera;
Texture2D player;

void main_map() {
  while (!WindowShouldClose()) {
    main_camera.zoom = (float)GetScreenHeight() / 270;
    BeginDrawing();
    BeginMode2D(main_camera);
    ClearBackground(ORANGE);
    DrawTexture(player, 0, 0, WHITE);
    EndMode2D();
    EndDrawing();
  }
  CloseWindow();
}
