#include <stdio.h>

int main(void) {
  int x, y;

  scanf("%d", &x);
  scanf("%d", &y);

  int quadrant;
  if (x < 0) {
    if (y < 0)
      quadrant = 3;
    else
      quadrant = 2;
  } else {
    if (y < 0)
      quadrant = 4;
    else
      quadrant = 1;
  }

  printf("%d\n", quadrant);

  return 0;
}
