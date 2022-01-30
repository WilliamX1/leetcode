#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

bool myCompare(int a, int b){return a > b;};

int first_profit[30];
int decrease[30];
int road_time[30];
int tmp_stay[30];
int true_stay[30];
int i, j, k;

int main()
{
    int n, h; scanf("%d", &n);
    while(n != 0)
    {
        scanf("%d", &h);

    int sum_max = 0;

    for (int i = 1; i <= n; i++)
        scanf("%d", &first_profit[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &decrease[i]);
    for (int i = 1; i < n; i++)
        scanf("%d", &road_time[i]);

    memset(true_stay, 0, sizeof(true_stay));

    for (int i = 1; i <= n; i++)
    {
        int c_profit[30];
        for (int i = 1; i <= n; i++)
            c_profit[i] = first_profit[i];  //����һ����

        int tmp_sum = 0;

        int left_time = 12 * h;
        for (int j = 1; j < i; j++)
            left_time -= road_time[j];  //ʵ�����������ʱ��

        memset(tmp_stay, 0, sizeof(tmp_stay));  //��ʼ��tmp_stay����

        for (int k = 1; k <= left_time; k++)  //�ܵĵ���ʱ�����
        {
            int tmp_xb = 1;  //��Ѱ��ǰ����ֵ����Ԫ���±�
            for (int s = 1; s <= i; s++)
                if (c_profit[s] > c_profit[tmp_xb]) tmp_xb = s;
            tmp_sum += c_profit[tmp_xb];  //���������ۼ�
            tmp_stay[tmp_xb]++;  //����ͣ��ʱ������
            c_profit[tmp_xb] -= decrease[tmp_xb];  //�õ�����ֵ�½�
            c_profit[tmp_xb] = max(0, c_profit[tmp_xb]);
        }
        if (tmp_sum > sum_max) //������ֵ��������ֱ�Ӹ���
        {
            for (int k = 1; k <= n; k++)
                true_stay[k] = tmp_stay[k];
            sum_max = tmp_sum;
        }
        if (tmp_sum == sum_max)
        {
            for (j = 1; j <= n && tmp_stay[j] == true_stay[j]; j++);  //��Ѱ��һ�β����ͣ��ʱ��
            if (tmp_stay[j] > true_stay[j])
                for (int k = 1; k <= n; k++)
                    true_stay[k] = tmp_stay[k];
        }
    }

    for (int i = 1; i <= n; i++) true_stay[i] *= 5;

    printf("%d", true_stay[1]);
    for (int i = 2; i <= n; i++)
        printf("%c %d",',',true_stay[i]);
    printf("\n%s%d\n\n", "Number of fish expected: ", sum_max);

        scanf("%d", &n);
    }
    return 0;
}
