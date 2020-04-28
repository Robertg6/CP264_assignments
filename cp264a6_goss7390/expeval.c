
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "common.h"
#include "queue.h"
#include "stack.h"
#include "expeval.h"

/*
 * axillary function 
*/
int get_priority(char op) {
  if (op == '/' || op == '*' || op == '%') 
    return 1;
  else if (op == '+' || op == '-')
    return 0;
  else 
    return -1;    
}

/*
 * axillary function 
*/
int type(char c) {
  if (c >= '0' &&  c <= '9' )
     return 0;
  else if (c == '/' || c == '*' || c == '%' || c == '+' || c == '-')
    return 1;
  else if (c == '(')
    return 2;
  else if ( c == ')')
    return 3;  
  else 
    return 4;
}

QUEUE infix_to_postfix(char *infixstr) {
char *p = infixstr;
QUEUE queue = {0};
STACK stack = {0};
int sign = 1, num = 0;

while (*p) {
	if (*p == '-' && (p == infixstr || *(p-1) == '(')){
		sign = -1;
	}
	else if(*p >= '0' && *p <= '9'){
		num = *p-'0';
		while ((*(p+1) >= '0' && *(p+1) <= '9')){
			num = num*10 + *(p+1)-'0';
			p++;
		}
		enqueue(&queue, new_node(sign*num, 0));
		sign = 1;
	}
	else if (*p == '(') {
		push(&stack, new_node('(', 2));
	}
	else if (*p == ')'){
		while (stack.top){
			if(stack.top->type == 2) {
				free(pop(&stack));
				break;
			}
			enqueue(&queue, pop(&stack));
		}
	} else if (type(*p) == 1) {
		while(stack.top && stack.top->type==1 && get_priority( stack.top->data) >= get_priority(*p))
			enqueue(&queue, pop(&stack));
		push(&stack, new_node(*p, 1));
	}
	p++;
}

while (stack.top) {
	enqueue(&queue, pop(&stack));
}
return queue;
}

int evaluate_postfix(QUEUE queue) {
STACK stack = {0};
int type = 0;
NODE *p = queue.front;

while(p){
	type = p->type;
	
	if(type == 0){
		push(&stack, new_node(p->data, 0));
	}
	
	else if(type == 1){
		int operator = p->data;
		NODE *operand2 = pop(&stack);
		
		if(operator == '+'){
			stack.top->data = stack.top->data + operand2->data;
		}
		else if(operator == '-'){
			stack.top->data = stack.top->data - operand2->data;
		}
		else if(operator == '*'){
			stack.top->data = stack.top->data * operand2->data;
		}
		else if(operator == '/'){
			stack.top->data = stack.top->data / operand2->data;
		}
		
		free(operand2);
		
	}
	p = p->next;
}
int result = stack.top->data;
return result;
}