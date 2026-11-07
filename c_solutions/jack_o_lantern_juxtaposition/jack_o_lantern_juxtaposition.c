#include <stdio.h>

int main(void) {
  int num_eyes, num_mouths, num_noses;
  scanf("%d %d %d", &num_eyes, &num_mouths, &num_noses);

  printf("%d\n", num_eyes * num_mouths * num_noses);

  return 0;
}
