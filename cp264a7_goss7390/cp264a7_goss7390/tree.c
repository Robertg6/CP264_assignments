#include <stdio.h>
#include <malloc.h>
#include "tree.h"

TNODE *new_node(int value) {
  TNODE *np = (TNODE *) malloc(sizeof(TNODE));
  if (np == NULL) return NULL;
  np->data = value;
  np->left = NULL;
  np->right = NULL;
  return np;
}

int get_count(TNODE *root) {
	if (root == NULL) 
       return 0; 
   
    

    
  else{
  return 1 + get_count(root->left) + get_count(root->right);} 
    
}

int get_height(TNODE *root) {
	if (root == NULL)  
        return 0;  
    else
    {  
        /* compute the depth of each subtree */
        int lDepth = get_height(root->left);  
        int rDepth = get_height(root->right);  
      
        /* use the larger one */
        if (lDepth > rDepth)  
            return(lDepth + 1);  
        else return(rDepth + 1);  
    } 
}

void clean_tree(TNODE **rootp) {
TNODE *root = *rootp;
  if (root) {
    if (root->left)
      clean_tree(&root->left);
    if (root->right)
      clean_tree(&root->right);
    free(root);
  }
  *rootp = NULL;
}

void display_preorder(TNODE *root) {
 if (root) {
    printf("%c ", root->data);
    display_preorder(root->left);
    display_preorder(root->right);
  }
}

void display_inorder(TNODE *root) {
 if (root) {
    display_inorder(root->left);
    printf("%c ", root->data);
    display_inorder(root->right);
  }

}

void display_postorder(TNODE *root) {
if (root) {
    display_postorder(root->left);
    display_postorder(root->right);
    printf("%c ", root->data);
  }
}

void display_tree(TNODE *root, int prelen) {
  if (root) {
    int i;
    for (i = 0; i < prelen; i++)
      printf("%c", ' ');
    printf("%s", "|___");
    printf("%c\n", root->data);
    display_tree(root->right, prelen + 4);
    display_tree(root->left, prelen + 4);
  }
}

/* use auxiliary queue data structure for the algorithm */
void iterative_bf_display(TNODE *root) {
	QUEUE store = {0};
	if(root == NULL){
		return;
	}
	else{
		enqueue(&store, root);
		while(store.front){
			TNODE *temp = dequeue(&store);
			printf("%c ", temp->data);
			if(temp->left){
				enqueue(&store, temp->left);
			}
			if(temp->right){
				enqueue(&store, temp->right);
			}
		}
	}
	
}

/* use auxiliary queue data structure for the algorithm */
TNODE *iterative_bf_search(TNODE *root, int val) {  
	QUEUE store = {0};
	if(root == NULL){
		return(NULL);
	}
	else{
		enqueue(&store, root);
		while(store.front){
			TNODE *temp = dequeue(&store);
			if(temp->data == val){
			clean_queue(&store);
			return(temp);}
			if(temp->left){
				enqueue(&store, temp->left);
			}
			if(temp->right){
				enqueue(&store, temp->right);
			} 
		}
	}
}

/* use auxiliary stack data structure for the algorithm */
TNODE *iterative_df_search(TNODE *root, int val) {
	
	if(root == NULL){
		return(NULL);
	}
	STACK store = {0};
		TNODE *p = NULL;
		TNODE *cp = NULL;

		
		push(&store, root);
		while(store.top){
			p = peek(&store);
			if(val == p->data){
				clean_stack(&store);
				return p;
			}
			else if (cp == NULL){
				if(p->left!= NULL){
					push(&store, p->left);
					p = peek(&store);
				}
				else if (p->right !=NULL){
					cp = NULL;
					push(&store, p->right);
					p = peek(&store);
				}
				else{
					cp = p;
					pop(&store);
					p = peek(&store);
				}
			}
			else if (cp != NULL){
				if(cp == p->left && p->right!= NULL){
				cp = NULL;
				push(&store, p->right);
				p = peek(&store);
			}
			else if(cp == p->left && p->right== NULL){
				cp = p;
				pop(&store);
				p = peek(&store);
			}
			else if(cp == p->right){
				cp = p;
				pop(&store);	
				p = peek(&store);
			}
			
		}
		
	
	
}return(NULL);}

// queue functions adapted and modified from a6
void enqueue(QUEUE *qp, void *data) {
   QNODE *p = (QNODE*) malloc(sizeof(QNODE));
   if (p == NULL) return; 
   else { 
     p->data = data;
     p->next = NULL;
     
     if (qp->front == NULL) {
      qp->front = p;
      qp->rear = p;
     } else {
      (qp->rear)->next = p;
      qp->rear = p; 
    }
  }
}
void *dequeue(QUEUE *qp) {
  void *temp = NULL;
  if (qp->front) {
    QNODE *p = qp->front;
    temp = p->data;
    if (qp->front == qp->rear) {
      qp->front = NULL;
      qp->rear = NULL;
    } else {
      qp->front = p->next;
    }
    free(p);
    return temp;
  }
  return NULL;
}
void clean_queue(QUEUE *qp) {
  QNODE *temp, *p = qp->front; 
  while (p != NULL) {
    temp = p;
    p = p->next;
    free(temp);
  }
}

// stack functions adapted and modified from a6
void push(STACK *sp, void *data) {
  SNODE *p = (SNODE*) malloc(sizeof(SNODE));
  p->data = data;
  p->next = NULL;
  if (sp->top == NULL) {
    sp->top = p;
  } else {
    p->next = sp->top;
    sp->top = p  ;
  }
}
void pop(STACK *sp) {
  if (sp->top != NULL) {
    SNODE *p = sp->top;
    sp->top = p->next;
    free(p);
  }
}
void *peek(STACK *sp) {
  if (sp->top != NULL) {
     return sp->top->data;
  }
  return NULL;
}
void clean_stack(STACK *sp) {
  SNODE *temp, *p = sp->top;
  while (p) {
    temp = p;
    p = p->next;
    free(temp);
  }
  sp->top = NULL;
}