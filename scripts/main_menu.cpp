#include "raylib.h"
#include "static_texture.h"

Camera2D main_menu_camera;
Texture2D button;
Texture2D button_hover;

void main_menu() {
  button = LoadTexture("assets/button.png");

  StaticTexture a("assets/button.png", "assets/button.png");

  while (!WindowShouldClose()) {
    Vector2 screen_middle = {(float)GetScreenWidth() / 2,
                             (float)GetScreenHeight() / 2};
    main_menu_camera.zoom = (float)GetScreenHeight() / 270;
    main_menu_camera.target = screen_middle;
    main_menu_camera.offset = screen_middle;

    BeginDrawing();
    BeginMode2D(main_menu_camera);
    ClearBackground(ORANGE);
    a.draw({screen_middle.x - (int)(button.width / 2),
            screen_middle.y - (int)(button.height / 2)});
    a.draw({screen_middle.x - (int)(button.width / 2),
            screen_middle.y - (int)(button.height / 2) + 23});
    EndMode2D();
    EndDrawing();
  }

  a.unload();
  CloseWindow();
}
