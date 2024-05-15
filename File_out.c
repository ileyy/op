#include "Var_str.h"

extern int width, height;
extern Cell map[1000][1000];
extern Cell start, end;

void printMap();

int main3() {
  printf("Start: (%d, %d)\n", start.x, start.y);
  printf("End: (%d, %d)\n", end.x, end.y);

  printMap();
  return 0;
}

void drawLine(int x1, int y1, int x2, int y2) {
  int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
  int dy = -abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
  int err = dx + dy, e2;

  for (;;) {
    if (x1 >= 0 && x1 < width && y1 >= 0 && y1 < height) {
      map[y1][x1].walkable = 0;
    }
    if (x1 == x2 && y1 == y2) break;
    e2 = 2 * err;
    if (e2 >= dy) {
      err += dy;
      x1 += sx;
    }
    if (e2 <= dx) {
      err += dx;
      y1 += sy;
    }
  }
}

void printMap() {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (i == start.y && j == start.x) {
        printf("A ");
      } else if (i == end.y && j == end.x) {
        printf("B ");
      } else if (!map[j][i].walkable) {
        printf("O ");
      } else {
        printf(". ");
      }
    }
    printf("\n");
  }
}
