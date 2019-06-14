#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <stdlib.h>
#include "mystack.h"
#include "myqueue.h"
#include "order.h"
using namespace std;

void park(Sqstack &S, linkQueue &Q, int num)
{

    if(!isFull(S))
    {
	cout<<"当前停车场未停满，你可以停车"<<endl;
        Push(S, num);
	cout<<"您的牌照为"<<num<<"的车已停入"<<endl;
    }
    else
    {
	cout<<"抱歉，停车场已经停满，您的车辆将进入等待通道"<<endl;
        enQueue(Q, num);
    }
}

void leave(Sqstack &S, linkQueue &Q, Sqstack &Assist, int num)
{
    int temp;
    while(1)
    {
        if(getTop(S) == num)
        {
            temp = Pop(S, temp);
	    cout<<"您的牌照为"<<temp<<"的车辆已经离开"<<endl;
            break;
        }
        else
        {
            temp = Pop(S, temp);
            Push(Assist, temp);
        }
    }
    while(!isEmpty(Assist))
    {
        temp = Pop(Assist, temp);
        Push(S, temp);
    }
    if(!QueueEmpty(Q))
    {
        deQueue(Q, temp);
	cout<<"停车场内已经有一个空位，牌照为"<<temp<<"的车辆可以停入"<<endl;
        Push(S, temp);
    }
}

void quit()
{
    exit(0);
}

void get_info(Sqstack &S)
{
    cout<<"当前在停车场中有"<<S.length<<"辆车"<<endl;
    if(S.length >= 5)
	cout<<"停车场已停满"<<endl;
    else 
	cout<<"停车场未停满"<<endl;
}

/*int judge(int order_num)
{
	char for_sure;
	char string[5][5] = {"  ","停车","取车","获取停车场信息","退出系统"}；
	cout<<"你想要  "<<string[order_num]<<"?"<<endl;
	cout<<"如果确定您的输入无误，请输入y继续，否则输入n"<<endl;
	cin>>for_sure;

}*/

