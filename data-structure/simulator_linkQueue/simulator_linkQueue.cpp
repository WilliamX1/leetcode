#include "simulator_linkQueue.h"
#include "linkQueue.h"
#include <iostream> 
using namespace std;

simulator_linkQueue::simulator_linkQueue()
{
	cout << "�����뵽��ʱ���������½磺";
	cin >> arrivalLow >> arrivalHigh;

	cout << "���������ʱ������½磺";
	cin >> serviceTimeLow >> serviceTimeHigh;

	cout << "������ģ��Ĺ˿�����";
	cin >> customNum;

	srand(time(NULL));  //��ʼ�������������
}
int simulator_linkQueue::avgWaitTime()const
{
	int currentTime = 0;  //��ǰʱ��
	int totalWaitTime = 0;  //�ܵĵȴ�ʱ��
	int eventTime;
	linkQueue<int> customerQueue;  //�˿͵����¼�����
	int i;

	for (i = 0; i < customNum; ++i) {
		currentTime += arrivalLow + (arrivalHigh - arrivalLow + 1) * rand() / (RAND_MAX + 1);
		customerQueue.enQueue(currentTime);
	}

	//�������е����¼�
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