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
