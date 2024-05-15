#ifndef VAR_STR_H
#define VAR_STR_H

#include <stdio.h>
#include <stdlib.h>
typedef struct Cell {
  int x, y;
  int f, g, h;
  int walkable;
  struct Cell *parent;
} Cell;

typedef struct Node {
  Cell *cell;
  struct Node *next;
} Node;

typedef struct {
  Node *top;
} Stack;

typedef struct {
  int x;
  int y;
} Point;

typedef struct {
  Point start;
  Point end;
} Obstacle;

typedef struct {
  int width;
  int height;
  int droneSize;
  Point start, end;
} MapConfig;

void push(Stack *s, Cell *cell);
Node *pop(Stack *s);
int isEmpty(Stack *s);
void initStack(Stack *s);
int isOnList(Stack *s, Cell *cell);
void random1();

#endif
