#include <stdio.h>
#include <stdlib.h>

typedef struct list {
  int item; /* data item */
  struct list *next; /* point to successor */
} list;

list *search_list(list *l, int x) {
  if (l == NULL) {
    return(NULL);
  }
  if (l->item == x) {
    return(l);
  } else {
    return(search_list(l->next, x));
  }
}
