#include <stdio.h>

int main(void) {
  int n;
  scanf("%d", &n);

  int sum = 0;
  for (int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);

    sum += num;
  }

  sum -= n - 1;

  printf("%d\n", sum);

  return 0;
}
