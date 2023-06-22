#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "CircularArray.h"

void initQueue(Queue *q){
	q->front = 7;
	q->rear = 6;
	int ctr;
	
	for(ctr=0; ctr < MAX; ctr++){
		q->elems[ctr] = EMPTY;
	}
}
void enqueue(Queue *q, int item){
	if(!isFull(*q)){
		q->rear = (q->rear+1) % MAX;
		q->elems[q->rear] = item;
	}
}
void dequeue(Queue *q){
	if(!isEmpty(*q)){
		q->front = (q->front + 1) % MAX;
	}
}
int front(Queue q){
	return(!isEmpty(q))? q.elems[q.front]: EMPTY;
}
bool isEmpty (Queue q){
	return (q.rear +1)%MAX == q.front;
}
bool isFull(Queue q){
	return (q.rear +2)%MAX == q.front;
}
//void display(Queue q);
void visualize(Queue q){
	int ctr;
	printf("%5s | %5s | %s\n","INDEX","VALUE","POSITION");
	printf("========================\n");
	for(ctr = 0; ctr< MAX; ctr++){
		printf("%5d | ", ctr);
		if(q.elems[ctr] != EMPTY){
			printf("%5d | ",q.elems[ctr]);
		}else{
			printf("%5s | ", " ");
		}
		if(ctr == q.front){
				printf(" FRONT");
		}else if(ctr == q.rear){
				printf(" REAR");
		}
		printf("\n");		
	}
	printf("========================\n");
}
