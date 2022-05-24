#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n;
  scanf("%d", &n);

  int *nums = malloc(sizeof(int) * n);

  for (int i = n - 1; i >= 0; i--)
    scanf("%d", &nums[i]);

  for (int i = 0; i < n; i++)
    printf("%d\n", nums[i]);

  free(nums);

  return 0;
}
