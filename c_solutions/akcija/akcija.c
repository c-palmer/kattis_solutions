/*

first time implementing merge sort by hand

the middle m always belongs to the left part of the array

in merge, its important to set the i's in the main loop to be in [l, r]
so that we can naturally address arr like arr[i].
This also helps so that we don't need to use a while loop because
the loop will run exactly r - l + 1 times. That's why we don't have to
check if lp >= l_len && rp >= r_len and stop the loop

we use arr[l + i] when setting arr_l because the left array starts at l
similarly, we use arr[m + 1 + i] in arr_r because it starts at m + 1

this merge sort will sort in non-increasing order because of the >
at the end of the for loop. We can set it to non-decreasing by
changing it to <, or we could take a function pointer as argument with type
bool (*cmp)(int *, int *) ("cmp is a pointer to function that takes two
pointers to ints and returns a bool") and replace arr_l[lp] > arr_r[rp] with
cmp(&arr_l[lp], &arr_r[rp]) so we can change the order or compare custom
types (the pointers to ints in the function signature would need to be changed
to those custom types)

*/

#include <stdio.h>
#include <stdlib.h>

void merge(int *arr, int l, int r) {
    int m = l + (r - l) / 2;

    int l_len = m - l + 1, r_len = r - m;
    int arr_l[l_len], arr_r[r_len];
    for (int i = 0; i < l_len; i++) arr_l[i] = arr[l + i];
    for (int i = 0; i < r_len; i++) arr_r[i] = arr[m + 1 + i];

    int lp = 0, rp = 0;
    for (int i = l; i <= r; i++) {
        if (lp >= l_len) {
            arr[i] = arr_r[rp++];
            continue;
        }

        if (rp >= r_len) {
            arr[i] = arr_l[lp++];
            continue;
        }

        arr[i] = (arr_l[lp] > arr_r[rp]) ? arr_l[lp++] : arr_r[rp++];
    }
}

void merge_sort(int *arr, int l, int r) {
    if (l >= r) return;
      
    int m = l + (r - l) / 2;

    merge_sort(arr, l, m);
    merge_sort(arr, m + 1, r);

    merge(arr, l, r);
}


int main(void) {
    int n;
    scanf("%d", &n);
    
    int *prices = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &prices[i]);
    }

    merge_sort(prices, 0, n - 1);

    long int sum = 0;
    for (int i = 0; i < n; i++) {
        if (i % 3 == 2) continue;
        
        sum += prices[i];
    }
    
    printf("%d\n", sum);
}