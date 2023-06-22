#include <stdio.h>
#include <stdlib.h>
#include "CircularArray.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Queue myQueue;
	int choice;
	String menuOption[7] = {"Enqueue", "Dequeue", 
							"isEmpty", "isFull", 
							"Display", "Visualize", 
							"Front"};
							
	int ctr, value;
	initQueue(&myQueue);
	
	do{
		system("cls");
		printf("MENU\n");
		for(ctr = 0; ctr<7; ctr++){
			printf("[%d] %s\n", ctr+1, menuOption[ctr]);
		}
		printf("Enter your choice <0 to EXIT>: ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				printf("Enqueue\n");
				printf("Enter a number: ");
				scanf("%d", &value);
				enqueue(&myQueue, value);
				visualize(myQueue);
				break;
			case 2:
				printf("Dequeue\n");
				dequeue(&myQueue);
				visualize(myQueue);
				break;
			case 3:
				printf("Check if Empty\n");
				if(isEmpty(myQueue)){
					printf("EMPTY!");
				}else{
					printf("NOT EMPTY");
				}
				break;
			case 4:
				printf("Check if Full\n");
				if(isFull(myQueue)){
					printf("FULL!");
				}else{
					printf("NOT FULL");
				}
				break;
//			case 5:
//				printf("Display Queue\n");
//				display(myQueue);
//				break;
			case 6:
				printf("Visualize Queue\n");
				visualize(myQueue);
				break;
			case 7:
				printf("Front: %d\n",front(myQueue));
				break;
			case 0:
				printf("Thank You!!!!!\n");
				break;
			default:
				printf("Invalid Choice\n");
		}
		printf("\n");
		system("pause");
	}while(choice != 0);
	printf("BYE!!!\n");
	
	return 0;
}
