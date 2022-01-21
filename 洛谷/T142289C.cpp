#include <bits/stdc++.h>
#include <string>
#include <map>

using namespace std;

int A[300010];
bool flag[300010];

struct node
{
    int num;  //数值
    int times;  //次数
};
node T[300010];

int main()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]);
    sort(A + 1, A + n + 1);  //先排序

    int T_xb = 0;
    for (int i = 1; i <= n; i++)
    {
        int j = i;
        while(j < n && A[j] == A[j + 1]) j++;
        //将A转换为T数组
        ++T_xb;
        T[T_xb].num = A[i];
        T[T_xb].times = j - i + 1;
        i = j;
    }

    map<int, int> MAP;
    map<int, int>:: iterator iter;
    for (int i = 1; i <= T_xb; i++)
        MAP.insert(pair<int, int>(T[i].num, i));


    memset(flag, 0, sizeof(flag));  //统计该数是否用过
    long long int res = -1;
    long long int tmp_sum;

    for (int i = 1; i <= T_xb; i++)
    {
        if (flag[i]) continue; //已经计算过则跳过

        tmp_sum = 0;
        int j = i;  //用来寻找下一个可行数
        int next;

        do
        {
            tmp_sum += (long long)T[j].num * (long long)T[j].times;  //加上一次
            flag[j] = true;  //标记为计算过
            //寻找下一个数
            if (T[j].num % 2 == 1) break;  //如果下一个数不可能存在，则退出循环

            next = (T[j].num / 2) * 3;  //下一个数的值

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
