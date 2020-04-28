#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "queue.h"

void enqueue(QUEUE *qp, NODE *np) {
  if (qp->front == NULL) {
    qp->front = np;
    qp->rear = np;
    qp->front->next = qp->rear->next = NULL;
  } else {
    qp->rear->next = np;
    qp->rear = np;
    qp->rear->next = NULL;
  }
}  

NODE *dequeue(QUEUE *qp) {
NODE *ptr = NULL;
  if (qp->front) {
    ptr = qp->front;
    if (qp->front == qp->rear) {
      qp->front = NULL;
      qp->rear = NULL;
    } else {
      qp->front = ptr->next;
    }
  }
  return ptr;
}

void clean_queue(QUEUE *qp) {
if (qp->front != NULL) {
    NODE *temp, *ptr = qp->front;

    while (ptr != NULL) {
      temp = ptr; 
      ptr = ptr->next;
      free(temp);
    }
    qp->front = NULL;
    qp->rear = NULL;
  }
}