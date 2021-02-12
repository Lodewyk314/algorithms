#include <stdio.h>

void swap(int *px, int *py) {
  int temp = *px;
  *px = *py;
  *py = temp;
}

void insertion_sort(int s[], int n) {
  int i, j; //counters
  
  for (i = 1; i < n; i++) {
    j = i;
    while ((j > 0) && (s[j] < s[j - 1])) {
      swap(&s[j], &s[j - 1]);
      j = j - 1;
    }
  }
}

int main() {
  int a[4] = {7, 3, 17, 2};
  for (int i = 0; i < 4; i++) printf("Item %d is %d\n", i, a[i]);
  printf("\n");
  insertion_sort(a, 4);
  for (int i = 0; i < 4; i++) printf("Item %d is %d\n", i, a[i]);
}


