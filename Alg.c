#include "Var_str.h"

#define INTMAX 2147483647

extern int width, height;
extern int numObstacles;
#define MAP_HEIGHT 1000
#define MAP_WIDTH 1000

Cell map[MAP_HEIGHT][MAP_WIDTH];
Cell start, end;

void initializeMap();
void setObstacles();
Cell *findLowestFNode(Stack *openList);
int heuristic(Cell *a, Cell *b);
void aStarSearch(Cell start, Cell end);
void readMapConfig(MapConfig *config);

int main2() {
  MapConfig config;
  readMapConfig(&config);

  Cell start = {config.start.x, config.start.y};
  Cell end = {config.end.x, config.end.y};

  initializeMap();
  setObstacles();
  aStarSearch(start, end);

  return 0;
}

void initializeMap() {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      map[i][j].x = j;
      map[i][j].y = i;
      map[i][j].walkable = 1;
      map[i][j].parent = NULL;
      map[i][j].g = map[i][j].h = map[i][j].f = 0;
    }
  }
}

void setObstacles() {
  const char *filename = "map.txt";
  FILE *file = fopen(filename, "r");
  if (!file) {
    perror("Failed to open file");
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

    for (int i = y1; i <= y2; i++) {
      for (int j = x1; j <= x2; j++) {
        if (i >= 0 && i < height && j >= 0 && j < width) {
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
    Cell *current = &map[node->y][node->x];
    if (current->f < lowestF) {
      if (lowestFCell) {
        push(&temp, lowestFCell->x, lowestFCell->y);
      }
      lowestF = current->f;
      lowestFCell = current;
    } else {
      push(&temp, current->x, current->y);
    }
    free(node);
  }

  while (!isEmpty(&temp)) {
    node = pop(&temp);
    push(openList, node->x, node->y);
    free(node);
  }
  return lowestFCell;
}

void aStarSearch(Cell start, Cell end) {
  Stack openList, closedList;
  initStack(&openList);
  initStack(&closedList);

  push(&openList, start.x, start.y);
  map[start.y][start.x].g = 0;
  map[start.y][start.x].h = heuristic(&start, &end);
  map[start.y][start.x].f = map[start.y][start.x].h;

  while (!isEmpty(&openList)) {
    Cell *current = findLowestFNode(&openList);

    if (current->x == end.x && current->y == end.y) {
      printf("Path found!\n");
      return;
    }

    push(&closedList, current->x, current->y);

    for (int i = 0; i < 8; i++) {
      int newX = current->x + directions[i][0];
      int newY = current->y + directions[i][1];

      if (newX >= 0 && newX < MAP_WIDTH && newY >= 0 && newY < MAP_HEIGHT) {
        if (!map[newY][newX].walkable || isOnList(&closedList, newX, newY)) {
          continue;
        }

        int tentativeGScore = current->g + 1;
        int isNewNode = !isOnList(&openList, newX, newY);
        if (isNewNode || tentativeGScore < map[newY][newX].g) {
          map[newY][newX].g = tentativeGScore;
          map[newY][newX].h = heuristic(&map[newY][newX], &end);
          map[newY][newX].f = map[newY][newX].g + map[newY][newX].h;
          map[newY][newX].parent = current;

          if (isNewNode) {
            push(&openList, newX, newY);
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
  const char *filename2 = "map.txt";
  FILE *file2 = fopen(filename2, "r");
  if (!file2) {
    perror("Failed to open file");
    return;
  }

  fscanf(file1, "Width and height of the map: (%d, %d)\nDrone size: %d",
         &config->width, &config->height, &config->droneSize);
  fscanf(file2, "Start point A: (%d, %d) \nEnd point B: (%d, %d)",
         &config->start.x, &config->start.y, &config->end.x, &config->end.y);

  fclose(file1);
  fclose(file2);

  return;
}
