#include <stdio.h>

int main(void) {
  int a, b;

  scanf("%d %d", &a, &b);

  printf("%d\n", a > b ? 1 : 0);

  return 0;
}
