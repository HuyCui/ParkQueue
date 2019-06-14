#ifndef _MYSTACK_H
#define _MYSTACK_H

typedef int elemtype;
typedef struct {  
    elemtype *base;  
    elemtype *top;  
    int stacksize;  
    int length;
}Sqstack;  

void initStack(Sqstack &S, int size);
bool isEmpty(Sqstack &S);
bool isFull(Sqstack &S);
elemtype getTop(Sqstack &S);
void cleanStack(Sqstack &S);
void Push(Sqstack &S, elemtype e);
elemtype Pop(Sqstack &S, elemtype &e);

#endif
