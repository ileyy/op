#ifndef VAR_STR_H
#define VAR_STR_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int x;
  int y;
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

typedef struct Cell {
  int x, y;
  int f, g, h;
  int walkable;
  struct Cell *parent;
} Cell;

typedef struct {
  int width;
  int height;
  int droneSize;
  Point start, end;
} MapConfig;

void push(Stack *s, int x, int y);
Node *pop(Stack *s);
int isEmpty(Stack *s);
void initStack(Stack *s);
int isOnList(Stack *s, int x, int y);
void random1();

#endif
