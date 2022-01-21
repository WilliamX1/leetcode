#include "simulator.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "linkQueue.h"
#include "priorityQueue.h"
using namespace std;
simulator_priorityQueue::simulator_priorityQueue()
{
	cout << "�������̨����";    cin >> noOfServer;
	cout << "�����뵽��ʱ���������½磨��С���ʱ��  �����ʱ�䣩��";
	cin >> arrivalLow >> arrivalHigh;
	cout << "���������ʱ������½磨����ʱ���Ͻ�  ����ʱ���½磩��";
	cin >> serviceTimeLow >> serviceTimeHigh;
	cout << "������ģ��Ĺ˿�����";    cin >> customNum;

	srand(time(NULL));  //�������������ʼ��
}
/* �Ŷ�ģ�����α����
   ����customNum���˿͵ĵ����¼�������ʱ���С�����¼����У�
   �õȴ�����Ϊ�գ�
   �����й�̨Ϊ�գ�
   ���õȴ�ʱ��Ϊ0��
   while(�¼����зǿ�)
   {
       ��ͷԪ�س���;
	   ���õ�ǰʱ��Ϊ���¼�������ʱ��;
	   switch(�¼�����)
	   {
	       case ����:if(��̨�п�)
		             {
					     ��̨����1;
						 ��������ķ���ʱ��;
						 �޸��¼�����Ϊ"�뿪";
						 �����¼�����ʱ��Ϊ��ǰʱ����Ϸ���ʱ��;
						 ���´����¼�����;
				     }
					 else �����¼�����ȴ�����;
		   case �뿪:if(�ȴ����зǿ�)
		             {
					     ��ͷԪ�س���;
						 ͳ�Ƹù˿͵ĵȴ�ʱ��;
						 ��������ķ���ʱ��;
						 �޸��¼�����Ϊ"�뿪";
						 �����¼�����ʱ��Ϊ��ǰʱ����Ϸ���ʱ��;
						 �����¼�����;
					 }
					 else ���й�̨����1;
		}
	}
    ����ƽ���ȴ�ʱ��;
	����;
} */
int simulator_priorityQueue::avgWaitTime()
{
	int serverBusy = 0;        //���ڹ����ķ���̨��
	int currentTime = 0;       //��¼ģ������е�ʱ��
	int totalWaitTime = 0;     //ģ����������й˿͵ĵȴ�ʱ����ܺ�
	linkQueue<eventT> waitQueue;    //�˿͵ȴ�����
	priorityQueue<eventT> eventQueue;    //�¼�����

	eventT currentEvent;

	//���ɳ�ʼ���¼�����
	int i;
	currentEvent.time = 0;
	currentEvent.type = 0;
	for (i = 0; i < customNum; ++i)
	{
		currentEvent.time += arrivalLow + (arrivalHigh - arrivalLow + 1) * rand() / (RAND_MAX + 1);
		eventQueue.enQueue(currentEvent);
	}
	//ģ�����
	while (!eventQueue.isEmpty())
	{
		currentEvent = eventQueue.deQueue();
		currentTime = currentEvent.time;
		switch (currentEvent.type)
		{
		case 0:   //�������¼�
			if (serverBusy != noOfServer)
			{
				++serverBusy;
				currentEvent.time += serviceTimeLow + (serviceTimeHigh - serviceTimeLow) * rand() / (RAND_MAX + 1);
				currentEvent.type = 1;
				eventQueue.enQueue(currentEvent);
			}
			else waitQueue.enQueue(currentEvent);
			break;
		case 1:   //�����뿪�¼�
			if (!waitQueue.isEmpty())
			{
				currentEvent = waitQueue.deQueue();
				totalWaitTime += currentTime - currentEvent.time;
				currentEvent.time = currentTime + serviceTimeLow + (serviceTimeHigh - serviceTimeLow) * rand() / (RAND_MAX + 1);
				currentEvent.type = 1;
				eventQueue.enQueue(currentEvent);
			}
			else --serverBusy;
		}  //switch����
	}  //while����
	return totalWaitTime / customNum;
}