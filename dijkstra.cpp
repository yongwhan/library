#include <stdio.h>
#include <stdlib.h>
#define INF 987654321
int V, E, K;
 
struct EDGE {
    int st, ed;
    int cost;
};
typedef struct EDGE edge;
edge e[300003];
edge heap[300003];
 
int distance[20002];
int vertex[20002];
 
int size;
 
void push(edge e)
{
    int cur = ++size;
    while (cur != 1 && heap[cur / 2].cost > e.cost)
    {
        heap[cur] = heap[cur / 2];
        cur /= 2;
    }
    heap[cur] = e;
}
void pop()
{
    edge last = heap[size--];
    int cur = 1;
    int child = 2;
    while (child <= size)
    {
        if (child < size && heap[child].cost > heap[child + 1].cost) child++;
        if (last.cost <= heap[child].cost) break;
 
        heap[cur] = heap[child];
        cur = child;
        child *= 2;
    }
    heap[cur] = last;
}
 
void dijkstra(int st) {
    int i, j, here, cost, pt, there, weight;
    edge tmp;
    for (i = 0; i <= V; i++) distance[i] = INF;
    distance[st] = 0;
    tmp.st = st;
    tmp.cost = 0;
    push(tmp);
    while (size > 0) {
        here = heap[1].st;
        cost = heap[1].cost;
        pop();
        if (cost > distance[here])
            continue;
        for (j = 0; j < vertex[here] - vertex[here - 1]; j++)
        {
            pt = vertex[here - 1] + j;
            weight = e[pt].cost + cost;
            if (distance[e[pt].ed] > weight)
            {
                distance[e[pt].ed] = weight;
                tmp.st = e[pt].ed;
                tmp.cost = weight;
                push(tmp);
            }
        }
    }
}
 
int cmp(const void* arg1, const void* arg2)
{
    edge* a = (edge*)arg1;
    edge* b = (edge*)arg2;
    return a->st < b->st ? -1 : a->st > b->st ? 1 : 0;
}
 
int main(void) {
    int i, j, a, b, c;
    scanf("%d%d", &V, &E);
    scanf("%d", &K);
    for (i = 0; i<E; i++) {
        scanf("%d%d%d", &a, &b, &c);
        e[i].st = a;
        e[i].ed = b;
        e[i].cost = c;
    }
    qsort(e, E, sizeof(edge), cmp);
    vertex[1] = 0;
    for (int i = 1, j = 0; i <= V; ++i)
        for (; e[j].st == i; ++j)
            vertex[i]++;
    for (int i = 1; i <= V; ++i)
        vertex[i] += vertex[i - 1];
    dijkstra(K);
    for (i = 1; i <= V; i++) {
        if (distance[i] == INF) printf("INF\n");
        else printf("%d\n", distance[i]);
    }
    return 0;
}
