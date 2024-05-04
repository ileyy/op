#ifndef VAR_STR_H
#define VAR_STR_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int x;
    int y;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

typedef struct {
    int x, y;
    int f, g, h;
    int walkable;
    struct Node *parent;
} Cell;

void push(Stack *s, int x, int y);
Node* pop(Stack *s);
int isEmpty(Stack *s);
void initStack(Stack *s);
int isOnList(Stack *s, int x, int y);

#endif
