#include <stdio.h>

int main(void) {
  int num_cases;
  scanf("%d", &num_cases);

  for (int i = 1; i <= num_cases; i++) {
    int sum_positive = 0;
    int sum_odd = 0;
    int sum_even = 0;
    int k, n;

    scanf("%d %d", &k, &n);

    for (int j = 0; j < n; j++)
      sum_positive += j + 1;

    for (int j = 0; j < n; j++)
      sum_odd += (j * 2) + 1;

    for (int j = 1; j <= n; j++)
      sum_even += (j * 2);

    printf("%d %d %d %d\n", k, sum_positive, sum_odd, sum_even);
  }

  return 0;
}
