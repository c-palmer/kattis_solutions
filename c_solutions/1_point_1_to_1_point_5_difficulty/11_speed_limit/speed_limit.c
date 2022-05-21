#include <stdio.h>

int main(void) {
  int n;

  while (1) {
    scanf("%d", &n);

    if (n == -1) break;

    int prev_time = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      int speed, time;
      scanf("%d %d", &speed, &time);

      sum += speed * (time - prev_time);
      prev_time = time;
    }
    
    printf("%d miles\n", sum);
  }

  return 0;
}
