#include "Var_str.h"

int width, height, numObstacles, droneSize;
Cell start, end;

int checkOverlap(Obstacle *obstacles, int count, Obstacle newObstacle, Cell A,
                 Cell B, int droneSize);
void generateObstacles(FILE *file, int width, int height, int numObstacles,
                       int droneSize, Cell A, Cell B);
void selectPoints(int width, int height);
void selectStartEnd(FILE *file, Cell *A, Cell *B);

int main1() {
  random1();

  printf("Enter the map width and height: ");
  scanf("%d %d", &width, &height);
  printf("Enter the drone size (length of one side): ");
  scanf("%d", &droneSize);
  printf("Enter the number of obstacles: ");
  scanf("%d", &numObstacles);

  selectPoints(width, height);

  FILE *db = fopen("db.txt", "w");
  if (db == NULL) {
    perror("Error opening db.txt");
    return 1;
  }
  selectStartEnd(db, &start, &end);

  FILE *map = fopen("map.txt", "w");
  if (map == NULL) {
    perror("Error opening map.txt");
    return 1;
  }

  generateObstacles(map, width, height, numObstacles, droneSize, start, end);
  fclose(map);

  fprintf(db, "Width and height of the map: (%d, %d)\n", width, height);
  fprintf(db, "Drone size: %d\n", droneSize);
  fclose(db);

  return 0;
}

int checkOverlap(Obstacle *obstacles, int count, Obstacle newObstacle, Cell A,
                 Cell B, int droneSize) {
  for (int i = 0; i < count; i++) {
    int buffer = droneSize;
    int left = obstacles[i].start.x - buffer;
    int right = obstacles[i].end.x + buffer;
    int top = obstacles[i].start.y - buffer;
    int bottom = obstacles[i].end.y + buffer;

    if ((newObstacle.start.x >= left && newObstacle.start.x <= right &&
         newObstacle.start.y >= top && newObstacle.start.y <= bottom) ||
        (newObstacle.end.x >= left && newObstacle.end.x <= right &&
         newObstacle.end.y >= top && newObstacle.end.y <= bottom)) {
      return 1;
    }
  }
  if ((newObstacle.start.x == A.x && newObstacle.start.y == A.y) ||
      (newObstacle.end.x == A.x && newObstacle.end.y == A.y) ||
      (newObstacle.start.x == B.x && newObstacle.start.y == B.y) ||
      (newObstacle.end.x == B.x && newObstacle.end.y == B.y)) {
    return 1;
  }
  return 0;
}

void generateObstacles(FILE *file, int width, int height, int numObstacles,
                       int droneSize, Cell A, Cell B) {
  Obstacle *obstacles = (Obstacle *)malloc(numObstacles * sizeof(Obstacle));
  if (obstacles == NULL) {
    printf("Memory allocation failed.\n");
    return;
  }

  int count = 0;
  while (count < numObstacles) {
    Point start = {rand() % (width - droneSize), rand() % (height - droneSize)};

    Point end;
    int obstacleType = rand() % 3;
    int valid = 0;
    while (!valid) {
      switch (obstacleType) {
        case 0:
          end.y = start.y;
          end.x = start.x + (rand() % (width - start.x) + 1);
          break;
        case 1:
          end.x = start.x;
          end.y = start.y + (rand() % (height - start.y) + 1);
          break;
        case 2: {
          int length = rand() % (width - start.x) + 1;
          length = length < (height - start.y) ? length : (height - start.y);
          end.x = start.x + length;
          end.y = start.y + length;
        } break;
      }
      if (end.x != start.x || end.y != start.y) {
        valid = 1;
      }
    }

    Obstacle newObstacle = {start, end};
    if (!checkOverlap(obstacles, count, newObstacle, A, B, droneSize)) {
      obstacles[count++] = newObstacle;
      fprintf(file, "Obstacle %d: Start (%d, %d), End (%d, %d)\n", count,
              newObstacle.start.x, newObstacle.start.y, newObstacle.end.x,
              newObstacle.end.y);
    }
  }
  free(obstacles);
}

void selectPoints(int width, int height) {
  printf("Select points A and B within the map dimensions of %d by %d.\n",
         width, height);
}

void selectStartEnd(FILE *file, Cell *A, Cell *B) {
  printf("Enter x coordinate for start point A: ");
  scanf("%d", &A->x);
  A->y = 0;
  printf("Enter x coordinate for end point B: ");
  scanf("%d", &B->x);
  B->y = height - 1;
  fprintf(file, "Start point A: (%d, %d) \nEnd point B: (%d, %d)", A->x, A->y,
          B->x, B->y);
}
