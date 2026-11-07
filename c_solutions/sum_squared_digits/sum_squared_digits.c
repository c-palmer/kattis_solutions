#include <stdio.h>

int square(int a);

int main(void) {
  int num_cases;
  scanf("%d", &num_cases);

  for (int i = 0; i < num_cases; i++) {
    int case_num, base, n;
    scanf("%d %d %d", &case_num, &base, &n);

    int sum = 0;
    while (n != 0) {
      sum += square(n % base);
      n /= base;
    }

    printf("%d %d\n", case_num, sum);
  }

  return 0;
}

int square(int a) {
  return a * a;
}
