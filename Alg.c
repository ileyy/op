#include "Var_str.h"

#define INTMAX 2147483647

extern int width, height;
Cell map[1000][1000];
Cell start, end;

void initializeMap();
void setObstacles();
void aStarSearch(Cell start, Cell end);
void readMapConfig(MapConfig *config);

int main2() {
  MapConfig config;
  readMapConfig(&config);

  initializeMap();
  setObstacles();
  aStarSearch(start, end);

  return 0;
}

void initializeMap() {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      map[i][j] = (Cell){.x = j,
                         .y = i,
                         .walkable = 1,
                         .parent = NULL,
                         .g = 0,
                         .h = 0,
                         .f = 0};
    }
  }
}

void setObstacles() {
  const char *filename = "map.txt";
  FILE *file = fopen(filename, "r");
  if (!file) {
    perror("Failed to open file for obstacles");
    return;
  }

  int x1, y1, x2, y2;
  while (fscanf(file, "Obstacle %*d: Start (%d, %d), End (%d, %d)\n", &x1, &y1,
                &x2, &y2) == 4) {
    if (x1 > x2) {
      int temp = x1;
      x1 = x2;
      x2 = temp;
    }
    if (y1 > y2) {
      int temp = y1;
      y1 = y2;
      y2 = temp;
    }
    if (x2 - x1 == y2 - y1) {
      for (int i = y1; i <= y2 && i < height; i++) {
        for (int j = x1; j <= x2 && j < width; j++) {
          if (x2 - j == y2 - i) {
            map[i][j].walkable = 0;
          }
        }
      }
    } else {
      for (int i = y1; i <= y2 && i < height; i++) {
        for (int j = x1; j <= x2 && j < width; j++) {
          map[i][j].walkable = 0;
        }
      }
    }
  }
  fclose(file);
}

const int directions[8][2] = {{-1, 0},  {1, 0},  {0, -1}, {0, 1},
                              {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

int heuristic(Cell *a, Cell *b) { return abs(a->x - b->x) + abs(a->y - b->y); }

Cell *findLowestFNode(Stack *openList) {
  Stack temp;
  initStack(&temp);
  Node *node;
  Cell *lowestFCell = NULL;
  int lowestF = INTMAX;

  while (!isEmpty(openList)) {
    node = pop(openList);
    if (node == NULL) continue;

    Cell *current = node->cell;
    if (current && current->f < lowestF) {
      if (lowestFCell) {
        push(&temp, lowestFCell);
      }
      lowestF = current->f;
      lowestFCell = current;
    } else {
      push(&temp, current);
    }
    free(node);
  }

  while (!isEmpty(&temp)) {
    node = pop(&temp);
    if (node && node->cell) {
      push(openList, node->cell);
    }
    free(node);
  }

  return lowestFCell;
}

void aStarSearch(Cell start, Cell end) {
  Stack openList, closedList;
  initStack(&openList);
  initStack(&closedList);

  push(&openList, &start);
  start.g = 0;
  start.h = heuristic(&start, &end);
  start.f = start.h;

  while (!isEmpty(&openList)) {
    Cell *current = findLowestFNode(&openList);

    if (current->x == end.x && current->y == end.y) {
      printf("Path found!\n");
      return;
    }

    push(&closedList, current);

    for (int i = 0; i < 8; i++) {
      int newX = current->x + directions[i][0];
      int newY = current->y + directions[i][1];

      if (newX >= 0 && newX < width && newY >= 0 && newY < height) {
        if (!map[newY][newX].walkable ||
            isOnList(&closedList, &map[newY][newX])) {
          continue;
        }

        int tentativeGScore = current->g + 1;
        int isNewNode = !isOnList(&openList, &map[newY][newX]);
        if (isNewNode || tentativeGScore < map[newY][newX].g) {
          map[newY][newX].g = tentativeGScore;
          map[newY][newX].h = heuristic(&map[newY][newX], &end);
          map[newY][newX].f = map[newY][newX].g + map[newY][newX].h;
          map[newY][newX].parent = current;

          if (isNewNode) {
            push(&openList, &map[newY][newX]);
          }
        }
      }
    }
  }
  printf("No path found.\n");
}

void readMapConfig(MapConfig *config) {
  const char *filename1 = "db.txt";
  FILE *file1 = fopen(filename1, "r");
  if (!file1) {
    perror("Failed to open file");
    return;
  }
  fscanf(file1, "Width and height of the map: (%d, %d)\nDrone size: %d",
         &config->width, &config->height, &config->droneSize);
  fclose(file1);

  const char *filename2 = "map.txt";
  FILE *file2 = fopen(filename2, "r");
  if (!file2) {
    perror("Failed to open file");
    return;
  }
  fscanf(file2, "Start point A: (%d, %d) \nEnd point B: (%d, %d)",
         &config->start.x, &config->start.y, &config->end.x, &config->end.y);
  fclose(file2);
}
