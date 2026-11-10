/*

take 320 for example:

the 0 tells us there was no 2 added to a 0 in the 1s place
the 2 tells us there was a 2 added to a 0 in the 2s place
the 3 tells us there was a 2 added to a 1 in the 4s place

so decomposing the 2 binary from the normal 1 binary, we have:
220 for y (which equals 6 in decimal)
100 for x (which equals 4 in decmial)

there are 3 digits in 320, so the level is 3

therefor we arrive at the answer 3 4 6


take 3 for example:
decomposes into:
2 for y (1 in decimal) (treating 2s like 1s in binary)
1 for x (1 in decimal) (normal binary with 1s)

there is 1 digit in 3

so we have 1 1 1 (number of digits, x, and y)

see https://en.wikipedia.org/wiki/Z-order_curve
it kind of reminds me of cantor's diagonalization

*/

#include <stdio.h>

int main(void) {
    char *line = NULL;
    size_t line_n = 0;
    
    ssize_t line_len = getline(&line, &line_n, stdin);
    line[--line_len] = '\0';

    int pow = 0, y = 0, x = 0;
    for (int i = line_len - 1; i >= 0; i--) {
        int digit = line[i] - '0';

        if (digit == 2 || digit == 3) y += (1 << pow);
        if (digit == 1 || digit == 3) x += (1 << pow);

        pow++;
    }

    printf("%d %d %d\n", line_len, x, y);

    return 0;
}