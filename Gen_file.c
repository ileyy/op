#include <time.h> // remove
#include "Var_str.h"

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point start;
    Point end;
} Obstacle;

int checkOverlap(Obstacle *obstacles, int count, Obstacle newObstacle);
void generateObstacles(FILE *file, int width, int height, int numObstacles);
void selectPoints(int width, int height);

int main() {
    int width, height, numObstacles;

    srand(time(NULL)); // remove

    printf("Enter the map width: ");
    scanf("%d", &width);
    printf("Enter the map height: ");
    scanf("%d", &height);
    printf("Enter the number of obstacles: ");
    scanf("%d", &numObstacles);

    FILE *file = fopen("map.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    generateObstacles(file, width, height, numObstacles);
    fclose(file);

    selectPoints(width, height);

    return 0;
}

int checkOverlap(Obstacle *obstacles, int count, Obstacle newObstacle) {
    for (int i = 0; i < count; i++) {
        if ((newObstacle.start.x <= obstacles[i].end.x && newObstacle.end.x >= obstacles[i].start.x) &&
            (newObstacle.start.y <= obstacles[i].end.y && newObstacle.end.y >= obstacles[i].start.y)) {
            return 1;
        }
    }
    return 0;
}

void generateObstacles(FILE *file, int width, int height, int numObstacles) {
    Obstacle *obstacles = (Obstacle*)malloc(numObstacles * sizeof(Obstacle));
    if (obstacles == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    int count = 0;
    while (count < numObstacles) {
        Obstacle newObstacle = {
            {rand() % width, rand() % height},
            {rand() % width, rand() % height}
        };
        if (!checkOverlap(obstacles, count, newObstacle) && newObstacle.start.x != newObstacle.end.x && newObstacle.start.y != newObstacle.end.y) {
            obstacles[count++] = newObstacle;
            fprintf(file, "Obstacle %d: Start (%d, %d) End (%d, %d)\n", count, newObstacle.start.x, newObstacle.start.y, newObstacle.end.x, newObstacle.end.y);
        }
    }
    free(obstacles);
}

void selectPoints(int width, int height) {
    printf("Select points A and B within the map dimensions of %d by %d.\n", width, height);
}

