
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void push(STACK *sp, NODE *np) {

  if (sp->top == NULL) {
    np->next = NULL;
	sp->top = np;
  } else {
    np->next = sp->top;
    sp->top = np;
  }
}

NODE *pop(STACK *sp) {
	if (sp->top == NULL)
		{printf("\nUNDERFLOW");
		return(NULL);
		}
  else {
    NODE *temp = sp->top;
    NODE *ptr = sp->top;
	sp->top = temp->next;
    
	return(ptr);
  }
  
}

void clean_stack(STACK *sp) {
if (sp->top != NULL) {
    NODE *temp, *ptr = sp->top;

    while (ptr != NULL) {
      temp = ptr; 
      ptr = ptr->next;
      free(temp);
    }
    sp->top = NULL;
   
  }
}

