#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "myqueue.h"
using namespace std;



void initQueue(linkQueue &Q){         //初始化队列  
    Q.front = new Qnode;  
    Q.rear = Q.front;  
    if(!Q.front) exit(-1);  
    Q.front->next = NULL;  
    Q.queueLength = 0;  
}  
void cleanQueue(linkQueue &Q){      //清空队列  
    while(Q.front){  
        Q.rear = Q.front->next;  
        free(Q.front);  
        Q.front = Q.rear;  
    }  
}  
void enQueue(linkQueue &Q, elemtype e){        //元素入队列  
    Queuenode p;  
    p = new Qnode;  
    if(!p) exit(-1);  
    p->data = e;  
    p->next = NULL;  
    Q.rear->next = p;  
    Q.rear = p;  
    Q.queueLength++;  
}  
void deQueue(linkQueue &Q, elemtype &e){       //元素出队列  
    if(Q.front == Q.rear) return;  
    Queuenode p;  
    p = Q.front->next;  
    e = p->data;  
    Q.front->next = p->next;  
    if(Q.rear == p)  
        Q.rear = Q.front;  
    free(p);  
}  
bool QueueEmpty(linkQueue &Q){               //队列判空  
    if(Q.rear  == Q.front)  
        return true;  
    else  
        return false;  
}  
