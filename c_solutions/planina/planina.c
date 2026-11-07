#include <stdio.h>
#include <math.h>

int main(void) {
  int n;
  scanf("%d", &n);

  // start with 2
  int last_points = 2;
  int total_points = 0;
  for (int i = 0; i < n; i++) {
    // calculate 2^i
    int edges = pow(2, i);

    // add 2^i to prev points
    int points = last_points + edges;

    total_points = pow(points, 2);
    last_points = points;
  }

  printf("%d\n", total_points);

  return 0;
}
