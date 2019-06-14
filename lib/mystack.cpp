#include <iostream>
#include <stdlib.h>
#include "mystack.h"
using namespace std;

void initStack(Sqstack &S, int size){  
    S.base = new elemtype[size];  
    S.top = S.base;  
    S.stacksize = size;  
    S.length = 0;
}  
bool isEmpty(Sqstack &S){  
    if(S.top == S.base)  
        return true;  
    else  
        return false;  
}  
  
elemtype getTop(Sqstack &S){  
    if(S.base == S.top)  
        return false;  
    else  
        return *(S.top-1);  
}  
bool isFull(Sqstack &S){  
    if(S.top-S.base >= S.stacksize)  
        return true;  
    else  
        return false;  
}  
void Push(Sqstack &S, elemtype e){      //压栈  
    /*if(S.top-S.base >= S.stacksize){ 
        S.base = (elemtype *)realloc(S.base,(another+S.stacksize)*sizeof(elemtype)); 
        S.top = S.base + S.stacksize; 
        S.stacksize += another 
        ; 
    }*/  
    *S.top++ = e;  
    S.length++;
}  
int Pop(Sqstack &S, elemtype &e){  
    if(S.top == S.base) return false;
    S.length--;  
    return e = * --S.top;  
}  

