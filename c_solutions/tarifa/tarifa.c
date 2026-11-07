#include <stdio.h>

int main(void) {
  int mb_per_month;
  int num_months;
  int mb_spent_this_month;

  scanf("%d", &mb_per_month);
  scanf("%d", &num_months);

  int sum = 0;
  for (int i = 0; i < num_months; i++) {
    int mb_spent;
    scanf("%d", &mb_spent);

    sum += mb_per_month - mb_spent;
  }

  sum += mb_per_month;

  printf("%d\n", sum);

  return 0;
}
