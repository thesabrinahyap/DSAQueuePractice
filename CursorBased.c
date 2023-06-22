#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"CursorBased.h"


Student newStudent(int studID, String studName, char sex, String program){
	Student s;
	
	s.studID = studID;
	strcpy(s.studName, studName);
	s.sex =sex;
	strcpy(s.program, program);
	
	return s;
}

VirtualHeap newVirtualHeap(){
	VirtualHeap VH;
	
	int ctr;
	
	for(ctr = 0; ctr<MAX; ctr++){
		VH.elems[ctr].elem = newStudent(0," ",' '," ");
		VH.elems[ctr].next = ctr-1;
	}
	VH.avail = MAX-1;
	
	return VH;
}
int allocSpace(VirtualHeap *VH){
	int retVal = VH->avail;
	
	if(retVal != -1){
		VH->avail = VH->elems[VH->avail].next;
	}
	
	return retVal;
}
void insertFront(VirtualHeap *VH, List *list, Student s){
	List temp = allocSpace(VH);
	
	if(temp != -1){
		VH->elems[temp].next = *list;
		*list = temp;
		VH->elems[temp].elem = s;
	}
	
}

void displayList(VirtualHeap VH, List list){
	printf("%5s | %30s | %s\n","INDEX", "ELEMENTS", "NEXT");
	printf("-------------------------------------------\n");
	
	while(list != -1){
		printf("%5d | ", list);
		if(!VH.elems[list].elem.studID){
			printf("%30s | ", "EMPTY");
		}else{
			printf("%4d - %23s | ", VH.elems[list].elem.studID,VH.elems[list].elem.studName);
		}
		printf("%d\n", VH.elems[list].next);
		list = VH.elems[list].next;
	}
	printf("---------------------------------------------\n");
}

void visualizeSpace(VirtualHeap VH){
	int ctr;
	printf("%5s | %30s | %s\n","INDEX", "ELEMENTS", "NEXT");
	printf("-------------------------------------------\n");
	
	for(ctr=0; ctr<MAX;ctr++){
		printf("%5d | ", ctr);
		if(!VH.elems[ctr].elem.studID){
			printf("%30s | ", "EMPTY");
		}else{
			printf("%4d - %23s | ", VH.elems[ctr].elem.studID,VH.elems[ctr].elem.studName);
		}
		printf("%d\n", VH.elems[ctr].next);
	}
	printf("---------------------------------------------\n");
	printf("AVAILABLE: %d\n\n", VH.avail);
}

void deallocSpace(VirtualHeap *VH, int index){
	if(index != -1 && index< MAX){
		VH->elems[index].next = VH->avail;
		VH->elems[index].elem = newStudent(0," ",' '," ");
		VH->avail = index;
	}
	
}

Student removeStudent(VirtualHeap *VH, List *list, String keyword){
	Student retVal;
	List *trav, temp;
	
	for(trav = list; *trav != -1 && strcmp(keyword,VH->elems[*trav].elem.studName)!=0;trav = &VH->elems[*trav].next){
		retVal = VH->elems[*trav].elem;
	}
	if(*trav != -1){
		temp = *trav;
		*trav = VH->elems[temp].next;
		deallocSpace(VH, temp);
	}
	
	return retVal;
}
