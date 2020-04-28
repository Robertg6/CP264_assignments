#include <stdio.h>
#include <malloc.h>
#include "common.h"

NODE *new_node(int data, int type) {
	NODE *ptr;
	ptr = (NODE*) malloc(sizeof(NODE));
	ptr->data = data;
	ptr->type = type;
	return(ptr);
	
}

void display(NODE *start) {
  while (start != NULL) {
	if (start->type == 0) 
      printf("%d ", start->data);
	else 
      printf("%c ", start->data);      
    
    start = start->next;
  }
}

void clean(NODE **topp) {
	 NODE *temp, *np = *topp;
  while (np != NULL) { 
    temp = np; 
    np = np -> next;
    free(temp);
  }
  *topp = NULL;
}