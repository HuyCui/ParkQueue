#ifndef _MYQUEUE_H
#define _MYQUEUE_H

typedef int elemtype;
typedef struct Qnode{  
    elemtype data;  
    struct Qnode *next;  
}Qnode, *Queuenode;  
typedef struct{  
    Queuenode front;  
    Queuenode rear;  
    int queueLength;  
}linkQueue; 

void initQueue(linkQueue &Q);
void cleanQueue(linkQueue &Q);
void enQueue(linkQueue &Q, elemtype e);
void deQueue(linkQueue &Q, elemtype &e);
bool QueueEmpty(linkQueue &Q);

#endif
