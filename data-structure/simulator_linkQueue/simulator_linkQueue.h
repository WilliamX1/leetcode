#ifndef SIMULATOR_LINKQUEUE_H
#define SIMULATOR_LINKQUEUE_H
//ģ����Ķ���
class simulator_linkQueue {
	int arrivalLow;  //������ʱ������
	int arrivalHigh;  //������ʱ������
	int serviceTimeLow;  //����ʱ������
	int serviceTimeHigh;  //����ʱ������
	int customNum;  //ģ��Ĺ˿���

public:
	simulator_linkQueue();
	int avgWaitTime()const;
};
#endif // !SIMULATOR_LINKQUEUE_H