#include "Var_str.h"

void initStack(Stack *s) { s->top = NULL; }

int isEmpty(Stack *s) { return s->top == NULL; }

void push(Stack *s, int x, int y) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    printf("Unable to allocate memory for new node\n");
    return;
  }
  newNode->x = x;
  newNode->y = y;
  newNode->next = s->top;
  s->top = newNode;
}

Node *pop(Stack *s) {
  if (isEmpty(s)) {
    return NULL;
  }
  Node *nodeToPop = s->top;
  s->top = nodeToPop->next;
  return nodeToPop;
}

int isOnList(Stack *s, int x, int y) {
  Node *current = s->top;
  while (current != NULL) {
    if (current->x == x && current->y == y) {
      return 1;
    }
    current = current->next;
  }
  return 0;
}

void random1() {
  char n[7];
  const char pattern[] = "XXXXXX";
  for (int i = 0; i < sizeof(pattern); ++i) n[i] = pattern[i];
  int fd = mkstemp(n);
  srand(*(int *)n);
}
