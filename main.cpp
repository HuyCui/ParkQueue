#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <unistd.h>
#include "mystack.h"
#include "myqueue.h"
#include "order.h"
#include "show.h"
using namespace std;

bool Find[100000];
int main()
{
    int num;
    char order_num[5];
    Sqstack S, Assist;
    linkQueue Q;
    initStack(S, 5);
    initStack(Assist, 5);
    initQueue(Q);
    memset(Find, false, sizeof(Find));
    cout<<"           欢迎登入停车场系统 "<<endl<<endl;

    show();
    while(1)
    {
        cout<<"         请根据提示输入你的指令"<<endl;
        cin>>order_num;
        if(order_num[0]-'0' == 1)
        {
            cout<<"请输入您的车牌号码："<<endl;
            cin>>num;
            if(Find[num] == true)
            {
                cout<<"停车场中发现相同拍照车辆，已替您报警"<<endl;		
		cout<<"系统即将退出"<<endl;
		sleep(2);
                quit();
            }
            park(S, Q, num);
            Find[num] = true;
	    sleep(2);
	    system("clear");
	    show();
        }
        else if(order_num[0]-'0' == 2)
        {
            cout<<"取车请输入您的车牌号码："<<endl;
            cin>>num;
            if(Find[num] == false)
            {
                cout<<"停车场中没有该车辆，请确认后输入"<<endl;
            }
            else
            {
                leave(S, Q, Assist, num);
                Find[num] = false;
		sleep(2);
		system("clear");
		show();
            }
        }
        else if(order_num[0]-'0' == 3)
        {
            get_info(S);
        }
        else if(order_num[0]-'0' == 4)
        {
		quit();
		system("clear");	
        }
	else 
	{
		cout<<"您输入的指令有误，请确认后重新输入"<<endl;
		sleep(2);
		system("clear");	
		show();		
	}
    }
}

