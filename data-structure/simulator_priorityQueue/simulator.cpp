#include "simulator.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "linkQueue.h"
#include "priorityQueue.h"
using namespace std;
simulator_priorityQueue::simulator_priorityQueue()
{
	cout << "请输入柜台数：";    cin >> noOfServer;
	cout << "请输入到达时间间隔的上下界（最小间隔时间  最大间隔时间）：";
	cin >> arrivalLow >> arrivalHigh;
	cout << "请输入服务时间的上下界（服务时间上界  服务时间下界）：";
	cin >> serviceTimeLow >> serviceTimeHigh;
	cout << "请输入模拟的顾客数：";    cin >> customNum;

	srand(time(NULL));  //随机数发生器初始化
}
/* 排队模拟过程伪代码
   产生customNum个顾客的到达事件，按照时间大小存入事件队列；
   置等待队列为空；
   置所有柜台为空；
   设置等待时间为0；
   while(事件队列非空)
   {
       队头元素出队;
	   设置当前时间为该事件发生的时间;
	   switch(事件类型)
	   {
	       case 到达:if(柜台有空)
		             {
					     柜台数减1;
						 生成所需的服务时间;
						 修改事件类型为"离开";
						 设置事件发生时间为当前时间加上服务时间;
						 重新存入事件队列;
				     }
					 else 将该事件存入等待队列;
		   case 离开:if(等待队列非空)
		             {
					     队头元素出队;
						 统计该顾客的等待时间;
						 生成所需的服务时间;
						 修改事件类型为"离开";
						 设置事件发生时间为当前时间加上服务时间;
						 存入事件队列;
					 }
					 else 空闲柜台数加1;
		}
	}
    计算平均等待时间;
	返回;
} */
int simulator_priorityQueue::avgWaitTime()
{
	int serverBusy = 0;        //正在工作的服务台数
	int currentTime = 0;       //记录模拟过程中的时间
	int totalWaitTime = 0;     //模拟过程中所有顾客的等待时间的总和
	linkQueue<eventT> waitQueue;    //顾客等待队列
	priorityQueue<eventT> eventQueue;    //事件队列

	eventT currentEvent;

	//生成初始的事件队列
	int i;
	currentEvent.time = 0;
	currentEvent.type = 0;
	for (i = 0; i < customNum; ++i)
	{
		currentEvent.time += arrivalLow + (arrivalHigh - arrivalLow + 1) * rand() / (RAND_MAX + 1);
		eventQueue.enQueue(currentEvent);
	}
	//模拟过程
	while (!eventQueue.isEmpty())
	{
		currentEvent = eventQueue.deQueue();
		currentTime = currentEvent.time;
		switch (currentEvent.type)
		{
		case 0:   //处理到达事件
			if (serverBusy != noOfServer)
			{
				++serverBusy;
				currentEvent.time += serviceTimeLow + (serviceTimeHigh - serviceTimeLow) * rand() / (RAND_MAX + 1);
				currentEvent.type = 1;
				eventQueue.enQueue(currentEvent);
			}
			else waitQueue.enQueue(currentEvent);
			break;
		case 1:   //处理离开事件
			if (!waitQueue.isEmpty())
			{
				currentEvent = waitQueue.deQueue();
				totalWaitTime += currentTime - currentEvent.time;
				currentEvent.time = currentTime + serviceTimeLow + (serviceTimeHigh - serviceTimeLow) * rand() / (RAND_MAX + 1);
				currentEvent.type = 1;
				eventQueue.enQueue(currentEvent);
			}
			else --serverBusy;
		}  //switch结束
	}  //while结束
	return totalWaitTime / customNum;
}