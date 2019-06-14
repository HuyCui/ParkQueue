#ifndef _ORDER_H
#define _ORDER_H

//bool Find[100000] = {0};
void park(Sqstack &S, linkQueue &Q, int num);
void leave(Sqstack &S, linkQueue &Q, Sqstack &Assist, int num);
void quit();
void get_info(Sqstack &S);
//int judge(int num);

#endif
