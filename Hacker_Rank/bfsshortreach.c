#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node_Tag {
    short int data;
    struct Node_Tag *next;
};
struct Node_Tag *head, *last;

int q_empty()
{
    if(head == NULL) {
        return 1;
    }
    return 0;
}

void enqueue(short int data)
{
    struct Node_Tag *temp = NULL;
    temp = (struct Node_Tag *)malloc(sizeof(struct Node_Tag));
    temp->data = data;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
    } else {
        last->next = temp;
    }
    last = temp;
}

short int dequeue()
{
    struct Node_Tag *temp;
    short int val;
    temp = head;
    head = head->next;
    val = temp->data;
    free(temp);
    return val;
}

int main(void)
{
    short unsigned int Q;
    scanf("%hu", &Q);
    while(Q--) {
        short unsigned int n, m, r, c, i, start;
        scanf("%hu %hu", &n, &m);
        short unsigned int graph[n+1][n+1], dist[n+1];
        memset(graph, 0, sizeof(graph));
        memset(dist, 0, sizeof(dist));
        for(i = 0; i < m; i++) {
            scanf("%hu %hu", &r, &c);
            graph[r][c] = 1;
            graph[c][r] = 1;
        }
        scanf("%hu", &start);
        enqueue(start);

        while(!q_empty()) {
            int cur = dequeue();
            for(i = 1; i <= n; i++) {
                if(graph[cur][i] && dist[i] == 0) {
                    dist[i] = dist[cur] + 1;
                    enqueue(i);
                }
            }
            dist[start] = 1;
        }
        for(i = 1; i <= n; i++) {
            if (i != start) {
                if (dist[i] == 0) {
                    printf("-1 ");
                } else {
                    printf("%hu ", dist[i] * 6);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
