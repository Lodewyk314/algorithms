#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node;

node *search_list(node *phead, int val);

//NB: passing in pointer to head won't work since it would simply pass the value of the address
//of the head, so we need a pointer to the pointer to modify the pointer to the head
void insert_list(node **pphead, int val);

int main() {
  
  node A, B, C;
  node *root = &A;
  A.next = &B;
  B.next = &C;
  C.next = NULL;
  A.data = 50;
  B.data = 60;
  C.data = 3;
  
  printf("To access B's data using A's pointer: %d\n", A.next->data);
  printf("%p\n", search_list(root, 7));

  
  insert_list(&root, 9);
  printf("%d\n", root->data);
  
}

node *search_list(node *phead, int val) {
  if(phead == NULL) {
    return NULL;
  }
  if(phead->data == val) {
    return phead;
  } else {
    return search_list(phead->next, val);
  }
}

void insert_list(node **pphead, int val) {

  node new_head;
  new_head.data = val;
  new_head.next = *pphead;

  *pphead = &new_head;
}

