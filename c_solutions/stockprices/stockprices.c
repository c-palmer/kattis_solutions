/*

figure out how to make dynamic list functions and struct generic

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int q, p;
} Order;

typedef struct {
    Order *data;
    int capacity, count;
} List;

void solve(int n);
List *list_create(void);
void list_destroy(List *list);
void list_insert_sort(List *list, int q, int p);
void list_append(List *list, int q, int p);
void list_insert(List *list, int index, int q, int p);
void list_delete(List *list, int index);

char *line = NULL;
size_t line_n = 0;

int main(void) {
    getline(&line, &line_n, stdin);
    
    int t;
    sscanf(line, "%d", &t);
    
    for (int i = 0; i < t; i++) {
        getline(&line, &line_n, stdin);
        
        int n;
        sscanf(line, "%d", &n);
        
        solve(n);
    }
    
    return 0;
}

void solve(int n) {
    List *bids = list_create();
    List *asks = list_create();
    int stock_price = 0;
    for (int i = 0; i < n; i++) {
        getline(&line, &line_n, stdin);
        
        char order_type[5];
        int q, p;
        sscanf(line, "%s %d shares at %d", order_type, &q, &p);
        
        if (order_type[0] == 'b') list_insert_sort(bids, q, p);
        if (order_type[0] == 's') list_insert_sort(asks, q, p);
        
        while (1) {
            if (bids->count == 0 || asks->count == 0) break;
            
            int max_bid_i = bids->count - 1;
            int min_ask_i = 0;
            Order *max_bid = &bids->data[max_bid_i];
            Order *min_ask = &asks->data[min_ask_i];
            
            if (max_bid->p < min_ask->p) break;
            
            stock_price = min_ask->p;
            
            if (max_bid->q == min_ask->q) {
                list_delete(bids, max_bid_i);
                list_delete(asks, min_ask_i);
            } else if (max_bid->q > min_ask->q) {
                max_bid->q -= min_ask->q;
                list_delete(asks, min_ask_i);
            } else {
                min_ask->q -= max_bid->q;
                list_delete(bids, max_bid_i);
            }
        }
        
        if (asks->count == 0) printf("-");
        else printf("%d", asks->data[0].p);
        
        printf(" ");
        
        if (bids->count == 0) printf("-");
        else printf("%d", bids->data[bids->count - 1].p);
        
        printf(" ");
        
        if (stock_price == 0) printf("-");
        else printf("%d", stock_price);
        
        printf("\n");
    }
    
    list_destroy(bids);
    list_destroy(asks);
}



List *list_create(void) {
    List *new_list = malloc(1 * sizeof(List));
    
    if (new_list == NULL) {
        fprintf(stderr, "error: list_create malloc failed\n");
        exit(1);
    }
    
    new_list->count = 0;
    new_list->capacity = 8;
    new_list->data = malloc(new_list->capacity * sizeof(Order));
    
    if (new_list->data == NULL) {
        fprintf(stderr, "error: list_create second malloc failed\n");
        exit(1);
    }
    
    return new_list;
}

void list_destroy(List *list) {
    if (list == NULL) {
        fprintf(stderr, "error: list_destroy list is NULL\n");
        exit(1);
    }
    
    if (list->data == NULL) {
        fprintf(stderr, "error: list_destroy list->data is NULL\n");
        exit(1);
    }
    
    free(list->data);
    free(list);
}

void list_delete(List *list, int index) {
    if (index >= list->count) {
        fprintf(stderr, "error: list_delete index out of bounds\n");
        exit(1);
    }
    
    list->count--;
    
    for (int i = 0; i < list->count; i++) {
        if (i < index) continue;
        
        list->data[i] = list->data[i + 1];
    }
}

void list_insert_sort(List *list, int q, int p) {
    for (int i = 0; i < list->count; i++) {
        if (list->data[i].p <= p) continue;
        
        list_insert(list, i, q, p);
        return;
    }
    
    list_append(list, q, p);
}

void list_append(List *list, int q, int p) {
    list_insert(list, list->count, q, p);
}

void list_insert(List *list, int index, int q, int p) {
    if (index > list->count) {
        fprintf(stderr, "error: list_insert index out of bounds\n");
        exit(1);
    }
    
    if (list->count == list->capacity) {
        list->capacity *= 2;
        list->data = realloc(list->data, list->capacity * sizeof(Order));
        
        if (list->data == NULL) {
            fprintf(stderr, "error: list_insert realloc failed\n");
            exit(1);
        }
    }
    
    list->count++;
    
    for (int i = list->count; i >= 0; i--) {
        if (i == index) {
            list->data[i] = (Order) { q, p };
            return;
        }
        
        list->data[i] = list->data[i - 1];
    }
}