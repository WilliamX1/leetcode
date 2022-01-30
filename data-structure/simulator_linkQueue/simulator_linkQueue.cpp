#include "simulator_linkQueue.h"
#include "linkQueue.h"
#include <iostream> 
using namespace std;

simulator_linkQueue::simulator_linkQueue()
{
	cout << "请输入到达时间间隔的上下界：";
	cin >> arrivalLow >> arrivalHigh;

	cout << "请输入服务时间的上下界：";
	cin >> serviceTimeLow >> serviceTimeHigh;

	cout << "请输入模拟的顾客数：";
	cin >> customNum;

	srand(time(NULL));  //初始化随机数发生器
}
int simulator_linkQueue::avgWaitTime()const
{
	int currentTime = 0;  //当前时间
	int totalWaitTime = 0;  //总的等待时间
	int eventTime;
	linkQueue<int> customerQueue;  //顾客到达事件队列
	int i;

	for (i = 0; i < customNum; ++i) {
		currentTime += arrivalLow + (arrivalHigh - arrivalLow + 1) * rand() / (RAND_MAX + 1);
		customerQueue.enQueue(currentTime);
	}

	//处理所有到达事件
	currentTime = 0;
	while (!customerQueue.isEmpty()) {
		eventTime = customerQueue.deQueue();
		if (eventTime < currentTime)
			totalWaitTime += currentTime - eventTime;
		else currentTime = eventTime;
		currentTime += serviceTimeLow + (serviceTimeHigh - serviceTimeLow + 1) * rand() / (RAND_MAX + 1);
	}
	return totalWaitTime / customNum;
}