#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char *buf = NULL;
    size_t size = 0;
    
    int num_rows, num_cols, num_points;
    getline(&buf, &size, stdin);
    sscanf(buf, "%d %d %d", &num_rows, &num_cols, &num_points);
    
    size_t row_len = num_cols + 1; // + 1 for \n
    size_t data_size = sizeof(char) * row_len * num_rows;
    char *data = malloc(data_size);
    
    memset(data, '.', data_size);
    char **res = malloc(sizeof(char *) * num_rows); // pointers to rows
    for (int y = 0; y < num_rows; y++) {
        res[y] = &data[y * row_len];
        res[y][row_len - 1] = '\n';
    }
    res[num_rows - 1][row_len - 1] = '\0'; // replace \n of last row with \0
    
    int x, y;
    for (int i = 0; i < num_points; i++) {
        getline(&buf, &size, stdin);
        sscanf(buf, "%d %d", &y, &x);
        
        res[y - 1][x - 1] = '*';
    }
    
    fwrite(data, sizeof(char), data_size, stdout);
    
    free(buf);
    free(data);
    free(res);
    return 0;
}
