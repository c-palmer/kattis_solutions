#include <stdio.h>
#include <math.h>

int main(void) {
  int n;
  scanf("%d", &n);

  int sum = 0;
  for (int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);

    int exp = num % 10;
    int base = num / 10;

    sum += pow(base, exp);
  }

  printf("%d\n", sum);

  return 0;
}
