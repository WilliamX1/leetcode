#ifndef SIMULATOR_LINKQUEUE_H
#define SIMULATOR_LINKQUEUE_H
//模拟类的定义
class simulator_linkQueue {
	int arrivalLow;  //到达间隔时间下限
	int arrivalHigh;  //到达间隔时间上限
	int serviceTimeLow;  //服务时间下限
	int serviceTimeHigh;  //服务时间上限
	int customNum;  //模拟的顾客数

public:
	simulator_linkQueue();
	int avgWaitTime()const;
};
#endif // !SIMULATOR_LINKQUEUE_H