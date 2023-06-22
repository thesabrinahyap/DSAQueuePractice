#ifndef CIRCULAR_H
#define CIRCULAR_H
#include <stdbool.h>

#define MAX 10
#define EMPTY 9999

typedef char String[20];
typedef struct{
	int elems[MAX];
	int front;
	int rear;
}Queue;

void initQueue(Queue *q);
void enqueue(Queue *q, int item);
void dequeue(Queue *q);
int front(Queue q);
bool isEmpty (Queue q);
bool isFull(Queue q);
//void display(Queue q);
void visualize(Queue q);

#endif
