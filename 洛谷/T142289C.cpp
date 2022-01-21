#include <bits/stdc++.h>
#include <string>
#include <map>

using namespace std;

int A[300010];
bool flag[300010];

struct node
{
    int num;  //��ֵ
    int times;  //����
};
node T[300010];

int main()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]);
    sort(A + 1, A + n + 1);  //������

    int T_xb = 0;
    for (int i = 1; i <= n; i++)
    {
        int j = i;
        while(j < n && A[j] == A[j + 1]) j++;
        //��Aת��ΪT����
        ++T_xb;
        T[T_xb].num = A[i];
        T[T_xb].times = j - i + 1;
        i = j;
    }

    map<int, int> MAP;
    map<int, int>:: iterator iter;
    for (int i = 1; i <= T_xb; i++)
        MAP.insert(pair<int, int>(T[i].num, i));


    memset(flag, 0, sizeof(flag));  //ͳ�Ƹ����Ƿ��ù�
    long long int res = -1;
    long long int tmp_sum;

    for (int i = 1; i <= T_xb; i++)
    {
        if (flag[i]) continue; //�Ѿ������������

        tmp_sum = 0;
        int j = i;  //����Ѱ����һ��������
        int next;

        do
        {
            tmp_sum += (long long)T[j].num * (long long)T[j].times;  //����һ��
            flag[j] = true;  //���Ϊ�����
            //Ѱ����һ����
            if (T[j].num % 2 == 1) break;  //�����һ���������ܴ��ڣ����˳�ѭ��

            next = (T[j].num / 2) * 3;  //��һ������ֵ

            iter = MAP.find(next);
            if (iter != MAP.end())
                j = iter->second;
            //while(++j <= T_xb && T[j].num < next);
        }while(iter != MAP.end());
        //while(j <= T_xb && T[j].num == next);
        res = max(res, tmp_sum);

    }
    cout << res;

    return 0;
}
