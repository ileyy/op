#include "Var_str.h"
int width, height, numObstacles;

int checkOverlap(Obstacle *obstacles, int count, Obstacle newObstacle,
                 int droneSize);
void generateObstacles(FILE *file, int width, int height, int numObstacles,
                       int droneSize);
void selectPoints(int width, int height);
void selectStartEnd(FILE *file, Point A, Point B);

int main1() {
  int droneSize;
  Point A, B;

  random1();

  printf("Enter the map width and height: ");
  scanf("%d %d", &width, &height);
  printf("Enter the drone size (length of one side): ");
  scanf("%d", &droneSize);
  printf("Enter the number of obstacles: ");
  scanf("%d", &numObstacles);

  FILE *file = fopen("map.txt", "w");
  if (file == NULL) {
    printf("Error opening file.\n");
    return 1;
  }
  FILE *db = fopen("db.txt", "w");
  if (file == NULL) {
    printf("Error opening file.\n");
    return 1;
  }
  generateObstacles(file, width, height, numObstacles, droneSize);
  fclose(file);

  fprintf(db, "Width and height of the map: (%d, %d)\n", width, height);
  fprintf(db, "Drone size: %d\n", droneSize);
  selectPoints(width, height);
  selectStartEnd(db, A, B);
  fclose(db);

  return 0;
}

int checkOverlap(Obstacle *obstacles, int count, Obstacle newObstacle,
                 int droneSize) {
  for (int i = 0; i < count; i++) {
    if ((newObstacle.start.x <= obstacles[i].end.x + droneSize &&
         newObstacle.end.x + droneSize >= obstacles[i].start.x) &&
        (newObstacle.start.y <= obstacles[i].end.y + droneSize &&
         newObstacle.end.y + droneSize >= obstacles[i].start.y)) {
      return 1;
    }
  }
  return 0;
}

void generateObstacles(FILE *file, int width, int height, int numObstacles,
                       int droneSize) {
  Obstacle *obstacles = (Obstacle *)malloc(numObstacles * sizeof(Obstacle));
  if (obstacles == NULL) {
    printf("Memory allocation failed.\n");
    return;
  }

  int count = 0;
  while (count < numObstacles) {
    Obstacle newObstacle = {
        {rand() % (width - droneSize), rand() % (height - droneSize)},
        {rand() % (width - droneSize), rand() % (height - droneSize)}};
    if (!checkOverlap(obstacles, count, newObstacle, droneSize) &&
        newObstacle.start.x != newObstacle.end.x &&
        newObstacle.start.y != newObstacle.end.y) {
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

void selectStartEnd(FILE *file, Point A, Point B) {
  printf("Enter coordinates for start point A: ");
  scanf("%d %d", &A.x, &A.y);
  printf("Enter coordinates for end point B: ");
  scanf("%d %d", &B.x, &B.y);
  fprintf(file, "Start point A: (%d, %d) \nEnd point B: (%d, %d)", A.x, A.y,
          B.x, B.y);
}
