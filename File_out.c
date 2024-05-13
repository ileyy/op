#include <stdio.h>
#include "Var_str.h"

Cell map[20][20];
Cell start, end;

void printMap();

int main3() {
    printMap();
    return 0;
}

void printMap() {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (i == start.y && j == start.x) {
                printf("A ");
            } else if (i == end.y && j == end.x) {
                printf("B ");
            } else if (!map[i][j].walkable) {
                printf("O ");
            } else {
                Cell *current = &map[i][j];
                int isPath = 0;

                while (current->parent != NULL) {
                    if (current->parent->x == j && current->parent->y == i) {
                        printf("* ");
                        isPath = 1;
                        break;
                    }
                    current = current->parent;
                }

                if (!isPath) {
                    printf(". "); 
                }
            }
        }
        printf("\n");
    }
}
