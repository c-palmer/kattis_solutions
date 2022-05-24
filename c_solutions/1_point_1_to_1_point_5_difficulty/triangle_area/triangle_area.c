#include <stdio.h>

int main(void) {
  int h, b;

  scanf("%d %d", &h, &b);

  printf("%f\n", (float) (b * h) / 2);

  return 0;
}
