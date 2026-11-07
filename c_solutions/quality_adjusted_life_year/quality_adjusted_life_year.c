#include <stdio.h>

int main(void) {
  int n;
  scanf("%d", &n);

  float sum = 0;
  for (int i = 0; i < n; i++) {
    float weight, value;
    scanf("%f %f", &weight, &value);

    sum += weight * value;
  }

  printf("%f\n", sum);

  return 0;
}
