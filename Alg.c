#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Var_str.h"

#define MAP_WIDTH 20
#define MAP_HEIGHT 20
Cell map[MAP_HEIGHT][MAP_WIDTH];

void initializeMap();
void setObstacles();
Cell *findLowestFNode(Stack *openList);
int heuristic(Cell *a, Cell *b);
void aStarSearch(Cell start, Cell end);

int main() {
    Cell start = {1, 1};
    Cell end = {18, 18};

    initializeMap();
    setObstacles();
    aStarSearch(start, end);

    return 0;
}

void initializeMap() {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            map[i][j].x = j;
            map[i][j].y = i;
            map[i][j].walkable = 1;
        }
    }
}

void setObstacles() {
    for (int i = 0; i < 5; i++) {
        int x = rand() % MAP_WIDTH;
        int y = rand() % MAP_HEIGHT;
        map[y][x].walkable = 0;
    }
}

const int directions[8][2] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1},
    {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
};

int heuristic(Cell *a, Cell *b) {
    return abs(a->x - b->x) + abs(a->y - b->y);
}

Cell *findLowestFNode(Stack *openList) {
    Stack temp;
    initStack(&temp);
    Node *node;
    Cell *lowestFCell = NULL;
    int lowestF = INT_MAX;

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
