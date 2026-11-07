#include <stdio.h>

int main(void) {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    int revenue_no_ad, revenue_with_ad, ad_cost;

    scanf("%d %d %d", &revenue_no_ad, &revenue_with_ad, &ad_cost);

    if (revenue_with_ad - ad_cost > revenue_no_ad)
      printf("advertise\n");
    else if (revenue_with_ad - ad_cost < revenue_no_ad)
      printf("do not advertise\n");
    else
      printf("does not matter\n");
  }

  return 0;
}
