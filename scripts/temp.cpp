#include <cstdio>

double calc(int width, int height) {
  int width_ref = 480;
  int height_ref = 270;
  int size_ref = width_ref * height_ref;
  int new_size_ref = width * height;

  int output = new_size_ref / size_ref;
  return (float)output / 4;
}

int main() {
  printf("Output for 1920x1080: %.2f\n", calc(1920, 1080));
  printf("Output for 480x270: %.2f\n", calc(480, 270));
  printf("Output for 1280x720: %.2f\n", calc(1280, 720));
  printf("Output for 1024x768: %.2f\n", calc(1024, 768));

  return 0;
}
