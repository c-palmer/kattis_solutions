#include <stdio.h>

int main(void) {
  int num_stones;
  scanf("%d", &num_stones);

  printf("%s\n", num_stones % 2 == 0 ? "Bob" : "Alice");

  return 0;
}
