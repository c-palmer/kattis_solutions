#include <stdio.h>

int main(void) {
  int option_1;

  scanf("%d", &option_1);

  float option_1_ratio = (float) 100 / option_1;
  float option_2_ratio = (float) 100 / (100 - option_1);

  printf("%f\n", option_1_ratio);
  printf("%f\n", option_2_ratio);

  return 0;
}
