/*  My solution to lostoncampus in Kattis:
 *      https://open.kattis.com/problems/lostoncampus
 *  
 *  see hint here:
 *      https://sumnerevans.com/posts/school/2022-hspc/#lost-on-campus
 * 
 *  This was my first time actually attempting a graph theory problem.
 *  My mind still is having trouble comprehending how to turn the ascii
 *  grid into a formal representation of a graph data structure, so I
 *  avoided that by simply traverising the grid as if it were a graph.
 *  I just can't figure out how to turn the rooms into nodes in the graph.
 *  I know I can find all of the doors in a room using BFS, but how do I then
 *  consider those doors as edges between the rooms and find which other rooms
 *  each of those doors connect to?
 * 
 *  First I did BFS to find all of the doors in a room. I add cells to the queue
 *  to check, and mark them already checked by replacing their contents
 *  with a '~'. If I come across a door, I add it to a special door queue.
 *  I don't know if this door queue is actually necessary or if I could just
 *  use the normal queue.
 *  
 *  I don't know how this normal queue and door queue combination differs from
 *  the priority queue supposedly used in Dijkstra's algorithm. When I find a
 *  new door, I store in the queue node the number of doors I've found before it.
 *  I also don't know if this is necessary or if I could just have a global
 *  variable or something. I'm still not understanding how storing this number
 *  differs from the numbers stored in Dijkstra's algorithm.
 * 
 *  I think BFS finds the shortest path through the rooms because instead of
 *  going through as many doors as possible and then going back to check the
 *  other ones like DFS would do, BFS checks every door on the same layer before
 *  moving on to the next layer, so if one door goes farther than the others
 *  on its same level, searching through that door and marking everything in
 *  that new room prevents the searches through the other doors that lead to
 *  that same room from continuing.
 * 
 *  I am super relieved to have finally figured this out, but I feel really
 *  frustrated at the same time. I feel like I just hacked it together and
 *  didn't do it the formal way. I don't feel like I am comfortable with
 *  representing graphs in code, I don't think I have an intuitive understanding
 *  of BFS and DFS. I can't carry the algorithm out in my mind without it
 *  spiraling out of control and me getting to overwhelmed by all of the
 *  different possibilities. I don't understand the real ways of doing it like
 *  Dijkstra's or A*. I don't even know what a priority queue is. And I don't
 *  like how I didn't convert the grid to a graph and how I have to store
 *  num_doors in the nodes.
 * 
 *  WHY is this problem labeled "easy" on Kattis. It makes me feel like I'm
 *  missing some obvious simple way that avoids all of this graph theory stuff.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *next;
    int x, y, num_doors;
} Node;

Node *create_node(int x, int y, int num_doors);
Node *insert_tail(Node *head, Node *new_tail);
Node *delete_head(Node *head);
int bfs_room_for_doors(char **grid, int num_doors);

Node *queue = NULL;
Node *door_queue = NULL;

int main(void) {
    char *line = NULL;
    size_t n = 0;
    getline(&line, &n, stdin);
    
    int w, h;
    sscanf(line, "%d %d", &w, &h);
    
    char **grid = malloc(h * sizeof(char *));
    
    int x, y;
    for (int i = 0; i < h; i++) {
        grid[i] = malloc(w * sizeof(char));
        
        getline(&line, &n, stdin);
        
        for (int j = 0; j < w; j++) {
            grid[i][j] = line[j];
            
            if (grid[i][j] == '*') {
                x = j;
                y = i;
            }
        }
    }

    queue = insert_tail(queue, create_node(x, y, -1));
    int num_doors = 0;
    while (1) {
        int found_exit = bfs_room_for_doors(grid, num_doors);
        
        if (found_exit) {
            printf("%d\n", num_doors);
            return 0;
        }
        
        if (door_queue == NULL) {
            printf("NOT POSSIBLE\n");
            return 0;
        };

        queue = insert_tail(
            queue,
            create_node(door_queue->x, door_queue->y, -1)
        );
        num_doors = door_queue->num_doors + 1;
        door_queue = delete_head(door_queue);
    }
}

int bfs_room_for_doors(char **grid, int num_doors) {
    int dirs[][2] = {
        {  0, -1 }, // north
        {  1,  0 }, // east
        {  0,  1 }, // south
        { -1,  0 }  // west
    };
    
    while (1) {
        if (queue == NULL) return 0;
        
        for (int i = 0; i < 4; i++) {
            int x = queue->x + dirs[i][0];
            int y = queue->y + dirs[i][1];
            
            switch (grid[y][x]) {
                case 'E': return 1;
                case '~':
                case '#': continue;
                case 'D':
                    door_queue = insert_tail(
                        door_queue,
                        create_node(x, y, num_doors)
                    );
                    grid[y][x] = '~';
                    continue;
            }
            
            queue = insert_tail(queue, create_node(x, y, -1));
            grid[y][x] = '~';
        }

        queue = delete_head(queue);
    }
}

Node *create_node(int x, int y, int num_doors) {
    Node *new_node = malloc(sizeof(Node));
    
    new_node->x = x;
    new_node->y = y;
    new_node->num_doors = num_doors;
    new_node->next = NULL;
    
    return new_node;
}

Node *delete_head(Node *head) {
    if (head == NULL) return NULL;
    
    Node *new_head = head->next;
    
    free(head);
    
    return new_head;
}

Node *insert_tail(Node *head, Node *new_tail) {
    if (head == NULL) return new_tail;
    
    if (head->next == NULL) {
        head->next = new_tail;
        return head;
    }
    
    head->next = insert_tail(head->next, new_tail);
    return head;
}