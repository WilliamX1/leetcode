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
            c_profit[i] = first_profit[i];  //复制一份用

        int tmp_sum = 0;

        int left_time = 12 * h;
        for (int j = 1; j < i; j++)
            left_time -= road_time[j];  //实际用来钓鱼的时间

        memset(tmp_stay, 0, sizeof(tmp_stay));  //初始化tmp_stay数组

        for (int k = 1; k <= left_time; k++)  //总的钓鱼时间分配
        {
            int tmp_xb = 1;  //找寻当前期望值最大的元素下标
            for (int s = 1; s <= i; s++)
                if (c_profit[s] > c_profit[tmp_xb]) tmp_xb = s;
            tmp_sum += c_profit[tmp_xb];  //钓鱼数量累加
            tmp_stay[tmp_xb]++;  //钓鱼停留时间增加
            c_profit[tmp_xb] -= decrease[tmp_xb];  //该点期望值下降
            c_profit[tmp_xb] = max(0, c_profit[tmp_xb]);
        }
        if (tmp_sum > sum_max) //若期望值更大了则直接更新
        {
            for (int k = 1; k <= n; k++)
                true_stay[k] = tmp_stay[k];
            sum_max = tmp_sum;
        }
        if (tmp_sum == sum_max)
        {
            for (j = 1; j <= n && tmp_stay[j] == true_stay[j]; j++);  //找寻第一次不相等停留时间
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
