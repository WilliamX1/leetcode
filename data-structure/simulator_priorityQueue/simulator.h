#ifndef SIMULATOR_PRIORITYQUEUE_H
#define SIMULATOR_PRIORITYQUEUE_H
class simulator_priorityQueue
{
  private:
    int noOfServer;      //����̨����
    int arrivalLow;      //������ʱ����½�
    int arrivalHigh;     //������ʱ����Ͻ�
    int serviceTimeLow;  //������ʱ����½�
    int serviceTimeHigh; //������ʱ����Ͻ�
    int customNum;       //ģ��Ĺ˿���

    struct eventT
    {
        int time; //�¼�����ʱ��
        int type; //�¼����ͣ�0Ϊ���1Ϊ�뿪
        bool operator<(const eventT &e) const
        {
            return time < e.time;
        };
    };

  public:
    simulator_priorityQueue();
    int avgWaitTime();
};
#endif // !SIMULATOR_H