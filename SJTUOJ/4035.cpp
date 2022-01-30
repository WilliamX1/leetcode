#include <iostream>
#include <queue>
using namespace std;
const int M = 100001;
int Des[M];  //总目的地记录

int main()
{
    queue<int> Place;  //用来存储地方
    int N, k;  cin >> N;  //t为到达时间，k为车上旅客数量
    long long int t;
    int i, j, s = 1, m;
    int tmp;  //临时输入用
    int curTotal = 0; //记录当前车次后的总目的地到达广度
    long long int* Time = new long long int[N + 1];  //对应车次的到达时间
    int* Num = new int[N + 1];  //对应车上的人数
    for (i = 0; i <= N; i++)
        Time[i] = Num[i] = 0;
    for (i = 0; i < M; i++)
        Des[i] = 0;

    for (i = 1; i <= N; i++)
    {
        cin >> t >> k;
        Time[i] = t;  
        Num[i] = k;
        for (j = 1; j <= k; j++)
        {
            cin >> tmp;
            Place.push(tmp);
            if (Des[tmp] == 0) curTotal += 1;  //如果还没有人到达过次目的地，则总到达广度+1
            Des[tmp] += 1;  //对应目的地到达次数到达加1
        }
        for (; s < i; s++)
        {
            if (t - Time[s] >= 86400)  //如果相差24小时
                for (m = 1; m <= Num[s]; m++)  //将所有该班次到达目的地出队
                {
                    tmp = Place.front();
                    Des[tmp] -= 1;
                    if (Des[tmp] == 0) curTotal -= 1;
                    Place.pop();
                }
            if (t - Time[s] < 86400)
                break;
        }
        cout << curTotal << endl;
    }
    return 0;
}
